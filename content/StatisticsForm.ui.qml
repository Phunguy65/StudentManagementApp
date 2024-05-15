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
    antialiasing: true
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
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.styleName: "Heavy"
                    font.bold: true
                }
            }

            Column {
                id: column3
                width: 200
                height: 400
                Layout.fillWidth: true
                Layout.fillHeight: true
                ListView {
                    id: lvHighestScores
                    anchors.fill: parent
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
                    font.styleName: "Heavy"
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Column {
                id: column4
                width: 200
                height: 400
                Layout.fillHeight: true
                Layout.fillWidth: true
                ListView {
                    id: lvLowestScores
                    anchors.fill: parent
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
                    font.styleName: "Heavy"
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Column {
                id: column5
                width: 200
                height: 400
                Layout.fillWidth: true
                Layout.fillHeight: true

                ChartView {
                    id: chartPercentage
                    height: 270
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    antialiasing: true
                    title: "Percentage Classification"

                    PieSeries {
                        id: pieChart
                        name: "pieChartView"
                        PieSlice {
                            color: "#00fa1d"
                            value: 13.5
                            label: "Excellent"
                        }

                        PieSlice {
                            color: "#3dace4"
                            value: 10.9
                            label: "Good"
                        }

                        PieSlice {
                            color: "#1ec2a3"
                            value: 8.6
                            label: "Average"
                        }

                        PieSlice {
                            color: "#cea223"
                            value: 10
                            label: "BelowAverage"
                        }

                        PieSlice {
                            color: "#a11c1c"
                            value: 10
                            label: "Weak"
                        }
                    }
                }

                ChartView {
                    id: chartDetailed
                    height: 280
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    antialiasing: true
                    title: "Detailed Classification"
                    BarSeries {
                        name: "barChartView"
                        barWidth: 1
                        labelsVisible: true
                        axisX: BarCategoryAxis {
                            id: bcaChartBar
                            categories: ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
                        }

                        labelsPosition: AbstractBarSeries.LabelsOutsideEnd

                        BarSet {
                            color: "#24d2a8"
                            labelColor: "#cc0707"
                            values: [0,9,10,20,10,0,101,2,1,1,200]
                        }

                    }
                }

                RowLayout {
                    id: rowLayout1
                    width: 100
                    height: 100
                    anchors.horizontalCenter: parent.horizontalCenter

                    Label {
                        id: lbTitleAverageScore
                        text: qsTr("Average Score")
                        font.pixelSize: 18
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        Layout.fillWidth: false
                    }

                    Label {
                        id: lbDetailedAverage
                        text: qsTr("")
                        font.pixelSize: 18
                        verticalAlignment: Text.AlignVCenter
                        Layout.fillWidth: true
                    }
                }
            }
        }
    }
}
