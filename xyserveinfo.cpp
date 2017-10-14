#include "xyserveinfo.h"

XYServeInfo::XYServeInfo(const QString &theme,
                       const QString &dutyer,
                       const QString &dateTime,
                       const QString &place,
                       const QString &times,
                       const QString &joinNumber,
                       const QString &status,
                       QObject *parent) : QObject(parent)
{
    msTheme = theme;
    msDutyer = dutyer;
    msDateTime =dateTime;
    msPlace = place;
    msTimes = times;
    msJoinNumber = joinNumber;
    msStatus = status;
}

XYServeInfo::~XYServeInfo()
{

}
QString XYServeInfo::getMsTheme() const
{
    return msTheme;
}

void XYServeInfo::setMsTheme(const QString &value)
{
    msTheme = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsDateTime() const
{
    return msDateTime;
}

void XYServeInfo::setMsDateTime(const QString &value)
{
    msDateTime = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsPlace() const
{
    return msPlace;
}

void XYServeInfo::setMsPlace(const QString &value)
{
    msPlace = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsDutyer() const
{
    return msDutyer;
}

void XYServeInfo::setMsDutyer(const QString &value)
{
    msDutyer = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsTimes() const
{
    return msTimes;
}

void XYServeInfo::setMsTimes(const QString &value)
{
    msTimes = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsJoinNumber() const
{
    return msJoinNumber;
}

void XYServeInfo::setMsJoinNumber(const QString &value)
{
    msJoinNumber = value;
    emit propertyChanged();
}
QString XYServeInfo::getMsStatus() const
{
    return msStatus;
}

void XYServeInfo::setMsStatus(const QString &value)
{
    msStatus = value;
    emit propertyChanged();
}








