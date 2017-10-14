import QtQuick 2.4
import QtQuick.Layouts 1.1

Rectangle {
    id: container

    property alias text: text.text
    property alias textColor: text.textColor
    property alias font: text.font
    signal clicked

    height: text.height;
    width: text.width
    antialiasing: true
    radius: 2
    color: "#00000000"

    MyTextBox {
        id: text
        anchors.centerIn: parent
        border.color: "#00000000"
        border.width: 0
        color: "#00000000"
        readOnly: true
        selectByMouse: false
        width: container.width
        height: container.height
        radius: container.radius
        horizontalAlignment: Qt.AlignHCenter
    }

    Rectangle {
        id: topcolor
        radius: container.radius
        anchors.fill: parent
        color: "#00000000"
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                container.clicked()
            }
            onPressed: {
                container.state = "checked"
            }
            onReleased: {
                container.state = "hover"
            }

            onEntered: {
                container.state = "hover"
            }
            onExited: {
                container.state = "leave"
            }
        }

    }

    states:
    [
        State {
            name: "checked"
            PropertyChanges { target: topcolor; color: "#5599BBFF" }
        },

        State {
            name: "hover"
            PropertyChanges { target: topcolor; color:"#77FFFFFF" }
        },

        State {
            name: "leave"
            PropertyChanges { target: topcolor; color:"#00000000" }
        }
    ]

    transitions:
    [
        Transition
        {
            PropertyAnimation
            {
                property: "color"
                easing.type: Easing.Linear
                duration: 200
            }
        }
    ]
}
