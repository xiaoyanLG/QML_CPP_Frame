import QtQuick 2.4
import QtQuick.Controls 1.3
import Qt.My.qobjectSingleton 1.0

Rectangle {
    id: root
    width: 400
    height: 70
    color: "#585858"
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
        title: qsTr("选择打印机：")
        anchors.top: parent.top
        width: parent.width
        onClose: {
            mainWin.close()
        }
        onMin: {
            mainWin.showMinimized()
        }
    }

    ListView {
        id: listview
        anchors.top: title.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        width: parent.width - 20
        anchors.horizontalCenter: parent.horizontalCenter
        model: MyApi.printerList
        delegate: contactDelegate
        orientation: ListView.Horizontal  // 默认垂直布局
        spacing: 10
        highlightMoveDuration: 500 // 设置切换时间
//        interactive: false // 设置不能拖拽
        Component {
            id: contactDelegate
            MyButton {
                text: modelData
                color: "#1AD96E"
                onClicked: {
                    mainWin.mslotSetChoisePrinter(text);
                    mainWin.accept();
                }
            }
        }
    }
}

