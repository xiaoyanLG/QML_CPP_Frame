import QtQuick 2.4
import Qt.My.qobjectSingleton 1.0

Rectangle {
    id: root
    color: "#00000000"
    property alias currentIndex: listview.currentIndex
    ListView {
        id: listview
        anchors.fill: parent
        model: MyApi.moduleList
        delegate: contactDelegate
        orientation: ListView.Vertical
        highlightMoveDuration: 500 // 设置切换时间
        interactive: false // 设置不能拖拽
        Component {
            id: contactDelegate
            Loader {
                source: MyApi.getModeleInfo(modelData)
                width: root.width
                height: root.height
            }
        }
    }
}

