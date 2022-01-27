#include "task3.h"
#include "ui_task3.h"

task3::task3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);

     model = new QStandardItemModel(this);
    if (!model) close();

    ui->tableView->setModel(model);

    std::vector< QList<QStandardItem*> > MachinePark;

//    for (size_t i{}; i < LAN_NET_PARK.size(); ++i)

    for (const auto elem: LAN_NET_PARK)
    {
        QList<QStandardItem*> temp;
        temp.append(new QStandardItem(elem.Number));
        temp.append(new QStandardItem(elem.Hostname));
        temp.append(new QStandardItem(elem.IPaddress));
        temp.append(new QStandardItem(elem.MACaddress));
        /*
        temp.append(new QStandardItem(LAN_NET_PARK.at(i).Number));
        temp.append(new QStandardItem(LAN_NET_PARK.at(i).Hostname));
        temp.append(new QStandardItem(LAN_NET_PARK.at(i).IPaddress));
        temp.append(new QStandardItem(LAN_NET_PARK.at(i).MACaddress));
        */
        model->appendRow(temp);
    }

    /*
    QList <QStandardItem*> listHeader;
    listHeader.append(new QStandardItem("N"));
    listHeader.append(new QStandardItem("Host name"));
    listHeader.append(new QStandardItem("IP address"));
    listHeader.append(new QStandardItem("MAC address"));
    model->appendRow(listHeader);

    QList <QStandardItem*> listData1;
    //listData1.append(new QStandardItem("1"));
    listData1.append(new QStandardItem("1"));
    listData1.append(new QStandardItem("Router"));
    listData1.append(new QStandardItem("192.168.0.1"));
    listData1.append(new QStandardItem("AA:BB:CC:DD:1A:1B"));
    model->appendRow(listData1);

    QList <QStandardItem*> listData2;
    listData2.append(new QStandardItem("2"));
    listData2.append(new QStandardItem("Server"));
    listData2.append(new QStandardItem("192.168.0.2"));
    listData2.append(new QStandardItem("A1:B2:C1:DD:3A:4C"));
    model->appendRow(listData2);

    QList <QStandardItem*> listData3;
    listData3.append(new QStandardItem("3"));
    listData3.append(new QStandardItem("Desktop1"));
    listData3.append(new QStandardItem("192.168.0.15"));
    listData3.append(new QStandardItem("B1:A2:C1:C5:A4:1C"));
    model->appendRow(listData3);

    QList <QStandardItem*> listData4;
    listData4.append(new QStandardItem("4"));
    listData4.append(new QStandardItem("Desktop2"));
    listData4.append(new QStandardItem("192.168.0.16"));
    listData4.append(new QStandardItem("A1:C5:21:C1:BA:C4"));
    model->appendRow(listData4);

    QList <QStandardItem*> listData5;
    listData5.append(new QStandardItem("5"));
    listData5.append(new QStandardItem("Desktop3"));
    listData5.append(new QStandardItem("192.168.0.17"));
    listData5.append(new QStandardItem("B4:A1:2C:C3:A4:22"));
    model->appendRow(listData5);
    */


}

task3::~task3()
{
    if (model) {
        model->clear();
        delete model;
        model = nullptr;
    }

    delete ui;
}

void task3::on_btnClose_clicked()
{
   close();
}

