import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

Rectangle {
    id: root
    color: "#e1433a"
    anchors.top: parent.top
    width: parent.width;
    height: 70
    z: 999

    Rectangle {
        width: parent.width * 0.4
        height: 50
        anchors.topMargin: 10;
        anchors.centerIn: parent;
        Material.elevation: 5
        color: "#ffffff"
        opacity: 0.7

        TextInput {
            anchors.fill: parent
            font.pixelSize: 15
            horizontalAlignment:  TextInput.AlignHCenter
            verticalAlignment:  TextInput.AlignVCenter
            text: "Search";
            font.capitalization: Font.AllLowercase
            onFocusChanged: this.text = ""
//            onTextChanged: mainView.updateView(text);
            onTextChanged: mainView.loadSongsFromApi(text);
        }
    }

    Image {
        id: hamburger
        source: "assets/hamburger.png"
        height: parent.height / 3
        width: height
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: height

        MouseArea {
            anchors.fill: parent
            onClicked: {
                drawer.open()
            }
        }

    }
}
