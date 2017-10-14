import QtQuick 2.0
import Qt.My.qobjectSingleton 1.0

Rectangle {
    id: root
    color: "#00000000"
    property alias model: listview.model
    property alias currentIndex: listview.currentIndex
    ListView {
        id: listview
        anchors.fill: parent
        model: MyApi.moduleList
        delegate: contactDelegate
        orientation: ListView.Vertical
        highlight: Rectangle {
            color: "lightsteelblue";
        }

        Component {
            id: contactDelegate
            MyButton {
                width: root.width
                height: 50
                text: modelData
                textColor: "white"
                radius: 0
                onClicked: {
                    listview.currentIndex = index
                }
            }
        }
    }
}
