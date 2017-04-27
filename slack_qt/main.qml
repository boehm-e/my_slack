import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick 2.7
import Qt.labs.folderlistmodel 2.1
import QtGraphicalEffects 1.0
import Socket 1.0

ApplicationWindow {
    id: root
    width: 960
    height: 540
    visible: true
    color: "#e8e8e8"

    Component.onCompleted: {
        //        socket.sendMessage("testttt");
    }

    Header {
        z: 2
        id: header
    }

    Drawer {
        id: drawer
        width: root.width / 3
        height: root.height
        DrawerContainer{}
    }

    Socket {
        id: socket
        onNewMessage: {
            console.log("New Message From Server : ", message)
            chat.addItem("you", message)
        }
    }

    Chat {
        id: chat
        anchors.top: header.bottom
        anchors.bottom: message.top
        width: parent.width
        rotation: 180
    }

    MessageBar {
        id: message
        anchors.bottom: parent.bottom
        width: parent.width
        height: 60
    }
}

