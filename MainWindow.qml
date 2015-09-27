import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    width: 500
    height: 500
    gradient: Gradient{
        GradientStop {position: 0.0; color:"lightsteelblue"}
        GradientStop {position: 1.0; color:"steelblue"}
    }

    // плавающая панель задач
    Rectangle {
        id: tasks
        anchors.left: parent.left
        width: parent.width / 3
        height: parent.height
        color: "white"
        state: "hidden"

        states: [
            State {
                name: "shown"
                PropertyChanges {
                    target: tasks
                    width: tasks.parent.width / 3
                }
            },
            State {
                name: "hidden"
                PropertyChanges {
                    target: tasks
                    width: 0
                }
            }
        ]

        transitions: [
            Transition {
                NumberAnimation {
                    property: "width"
                    duration: 500
                    easing.type: Easing.InOutSine
                }
            }
        ]
    }


    // кнопка для отображения/скрывания плавающей панели задач
    Rectangle {
        id:tasks_collapser
        anchors.left: tasks.right
        state: "collapsed"
        width: 32
        height: 32
        anchors.margins: 10
        radius: width / 4
        gradient: Gradient {
            GradientStop {id: tasks_collapser_stop0; position: 0.0; color: "springgreen"}
            GradientStop {id: tasks_collapser_stop1; position: 1.0; color: "forestgreen"}
        }

        states: [
            State {
                name: "expanded"
                PropertyChanges {
                    target: tasks_collapser_stop0
                    color: "forestgreen"
                }
                PropertyChanges {
                    target: tasks_collapser_stop1
                    color: "seagreen"
                }
            },
            State {
                name: "collapsed"
                PropertyChanges {
                    target: tasks_collapser_stop0
                    color: "springgreen"
                }
                PropertyChanges {
                    target: tasks_collapser_stop1
                    color: "forestgreen"
                }
            },
            State {
                name: "hovered"
                PropertyChanges {
                    target: tasks_collapser_stop0
                    color: "black"
                }
                PropertyChanges {
                    target: tasks_collapser_stop1
                    color: "orangered"
                }
            }
        ]

        MouseArea {
            anchors.fill: tasks_collapser;
            hoverEnabled: true;

            onEntered: {
                if (tasks.state == "hidden")
                    tasks_collapser.state = "hovered"
            }

            onExited: {
                if (tasks.state == "hidden")
                    tasks_collapser.state = "collapsed"
                else
                    tasks_collapser.state = "expanded"
            }

            onClicked: {
                if (tasks.state == "shown")
                {
                    tasks.state = "hidden"
                    tasks_collapser.state = "collapsed"
                }
                else
                {
                    tasks.state = "shown"
                    tasks_collapser.state = "expanded"
                }
            }
        }

        Image {
            id: tasks_collapser_img
            anchors.fill: parent
            source: "qrc:/img/hammer.ico"
        }
    }
}
