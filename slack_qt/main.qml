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
    }

    Chat {
        anchors.top: header.bottom
        anchors.bottom: message.top
        width: parent.width
        rotation: 180
        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("OK")
                socket.sendMessage("COUCOU")
            }
        }
    }

    MessageBar {
        id: message
        anchors.bottom: parent.bottom
        width: parent.width
        height: 60
    }
}

