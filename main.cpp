#include "mainwindow.h"
#include <QApplication>
#include "xyqmlsingleobject.h"
#include "xydatabase.h"

int main(int argc, char *argv[])
{
    QMLSINGLEOBJECT
    QApplication a(argc, argv);

//    CDataBase *mybase = new CDataBase("QSQLITE");
//    mybase->openDataBaseFile("test.db");
//    if (mybase->connectDatabase())
//    {
//        QSqlQuery query;
//        if (mybase->query("CREATE TABLE COMPANY( \
//                          ID INT PRIMARY KEY     NOT NULL, \
//                          NAME           TEXT    NOT NULL, \
//                          AGE            INT     NOT NULL, \
//                          ADDRESS        CHAR(50), \
//                          SALARY         REAL \
//                       );", query))
//        {
//            qDebug()<< "exec successful!";
//            while (query.next())
//            {
//                qDebug()<<query.value(0).toString();
//            }
//        }
//        else
//        {
//            qDebug()<<query.lastError().text();
//        }
//    }
//    else
//    {
//        qDebug()<< "connect failed!";
//    }
    MainWindow w;
    w.show();

    return a.exec();
}
