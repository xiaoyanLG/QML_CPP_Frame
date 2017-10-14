import QtQuick 2.4
import Qt.My.qobjectSingleton 1.0

Rectangle {
    id: root
    width: 650
    height: 480
//    border.color: "#585858"
//    border.width: 2
    function home()
    {
        listview.currentIndex = 0
    }
    function back()
    {
        if (listview.currentIndex <= listview.count - 1 && listview.currentIndex > 0)
        {
            listview.currentIndex = listview.currentIndex - 1
        }
    }
    function next()
    {
        if (listview.currentIndex < listview.count - 1 && listview.currentIndex >= 0)
        {
            listview.currentIndex = listview.currentIndex + 1
        }
    }
    function tail()
    {
        listview.currentIndex = listview.count - 1
    }

    ListView {
        id: listview
        anchors.margins: 2
        anchors.fill: parent
        model: MyApi.certificateTemplateModel
        delegate: contactDelegate
        orientation: ListView.Horizontal
        highlightMoveDuration: 500 // 设置切换时间
        interactive: false // 设置不能拖拽
        clip: true   // 指定超出View区域不显示
        Component {
            id: contactDelegate
            Rectangle {
                width: root.width
                height: root.height
                Image {
                    id: name
                    anchors.centerIn: parent
                    sourceSize.width: 640
                    source: modelData
                }
            }
        }
    }
}

