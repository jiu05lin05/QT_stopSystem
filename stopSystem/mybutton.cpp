 #include "mybutton.h"
#include <QDebug>

mybutton::mybutton(QWidget *parent)
{
    //关联clicked信号
    connect(this, SIGNAL(clicked()), this, SLOT(fun()));
}

void mybutton::fun()
{
    //获取信号的发送者
    QPushButton *p = qobject_cast<QPushButton *>(sender());
    QString str = p->text(); //获取按钮的字面值  a -->97-32=65

    //按照上课讲的事件产生的流程去写代码
    QKeyEvent *keyevent;
    //判断特殊按键
    if (str == "←") //退格键
    {
        //自定义一个按键事件
        keyevent = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, str);
    }
    else if (str == "Enter")
    {
        //自定义一个按键事件
        keyevent = new QKeyEvent(QEvent::KeyPress, Qt::Key_End, Qt::NoModifier, str);
        // 隐藏父组件
        if (this->parentWidget())
        {
            this->parentWidget()->parentWidget()->hide();
            qDebug()<<"父地址: "<<this->parentWidget()->parentWidget();
            this->parentWidget()->parentWidget()->window()->setFocus();
        }
    }
    else //字母按键
    {
        //自定义一个按键事件
        keyevent = new QKeyEvent(QEvent::KeyPress, str.toInt() - 32, Qt::NoModifier, str);
    }

    //把这个按键事件发送出去--》发送个鼠标光标聚集的组件
    QCoreApplication::postEvent(QApplication::focusWidget(), keyevent);
}
