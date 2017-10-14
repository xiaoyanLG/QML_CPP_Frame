#include "mainwindow.h"
#include "xyqmlsinglerealobject.h"
#include "xypicprinter.h"
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    mopQmlMainWnd = new XYQmlLoader(this);
    connect(XYQmlSingleRealObject::getInstance(), SIGNAL(StudentModelChanged()), this, SLOT(refreshStudentModel()));
    connect(XYQmlSingleRealObject::getInstance(), SIGNAL(CourseModelChanged()), this, SLOT(refreshCourseModel()));
    connect(XYQmlSingleRealObject::getInstance(), SIGNAL(ServeModelChanged()), this, SLOT(refreshServeModel()));
    refreshModel();
    mopQmlMainWnd->setSource(QUrl("qrc:/qmlMainWin.qml"));
    setCentralWidget(mopQmlMainWnd);
    XYQmlSingleRealObject::getInstance()->mopMainWindow = this;
    XYPicPrinter::getInstance()->setParent(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::refreshModel()
{
    refreshStudentModel();
    refreshCourseModel();
    refreshServeModel();
}

void MainWindow::refreshStudentModel()
{
    mopQmlMainWnd->setContextProperty("studentModel",
                                      QVariant::fromValue(XYQmlSingleRealObject::getInstance()->mlstStudentInfos));
}

void MainWindow::refreshCourseModel()
{
    mopQmlMainWnd->setContextProperty("courseModel",
                                      QVariant::fromValue(XYQmlSingleRealObject::getInstance()->mlstCourseInfos));
}

void MainWindow::refreshServeModel()
{
    mopQmlMainWnd->setContextProperty("ServeModel",
                                      QVariant::fromValue(XYQmlSingleRealObject::getInstance()->mlstServeInfos));
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen = painter.pen();
    pen.setColor("#cccccc");
    painter.setPen(pen);
    painter.drawRect(0, 0, size().width() - 1, size().height() - 1);
    QMainWindow::paintEvent(event);
}
