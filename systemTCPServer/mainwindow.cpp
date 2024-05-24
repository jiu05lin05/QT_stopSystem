#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("服务器");
    myserver=new QTcpServer(this);
    myserver->listen(SERVERIP,SERVERPORT);
    connect(myserver,SIGNAL(newConnection()),this,SLOT(fun()));
    //安装数据库驱动
    base1=QSqlDatabase::addDatabase("QSQLITE", "my_con");

    // 如果数据库文件不存在，则创建一个新的数据库文件
    if (!QFile::exists(DBPATH))
    {
        // 创建一个空的数据库文件
        QFile dbFile(DBPATH);
        if (!dbFile.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "出错了", "无法创建数据库文件：" + dbFile.errorString());
            return;
        }
        dbFile.close();
    }

    //设置数据库的名字
    base1.setDatabaseName(DBPATH);

    //打开数据库
    bool ret=base1.open();
    if(!ret)
    {
        QMessageBox::warning(this, "出错了", "打开数据库失败了: " + base1.lastError().text());
        return;
    }
    else
        qDebug()<<"打开数据库成功"<<base1;

    //新建表格
    query1=new QSqlQuery(base1);
    ret=query1->exec("create table if not exists rootinfo (phonenum text primary key,passwd text);");
    if(!ret)
    {
        QMessageBox::warning(this,"出错了","新建管理员表格失败了");
        return;
    }
    ret=query1->exec("create table if not exists userinfo (rfidCard text primary key,licensePlate text,place text,time text,state text);");
    if(!ret)
    {
        QMessageBox::warning(this,"出错了","新建用户表格失败了");
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}

//连接客户端
void MainWindow::fun()
{
    //连接到客户端
    newSocket=myserver->nextPendingConnection();
    qDebug()<<newSocket->peerAddress();     //客户端的IP地址
    qDebug()<<newSocket->peerPort();        //客户端的端口号
    QString user(newSocket->peerAddress().toString()+"@"+QString::number(newSocket->peerPort()));
    clientSockets.push_back(newSocket);

    connect(newSocket,SIGNAL(disconnected()),this,SLOT(discon()));
    connect(newSocket,SIGNAL(readyRead()),this,SLOT(recvClientMsg()));
    //把连接成功的套接字存到链表中
    clientSockets.push_back(newSocket);
    ui->listWidget->addItem(user);
}

//接收信息
void MainWindow::recvClientMsg()
{
    qDebug()<<"接收到信息";
    //获取信号发送者
    QObject *obj=sender();
    //当前套接字指针
    QTcpSocket* currentSocket=qobject_cast<QTcpSocket*>(obj);
    QString prefix=currentSocket->peerAddress().toString()+'@'+QString::number(currentSocket->peerPort());
    QString content=currentSocket->readAll();
    qDebug()<<prefix;
    qDebug()<<content;
    //切割判断发来的是什么信息
    QStringList parts=content.split('@');

    if(parts.at(0)=="login")        //用户登录
    {
        cmd=QString("select * from rootinfo where phonenum='%1' and passwd='%2';").arg(parts.at(1)).arg(parts.at(2));
        if (!query1->exec(cmd))
        {
            qDebug() << "Query execution failed:" << query1->lastError().text();
            currentSocket->write("Login fail: Query execution failed");
            return; // 或者采取其他适当的错误处理措施
        }
        else
        {
            if(query1->next())
            {
                qDebug()<<"登录成功";
                currentSocket->write("Login successful");
            }
            else
            {
                qDebug()<<"用户名或密码错误";
                currentSocket->write("Login fail");
            }
        }
    }
    else if(parts.at(0)=="reg")     //用户注册
    {
        cmd=QString("select * from rootinfo where account='%1';").arg(parts[1]);
        query1->exec(cmd);
        if (!query1->next())
        {
            cmd = QString("INSERT INTO rootinfo (account, passwd, phonenum) VALUES ('%1', '%2', '%3');").arg(parts[1]).arg(parts[2]).arg(parts[3]);
            bool success=query1->exec(cmd);
            if(success) {
                qDebug() << "注册成功";
                qDebug() << "Insertion successful!";
                currentSocket->write("reg successful");
            } else {
                qDebug() << "Insertion failed:" << query1->lastError().text();
            }
        }
        else if(query1->next())
        {
            qDebug()<<"注册失败";
            return;
        }
    }
    else if(parts.at(0)=="key")    //用户输入密钥
    {
        if(parts.at(1)=="ouyang")
        {
            currentSocket->write("The key is correct");
        }
    }
    else if(parts.at(0)=="snapshot")    //抓拍到照片
    {
        qDebug()<<"抓拍到照片";
        currentSocket->write("Get a license plate");
    }
    else if(parts.at(0)=="judgment")
    {
        if(parts.at(1)=="error")
        {
            cmd = QString("update userinfo set state = CASE state WHEN '0' THEN '1' ELSE '0' END where rfidCard='%1';").arg(parts.at(2));
            query1->exec(cmd);
            return;
        }
        cmd = QString("select state, place ,time from userinfo where rfidCard='%1';").arg(parts.at(1));
        bool success=query1->exec(cmd);
        if(success)
        {
            if(query1->next())
            {
                QString state = query1->value(0).toString();  // 获取 state 的值
                QString place = query1->value(1).toString();  // 获取 place 的值
                QString time = query1->value(2).toString();  // 获取 time 的值
                qDebug()<<"state is: "<<state;
                if(state=="1")    //说明出库
                {
                    qDebug()<<"发送了out答复";
                    currentSocket->write(("out@"+place+"@"+time).toUtf8());
                    //将该用户的state修改
                    cmd = QString("update userinfo set state='0',place='%1' where rfidCard='%2';").arg(place).arg(parts.at(1));
                    bool success=query1->exec(cmd);
                    if(success)
                    {
                        qDebug()<<"update 0 success";
                    }
                }
                else  //说明入库
                {
                    qDebug()<<"success: 发送了in答复";
                    currentSocket->write("in");
                    cmd = QString("update userinfo set state='1',place='%1' where rfidCard='%2';").arg(place).arg(parts.at(1));
                    bool success=query1->exec(cmd);
                    if(success)
                    {
                        qDebug()<<"update 1 success";
                    }
                }
            }
            else    //说明用户是第一次进入车库
            {
                qDebug()<<"fail: 发送了in答复";
                currentSocket->write("in");
            }
        }
    }
    else if(parts.at(0)=="root")
    {
        cmd = QString("INSERT INTO rootinfo (phonenum,passwd) VALUES ('%1', '%2');").arg(parts.at(1)).arg(parts.at(2));
        bool success=query1->exec(cmd);
        if(success)
        {
            qDebug() << "The administrator inserted successfully";
        }
        else
        {
            qDebug() << "Admin insertion failed";
        }
    }
    else if(parts.at(0)=="user")//刷卡入库/出库
    {
        cmd = QString("INSERT INTO userinfo (rfidCard,licensePlate,place,time,state) VALUES ('%1', '%2', '%3','%4','%5');").arg(parts.at(1)).arg(parts.at(2)).arg(parts.at(3)).arg(parts.at(4)).arg("1");
        bool success=query1->exec(cmd);
        if(success)
        {
            qDebug() << "ruku successful!";
        }
        else    //说明数据库中已经有该用户了
        {
            cmd = QString("UPDATE userinfo SET time ='%1',place='%2' where rfidCard='%3';").arg(parts.at(4)).arg(parts.at(3)).arg(parts.at(1));
            bool success=query1->exec(cmd);
            if(success)
            {
                qDebug() << "change successful!";
            }
            else
            {
                qDebug()<<"change false";
            }
            qDebug() << "ruku failed:" << query1->lastError().text();
        }
    }
    else if(parts.at(0)=="phoneNum")    //说明管理员要登录
    {
        cmd = QString("select * from rootinfo where phonenum='%1';").arg(parts.at(2));
        bool success=query1->exec(cmd);
        if(success)
        {
            if(parts.at(1)=="login")
            {
                if(query1->next()) //说明查询结果不为空，该用户已注册
                {
                    //可以成功登录
                    currentSocket->write("can log in");
                }
                else    //说明查询结果为空，该用户未注册,不可登录
                {
                    currentSocket->write("Not registered");
                }
            }
            else if(parts.at(1)=="reg")
            {
                if(query1->next()) //说明查询结果不为空，该用户已注册
                {
                    currentSocket->write("already registered");
                }
                else    //说明查询结果为空，可以注册
                {
                    currentSocket->write("Registration is possible");
                }
            }
        }
    }
    else if(parts.at(0)=="getSql")
    {
        cmd = "select * from userinfo;";
        bool success = query1->exec(cmd);
        if (success)
        {
            QString temp("sql~");
            int row = 0;

            while (query1->next())
            {
                QString info1 = query1->value(0).toString(); // 获取第一列的值 rfidCard
                temp += info1 + "@";
                QString info2 = query1->value(1).toString(); // 获取第二列的值 licensePlate
                temp += info2 + "@";
                QString info3 = query1->value(2).toString(); // 获取第三列的值 place
                temp += info3 + "@";
                QString info4 = query1->value(3).toString(); // 获取第四列的值 time
                temp += info4 + "@";
                QString info5 = query1->value(4).toString(); // 获取第五列的值 state
                temp += info5;

                if (row != query1->size() - 1)
                {
                    temp += "#";
                }
                row++;
            }
            currentSocket->write(temp.toUtf8());
        }
        else {
            qDebug() << "select fail";
        }
    }
    else if (parts.at(0) == "sql")
    {
        qDebug() << "进入sql判断";
        QStringList dataParts = parts.mid(1);

        QString clearTableCmd = "DELETE FROM userinfo";
        if (!query1->exec(clearTableCmd)) {
            qDebug() << "Clear table userinfo failed:" << query1->lastError().text();
            // 错误处理
        }

        foreach (const QString &data, dataParts) {
            QStringList rows = data.split('#');

            foreach (const QString &rowData, rows) {
                QStringList columns = rowData.split('~');

                if (columns.size() < 5) {
                    qDebug() << "Not enough data fields in columns: " << rowData;
                    continue; // 跳过当前数据行
                }

                QString rfidCard = columns.at(0);
                QString licensePlate = columns.at(1);
                QString place = columns.at(2);
                QString time = columns.at(3);
                QString state = columns.at(4);

                QString insertCmd = QString("INSERT INTO userinfo (rfidCard, licensePlate, place, time, state) VALUES ('%1', '%2', '%3', '%4', '%5')")
                        .arg(rfidCard)
                        .arg(licensePlate)
                        .arg(place)
                        .arg(time)
                        .arg(state);

                if (!query1->exec(insertCmd)) {
                    qDebug() << "Insert data into userinfo failed:" << query1->lastError().text();
                    // 错误处理
                }
            }
        }
    }


}

//客户端断开连接
void MainWindow::discon()
{
    //获取要从列表中删除用户
    QString del=newSocket->peerAddress().toString()+'@'+QString::number(newSocket->peerPort());
    qDebug()<<"del is: "<<del;
    //获取信号发送者
    QObject *obj=sender();
    //当前套接字指针
    QTcpSocket* currentSocket=qobject_cast<QTcpSocket*>(obj);
    //先找到要删除用户的套接字,准备后续关闭动作
    QString others;

    for(auto x:clientSockets)
    {
        others=x->peerAddress().toString()+'@'+QString::number(x->peerPort());
        if(others==clientstr)
        {
            currentSocket=x;  //存放要删除的用户的套接字
            break;
        }
    }

    //关闭该用户的套接字
    currentSocket->close();

}
