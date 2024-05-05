// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.6
import StudentManagement

Window {
    id: mainWindow
    width: mainWindowForm.width
    height: mainWindowForm.height
    visible: true
    property alias mainWindowForm: mainWindowForm
    title: "StudentManagement"
MainWindowForm {
        id: mainWindowForm
        anchors.fill: parent
    }

}
