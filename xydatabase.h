#ifndef XYDATABASE_H
#define XYDATABASE_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>

class XYDataBase : public QObject
{
public:
    XYDataBase(const QString &type, QString name = QString(), QObject *parent = NULL);
    ~XYDataBase();

    QString getMsDataBaseType() const;
    void setMsDataBaseType(const QString &value);

    QString getMsDataBaseName() const;
    void setMsDataBaseName(const QString &value);

    QString getMsUserName() const;
    void setMsUserName(const QString &value);

    QString getMsPassword() const;
    void setMsPassword(const QString &value);

    QString getMsHostName() const;
    void setMsHostName(const QString &value);

    int getMiPort() const;
    void setMiPort(int value);

public:
    bool connectDatabase();
    void openDataBaseFile(const QString &name);
    bool query(const QString &squery, QSqlQuery &qquery);

protected:
    bool    mbValid;
    QString msDataBaseType;
    QString msDataBaseName;
    QString msConnectionName;
    QString msUserName;
    QString msPassword;
    QString msHostName;
    int     miPort;

    QSqlQuery *mopQuery;

    static QStringList mlstConnectDatabase;
};

#endif // XYDATABASE_H
