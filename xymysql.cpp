#include "xymysql.h"
#include <QMessageBox>

XYMySql::XYMySql(QObject *parent) : QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mytest");
    db.setUserName("root");
    db.setPassword("root");
    if (db.open())
    {
        QMessageBox::warning(NULL, tr("Error"), tr("Open DataBase failed!"));
    }
}
