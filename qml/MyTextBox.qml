import QtQuick 2.4
import QtQuick.Layouts 1.1

FocusScope {
    id: root

    width: 100
    height: 30

    property Item nextInFocus;
    property alias text: txt.text
    property alias border: rect.border
    property alias color: rect.color
    property alias textColor: txt.color
    property alias readOnly: txt.readOnly
    property alias selectByMouse: txt.selectByMouse
    property alias font: txt.font
    property alias radius: rect.radius
    property alias horizontalAlignment: txt.horizontalAlignment

    Rectangle {
        id: rect
        anchors.margins: 2
        anchors.fill: parent
        radius: 2
        border.color: "#cccccc"
        border.width: 2
        antialiasing: true

        RowLayout {
            width: parent.width
            height: parent.height
            TextInput {
                id: txt
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                focus: true
                text: root.text;
                selectByMouse: true
                KeyNavigation.tab: root.nextInFocus;
            }
            layer.enabled: true
            layer.smooth: true
        }
    }
}
