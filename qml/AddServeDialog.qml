import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
    width: 300
    height: 280
    color: "#585858"
    property alias name: name.text
    property alias dutyer: dutyer.text
    property alias startTime: startTime.text
    property alias place: place.text
    property alias times: times.text
    property alias status: status.text

    MouseArea {
        anchors.fill: parent
        property variant previousPosition
        onPressed: {
            previousPosition = Qt.point(mouseX, mouseY)
        }
        onPositionChanged: {
            if (pressedButtons == Qt.LeftButton) {
                var dx = mouseX - previousPosition.x
                var dy = mouseY - previousPosition.y
                mainWin.pos = Qt.point(mainWin.pos.x + dx,
                                       mainWin.pos.y + dy)
            }
        }
    }

    TitleBar {
        id: title
        childWnd: true
        anchors.top: parent.top
        width: parent.width
        onClose: {
            mainWin.close()
        }
        onMin: {
            mainWin.showMinimized()
        }
    }

    GridLayout {
        id: content
        anchors.top: title.bottom
        width: parent.width
        columns: 2
        Label {
            horizontalAlignment: Qt.AlignHCenter
            Layout.fillWidth: true
            text: qsTr("活动主题")
            color: "white"
        }
        MyTextBox {
            id: name
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("现场负责人")
            color: "white"
        }
        MyTextBox {
            id: dutyer
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            width: 100
            text: qsTr("活动日期");
            color: "white"
        }
        MyTextBox {
            id: startTime
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            width: 100
            text: qsTr("活动地点")
            color: "white"
        }
        MyTextBox {
            id: place
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }


        Label {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("活动时长")
            color: "white"
        }
        MyTextBox {
            id: times
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("当前状态")
            color: "white"
        }
        MyTextBox {
            id: status
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }
    }
    RowLayout {
        id: buttons
        anchors.top: content.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 12
        MyButton {
            text: qsTr("确定")
            textColor: "#333333"
            font.bold: true
            color: "#1AD96E"
            onClicked: {
                mainWin.accept()
            }
        }
        MyButton {
            text: qsTr("取消")
            textColor: "#333333"
            font.bold: true
            color: "#1AD96E"
            onClicked: {
                mainWin.reject()
            }
        }
    }
}

