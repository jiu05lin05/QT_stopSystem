#include "admininterface.h"
#include "ui_admininterface.h"

adminInterface::adminInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminInterface)
{
    ui->setupUi(this);
    myclient=TCPclient::instance();
    myclient->writeSocket("getSql");
    myc= mycamera::getInstance();
}

adminInterface::~adminInterface()
{
    delete ui;
}

void adminInterface::getCameraflag(int *flag)
{
    cameraflag=flag;
}

//返回键
void adminInterface::on_pushButton_clicked()
{
    *(this->cameraflag)=1;
    myc->cameraflag=1;
    this->parentWidget()->parentWidget()->parentWidget()->show();

    this->hide();
    myclient->writeSocket("cameraChange");
}

void adminInterface::on_get_clicked()
{
    QString receivedData(myclient->readSocket()); // 这里填写接收到的字符串数据

    if (receivedData.startsWith("sql~")) {
        receivedData = receivedData.mid(4); // 跳过前缀"sql~"，获取剩余的数据部分
    }

    QStringList rows = receivedData.split("#"); // 按行分割数据
    QList<QStringList> result;
    foreach (const QString& row, rows) {
        if (row.trimmed().isEmpty()) continue; // 跳过空行
        QStringList columns = row.split("@");
        result.append(columns); // 添加到结果列表
    }

    // 清除现有内容并设置表格大小
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(result.size());
    ui->tableWidget->setColumnCount(result.isEmpty() ? 0 : result[0].size());

    // 设置表头
    QStringList headerLabels;
    headerLabels << "卡号" << "车牌号" << "车位" << "入库时间" << "停车状态";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    // 填充数据
    for (int row = 0; row < result.size(); ++row)
    {
        for (int column = 0; column < result[row].size(); ++column) {
            QTableWidgetItem* item = new QTableWidgetItem(result[row][column]);
            ui->tableWidget->setItem(row, column, item);
        }
    }
}


void adminInterface::on_confirm_clicked()
{
    // 获取表格中的数据
     QStringList rowsData;
     for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
     {
         QStringList rowData;
         for (int column = 0; column < ui->tableWidget->columnCount(); ++column)
         {
             QTableWidgetItem* item = ui->tableWidget->item(row, column);
             rowData.append(item->text());
         }
         rowsData.append(rowData.join("~")); // 使用特定分隔符拼接每行数据
     }
     QString sendData = rowsData.join("#"); // 使用特定分隔符拼接所有行数据

      qDebug()<<"sendData is: "<<sendData;
     // 发送数据给服务器
     myclient->writeSocket("sql@"+sendData);
}

void adminInterface::on_get_2_clicked()
{
    // 获取当前选中的单元格
    QModelIndexList selectedIndexes = ui->tableWidget->selectionModel()->selectedIndexes();

    if (!selectedIndexes.isEmpty()) {
        // 获取选中单元格的行号
        int selectedRow = selectedIndexes.first().row();

        // 删除该行数据
        ui->tableWidget->removeRow(selectedRow);
    }
}
