import QtQuick 2.4

Rectangle {
    id: root
    width: 900
    height: 600
    color: "#585858"
    TitleBar {
        id: titlebar
        z: 1
        title: "Manager"
        ico: "manager.ico"
        color: root.color
        width: parent.width
        anchors.right: parent.right
        anchors.top: parent.top
        onClose: {
            mainWin.close()
        }
        onMin: {
            mainWin.showMinimized()
        }
    }

    ModuleList {
        id: title
        anchors.top: titlebar.bottom
        width: 100
        height: parent.height
        onCurrentIndexChanged: {
            allwidgets.currentIndex = currentIndex
        }
    }

    AllMainWidgets {
        id: allwidgets
        width: 800
        anchors.top: titlebar.bottom
        anchors.bottom: statusBar.top
        anchors.left: title.right
        anchors.right: parent.right
        onCurrentIndexChanged: {
            title.currentIndex = currentIndex
        }
    }
    StatusBar {
        id: statusBar
        z: 1
        color: root.color
        anchors.bottom: parent.bottom
        width: parent.width
    }
}

