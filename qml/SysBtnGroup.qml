import QtQuick 2.4
import QtQuick.Layouts 1.1

RowLayout
{
    id: sysbtngroup
    property bool childWnd: false
    width: parent.width
    height: 25
    spacing: 0

    signal skin
    signal feedback
    signal menu
    signal min
    signal close

    SysBtn
    {
        id:skin
        visible: !childWnd
        picHover: "skin_hover.png"
        picNormal: "skin_normal.png"
        picPressed: "skin_pressed.png"
        anchors.right: feedback.left
        anchors.top: parent.top
        onClicked:
        {
            sysbtngroup.skin()
        }
    }

    SysBtn
    {
        id:feedback
        visible: !childWnd
        picHover: "feedback_hover.png"
        picNormal: "feedback_normal.png"
        picPressed: "feedback_pressed.png"
        anchors.right: menu.left
        anchors.top: parent.top
        onClicked:
        {
            sysbtngroup.feedback()
        }
    }

    SysBtn
    {
        id:menu
        visible: !childWnd
        picHover: "menu_hover.png"
        picNormal: "menu_normal.png"
        picPressed: "menu_pressed.png"
        anchors.right: min.left
        anchors.top: parent.top
        onClicked:
        {
            sysbtngroup.menu()
        }
    }

    SysBtn
    {
        id:min
        picHover: "min_hover.png"
        picNormal: "min_normal.png"
        picPressed: "min_pressed.png"
        anchors.right: close.left
        anchors.top: parent.top
        onClicked:
        {
            sysbtngroup.min()
        }
    }

    SysBtn
    {
        id:close
        picHover: "close_hover.png"
        picNormal: "close_normal.png"
        picPressed: "close_pressed.png"
        anchors.right: parent.right
        anchors.top: parent.top
        onClicked:
        {
            sysbtngroup.close()
        }
    }
}
