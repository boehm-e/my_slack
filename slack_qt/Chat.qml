import QtQuick 2.0

Rectangle {
    width: 180; height: 200

    Component {
        id: messageDelegate
        Rectangle {
            width: root.width / 2 - 50
            height: messageText.height + 20
            rotation: 180
            anchors.left: index%2==0 ? parent.left: 0
            anchors.right: index%2==0 ? right : parent.right
            anchors.leftMargin: index%2==0 ? 25 : 0
            anchors.rightMargin: index%2==0 ? 0 : 25
            color: index%2 == 0 ? "#3fa960" : "#e3e1e1"
            Text {
                id: messageText
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15
                text: message
            }

            Triangle {
                width: 20
                height: width
                color: parent.color;
                rotation: index%2 == 0 ? -90 : 180
                anchors.right: index%2 == 0 ? parent.right : parent.left
                anchors.rightMargin: index%2 == 0 ? -width : 0
                anchors.bottom: parent.bottom
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: MessageModel {}
        delegate: messageDelegate
        focus: true
    }
}
