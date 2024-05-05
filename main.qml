/* This file is generated and only relevant for integrating the project into a Qt 6 and cmake based
C++ project. */

import QtQuick 6.6
import content
import StoragedStructureSelections 1.0
import FilterColumnSelections 1.0
import SortedMethodSelections 1.0
MainWindow{

id: mainApp
mainWindowForm.cbDataStructures.textRole: "storagedStructureSelection"

mainWindowForm.cbDataStructures.model: ListModel {
    ListElement {
        storagedStructureSelection: "Storage By Array"
        value: StoragedStructures.Vector
    }
    ListElement {
        storagedStructureSelection: "Storage By Single Linked List"
        value: StoragedStructures.SList
    }
    ListElement {
        storagedStructureSelection: "Storage By Double Linked List"
        value: StoragedStructures.DList
    }
    ListElement {
        storagedStructureSelection: "Storage By Circular Linked List"
        value: StoragedStructures.CList
    }
}

mainWindowForm.tabOverview.cbFilterInfoStudent.textRole: "filterColumn"

mainWindowForm.tabOverview.cbFilterInfoStudent.model: ListModel {
    ListElement {
        filterColumn: "Filter By Id Student"
        value: FilterColumnSelections.IdStudent
    }
    ListElement {
        filterColumn: "Filter By Last Name"
        value: FilterColumnSelections.LastName
    }
    ListElement {
        filterColumn: "Filter By First Name"
        value: FilterColumnSelections.FirstName
    }
    ListElement {
        filterColumn: "Filter By Id Class"
        value: FilterColumnSelections.IdClass
    }
}

mainWindowForm.tabOverview.cbSortedMethods.textRole: "sortedMethod"

mainWindowForm.tabOverview.cbSortedMethods.model: ListModel {
    ListElement {
        sortedMethod: "Insertion Sort"
        value: SortedMethodSelections.InsertionSort
    }
    ListElement {
        sortedMethod: "Selection Sort"
        value: SortedMethodSelections.SelectionSort
    }
    ListElement {
        sortedMethod: "Bubble Sort"
        value: SortedMethodSelections.BubbleSort
    }
    ListElement {
        sortedMethod: "Quick Sort"
        value: SortedMethodSelections.QuickSort
    }
    ListElement {
        sortedMethod: "Heap Sort"
        value: SortedMethodSelections.HeapSort
    }
    ListElement {
        sortedMethod: "Merge Sort"
        value: SortedMethodSelections.MergeSort}
}

mainWindowForm.tabOverview.rbSearchInfoStudent.icon.source: "qrc:/asset_imports/searchIcon.png"
mainWindowForm.tabOverview.rbSearchInfoStudent.icon.color: "black"
mainWindowForm.tabOverview.rbInsertStudent.icon.source: "qrc:/asset_imports/adduserIcon.png"
mainWindowForm.tabOverview.rbInsertStudent.icon.color: "white"
mainWindowForm.tabOverview.rbUpdateStudent.icon.source: "qrc:/asset_imports/edituserIcon.png"
mainWindowForm.tabOverview.rbUpdateStudent.icon.color: "pink"
mainWindowForm.tabOverview.rbRemoveStudent.icon.source: "qrc:/asset_imports/removeuserIcon.png"
mainWindowForm.tabOverview.rbRemoveStudent.icon.color: "orange"
}


