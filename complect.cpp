#include <QString>

struct Complect
{
    QString town;
    QString fio;
    QString department;
    QString doctor;
    Complect(QString t, QString f, QString dep, QString doc):
        town(t), fio(f), department(dep), doctor(doc)
    {}
};
