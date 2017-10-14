#include "xyqmlloader.h"
#include <QHBoxLayout>
#include <QQmlContext>
#include <QQuickItem>

XYQmlLoader::XYQmlLoader(const QString &sQmlFile, QWidget *parent)
    : XYQmlLoader(parent)
{
    setSource(QUrl(sQmlFile));
}

XYQmlLoader::XYQmlLoader(QWidget *parent)
    :QDialog(parent)
{
    mopQmlWnd = new QQuickWidget;
    if (parent)
    {
        mopQmlWnd->rootContext()->setContextProperty("mainWin", parent);
    }
    else
    {
        mopQmlWnd->rootContext()->setContextProperty("mainWin", this);
    }
    QHBoxLayout *main_lay = new QHBoxLayout;
    main_lay->addWidget(mopQmlWnd);
    main_lay->setContentsMargins(1,1,1,1);
    setLayout(main_lay);

    setWindowFlags(Qt::FramelessWindowHint);
}

void XYQmlLoader::centerIn(QWidget *parent)
{
    if (parent)
    {
        move(parent->pos().x() + (parent->width() - property("width").toInt()) / 2,
             parent->pos().y() + (parent->height() - property("height").toInt()) / 2);
    }
}

void XYQmlLoader::setSource(const QUrl &url)
{
    mopQmlWnd->setSource(url);
    mopQmlWnd->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

void XYQmlLoader::setParent(QWidget *parent)
{
    mopParent = parent;
}

void XYQmlLoader::setContextProperty(const QString &name, QObject *value)
{
    mopQmlWnd->rootContext()->setContextProperty(name, value);
}

void XYQmlLoader::setContextProperty(const QString &name, const QVariant &value)
{
    mopQmlWnd->rootContext()->setContextProperty(name, value);
}

bool XYQmlLoader::setProperty(const char *name, const QVariant &value)
{
    return mopQmlWnd->rootObject()->setProperty(name, value);
}

QVariant XYQmlLoader::property(const char *name)
{
    return mopQmlWnd->rootObject()->property(name);
}

