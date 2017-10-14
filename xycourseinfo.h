#ifndef XYCOURSEINFO_H
#define XYCOURSEINFO_H

#include <QObject>

class XYCourseInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString msTheme READ getMsTheme WRITE setMsTheme NOTIFY propertyChanged)
    Q_PROPERTY (QString msDateTime READ getMsDateTime WRITE setMsDateTime NOTIFY propertyChanged)
    Q_PROPERTY (QString msPlace READ getMsPlace WRITE setMsPlace NOTIFY propertyChanged)
    Q_PROPERTY (QString msTeacher READ getMsTeacher WRITE setMsTeacher NOTIFY propertyChanged)
    Q_PROPERTY (QString msTimes READ getMsTimes WRITE setMsTimes NOTIFY propertyChanged)
    Q_PROPERTY (QString msJoinNumber READ getMsJoinNumber WRITE setMsJoinNumber NOTIFY propertyChanged)
    Q_PROPERTY (QString msStatus READ getMsStatus WRITE setMsStatus NOTIFY propertyChanged)
public:
    XYCourseInfo(const QString &theme,
                const QString &teacher,
                const QString &dateTime,
                const QString &place,
                const QString &times,
                const QString &joinNumber,
                const QString &status,
                QObject *parent = 0);

    QString getMsTheme() const;
    void setMsTheme(const QString &value);

    QString getMsDateTime() const;
    void setMsDateTime(const QString &value);

    QString getMsTeacher() const;
    void setMsTeacher(const QString &value);

    QString getMsTimes() const;
    void setMsTimes(const QString &value);

    QString getMsJoinNumber() const;
    void setMsJoinNumber(const QString &value);

    QString getMsStatus() const;
    void setMsStatus(const QString &value);

    QString getMsPlace() const;
    void setMsPlace(const QString &value);

signals:
    void propertyChanged();

public:
    QString msTheme;
    QString msDateTime;
    QString msPlace;
    QString msTeacher;
    QString msTimes;
    QString msJoinNumber;
    QString msStatus;
};

#endif // XYCOURSEINFO_H
