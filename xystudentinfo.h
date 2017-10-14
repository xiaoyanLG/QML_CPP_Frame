#ifndef XYSTUDENTINFO_H
#define XYSTUDENTINFO_H

#include <QObject>

class XYStudentInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString msName READ getMsName WRITE setMsName NOTIFY propertyChanged)
    Q_PROPERTY (QString msIDCard READ getMsIDCard WRITE setMsIDCard NOTIFY propertyChanged)
    Q_PROPERTY (QString msID READ getMsID WRITE setMsID NOTIFY propertyChanged)
    Q_PROPERTY (QString msSex READ getMsSex WRITE setMsSex NOTIFY propertyChanged)
    Q_PROPERTY (QString msPhoneNumber READ getMsPhoneNumber WRITE setMsPhoneNumber NOTIFY propertyChanged)
    Q_PROPERTY (QString msUnit READ getMsUnit WRITE setMsUnit NOTIFY propertyChanged)
public:
    XYStudentInfo(const QString &name,
                 const QString &sex,
                 const QString &id,
                 const QString &unit,
                 const QString &idcard,
                 const QString &phoneNumber,
                 QObject *parent = 0);
    XYStudentInfo(QObject *parent = 0);
    QString getMsName() const;
    void setMsName(const QString &value);

    QString getMsIDCard() const;
    void setMsIDCard(const QString &value);

    QString getMsID() const;
    void setMsID(const QString &value);

    QString getMsSex() const;
    void setMsSex(const QString &value);

    QString getMsPhoneNumber() const;
    void setMsPhoneNumber(const QString &value);

    QString getMsUnit() const;
    void setMsUnit(const QString &value);

signals:
    void propertyChanged();

public:
    QString msName;
    QString msIDCard;
    QString msID;
    QString msSex;
    QString msPhoneNumber;
    QString msUnit;
};

#endif // XYSTUDENTINFO_H
