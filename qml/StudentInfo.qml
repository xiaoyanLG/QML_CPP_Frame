import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
import Qt.My.qobjectSingleton 1.0
import QtQuick.Layouts 1.1

Rectangle {
    TableView {
        id: studentView
        anchors.left: parent.left
        width: parent.width - options.width + 2
        height: parent.height
        model: studentModel
        TableViewColumn {
            role: "msID"
            title: qsTr("编号");
            width: 100
        }
        TableViewColumn {
            role: "msName"
            title: qsTr("姓名");
            width: 100
        }
        TableViewColumn {
            role: "msSex"
            title: qsTr("性别");
            width: 100
        }
        TableViewColumn {
            role: "msUnit"
            title: qsTr("单位");
            width: 100
        }
        TableViewColumn {
            role: "msIDCard"
            title: qsTr("身份证");
            width: 200
        }
        TableViewColumn {
            role: "msPhoneNumber"
            title: qsTr("电话号码");
            width: 100
        }
        style: MyTableViewStyle {

        }
    }
    Rectangle {
        id: options
        color: "#585858"
        width: 100
        anchors.right: parent.right
        height: parent.height
        ColumnLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            spacing: 5
            MyButton {
                text: qsTr("添加人员")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.addStudentInfo()
                }
            }
            MyButton {
                text: qsTr("删除人员")
                textColor: "#333333"
                font.bold: true
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.delStudentInfo(studentView.currentRow)
                }
            }
            MyButton {
                text: qsTr("查询人员")
                font.bold: true
                textColor: "#333333"
                width: 90
                color: "#1AD96E"
            }
        }
    }
}

