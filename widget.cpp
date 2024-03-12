#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    changeEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEnabled()
{
    // ui->pbCoffee->setEnabled(false);
    // ui->pbTea->setEnabled(false);
    // ui->pbTang->setEnabled(false);

    // if(money >= 300){
    //     ui->pbCoffee->setEnabled(true);
    //     ui->pbTea->setEnabled(true);
    //     ui->pbTang->setEnabled(true);
    // }
    // else if (money >= 150){
    //     ui->pbCoffee->setEnabled(true);
    //     ui->pbTea->setEnabled(true);
    // }
    // else if (money >= 100){
    //     ui->pbCoffee->setEnabled(true);
    // }

    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbTang->setEnabled(money >= 300);
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    changeEnabled();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);

}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString message;
    int arrCnt[4];
    int arr[4] = {10, 50, 100, 500};

    for (int i = 3; i >= 0; i--){
        arrCnt[i] = money/arr[i];
        money %= arr[i];

        if(arrCnt[i]){
            message = message + QString::number(arr[i]) + " : " + QString::number(arrCnt[i]) + "\n";
        }
    }

    mb.information(nullptr, "reset", message);
}

