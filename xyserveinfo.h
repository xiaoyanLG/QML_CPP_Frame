#ifndef XYSERVEINFO_H
#define XYSERVEINFO_H

#include <QObject>

class XYServeInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString msTheme READ getMsTheme WRITE setMsTheme NOTIFY propertyChanged)
    Q_PROPERTY (QString msDateTime READ getMsDateTime WRITE setMsDateTime NOTIFY propertyChanged)
    Q_PROPERTY (QString msPlace READ getMsPlace WRITE setMsPlace NOTIFY propertyChanged)
    Q_PROPERTY (QString msDutyer READ getMsDutyer WRITE setMsDutyer NOTIFY propertyChanged)
    Q_PROPERTY (QString msTimes READ getMsTimes WRITE setMsTimes NOTIFY propertyChanged)
    Q_PROPERTY (QString msJoinNumber READ getMsJoinNumber WRITE setMsJoinNumber NOTIFY propertyChanged)
    Q_PROPERTY (QString msStatus READ getMsStatus WRITE setMsStatus NOTIFY propertyChanged)
public:
    XYServeInfo(const QString &theme,
               const QString &dutyer,
               const QString &dateTime,
               const QString &place,
               const QString &times,
               const QString &joinNumber,
               const QString &status,
               QObject *parent = 0);
    ~XYServeInfo();
    QString getMsTheme() const;
    void setMsTheme(const QString &value);

    QString getMsDateTime() const;
    void setMsDateTime(const QString &value);

    QString getMsPlace() const;
    void setMsPlace(const QString &value);

    QString getMsDutyer() const;
    void setMsDutyer(const QString &value);

    QString getMsTimes() const;
    void setMsTimes(const QString &value);

    QString getMsJoinNumber() const;
    void setMsJoinNumber(const QString &value);

    QString getMsStatus() const;
    void setMsStatus(const QString &value);

signals:
    void propertyChanged();

public:
    QString msTheme;
    QString msDateTime;
    QString msPlace;
    QString msDutyer;
    QString msTimes;
    QString msJoinNumber;
    QString msStatus;
};

#endif // XYSERVEINFO_H
