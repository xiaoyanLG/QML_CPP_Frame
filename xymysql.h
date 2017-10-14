#ifndef XYMYSQL_H
#define XYMYSQL_H

#include <QObject>
#include <QSqlDatabase>

class XYMySql : public QObject
{
    Q_OBJECT
public:
    XYMySql(QObject *parent = 0);
};

#endif // XYMYSQL_H
