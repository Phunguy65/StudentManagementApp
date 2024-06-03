// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include <QApplication>
#include <QIcon>
#include <QQmlApplicationEngine>

void InitApplication();
int main(int argc, char* argv[])
{
    set_qt_environment();

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(u":/asset_imports/StudentManagementAppIcon.png"_qs));

    std::setlocale(LC_COLLATE, "vi_VN.UTF-8");
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/Main/main.qml"_qs);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}

void InitApplication()
{
}
