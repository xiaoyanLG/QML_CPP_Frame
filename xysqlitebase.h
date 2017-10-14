#ifndef XYSQLITEBASE_H
#define XYSQLITEBASE_H

#include "xydatabase.h"
#include "xystudentinfo.h"
#include "xycourseinfo.h"
#include "xyserveinfo.h"

class XYSqliteBase: public XYDataBase
{
    Q_OBJECT
public:
    XYSqliteBase(const QString &file, QObject *parent = 0);
    ~XYSqliteBase();
    bool CreateTable();
    bool DeleteTable();
    bool ClearTable();

    bool InsertStudents(const QList<XYStudentInfo *> &infos);
    bool InsertCourses(const QList<XYCourseInfo *> &infos);
    bool InsertServes(const QList<XYServeInfo *> &infos);

    bool SearchStudents(QList<XYStudentInfo *> &infos);
    bool SearchCourses(QList<XYCourseInfo *> &infos);
    bool SearchServes(QList<XYServeInfo *> &infos);

private:
    QString msDataBaseFilePath;
};

#endif // XYSQLITEBASE_H
