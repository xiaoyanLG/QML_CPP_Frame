import QtQuick 2.0

Rectangle {
    color: "#00000000"
    width: parent.width
    height: 30
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
}

