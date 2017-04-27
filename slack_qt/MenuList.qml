import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

Button {
    property string custom_text
    property string custom_icon
    width: drawer.width
    Material.foreground: Material.Pink

    Rectangle {
        anchors.fill: parent;
        Image {
            id: icon
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 16
            anchors.top: parent.top
            anchors.topMargin: 12
            source: custom_icon
            height: parent.height - anchors.top * 2
            width: height
        }

        Text {
            id: name
            text: custom_text
            anchors.left: icon.right
            anchors.leftMargin: 24
            anchors.verticalCenter:parent.verticalCenter
            font.pixelSize: 18
        }
    }

}
