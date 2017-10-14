#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <xyqmlloader.h>
#include <QPaintEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refreshModel();

public slots:
    void refreshStudentModel();
    void refreshCourseModel();
    void refreshServeModel();

protected:
    void paintEvent(QPaintEvent * event);

private:
    XYQmlLoader *mopQmlMainWnd;

    QList<QObject *> studentModel;
    QList<QObject *> courseModel;
};

#endif // MAINWINDOW_H
