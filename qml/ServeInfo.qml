import QtQuick 2.4
import QtQuick.Controls 1.3
import Qt.My.qobjectSingleton 1.0
import QtQuick.Layouts 1.1

Rectangle {
    TableView {
        id: courseView
        anchors.left: parent.left
        width: parent.width - options.width + 2
        height: parent.height
        model: ServeModel
        style: MyTableViewStyle {

        }
        TableViewColumn {
            role: "msName"
            title: qsTr("活动主题");
            width: 150
        }
        TableViewColumn {
            role: "msDutyer"
            title: qsTr("现场负责人");
            width: 100
        }
        TableViewColumn {
            role: "msDateTime"
            title: qsTr("活动日期");
            width: 100
        }
        TableViewColumn {
            role: "msPlace"
            title: qsTr("活动地点");
            width: 100
        }
        TableViewColumn {
            role: "msTimes"
            title: qsTr("活动时长");
            width: 75
        }
        TableViewColumn {
            role: "msJoinNumber"
            title: qsTr("报名人数");
            width: 75
        }
        TableViewColumn {
            role: "msStatus"
            title: qsTr("当前状态");
            width: 100
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
                text: qsTr("添加服务")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.addServeInfo()
                }
            }
            MyButton {
                text: qsTr("删除服务")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.delServeInfo(courseView.currentRow)
                }
            }
            MyButton {
                text: qsTr("查询服务")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
            }
        }
    }
}
