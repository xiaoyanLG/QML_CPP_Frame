#include "xycourseinfo.h"

XYCourseInfo::XYCourseInfo(const QString &theme,
                         const QString &teacher,
                         const QString &startTimer,
                         const QString &place,
                         const QString &times,
                         const QString &joinNumber,
                         const QString &status,
                         QObject *parent)
    :QObject(parent)
{
    msTheme = theme;
    msTeacher = teacher;
    msDateTime =startTimer;
    msPlace = place;
    msTimes = times;
    msJoinNumber = joinNumber;
    msStatus = status;
}
QString XYCourseInfo::getMsTheme() const
{
    return msTheme;
}

void XYCourseInfo::setMsTheme(const QString &value)
{
    msTheme = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsDateTime() const
{
    return msDateTime;
}

void XYCourseInfo::setMsDateTime(const QString &value)
{
    msDateTime = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsTeacher() const
{
    return msTeacher;
}

void XYCourseInfo::setMsTeacher(const QString &value)
{
    msTeacher = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsTimes() const
{
    return msTimes;
}

void XYCourseInfo::setMsTimes(const QString &value)
{
    msTimes = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsJoinNumber() const
{
    return msJoinNumber;
}

void XYCourseInfo::setMsJoinNumber(const QString &value)
{
    msJoinNumber = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsStatus() const
{
    return msStatus;
}

void XYCourseInfo::setMsStatus(const QString &value)
{
    msStatus = value;
    emit propertyChanged();
}
QString XYCourseInfo::getMsPlace() const
{
    return msPlace;
}

void XYCourseInfo::setMsPlace(const QString &value)
{
    msPlace = value;
}








