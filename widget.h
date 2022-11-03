#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "complect.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    int row;
    Ui::Widget *ui;
    QList<Complect> my_list;
private slots:
    void load();
    void save();
    void itemChanged();
    void add();
    void rem();
};
#endif // WIDGET_H
