import QtQuick 2.0

Item {
    height: 40
    width: boxW

    Text {
        text: '<b>Name:</b>' + uavRegistery.uavQList[index].name
    }
}
