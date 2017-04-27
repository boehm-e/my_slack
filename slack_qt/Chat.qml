import QtQuick 2.0

Rectangle {
    width: 180; height: 200

    function addItem(owner, message) {
        lv.model.insert(0, {
                            message: message,
                            owner: owner
                        });
    }

    Component {
        id: messageDelegate
        Rectangle {
            width: root.width / 2 - 50
            height: messageText.height + 40
            rotation: 180
            anchors.left: owner == "me" ? parent.left: 0
            anchors.right: owner == "me" ? right : parent.right
            anchors.leftMargin: owner == "me" ? 25 : 0
            anchors.rightMargin: owner == "me" ? 0 : 25

            Rectangle {
                id: col
                width: parent.width
                height: parent.height - 20
                anchors.top: parent.top
                anchors.topMargin: 10
                color: owner == "me" ? "#3fa960" : "#e3e1e1"
            }


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
                color: col.color;
                rotation: owner == "me" ? -90 : 180
                anchors.right: owner == "me" ? parent.right : parent.left
                anchors.rightMargin: owner == "me" ? -width : 0
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
            }
        }
    }

    ListView {
        id: lv

        anchors.fill: parent
        model: MessageModel {}
        delegate: messageDelegate
        focus: true
    }
}
