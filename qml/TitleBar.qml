import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Rectangle {
    id: root
    property bool childWnd: false
    property alias title: title.text
    property alias ico: ico.source
    color: "#00000000"
    width: parent.width
    height: 30
    signal skin
    signal feedback
    signal menu
    signal min
    signal close
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
    RowLayout {
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 3
        Image {
            id: ico
            sourceSize.height: 15
            sourceSize.width: 15
        }
        Label {
            id: title
            font.family: "微软雅黑"
            font.pixelSize: 12
            color: "white"
        }
    }

    SysBtnGroup {
        childWnd: root.childWnd
        anchors.right: parent.right
        anchors.top: parent.top
        onSkin: {
            root.skin()
        }
        onFeedback: {
            root.feedback()
        }
        onMenu: {
            root.menu()
        }
        onMin: {
            root.min()
        }

        onClose: {
            root.close()
        }
    }
}

