#include "widget.h"
#include "ui_widget.h"
#include <QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(rem()));
    connect(ui->redact, SIGNAL(clicked()), this, SLOT(itemChanged()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(load()));
    row = 1;

}


Widget::~Widget()
{
    delete ui;
}

void Widget::load()
{
    QFile file("text.txt");
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "file not open";
    QTextStream stream(&file);
    qDebug() << stream.readAll();
    file.close();
}

void Widget::save()
{
    QFile file("text.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Error";
    }
    QTextStream stream(&file);
    for (int i = 0; i < my_list.size(); i++)
    {
        stream << my_list[i].town << ' ';
        stream << my_list[i].fio << ' ';
        stream << my_list[i].department << ' ';
        stream << my_list[i].doctor << ' ';
    }
    for (int i = 0; i < my_list.size(); i++)
        qDebug() << my_list[i].town << my_list[i].department << my_list[i].doctor << my_list[i].fio;
}

void Widget::itemChanged()
{
    for (int i = 0; i < my_list.size(); i++)
        if (my_list[i].town == ui->redactTown->toPlainText())
        {
        Complect a =
        Complect(ui->redactTown->toPlainText(), ui->redactFIO->toPlainText(), ui->redactDepaprtment->toPlainText(), ui->redactDoctor->toPlainText());
        my_list[i] = a;
        }

}

void Widget::add()
{
my_list.push_back(Complect(ui->townAdd->toPlainText(), ui->FIOAdd->toPlainText(), ui->departmentAdd->toPlainText(), ui->doctorAdd->toPlainText()));
QTableWidgetItem *item1, *item2, *item3, *item4;
item1 = new QTableWidgetItem(my_list.back().town);
item2 = new QTableWidgetItem(my_list.back().fio);
item3 = new QTableWidgetItem(my_list.back().department);
item4 = new QTableWidgetItem(my_list.back().doctor);
ui->tableWidget->setItem(row, 0, item1);
ui->tableWidget->setItem(row, 1, item2);
ui->tableWidget->setItem(row, 2, item3);
ui->tableWidget->setItem(row, 3, item4);
row++;

}

void Widget::rem()
{
    for (int i = 0; i  < my_list.size(); i++)
    {
        if (my_list[i].town == ui->deleteTown->toPlainText())
            my_list.removeAt(i);
    }
}

