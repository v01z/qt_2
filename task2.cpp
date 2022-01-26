#include "task2.h"
#include "ui_task2.h"

const QString DATA_PATH { "../qt_2/data/" };

task2::task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    if (!model) close();

    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "cpp.png"), "C++"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "java.png"), "Java"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "csharp.png"), "C#"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "php.png"), "PHP"));
    model->appendRow(new QStandardItem(QIcon(DATA_PATH + "js.png"), "JavaScript"));

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


void task2::on_btnChangeTxt_clicked()
{
//   if(ui->listView->item)selected
}

