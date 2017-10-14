#include "xysqlitebase.h"
#include "xysqliteexpression.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDriver>

XYSqliteBase::XYSqliteBase(const QString &file, QObject *parent)
    : XYDataBase("SQLITECIPHER", "", parent), msDataBaseFilePath(file)
{

}

XYSqliteBase::~XYSqliteBase()
{

}

bool XYSqliteBase::CreateTable()
{
    // 添加表
    QSqlDatabase db = QSqlDatabase::database(msConnectionName);
    if(db.driver()->hasFeature(QSqlDriver::Transactions))
    { //先判断该数据库是否支持事务操作
        if(db.transaction()) //启动事务操作
        {
            QSqlQuery query;
            if (!query.exec(createStudentTable) )
            {
                qDebug() << query.lastError().text();
            }
            if (!query.exec(createCourseTable) )
            {
                qDebug() << query.lastError().text();
            }
            if (!query.exec(createServeTable) )
            {
                 qDebug() << query.lastError().text();
            }
            if(!db.commit())
            {
                qDebug() << db.lastError(); //提交
                if(!db.rollback())
                {
                    qDebug() << db.lastError(); //回滚
                }
            }
        }
    }
    return true;
}

bool XYSqliteBase::DeleteTable()
{
    // 删除表
    QSqlDatabase db = QSqlDatabase::database(msConnectionName);
    if(db.driver()->hasFeature(QSqlDriver::Transactions))
    { //先判断该数据库是否支持事务操作
        if(db.transaction()) //启动事务操作
        {
            QSqlQuery query;
            if (!query.exec(DropStudentTable))
            {
                qDebug() << query.lastError().text();
            }
            if (!query.exec(DropCourseTable))
            {
                qDebug() << query.lastError().text();
            }
            if (!query.exec(DropServeTable))
            {
                qDebug() << query.lastError().text();
            }
            if(!db.commit())
            {
                qDebug() << db.lastError(); //提交
                if(!db.rollback())
                {
                    qDebug() << db.lastError(); //回滚
                }
            }
        }
    }
    return true;
}

bool XYSqliteBase::ClearTable()
{
    return true;
}

bool XYSqliteBase::InsertStudents(const QList<XYStudentInfo *> &infos)
{
    // 插入数据
    QSqlDatabase db = QSqlDatabase::database(msConnectionName);
    if(db.driver()->hasFeature(QSqlDriver::Transactions))
    { //先判断该数据库是否支持事务操作
        for (int i = 0; i < infos.size(); ++i)
        {
            XYStudentInfo *info = infos.at(i);
            QSqlQuery query;
            query.prepare(InsertStudent);
//            query.bindValue(":Number", info->msID.toInt());
//            query.bindValue(":Name", info->msName);
//            query.bindValue(":Sex", info->msSex);
//            query.bindValue(":Unit", info->msUnit);
//            query.bindValue(":IDCard", info->msIDCard);
//            query.bindValue(":Phonenumber", info->msPhoneNumber);
            query.bindValue(0, info->msID.toInt());
            query.bindValue(1, info->msName);
            query.bindValue(2, info->msSex);
            query.bindValue(3, info->msUnit);
            query.bindValue(4, info->msIDCard);
            query.bindValue(5, info->msPhoneNumber);
            query.exec();
        }

        if(!db.commit())
        {
            qDebug() << db.lastError(); //提交
            if(!db.rollback())
            {
                qDebug() << db.lastError(); //回滚
            }
        }
    }
    return true;
}

bool XYSqliteBase::InsertCourses(const QList<XYCourseInfo *> &infos)
{
    QSqlDatabase db = QSqlDatabase::database(msConnectionName);
    if(db.driver()->hasFeature(QSqlDriver::Transactions))
    { //先判断该数据库是否支持事务操作
        for (int i = 0; i < infos.size(); ++i)
        {
            XYCourseInfo *info = infos.at(i);
            QSqlQuery query;
            query.prepare(InsertCourse);
//            query.bindValue(":Theme", info->msTheme);
//            query.bindValue(":Teacher", info->msTeacher);
//            query.bindValue(":DateTime", info->msDateTime);
//            query.bindValue(":Place", info->msPlace);
//            query.bindValue(":DurationTime", info->msTimes);
//            query.bindValue(":Students", info->msJoinNumber.toInt());
//            query.bindValue(":Status", info->msStatus);
            query.bindValue(0, info->msTheme);
            query.bindValue(1, info->msTeacher);
            query.bindValue(2, info->msDateTime);
            query.bindValue(3, info->msPlace);
            query.bindValue(4, info->msTimes);
            query.bindValue(5, info->msJoinNumber.toInt());
            query.bindValue(6, info->msStatus);
            query.exec();
        }

        if(!db.commit())
        {
            qDebug() << db.lastError(); //提交
            if(!db.rollback())
            {
                qDebug() << db.lastError(); //回滚
            }
        }
    }
    return true;
}

bool XYSqliteBase::InsertServes(const QList<XYServeInfo *> &infos)
{
    QSqlDatabase db = QSqlDatabase::database(msConnectionName);
    if(db.driver()->hasFeature(QSqlDriver::Transactions))
    { //先判断该数据库是否支持事务操作
        for (int i = 0; i < infos.size(); ++i)
        {
            XYServeInfo *info = infos.at(i);
            QSqlQuery query;
            query.prepare(InsertServe);
//            query.bindValue(":Theme", info->msTheme);
//            query.bindValue(":DutyOfficer", info->msDutyer);
//            query.bindValue(":DateTime", info->msDateTime);
//            query.bindValue(":Place", info->msPlace);
//            query.bindValue(":DurationTime", info->msTimes);
//            query.bindValue(":Students", info->msJoinNumber.toInt());
//            query.bindValue(":Status", info->msStatus);
            query.bindValue(0, info->msTheme);
            query.bindValue(1, info->msDutyer);
            query.bindValue(2, info->msDateTime);
            query.bindValue(3, info->msPlace);
            query.bindValue(4, info->msTimes);
            query.bindValue(5, info->msJoinNumber.toInt());
            query.bindValue(6, info->msStatus);
            query.exec();
        }

        if(!db.commit())
        {
            qDebug() << db.lastError(); //提交
            if(!db.rollback())
            {
                qDebug() << db.lastError(); //回滚
            }
        }
    }
    return true;
}

bool XYSqliteBase::SearchStudents(QList<XYStudentInfo *> &infos)
{
    // 查询表数据
    QSqlQuery query;
    if (!query.exec(SearchStudent))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    else
    {
        while(query.next())
        {
            qDebug() << query.value(0).toString()
                     << query.value(1).toString()
                     << query.value(2).toString()
                     << query.value(3).toString()
                     << query.value(4).toString()
                     << query.value(5).toString();
        }
        return true;
    }
}

bool XYSqliteBase::SearchCourses(QList<XYCourseInfo *> &infos)
{
    // 查询表数据
    QSqlQuery query;
    if (!query.exec(SearchCourse))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    else
    {
        while(query.next())
        {
            qDebug() << query.value(0).toString()
                     << query.value(1).toString()
                     << query.value(2).toString()
                     << query.value(3).toString()
                     << query.value(4).toString()
                     << query.value(5).toString()
                     << query.value(6).toString();
        }
        return true;
    }
}

bool XYSqliteBase::SearchServes(QList<XYServeInfo *> &infos)
{
    // 查询表数据
    QSqlQuery query;
    if (!query.exec(SearchServe))
    {
        qDebug() << query.lastError().text();
        return false;
    }
    else
    {
        while(query.next())
        {
            qDebug() << query.value(0).toString()
                     << query.value(1).toString()
                     << query.value(2).toString()
                     << query.value(3).toString()
                     << query.value(4).toString()
                     << query.value(5).toString()
                     << query.value(6).toString();
        }
        return true;
    }
}

