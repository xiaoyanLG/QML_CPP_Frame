#ifndef XYQMLLOADER_H
#define XYQMLLOADER_H

#include <QDialog>
#include <QQuickWidget>

class XYQmlLoader : public QDialog
{
    Q_OBJECT
public:
    XYQmlLoader(const QString &sQmlFile, QWidget *parent = 0);
    XYQmlLoader(QWidget *parent = 0);
    void centerIn(QWidget *parent);
    void setSource(const QUrl & url);
    void setParent(QWidget *parent);
    void setContextProperty(const QString & name, QObject * value);
    void setContextProperty(const QString & name, const QVariant & value);
    bool setProperty(const char * name, const QVariant & value);
    QVariant property(const char * name);

protected:
    QWidget *mopParent;

private:
    QQuickWidget *mopQmlWnd;

};

#endif // XYQMLLOADER_H
