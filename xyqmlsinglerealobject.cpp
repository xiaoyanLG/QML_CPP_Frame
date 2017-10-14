#include "xyqmlsinglerealobject.h"
#include "xystudentinfo.h"
#include <QtXml/QDomDocument>
#include <QTextStream>
#include <QFileDialog>
#include <QImage>

XYQmlSingleRealObject *XYQmlSingleRealObject::mopInstance = 0;

XYQmlSingleRealObject::XYQmlSingleRealObject(QObject *parent) : QObject(parent)
{
    moduleList.append(QStringLiteral("人员信息"));
    moduleList.append(QStringLiteral("培训信息"));
    moduleList.append(QStringLiteral("服务信息"));
    moduleList.append(QStringLiteral("查询信息"));
    moduleList.append(QStringLiteral("信息统计"));
    moduleList.append(QStringLiteral("活动报名"));
    moduleList.append(QStringLiteral("活动签到"));
    moduleList.append(QStringLiteral("打印证书"));

    for (int i = 0; i < moduleList.size(); ++i)
    {
        switch (i) {
        case 0:
            modeleInfo.insert(moduleList.at(i), "StudentInfo.qml");
            break;
        case 1:
            modeleInfo.insert(moduleList.at(i), "CourseInfo.qml");
            break;
        case 2:
            modeleInfo.insert(moduleList.at(i), "ServeInfo.qml");
            break;
        case 7:
            modeleInfo.insert(moduleList.at(i), "PrintPage.qml");
            break;
        default:
            modeleInfo.insert(moduleList.at(i), "DefaultInfo.qml");
            break;
        }
    }
    // 在这里从数据库获取信息初始化model数据
    for (int i = 0; i < 13; ++i )
    {
        QString s_image = QString("tem/%1.png").arg(i + 1);
        certificateTemplateModel.append(s_image);
        mlstImages.append(new QImage(":/" + s_image));
    }
}

XYQmlSingleRealObject *XYQmlSingleRealObject::getInstance()
{
    if (mopInstance == 0)
    {
        mopInstance = new XYQmlSingleRealObject;
    }
    return mopInstance;
}

QString XYQmlSingleRealObject::getString(int index)
{
    QString fileName = "123";
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
