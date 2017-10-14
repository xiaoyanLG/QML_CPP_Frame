import QtQuick 2.4
import QtQuick.Controls.Styles 1.3

TableViewStyle {
    headerDelegate: Rectangle {
        height: 25
        color: "#cccccc"
        border.color: "#585858"
        border.width: 1
        Text {
            id: textItem
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.leftMargin: 12
            text: styleData.value
            font.family: "微软雅黑"
            font.bold: true
            font.pointSize: 11
            elide: Text.ElideRight
            color: textColor
            renderType: Text.NativeRendering
        }
    }
    itemDelegate: Rectangle {
        color: styleData.selected ? "#333333" : "#cccccc"
        border.color: "#585858"
        border.width: 1
        Text {
            width: parent.width
            anchors.leftMargin: 12
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 1
            elide: styleData.elideMode
            text: styleData.value !== undefined ? styleData.value : ""
            font.pointSize: 10
            color: styleData.textColor
            renderType: Text.NativeRendering
        }
    }
    rowDelegate: Rectangle {
        height: 25
    }
}

