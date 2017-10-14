#include "xydatabase.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

QStringList XYDataBase::mlstConnectDatabase;
XYDataBase::XYDataBase(const QString &type, QString name, QObject *parent)
    : QObject(parent),msDataBaseType(type),msConnectionName(name), mopQuery(NULL)
{
    mbValid = false;
    msDataBaseName.clear();
    msHostName = "localhost";
    msUserName = "root";
    msPassword = "root";
    miPort = 0;
}

XYDataBase::~XYDataBase()
{
    mlstConnectDatabase.removeAll(msConnectionName);
    if (mopQuery != NULL)
    {
        delete mopQuery;
    }
}

bool XYDataBase::connectDatabase()
{
    QString connectionname = msConnectionName;
    if (connectionname.isEmpty())
    {
        int i_begin = mlstConnectDatabase.size();
        while (1)
        {
            connectionname = QString("DataBase%1").arg(i_begin + 1);
            if (!mlstConnectDatabase.contains(connectionname))
            {
                break;
            }
            i_begin++;
        }
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(msDataBaseType, connectionname);
    db.setHostName(msHostName);
    db.setUserName(msUserName);
    db.setPassword(msPassword);
    if (miPort != 0)
    {
        db.setPort(miPort);
    }
    if (!msDataBaseName.isEmpty())
    {
        db.setDatabaseName(msDataBaseName);
    }
    mbValid = db.open();
    if (mbValid)
    {
        mopQuery = new QSqlQuery(db);
        msConnectionName = connectionname;
        mlstConnectDatabase.append(msConnectionName);
    }
    return mbValid;
}

void XYDataBase::openDataBaseFile(const QString &name)
{
    msDataBaseName = name;
}

bool XYDataBase::query(const QString &squery, QSqlQuery &qquery)
{
    if (mopQuery == NULL || !mbValid)
    {
        return false;
    }
    if (mopQuery->exec(squery))
    {
        qquery = *mopQuery;
        return true;
    }
    else
    {
        qquery = *mopQuery;
        return false;
    }
}
int XYDataBase::getMiPort() const
{
    return miPort;
}

void XYDataBase::setMiPort(int value)
{
    miPort = value;
}

QString XYDataBase::getMsHostName() const
{
    return msHostName;
}

void XYDataBase::setMsHostName(const QString &value)
{
    msHostName = value;
}

QString XYDataBase::getMsPassword() const
{
    return msPassword;
}

void XYDataBase::setMsPassword(const QString &value)
{
    msPassword = value;
}

QString XYDataBase::getMsUserName() const
{
    return msUserName;
}

void XYDataBase::setMsUserName(const QString &value)
{
    msUserName = value;
}

QString XYDataBase::getMsDataBaseName() const
{
    return msConnectionName;
}

void XYDataBase::setMsDataBaseName(const QString &value)
{
    msConnectionName = value;
}

QString XYDataBase::getMsDataBaseType() const
{
    return msDataBaseType;
}

void XYDataBase::setMsDataBaseType(const QString &value)
{
    msDataBaseType = value;
}


