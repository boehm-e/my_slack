import QtQuick 2.0
import QtQuick.Controls 2.1

Rectangle {
    color: "white"
    TextField {
        anchors.left: parent.left
        anchors.leftMargin: 15
        width: parent.width
        height: parent.height + 10
        placeholderText: "Message"
        font.family: "Helvetica"
    }

    Image {
        source: "assets/send.svg"
        anchors.right: parent.right
        anchors.rightMargin: 15
        anchors.verticalCenter: parent.verticalCenter
    }
}
