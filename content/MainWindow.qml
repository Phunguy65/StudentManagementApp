// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.6
import StudentManagement

Window {
    width: mainWindow.width
    height: mainWindow.height

    visible: true
    title: "StudentManagement"

    MainWindowForm {
        id: mainWindow
        anchors.fill: parent
    }

}

