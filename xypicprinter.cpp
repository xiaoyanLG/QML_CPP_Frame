#include "xypicprinter.h"
#include "xyqmlsinglerealobject.h"
#include <QImage>
#include <QPainter>
#include <QPrinterInfo>
#include <QDebug>

XYPicPrinter *XYPicPrinter::mopInstance = NULL;
XYPicPrinter *XYPicPrinter::getInstance()
{
    if (mopInstance == NULL)
    {
        mopInstance = new XYPicPrinter;
    }
    return mopInstance;
}

XYPicPrinter::XYPicPrinter(QWidget *parent)
    :XYQmlLoader(parent)
{
    /**
         * QPrintPreviewDialog?????????????????????????œ¤???????
         * paintRequested(QPrinter *printer)?????????
         * ??preview.exec()????????????????
         * plotPic(QPrinter *printer)???????????????????????????????????????
    */
    mopPrinter = new QPrinter(QPrinter::HighResolution);
    mopPrinter->setPageSize(QPrinter::Custom);
    mopPrinter->setPageSizeMM(QSizeF(170, 125));
    mopPrinter->setPaperSize(QSizeF(170, 125), QPrinter::Millimeter);
    mopPrinter->setFullPage(true);
    mopPrintViewer = new QPrintPreviewDialog(mopPrinter, NULL);
    connect(mopPrintViewer, SIGNAL(paintRequested(QPrinter*)), this, SLOT(mslotPrintPic(QPrinter *)));

    setSource(QUrl("qrc:/ChoisePrinter.qml"));
}

XYPicPrinter::~XYPicPrinter()
{

}

void XYPicPrinter::mvPrintViewer()
{
    mopPrinter->setPageSize(QPrinter::Custom);
    mopPrinter->setPageSizeMM(QSizeF(170, 125));
    mopPrinter->setPaperSize(QSizeF(170, 125), QPrinter::Millimeter);
    mopPrinter->setFullPage(true);
    mopPrintViewer->exec(); /* ????????????? */
}

QString XYPicPrinter::msGetChoisePrinter()
{
    return msChoisePrinter;
}

void XYPicPrinter::mslotPrintPic()
{
    centerIn(mopParent);
    if (exec() == QDialog::Accepted)
    {
        mopPrinter->setPrinterName(msChoisePrinter);
        mopPrinter->setPageSize(QPrinter::Custom);
        mopPrinter->setPageSizeMM(QSizeF(170, 125));
        mopPrinter->setPaperSize(QSizeF(170, 125), QPrinter::Millimeter);
        mopPrinter->setFullPage(true);
        mslotPrintPic(mopPrinter);
    }
}

void XYPicPrinter::mslotPrintPic(QPrinter *printer)
{
    QPainter painter(printer);
    QImage image(":/tem/1.png");

    QRect rect = painter.viewport();
    QSize size = image.size();
    size.scale(rect.size(), Qt::KeepAspectRatio);//???????????????
    painter.setViewport(rect.x(), rect.y(),size.width(), size.height());
    painter.setWindow(image.rect());

    for (int i = 0; i < 13; ++i)
    {
        QImage *image = XYQmlSingleRealObject::getInstance()->mlstImages.at(i);
        painter.drawImage(1, 0, *image);
        DrawTextOnImage(painter, i + 1);
        if (i < 12)
        {
            mopPrinter->newPage();
        }
    }
}

void XYPicPrinter::mslotSetChoisePrinter(const QString &printer)
{
    msChoisePrinter = printer;
}

void XYPicPrinter::DrawTextOnImage(QPainter &painter, int page)
{
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    QPen pen = painter.pen();
    painter.setPen(pen);

    QFont font = painter.font();
//    font.setBold(true);//???
    font.setPixelSize(20);//?????????§³
    painter.setFont(font);

    switch (page)
    {
    case 1:
    {
        int x0 = 850;
        int y0 = 630;
        painter.drawText(x0, y0, QString("123456789%1").arg(page));
        break;
    }
    case 2:
    {
        int x0 = 250;
        int y0 = 520;
        int x1 = x0 + 570;
        int y1 = 260;
        painter.drawText(x0, y0, QString("????: %1").arg(page));
        painter.drawText(x0, y0 + 95, QString("????: %1").arg(page));
        painter.drawText(x0, y0 + 185, QString("??: %1").arg(page));

        painter.drawText(x1, y1, QString("12345?????543211: %1").arg(page));
        painter.drawText(x1, y1 + 90, QString("12345??????543211: %1").arg(page));

        painter.drawText(x1 + 40, y1 + 200, QString("%1").arg(1991));
        painter.drawText(x1 + 130, y1 + 200, QString("%1").arg(11));
        painter.drawText(x1 + 210, y1 + 200, QString("%1").arg(22));
        break;
    }
    case 3:
    case 4:
    case 5:
    case 6:
    {
        int x0 = 260;
        int y0 = 0;
        int x1 = x0 + 600;
        int y1 = y0 + 330;

        painter.drawText(x0, 215, QString("??????: %1").arg(page));
        painter.drawText(x0, 260, QString("??????: %1").arg(page));
        painter.drawText(x0, 300, QString("??????: %1").arg(page));
        painter.drawText(x0, 345, QString("??????: %1").arg(page));
        painter.drawText(x0, 390, QString("??????: %1").arg(page));
        painter.drawText(x0, 435, QString("??????: %1").arg(page));

        painter.drawText(x1, 215, QString("??????: %1").arg(page));
        painter.drawText(x1, 260, QString("??????: %1").arg(page));
        painter.drawText(x1, 300, QString("??????: %1").arg(page));
        painter.drawText(x1, 345, QString("??????: %1").arg(page));
        painter.drawText(x1, 390, QString("??????: %1").arg(page));
        painter.drawText(x1, 435, QString("??????: %1").arg(page));

        painter.drawText(x0, 215 + y1, QString("??????: %1").arg(page));
        painter.drawText(x0, 260 + y1, QString("??????: %1").arg(page));
        painter.drawText(x0, 300 + y1, QString("??????: %1").arg(page));
        painter.drawText(x0, 345 + y1, QString("??????: %1").arg(page));
        painter.drawText(x0, 390 + y1, QString("??????: %1").arg(page));
        painter.drawText(x0, 435 + y1, QString("??????: %1").arg(page));

        painter.drawText(x1, 215 + y1, QString("??????: %1").arg(page));
        painter.drawText(x1, 260 + y1, QString("??????: %1").arg(page));
        painter.drawText(x1, 300 + y1, QString("??????: %1").arg(page));
        painter.drawText(x1, 345 + y1, QString("??????: %1").arg(page));
        painter.drawText(x1, 390 + y1, QString("??????: %1").arg(page));
        painter.drawText(x1, 435 + y1, QString("??????: %1").arg(page));
        break;
    }
    case 7:
    case 8:
    case 9:
    {
        int x0 = 260;
        int y0 = 0;
        int x1 = x0 + 600;
        int y1 = y0 + 330;

        painter.drawText(x0, 215, QString("???????: %1").arg(page));
        painter.drawText(x0, 260, QString("???????: %1").arg(page));
        painter.drawText(x0, 300, QString("???????: %1").arg(page));
        painter.drawText(x0, 345, QString("???????: %1").arg(page));
        painter.drawText(x0, 390, QString("???????: %1").arg(page));
        painter.drawText(x0, 435, QString("???????: %1").arg(page));

        painter.drawText(x1, 215, QString("???????: %1").arg(page));
        painter.drawText(x1, 260, QString("???????: %1").arg(page));
        painter.drawText(x1, 300, QString("???????: %1").arg(page));
        painter.drawText(x1, 345, QString("???????: %1").arg(page));
        painter.drawText(x1, 390, QString("???????: %1").arg(page));
        painter.drawText(x1, 435, QString("???????: %1").arg(page));

        painter.drawText(x0, 215 + y1, QString("???????: %1").arg(page));
        painter.drawText(x0, 260 + y1, QString("???????: %1").arg(page));
        painter.drawText(x0, 300 + y1, QString("???????: %1").arg(page));
        painter.drawText(x0, 345 + y1, QString("???????: %1").arg(page));
        painter.drawText(x0, 390 + y1, QString("???????: %1").arg(page));
        painter.drawText(x0, 435 + y1, QString("???????: %1").arg(page));

        painter.drawText(x1, 215 + y1, QString("???????: %1").arg(page));
        painter.drawText(x1, 260 + y1, QString("???????: %1").arg(page));
        painter.drawText(x1, 300 + y1, QString("???????: %1").arg(page));
        painter.drawText(x1, 345 + y1, QString("???????: %1").arg(page));
        painter.drawText(x1, 390 + y1, QString("???????: %1").arg(page));
        painter.drawText(x1, 435 + y1, QString("???????: %1").arg(page));
        break;
    }
    case 10:
    {
        int x0 = 175;
        int y0 = 415;
        int x1 = x0 + 578;
        int y1 = y0 + 238;
        painter.drawText(x0, y0, QString("%1").arg(1991));
        painter.drawText(x0 + 60, y0, QString("%1").arg(11));
        painter.drawText(x0 + 100, y0, QString("%1").arg(11));
        painter.drawText(x0 + 145, y0, QString("%1").arg(1992));
        painter.drawText(x0 + 200, y0, QString("%1").arg(12));
        painter.drawText(x0 + 238, y0, QString("%1").arg(22));

        painter.drawText(x1, y0, QString("%1").arg(1991));
        painter.drawText(x1 + 60, y0, QString("%1").arg(11));
        painter.drawText(x1 + 100, y0, QString("%1").arg(11));
        painter.drawText(x1 + 145, y0, QString("%1").arg(1992));
        painter.drawText(x1 + 200, y0, QString("%1").arg(12));
        painter.drawText(x1 + 238, y0, QString("%1").arg(22));

        painter.drawText(x0, y1, QString("%1").arg(1991));
        painter.drawText(x0 + 60, y1, QString("%1").arg(11));
        painter.drawText(x0 + 100, y1, QString("%1").arg(11));
        painter.drawText(x0 + 145, y1, QString("%1").arg(1992));
        painter.drawText(x0 + 200, y1, QString("%1").arg(12));
        painter.drawText(x0 + 238, y1, QString("%1").arg(22));

        painter.drawText(x1, y1, QString("%1").arg(1991));
        painter.drawText(x1 + 60, y1, QString("%1").arg(11));
        painter.drawText(x1 + 100, y1, QString("%1").arg(11));
        painter.drawText(x1 + 145, y1, QString("%1").arg(1992));
        painter.drawText(x1 + 200, y1, QString("%1").arg(12));
        painter.drawText(x1 + 238, y1, QString("%1").arg(22));
        break;
    }
    case 11:
    {
        int x0 = 160;
        int y0 = 417;
        int x1 = x0 + 578;
        int y1 = y0 + 240;
        painter.drawText(x0 + 5, y0, QString("%1").arg(1991));
        painter.drawText(x0 + 60, y0, QString("%1").arg(11));
        painter.drawText(x0 + 100, y0, QString("%1").arg(11));
        painter.drawText(x0 + 145, y0, QString("%1").arg(1992));
        painter.drawText(x0 + 200, y0, QString("%1").arg(12));
        painter.drawText(x0 + 238, y0, QString("%1").arg(22));

        painter.drawText(x1 + 5, y0, QString("%1").arg(1991));
        painter.drawText(x1 + 60, y0, QString("%1").arg(11));
        painter.drawText(x1 + 100, y0, QString("%1").arg(11));
        painter.drawText(x1 + 145, y0, QString("%1").arg(1992));
        painter.drawText(x1 + 200, y0, QString("%1").arg(12));
        painter.drawText(x1 + 238, y0, QString("%1").arg(22));

        painter.drawText(x0 + 5, y1, QString("%1").arg(1991));
        painter.drawText(x0 + 60, y1, QString("%1").arg(11));
        painter.drawText(x0 + 100, y1, QString("%1").arg(11));
        painter.drawText(x0 + 145, y1, QString("%1").arg(1992));
        painter.drawText(x0 + 200, y1, QString("%1").arg(12));
        painter.drawText(x0 + 238, y1, QString("%1").arg(22));

        painter.drawText(x1 + 5, y1, QString("%1").arg(1991));
        painter.drawText(x1 + 60, y1, QString("%1").arg(11));
        painter.drawText(x1 + 100, y1, QString("%1").arg(11));
        painter.drawText(x1 + 145, y1, QString("%1").arg(1992));
        painter.drawText(x1 + 200, y1, QString("%1").arg(12));
        painter.drawText(x1 + 238, y1, QString("%1").arg(22));
        break;
    }
    case 12:
    {
        int x0 = 900;
        int y0 = 580;
        painter.drawText(x0, y0, QString("%1?????").arg(111111111111));
        break;
    }
    case 13:
    {
        int x0 = 220;
        int y0 = 335;
        int y1 = y0 + 235;
        painter.drawText(x0, y0, QString("123456789%1").arg(page));
        painter.drawText(x0, y0 + 43, QString("1231565@163.com%1").arg(page));
        painter.drawText(x0, y0 + 86, QString("?????%1").arg(page));
        painter.drawText(x0, y0 + 129, QString("402522%1").arg(page));


        painter.drawText(x0, y1 + 43, QString("www.baidu.com%1").arg(page));
        painter.drawText(x0, y1 + 86, QString("????%1").arg(page));
        painter.drawText(x0, y1 + 129, QString("????%1").arg(page));
        break;
    }
    default:
        break;
    }
}

