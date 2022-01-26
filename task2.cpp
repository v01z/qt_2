#include "task2.h"
#include "ui_task2.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

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

    QModelIndex indx { ui->listView->currentIndex() };
//    model->dataChanged();
    QStandardItem *itm { model->itemFromIndex(indx) };
    /*
    if (!itm)
    {
       QMessageBox::warning(this, "Smth is wrong.",
            "ListView's item should be selected.");
    }
    */

//    qDebug() << itm->text();

    bool ok { false };
    QString newStr { QInputDialog::getText(this, "Changing text.",
        "Change this text if you want:", QLineEdit::Normal, itm->text(), &ok) };
    if (ok && !newStr.isEmpty())
    {
        itm->setText(newStr);
    }


}


void task2::on_btnUp_clicked()
{

    std::pair <QIcon, QString> temp;

    QModelIndex indx { ui->listView->currentIndex() };
    QStandardItem *itm { model->itemFromIndex(indx) };

    temp.first = itm->icon();
    temp.second = itm->text();


    QModelIndex indx_prev = ui->listView->model()->index(indx.row() -1, 0);

    if (!indx_prev.isValid())
    {
        QMessageBox::warning(this, "Wrong way.",
            "There is no previous item.");
        return;
    }

    QStandardItem *itm_prev { model->itemFromIndex(indx_prev) };

    itm->setIcon (itm_prev->icon());
    itm->setText(itm_prev->text());

    itm_prev->setIcon(temp.first);
    itm_prev->setText(temp.second);

    ui->listView->setCurrentIndex(indx_prev);

}


void task2::on_btnDown_clicked()
{
    std::pair <QIcon, QString> temp;

    QModelIndex indx { ui->listView->currentIndex() };
    QStandardItem *itm { model->itemFromIndex(indx) };

    temp.first = itm->icon();
    temp.second = itm->text();


    QModelIndex indx_next = ui->listView->model()->index(indx.row() + 1, 0);

    if (!indx_next.isValid())
    {
        QMessageBox::warning(this, "Wrong way.",
            "There is no next item.");
        return;
    }

    QStandardItem *itm_next { model->itemFromIndex(indx_next) };

    itm->setIcon (itm_next->icon());
    itm->setText(itm_next->text());

    itm_next->setIcon(temp.first);
    itm_next->setText(temp.second);

    ui->listView->setCurrentIndex(indx_next);

}

