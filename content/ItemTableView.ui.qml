import QtQuick 6.6
import QtQuick.Controls 6.6

Rectangle {
    id: rectangle
    required property bool current
    color: current ? "lightblue" : "lightgray"
    clip: true
    border.width: 1
    property alias txtdlgTableview: txtdlgTableview
    Text {
        id: txtdlgTableview
        text: qsTr("")
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 0
        anchors.rightMargin: 518
        font.pixelSize: 16
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
