

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.6
import QtQuick.Controls 6.6
import StudentManagement 1.0
import QtQuick.Layouts 6.6
import QtCharts

Rectangle {
    width: 1200
    height: 800

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Frame {
            id: frame
            width: 0
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Frame {
            id: frame1
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Frame {
            id: frame2
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true

            ChartView {
                id: pie
                width: 300
                height: 300
                PieSeries {
                    name: "PieSeries"
                    PieSlice {
                        value: 13.5
                        label: "Slice1"
                    }

                    PieSlice {
                        value: 10.9
                        label: "Slice2"
                    }

                    PieSlice {
                        value: 8.6
                        label: "Slice3"
                    }
                }
            }
        }
    }
}
