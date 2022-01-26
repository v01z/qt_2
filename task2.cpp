#include "task2.h"
#include "ui_task2.h"

task2::task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    if (!model) close();

    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon("../qt_2/data/cpp.png"), "C++"));
    model->appendRow(new QStandardItem(QIcon("../qt_2/data/python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon("../qt_2/data/java.png"), "Java"));
    model->appendRow(new QStandardItem(QIcon("../qt_2/data/csharp.png"), "C#"));
    model->appendRow(new QStandardItem(QIcon("../qt_2/data/php.png"), "PHP"));
    model->appendRow(new QStandardItem(QIcon("../qt_2/data/js.png"), "JavaScript"));


}

task2::~task2()
{
    if (model) {
        delete model;
        model = nullptr;
    }

    delete ui;
}

void task2::on_btnClose_clicked()
{
   close();
}

