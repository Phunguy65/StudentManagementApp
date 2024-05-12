

/* This file is generated and only relevant for integrating the project into a Qt 6 and cmake based
C++ project. */
import QtQuick 6.7
import content
import QtQuick.Dialogs 6.7
import QtCore 6.7
import MainWindowController
import OverviewTabController

Window {
    id: mainWindow
    width: mainWindowForm.width
    height: mainWindowForm.height
    visible: true
    property alias mainWindowForm: mainWindowForm
    title: "StudentManagement"
    visibility: Window.Maximized
    mainWindowForm.tabOverview.tableViewStudent.model: OverviewController.sortFilterModel

    mainWindowForm.tabOverview.tableViewStudent.selectionModel: ItemSelectionModel {
        onCurrentChanged: {
            if (currentIndex === -1) {
                return
            }
            var rowIndex = currentIndex.row
            mainWindowForm.tabOverview.tfStudentId.text
                    = mainWindowForm.tabOverview.tableViewStudent.model.index(
                        rowIndex, 0).data().toString()
            mainWindowForm.tabOverview.tfStudentLastName.text
                    = mainWindowForm.tabOverview.tableViewStudent.model.index(
                        rowIndex, 1).data().toString()
            mainWindowForm.tabOverview.tfStudentFirstName.text
                    = mainWindowForm.tabOverview.tableViewStudent.model.index(
                        rowIndex, 2).data().toString()
            mainWindowForm.tabOverview.tfStudentClassId.text
                    = mainWindowForm.tabOverview.tableViewStudent.model.index(
                        rowIndex, 3).data().toString()
            mainWindowForm.tabOverview.tfStudentScore.text
                    = mainWindowForm.tabOverview.tableViewStudent.model.index(
                        rowIndex, 4).data().toString()
        }
    }

    mainWindowForm.tabOverview.tableViewStudent.selectionMode: TableView.SingleSelection

    MainWindowForm {
        id: mainWindowForm
        anchors.fill: parent
        property var columnWidths: [180, 200, 180, 180, 100]

        tabOverview.tableViewStudent.delegate: Rectangle {
            required property bool current
            color: current ? "lightblue" : "lightgray"
            clip: true
            border.width: 1
            Text {
                text: model.display
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 16
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        tabOverview.hhvTableViewStudent.selectionModel: ItemSelectionModel {}

        tabOverview.hhvTableViewStudent.delegate: Rectangle {
            color: "#34BF00"
            implicitWidth: 180
            implicitHeight: 50
            border.width: 1
            border.color: "black"
            required property bool current

            Text {
                text: model.display
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 5
                font.pixelSize: 18
                font.bold: true
                color: "white"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log(column)
                }
            }
        }

        tabOverview.tableViewStudent.columnWidthProvider: function (column) {
            return columnWidths[column]
        }

        tabOverview.lbTotalRcords.text: qsTr("%1").arg(
                                            OverviewController.rowCount)

        tabOverview.lbSearchingTime.text: qsTr(" ms")
    }
    /**********  Set properties of the main window **********/
    mainWindowForm.cbDataStructures.textRole: "storagedStructureSelection"
    mainWindowForm.cbDataStructures.valueRole: "value"
    mainWindowForm.cbDataStructures.model: ListModel {
        ListElement {
            storagedStructureSelection: "Storage By Array"
            value: 0
        }
        ListElement {
            storagedStructureSelection: "Storage By Single Linked List"
            value: 1
        }
        ListElement {
            storagedStructureSelection: "Storage By Double Linked List"
            value: 2
        }
        ListElement {
            storagedStructureSelection: "Storage By Circular Linked List"
            value: 3
        }
    }

    mainWindowForm.tabOverview.cbFilterInfoStudent.textRole: "filterColumn"
    mainWindowForm.tabOverview.cbFilterInfoStudent.valueRole: "value"

    mainWindowForm.tabOverview.cbFilterInfoStudent.model: ListModel {
        ListElement {
            filterColumn: "Filter By All"
            value: -1
        }

        ListElement {
            filterColumn: "Filter By Id Student"
            value: 0
        }
        ListElement {
            filterColumn: "Filter By Last Name"
            value: 1
        }
        ListElement {
            filterColumn: "Filter By First Name"
            value: 2
        }
        ListElement {
            filterColumn: "Filter By Id Class"
            value: 3
        }
        ListElement {
            filterColumn: "Filter By Score"
            value: 4
        }
    }

    mainWindowForm.tabOverview.cbSortedMethods.textRole: "sortedMethod"

    mainWindowForm.tabOverview.cbSortedMethods.model: ListModel {
        ListElement {
            sortedMethod: "Insertion Sort"
            value: 0
        }
        ListElement {
            sortedMethod: "Selection Sort"
            value: 1
        }
        ListElement {
            sortedMethod: "Bubble Sort"
            value: 2
        }
        ListElement {
            sortedMethod: "Quick Sort"
            value: 3
        }
        ListElement {
            sortedMethod: "Heap Sort"
            value: 4
        }
        ListElement {
            sortedMethod: "Merge Sort"
            value: 5
        }
    }

    mainWindowForm.tabOverview.rbSearchInfoStudent.icon.source: "qrc:/asset_imports/searchIcon.png"
    mainWindowForm.tabOverview.rbSearchInfoStudent.icon.color: "black"
    mainWindowForm.tabOverview.rbInsertStudent.icon.source: "qrc:/asset_imports/adduserIcon.png"
    mainWindowForm.tabOverview.rbInsertStudent.icon.color: "white"
    mainWindowForm.tabOverview.rbUpdateStudent.icon.source: "qrc:/asset_imports/edituserIcon.png"
    mainWindowForm.tabOverview.rbUpdateStudent.icon.color: "pink"
    mainWindowForm.tabOverview.rbRemoveStudent.icon.source: "qrc:/asset_imports/removeuserIcon.png"
    mainWindowForm.tabOverview.rbRemoveStudent.icon.color: "orange"

    FileDialog {
        id: fdOpenFile
        currentFolder: StandardPaths.standardLocations(
                           StandardPaths.DocumentsLocation)[0]
        acceptLabel: qsTr("Open")
        rejectLabel: qsTr("Cancel")
        title: qsTr("Open File Xlsx")
        nameFilters: ["Excel Files (*.xlsx)"]
        fileMode: FileDialog.OpenFile

        onAccepted: {
            MainWindowController.openFile(fdOpenFile.selectedFile)
        }
    }

    MessageDialog {
        id: mdNotifyError
        buttons: MessageDialog.Ok
    }

    MessageDialog {
        id: mdNotifyExistedStudent
        buttons: MessageDialog.Yes | MessageDialog.No
        onButtonClicked: (button, role) => {
                             if (button === MessageDialog.Yes) {
                                 mdNotifyExistedStudent.close()
                                 mainWindowForm.tabOverview.rbUpdateStudent.clicked()
                             }
                         }
    }

    mainWindowForm.tabOverview.rbInsertStudent.onClicked: {
        OverviewController.addStudent(
                    mainWindowForm.tabOverview.tfStudentId.text,
                    mainWindowForm.tabOverview.tfStudentLastName.text,
                    mainWindowForm.tabOverview.tfStudentFirstName.text,
                    mainWindowForm.tabOverview.tfStudentClassId.text,
                    mainWindowForm.tabOverview.tfStudentScore.text)
        mainWindowForm.tabOverview.tableViewStudent.selectionModel.clear()
        if (!mdNotifyError.visible && !mdNotifyExistedStudent.visible) {
            mainWindowForm.tabOverview.rbResetForm.clicked()
        }
    }

    mainWindowForm.tabOverview.rbUpdateStudent.onClicked: {
        OverviewController.updateStudent(
                    mainWindowForm.tabOverview.tableViewStudent.selectionModel.currentIndex.row,
                    mainWindowForm.tabOverview.tfStudentId.text,
                    mainWindowForm.tabOverview.tfStudentLastName.text,
                    mainWindowForm.tabOverview.tfStudentFirstName.text,
                    mainWindowForm.tabOverview.tfStudentClassId.text,
                    mainWindowForm.tabOverview.tfStudentScore.text)
        if (!mdNotifyError.visible && !mdNotifyExistedStudent.visible) {
            mainWindowForm.tabOverview.tableViewStudent.selectionModel.clear()
            mainWindowForm.tabOverview.rbResetForm.clicked()
        }
    }

    mainWindowForm.tabOverview.rbResetForm.onClicked: {
        mainWindowForm.tabOverview.tfStudentId.text = qsTr("")
        mainWindowForm.tabOverview.tfStudentLastName.text = qsTr("")
        mainWindowForm.tabOverview.tfStudentFirstName.text = qsTr("")
        mainWindowForm.tabOverview.tfStudentClassId.text = qsTr("")
        mainWindowForm.tabOverview.tfStudentScore.text = qsTr("")
    }

    mainWindowForm.tabOverview.rbRemoveStudent.onClicked: {
        OverviewController.removeStudent(
                    mainWindowForm.tabOverview.tableViewStudent.selectionModel.currentIndex.row)
        mainWindowForm.tabOverview.tableViewStudent.selectionModel.clear()
        mainWindowForm.tabOverview.rbResetForm.clicked()
    }

    mainWindowForm.cbDataStructures.onActivated: index => {
                                                     OverviewController.setStructureType(
                                                         index)
                                                 }

    mainWindowForm.rbImportData.onClicked: {
        fdOpenFile.open()
    }

    mainWindowForm.tabOverview.tfSearchInfoStudent.onTextChanged: {
        OverviewController.searchStudent(
                    mainWindowForm.tabOverview.tfSearchInfoStudent.text)
    }

    mainWindowForm.tabOverview.cbReverseNameStudent.onToggled: {
        OverviewController.sortFilterModel.isReverseFullName
                = mainWindowForm.tabOverview.cbReverseNameStudent.checked
    }
    mainWindowForm.tabOverview.cbFilterInfoStudent.onActivated: function (index) {
        OverviewController.sortFilterModel.filterKeyColumn
                = mainWindowForm.tabOverview.cbFilterInfoStudent.valueAt(index)
    }

    Connections {
        target: OverviewController
        function onErrorOccured(error) {
            mdNotifyError.text = qsTr(error)
            mdNotifyError.open()
        }
        function onExistedStudent(error) {
            mdNotifyExistedStudent.text = qsTr(
                        "Student has id: %1 existed").arg(error)
            mdNotifyExistedStudent.informativeText = qsTr(
                        "Do you want to update this student?")
            mdNotifyExistedStudent.open()
        }

        function onDataProviderChanged() {
            mainWindowForm.tabOverview.rbResetForm.clicked()
        }

        function onRowCountChanged() {
            mainWindowForm.tabOverview.lbTotalRcords.text = qsTr("%1").arg(
                        OverviewController.rowCount)
        }
        function onSearchingTimeChanged(time) {
            mainWindowForm.tabOverview.lbSearchingTime.text = qsTr(
                        "%1 ms").arg(time)
        }
    }

    Connections {
        target: MainWindowController
        function onDataRead(listStudents) {
            OverviewController.getDataFromXlsx(listStudents)
        }
        function onDataReadError(error) {
            mdNotifyError.text = qsTr(error)
            mdNotifyError.open()
        }
    }
}
