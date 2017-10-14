#ifndef XYQMLSINGLEOBJECT_H
#define XYQMLSINGLEOBJECT_H

#include <QObject>
#include <QtQml>

class XYQmlSingleObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QStringList printerList READ getPrinterList WRITE setPrinterList NOTIFY propertyChanged)
    Q_PROPERTY (QStringList moduleList READ getModuleList WRITE setModuleList NOTIFY propertyChanged)
    Q_PROPERTY (QStringList certificateTemplateModel READ certificateTemplateModel WRITE setCertificateTemplateModel NOTIFY propertyChanged)
public:
    XYQmlSingleObject(QObject* parent = 0);
    ~XYQmlSingleObject();

    Q_INVOKABLE QString doSomething();
    Q_INVOKABLE QString getModeleInfo(const QString &title);
    Q_INVOKABLE void addStudentInfo();
    Q_INVOKABLE void delStudentInfo(int index);

    Q_INVOKABLE void addServeInfo();
    Q_INVOKABLE void delServeInfo(int index);

    Q_INVOKABLE void addCourseInfo();
    Q_INVOKABLE void delCourseInfo(int index);

    Q_INVOKABLE void printViewer();
    Q_INVOKABLE void printCCIE();

    QStringList getPrinterList() const;
    void setPrinterList(const QStringList &value);

    QStringList getModuleList() const;
    void setModuleList(const QStringList &value);

    QStringList certificateTemplateModel() const;
    void setCertificateTemplateModel(const QStringList &value);

signals:
    void propertyChanged();
};

static QObject *qmlCallback(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    XYQmlSingleObject *example =new XYQmlSingleObject;
    return example;
}

#define QMLSINGLEOBJECT qmlRegisterSingletonType<XYQmlSingleObject>("Qt.My.qobjectSingleton", 1, 0, "MyApi", qmlCallback);;
#endif // XYQMLSINGLEOBJECT_H
