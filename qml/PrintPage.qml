import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3
import Qt.My.qobjectSingleton 1.0

Rectangle {
    id: root
    Rectangle {
        id: leftrect
        width: parent.width - options.width
        anchors.left: parent.left
        height: parent.height
//        Rectangle {
//            id: seekrrect
//            anchors.top: parent.top
//            anchors.topMargin: 10
//            height: 30
//            width: parent.width
//            Label {
//                id: peoplelabel
//                anchors.left: parent.left
//                anchors.leftMargin: 20
//                anchors.verticalCenter: parent.verticalCenter
//                text: "人员信息"
//            }
//            MyTextBox {
//                id: peopletextbox
//                anchors.left: peoplelabel.right
//                anchors.leftMargin: 20
//                anchors.right: parent.right
//                anchors.rightMargin: 5
//                border.color: "#585858"
//            }
//        }
        Rectangle {
            id: printrect
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            height: parent.height - 96
            width: parent.width - 10
            CertificateTemplate {
                id: certificatecontents
                anchors.centerIn: parent
            }
        }
        RowLayout {
            height: 30
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            width: parent.width
            MyButton {
                id: homebtn
                anchors.right: backbtn.left
                anchors.rightMargin: 10
                text: qsTr("首页")
                color: "#1AD96E"
                onClicked: {
                    certificatecontents.home()
                }
            }
            MyButton {
                id: backbtn
                anchors.right: nextbtn.left
                anchors.rightMargin: 10
                text: qsTr("上一页");
                color: "#1AD96E"
                onClicked: {
                    certificatecontents.back()
                }
            }

            MyButton {
                id: nextbtn
                anchors.right: tailbtn.left
                anchors.rightMargin: 10
                text: qsTr("下一页")
                color: "#1AD96E"
                onClicked: {
                    certificatecontents.next()
                }
            }
            MyButton {
                id: tailbtn
                anchors.right: parent.right
                anchors.rightMargin: 10
                text: qsTr("末页")
                color: "#1AD96E"
                onClicked: {
                    certificatecontents.tail()
                }
            }
        }
    }
    Rectangle {
        id: options
        color: "#585858"
        anchors.left: leftrect.right
        anchors.right: parent.right
        height: parent.height
        width: 100
        ColumnLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            spacing: 5
            Rectangle {
                id: btn4
                color: "#1AD96E"
                anchors.top: parent.top
                anchors.topMargin: 12
                width: 90
                height: btn0.height
                Text {
                    id: name
                    anchors.centerIn: parent
                    font.bold: true
                    color: "#333333"
                    text: qsTr("指定打印")
                }
            }
            MyTextBox {
                anchors.top: btn4.bottom
                anchors.topMargin: 10
                font.bold: true
                textColor: "#333333"
                width: 90
            }
            MyButton {
                id: btn3
                anchors.bottom: btn2.top
                anchors.bottomMargin: 10
                text: qsTr("生成证书")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                }
            }
            MyButton {
                id: btn2
                anchors.bottom: btn1.top
                anchors.bottomMargin: 10
                text: qsTr("修改证书")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                }
            }
            MyButton {
                id: btn1
                anchors.bottom: btn0.top
                anchors.bottomMargin: 10
                text: qsTr("打印证书")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.printCCIE();
                }
            }
            MyButton {
                id: btn0
                anchors.bottom: parent.bottom
                text: qsTr("打印预览")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.printViewer();
                }
            }
        }
    }
}

