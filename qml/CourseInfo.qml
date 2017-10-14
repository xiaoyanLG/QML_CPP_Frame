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
        model: courseModel
        style: MyTableViewStyle {

        }
        TableViewColumn {
            role: "msName"
            title: qsTr("培训主题")
            width: 150
        }
        TableViewColumn {
            role: "msTeacher"
            title: qsTr("培训讲师")
            width: 100
        }
        TableViewColumn {
            role: "msStartTime"
            title: qsTr("培训日期")
            width: 100
        }
        TableViewColumn {
            role: "msPlace"
            title: qsTr("培训地点")
            width: 100
        }
        TableViewColumn {
            role: "msTimes"
            title: qsTr("培训时长")
            width: 75
        }
        TableViewColumn {
            role: "msJoinNumber"
            title: qsTr("报名人数")
            width: 75
        }
        TableViewColumn {
            role: "msStatus"
            title: qsTr("当前状态")
            width: 100
        }
    }
    Rectangle {
        id: options;
        color: "#585858"
        width: 100
        anchors.right: parent.right
        height: parent.height
        ColumnLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            spacing: 5
            MyButton {
                text: qsTr("添加培训")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.addCourseInfo()
                }
            }
            MyButton {
                text: qsTr("删除培训")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
                onClicked: {
                    MyApi.delCourseInfo(courseView.currentRow)
                }
            }
            MyButton {
                text: qsTr("查询培训")
                font.bold: true
                textColor: "#333333"
                color: "#1AD96E"
                width: 90
            }
        }
    }
}
