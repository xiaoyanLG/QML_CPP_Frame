import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
    width: 300
    height: 300
    color: "#585858"
    property alias name: name.text
    property alias sex: sex.text
    property alias classID: classID.text
    property alias idCard: idCard.text
    property alias phoneNumber: phoneNumber.text

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
        anchors.centerIn: parent
        width: parent.width
        columns: 2
        Label {
            horizontalAlignment: Qt.AlignHCenter
            Layout.fillWidth: true
            text: qsTr("姓名")
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
            text: qsTr("性别")
            color: "white"
        }
        MyTextBox {
            id: sex
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            width: 100
            text: qsTr("学号");
            color: "white"
        }
        MyTextBox {
            id: classID
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("身份证");
            color: "white"
        }
        MyTextBox {
            id: idCard
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }

        Label {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("电话号码")
            color: "white"
        }
        MyTextBox {
            id: phoneNumber
            anchors.right: parent.right
            anchors.rightMargin: 10
            Layout.fillWidth: true
        }
    }
    RowLayout {
        anchors.top: content.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 20
        MyButton {
            text: qsTr("确定")
            textColor: "#333333"
            font.bold: true
            color: "#54c218"
            onClicked: {
                mainWin.accept()
            }
        }
        MyButton {
            text: qsTr("取消")
            textColor: "#333333"
            font.bold: true
            color: "#54c218"
            onClicked: {
                mainWin.reject()
            }
        }
    }
}

