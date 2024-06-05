import QtQuick 6.6
import QtQuick.Controls 6.6
import StudentManagement 1.0
import QtQuick.Layouts 6.6
import QtCharts 6.6

Rectangle {
    width: 1920
    height: 1080
    property alias lbDetailedAverage: lbDetailedAverage
    property alias lbTitleAverageScore: lbTitleAverageScore
    property alias rowLayout1: rowLayout1
    property alias chartDetailed: chartDetailed
    property alias chartPercentage: chartPercentage
    property alias column5: column5
    property alias lbCharts: lbCharts
    property alias rectangle3: rectangle3
    property alias column2: column2
    property alias lvLowestScores: lvLowestScores
    property alias column4: column4
    property alias lbLowestScores: lbLowestScores
    property alias rectangle6: rectangle6
    property alias column1: column1
    property alias lvHighestScores: lvHighestScores
    property alias column3: column3
    property alias lbHighestScores: lbHighestScores
    property alias recStaistics: recStaistics
    property alias colFirst: colFirst
    property alias rowStatisticsForm: rowStatisticsForm
    clip: true

    RowLayout {
        id: rowStatisticsForm
        anchors.fill: parent

        ColumnLayout {
            id: colFirst
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                id: recStaistics
                height: 40

                radius: 5
                gradient: Gradient {
                    GradientStop {
                        position: 0
                        color: "#fa709a"
                    }

                    GradientStop {
                        position: 1
                        color: "#fee140"
                    }
                    orientation: Gradient.Vertical
                }
                Layout.preferredWidth: 620
                Layout.fillHeight: false
                Layout.fillWidth: true
                clip: true

                Label {
                    id: lbHighestScores
                    color: "#000000"
                    text: qsTr("Highest Scores")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "SF Pro Display"
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.styleName: "Heavy"
                    font.bold: true
                }
            }

            ColumnLayout {
                id: column3
                width: 200
                height: 400
                Layout.fillWidth: true
                Layout.fillHeight: true
                ListView {
                    id: lvHighestScores
                    boundsMovement: Flickable.StopAtBounds
                    boundsBehavior: Flickable.StopAtBounds
                    snapMode: ListView.SnapToItem
                    pixelAligned: true
                    spacing: 10
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    delegate: ItemList {
                        lbDetailFullName.text: model.fullName
                        lbDetailStudentId.text: model.idStudent
                        lbDetailClass.text: model.idClass
                        lbStudentScore.text: model.score
                        width: recStaistics.width
                    }
                }
            }
        }

        ColumnLayout {
            id: column1
            width: 200
            height: 400
            Layout.fillHeight: true
            Layout.fillWidth: true
            Rectangle {
                id: rectangle6
                height: 40
                color: "#ffffff"
                radius: 5
                gradient: Gradient {
                    GradientStop {
                        position: 0
                        color: "#cfd9df"
                    }

                    GradientStop {
                        position: 1
                        color: "#e2ebf0"
                    }
                    orientation: Gradient.Vertical
                }
                Layout.preferredWidth: 620
                Layout.fillHeight: false
                Layout.fillWidth: true
                Label {
                    id: lbLowestScores
                    text: qsTr("Lowest Scores")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "SF Pro Display"
                    font.styleName: "Heavy"
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            ColumnLayout {
                id: column4
                width: 200
                height: 400
                Layout.fillHeight: true
                Layout.fillWidth: true
                ListView {
                    id: lvLowestScores
                    boundsBehavior: Flickable.StopAtBounds
                    boundsMovement: Flickable.StopAtBounds
                    snapMode: ListView.SnapToItem
                    spacing: 10
                    pixelAligned: true
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    delegate: ItemList {
                        lbDetailFullName.text: model.fullName
                        lbDetailStudentId.text: model.idStudent
                        lbDetailClass.text: model.idClass
                        lbStudentScore.text: model.score
                        width: rectangle6.width
                    }
                }
            }
        }

        ColumnLayout {
            id: column2
            width: 200
            height: 400
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                id: rectangle3
                height: 40
                width: 630
                color: "#ffffff"
                radius: 5
                gradient: Gradient {
                    GradientStop {
                        position: 0
                        color: "#000000"
                    }

                    GradientStop {
                        position: 0.01
                        color: "#fad0c4"
                    }

                    GradientStop {
                        position: 1
                        color: "#ffd1ff"
                    }
                    orientation: Gradient.Vertical
                }
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.fillWidth: true
                Label {
                    id: lbCharts
                    text: qsTr("Charts")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "SF Pro Display"
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            ColumnLayout {
                id: column5
                width: 200
                height: 400
                Layout.fillWidth: true
                Layout.fillHeight: true

                ChartView {
                    id: chartPercentage
                    height: 250
                    dropShadowEnabled: true
                    backgroundRoundness: 20
                    backgroundColor: "#dedb9b"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    antialiasing: true
                    title: "Percentage Classification"
                    property alias pieChart: pieChart
                    animationOptions: ChartView.SeriesAnimations
                    PieSeries {
                        id: pieChart
                        name: "pieChartView"

                        PieSlice {
                            color: Qt.rgba(Math.random(), Math.random(),
                                           Math.random(), 1)
                            value: 10.9
                            labelVisible: true
                            label: qsTr("Good: %1%").arg(percentage * 100)
                        }

                        PieSlice {
                            color: Qt.rgba(Math.random(), Math.random(),
                                           Math.random(), 1)
                            value: 8.6
                            labelVisible: true
                            label: qsTr("Average: %1%").arg(percentage * 100)
                        }

                        PieSlice {
                            color: Qt.rgba(Math.random(), Math.random(),
                                           Math.random(), 1)
                            value: 10
                            labelVisible: true
                            label: qsTr("Weak: %1%").arg(percentage * 100)
                        }
                    }
                }

                ChartView {
                    id: chartDetailed
                    height: 260
                    dropShadowEnabled: true
                    backgroundRoundness: 20
                    backgroundColor: "#d8bfea"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    antialiasing: true
                    title: "Detailed Classification"
                    property alias barChart: barChart
                    property alias vlAxis: vlAxis
                    animationOptions: ChartView.GridAxisAnimations

                    ValuesAxis {
                        id: vlAxis
                    }

                    BarSeries {
                        id: barChart
                        name: "barChartView"
                        barWidth: 1
                        labelsVisible: true
                        axisX: BarCategoryAxis {
                            id: bcaChartBar
                            categories: ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
                        }

                        axisY: vlAxis

                        labelsPosition: AbstractBarSeries.LabelsOutsideEnd

                        BarSet {
                            color: "#24d2a8"
                            labelColor: "#cc0707"
                            label: "Number of student of scores"
                            values: []
                        }
                    }
                }

                RowLayout {
                    id: rowLayout1
                    width: 100
                    height: 100
                    Layout.leftMargin: 20
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Label {
                        id: lbTitleAverageScore
                        text: qsTr("Average Score")
                        font.pixelSize: 18
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font.family: "SF Pro Display"
                        Layout.fillHeight: true
                        font.bold: true
                        Layout.fillWidth: true
                    }

                    Label {
                        id: lbDetailedAverage
                        text: qsTr("")
                        font.pixelSize: 18
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        font.family: "SF Pro Display"
                        Layout.preferredWidth: 70
                        Layout.fillHeight: true
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        Layout.fillWidth: true
                    }
                }
            }
        }
    }
}
