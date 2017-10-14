#ifndef XYPICPRINTER_H
#define XYPICPRINTER_H
#include "xyqmlloader.h"
#include <QPrinter>
#include <QPrintPreviewDialog>

class XYPicPrinter : public XYQmlLoader
{
    Q_OBJECT
public:
    static XYPicPrinter *getInstance();
    XYPicPrinter(QWidget *parent = NULL);
    ~XYPicPrinter();
    void mvPrintViewer();
    QString msGetChoisePrinter();

public slots:
    void mslotPrintPic();
    void mslotPrintPic(QPrinter *printer);
    void mslotSetChoisePrinter(const QString &printer);

private:
    void DrawTextOnImage(QPainter &painter, int page);

private:
    static XYPicPrinter  *mopInstance;
    QPrinter            *mopPrinter;
    QPrintPreviewDialog *mopPrintViewer;
    QString              msChoisePrinter;
};

#endif // XYPICPRINTER_H
