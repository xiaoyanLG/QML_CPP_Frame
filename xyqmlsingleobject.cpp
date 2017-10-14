#include "xyqmlsingleobject.h"
#include "xyqmlsinglerealobject.h"
#include "xyqmlloader.h"
#include "xystudentinfo.h"
#include "xycourseinfo.h"
#include "xyserveinfo.h"
#include "xypicprinter.h"
#include <QtXml/QDomDocument>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinterInfo>

XYQmlSingleObject::XYQmlSingleObject(QObject *parent)
    : QObject(parent)
{
    connect(XYQmlSingleRealObject::getInstance(), SIGNAL(emitPropertyChanged()), this, SIGNAL(propertyChanged()));
}

XYQmlSingleObject::~XYQmlSingleObject()
{

}

QString XYQmlSingleObject::doSomething()
{
    QString fileName = "1646";
    if (fileName.isEmpty())
        return "";
    if (!fileName.endsWith(QLatin1String(".rtf")))
        fileName += QLatin1String(".rtf");

    // 上面那块代码，主要用于用户手动选择保存路径， 以及输入文件名后， 如果用户没有加上后缀，自动加上文件后缀。
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return "";
    }
    // 上面这一小段，以文本的方式，打开并读写文件。

    QDomDocument doc;  //xml，rtf 等多种文本格式生成所需要的类。
    doc.setContent(&file);
    QDomElement root = doc.documentElement();
    QDomElement body;
    if (!root.isNull()) {
        body = root.firstChildElement(QLatin1String("body"));  //如果用户保存的文件里面有内容， 查找是否是rtf格式的相关元素。
    }
    if (body.isNull()) {
        root = doc.createElement(QLatin1String("html"));
        QDomElement head = doc.createElement(QLatin1String("head"));
        QDomElement meta = doc.createElement(QLatin1String("meta"));
        meta.setAttribute(QLatin1String("http-equiv"), QLatin1String("Content-Type"));
        meta.setAttribute(QLatin1String("content"), QLatin1String("text/html; charset=utf-8"));
        //rtf格式就是一个html格式文件， 一样的结构， 需要文件头， body内容。
        head.appendChild(meta);
        root.appendChild(head);
        body = doc.createElement(QLatin1String("body"));
        root.appendChild(body);
        doc.appendChild(root);
    }
    // 上面这一小块主要写文件的文件头部内容。
    if (body.isNull())
        return "";
    QDomElement subtitleParagraph = doc.createElement(QLatin1String("p"));
    QDomText subtitleText = doc.createTextNode(tr("Subtitle:")+QLatin1String("this is a test"));
    // 上面这一小块， 通过一个普通的p标签，来实现body 的一部份。
    subtitleParagraph.appendChild(subtitleText);
    QDomElement tempLabel = doc.createElement(QLatin1String("span"));
    tempLabel.setAttribute(QLatin1String("style"), QLatin1String("color:red"));
    QDomText tempNode = doc.createTextNode(QLatin1String("  this is red"));
    tempLabel.appendChild(tempNode);
    subtitleParagraph.appendChild(tempLabel);
    // 上面这一段内容，则是在p标签后， 加入一个有文本样式的字<span>标签 ， 把里面的字符串内容变为红色。
    body.appendChild(subtitleParagraph);
    QTextStream out(&file);
    doc.save(out, 4);

    file.close();
    return doc.toString();
}

QString XYQmlSingleObject::getModeleInfo(const QString &title)
{
    return XYQmlSingleRealObject::getInstance()->modeleInfo.value(title);
}

void XYQmlSingleObject::addStudentInfo()
{
    XYQmlLoader loder("qrc:/AddStudentDialog.qml");
    loder.centerIn(XYQmlSingleRealObject::getInstance()->mopMainWindow);
    if (loder.exec() == QDialog::Accepted)
    {
        XYStudentInfo *info = new XYStudentInfo(loder.property("name").toString(),
                                              loder.property("sex").toString(),
                                              loder.property("classID").toString(),
                                              loder.property("unit").toString(),
                                              loder.property("idCard").toString(),
                                              loder.property("phoneNumber").toString());
        XYQmlSingleRealObject::getInstance()->mlstStudentInfos.append(info);
        emit XYQmlSingleRealObject::getInstance()->CourseModelChanged();
    }
}

void XYQmlSingleObject::delStudentInfo(int index)
{
    XYQmlSingleRealObject::getInstance()->mlstStudentInfos.removeAt(index);
    emit XYQmlSingleRealObject::getInstance()->StudentModelChanged();
}

void XYQmlSingleObject::addServeInfo()
{
    XYQmlLoader loder("qrc:/AddServeDialog.qml");
    loder.centerIn(XYQmlSingleRealObject::getInstance()->mopMainWindow);
    if (loder.exec() == QDialog::Accepted)
    {
        XYServeInfo *info = new XYServeInfo(loder.property("name").toString(),
                                          loder.property("dutyer").toString(),
                                          loder.property("startTime").toString(),
                                          loder.property("place").toString(),
                                          loder.property("times").toString(),
                                          loder.property("joinNumber").toString(),
                                          loder.property("status").toString());
        XYQmlSingleRealObject::getInstance()->mlstServeInfos.append(info);
        emit XYQmlSingleRealObject::getInstance()->ServeModelChanged();
    }
}

void XYQmlSingleObject::delServeInfo(int index)
{
    XYQmlSingleRealObject::getInstance()->mlstServeInfos.removeAt(index);
    emit XYQmlSingleRealObject::getInstance()->StudentModelChanged();
}

void XYQmlSingleObject::addCourseInfo()
{
    XYQmlLoader loder("qrc:/AddCourseDialog.qml");
    loder.centerIn(XYQmlSingleRealObject::getInstance()->mopMainWindow);
    if (loder.exec() == QDialog::Accepted)
    {
        XYCourseInfo *info = new XYCourseInfo(loder.property("name").toString(),
                                            loder.property("teacher").toString(),
                                            loder.property("startTime").toString(),
                                            loder.property("place").toString(),
                                            loder.property("times").toString(),
                                            loder.property("joinNumber").toString(),
                                            loder.property("status").toString());
        XYQmlSingleRealObject::getInstance()->mlstCourseInfos.append(info);
        emit XYQmlSingleRealObject::getInstance()->StudentModelChanged();
    }
}

void XYQmlSingleObject::delCourseInfo(int index)
{
    XYQmlSingleRealObject::getInstance()->mlstCourseInfos.removeAt(index);
    emit XYQmlSingleRealObject::getInstance()->StudentModelChanged();
}

void XYQmlSingleObject::printViewer()
{
    XYPicPrinter::getInstance()->mvPrintViewer();
}

void XYQmlSingleObject::printCCIE()
{
    XYPicPrinter::getInstance()->mslotPrintPic();
}

QStringList XYQmlSingleObject::getPrinterList() const
{
    XYQmlSingleRealObject::getInstance()->printerList = QPrinterInfo::availablePrinterNames();
    return XYQmlSingleRealObject::getInstance()->printerList;
}

void XYQmlSingleObject::setPrinterList(const QStringList &value)
{
    XYQmlSingleRealObject::getInstance()->printerList = value;
    emit propertyChanged();
}

QStringList XYQmlSingleObject::getModuleList() const
{
    return XYQmlSingleRealObject::getInstance()->moduleList;
}

void XYQmlSingleObject::setModuleList(const QStringList &value)
{
    XYQmlSingleRealObject::getInstance()->moduleList = value;
    emit propertyChanged();
}

QStringList XYQmlSingleObject::certificateTemplateModel() const
{
    return XYQmlSingleRealObject::getInstance()->certificateTemplateModel;
}

void XYQmlSingleObject::setCertificateTemplateModel(const QStringList &value)
{
    XYQmlSingleRealObject::getInstance()->certificateTemplateModel = value;
    emit propertyChanged();
}

