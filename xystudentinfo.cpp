#include "xystudentinfo.h"

XYStudentInfo::XYStudentInfo(const QString &name,
                           const QString &sex,
                           const QString &id,
                           const QString &unit,
                           const QString &idcard,
                           const QString &phoneNumber,
                           QObject *parent)
    :XYStudentInfo(parent)
{
    msName = name;
    msSex = sex;
    msID = id;
    msUnit = unit;
    msIDCard = idcard;
    msPhoneNumber = phoneNumber;
}

XYStudentInfo::XYStudentInfo(QObject *parent)
    :QObject(parent)
{

}

QString XYStudentInfo::getMsName() const
{
    return msName;
}

void XYStudentInfo::setMsName(const QString &value)
{
    msName = value;
    emit propertyChanged();
}
QString XYStudentInfo::getMsIDCard() const
{
    return msIDCard;
}

void XYStudentInfo::setMsIDCard(const QString &value)
{
    msIDCard = value;
    emit propertyChanged();
}
QString XYStudentInfo::getMsID() const
{
    return msID;
}

void XYStudentInfo::setMsID(const QString &value)
{
    msID = value;
    emit propertyChanged();
}
QString XYStudentInfo::getMsSex() const
{
    return msSex;
}

void XYStudentInfo::setMsSex(const QString &value)
{
    msSex = value;
    emit propertyChanged();
}
QString XYStudentInfo::getMsPhoneNumber() const
{
    return msPhoneNumber;
}

void XYStudentInfo::setMsPhoneNumber(const QString &value)
{
    msPhoneNumber = value;
    emit propertyChanged();
}
QString XYStudentInfo::getMsUnit() const
{
    return msUnit;
}

void XYStudentInfo::setMsUnit(const QString &value)
{
    msUnit = value;
    emit propertyChanged();
}







