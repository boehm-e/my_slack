import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

Rectangle{
    visible: drawer.position > 0

    Image {
        id: header_picture
        source: "assets/background_header.png"
        width: drawer.width
        height: (width * 9) / 16
    }
    Column{
        anchors.top: header_picture.bottom
        anchors.topMargin: 16
        width: drawer.width

        MenuList {
            custom_text: "Custom"
            custom_icon: "assets/lyrics.svg"
        }

        MenuList {
            custom_text: "General"
            custom_icon: "assets/back.svg"
        }

        MenuList {
            custom_text: "Public"
            custom_icon: "assets/lyrics.svg"
        }
    }
}
