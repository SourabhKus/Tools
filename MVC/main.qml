import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import com.xyz.UAV 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property real boxW: 200

    Rectangle {
        border.color: "black"
        height: 200
        width:  boxW
        color: "yellow"

        ListView {
            id: myData
            anchors.fill: parent
            model: uavRegistery.uavQList
            delegate: Component { Loader { source: "UAVInfoPanel.qml"} }
            focus: true
            clip: true
        }
    }

    Row {
        y: 150

        Rectangle {
            height: 50
            width: boxW
            border.color: "black"

            TextInput {
                id: inputBox
                anchors.fill: parent
            }
        }

        Button {
            height: 50
            width: 50
            text: "Add"

            onClicked: {
                uavRegistery.addUAV(inputBox.text)
            }
        }

        Button {
            height: 50
            width: 50
            text: "Delete"

            onClicked: {
                uavRegistery.removeUAV(inputBox.text)
            }
        }

        Button {
            height: 50
            width: 70
            text: "Rename"

            onClicked: {
                uavRegistery.renameUAV(inputBox.text, "NewName")
            }
        }

        Button {
            height: 50
            width: 50
            text: "Print"

            onClicked: {
                uavRegistery.printUAVList()
            }
        }
    }
}
