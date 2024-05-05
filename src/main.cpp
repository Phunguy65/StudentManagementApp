// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "Models/filtercolumnselections.h"
#include "Models/overviewcontroller.h"
#include "Models/sortedmethodselections.h"
#include "Models/storagedstructureselections.h"
#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include <QApplication>
#include <QQmlApplicationEngine>
using namespace Models;
int main(int argc, char *argv[])
{
    set_qt_environment();

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Main/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    qmlRegisterUncreatableType<StoragedStructures>("StoragedStructureSelections", 1, 0, "StoragedStructures",
                                                   "StoragedStructures is a enum class");
    qmlRegisterType<OverviewController>("OverviewControllerQml", 1, 0, "OverviewController");
    qmlRegisterUncreatableType<FilterColumnSelections>("FilterColumnSelections", 1, 0, "FilterColumnSelections",
                                                       "FilterColumnSelections is a enum class");
    qmlRegisterUncreatableType<SortedMethodSelections>("SortedMethodSelections", 1, 0, "SortedMethodSelections",
                                                       "SortedMethodSelections is a enum class");
    engine.load(url);

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
