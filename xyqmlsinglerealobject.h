#ifndef XYQMLSINGLEREALOBJECT_H
#define XYQMLSINGLEREALOBJECT_H

#include <QObject>
#include <QStringList>
#include <QMap>

class XYQmlSingleRealObject : public QObject
{
    Q_OBJECT
signals:
    void emitPropertyChanged();
    void StudentModelChanged();
    void CourseModelChanged();
    void ServeModelChanged();

public:
    XYQmlSingleRealObject(QObject *parent = 0);
    static XYQmlSingleRealObject *getInstance();

    static XYQmlSingleRealObject *mopInstance;

    static QString getString(int index);

    QWidget *mopMainWindow;
    QStringList printerList;
    QStringList moduleList;
    QStringList certificateTemplateModel;
    friend class CQmlSingleObject;
    QMap<QString, QString> modeleInfo;
    QList<QObject *>  mlstStudentInfos;
    QList<QObject *>  mlstCourseInfos;
    QList<QObject *>  mlstServeInfos;
    QList<QImage *>     mlstImages;
};

#endif // XYQMLSINGLEREALOBJECT_H
