
#include "AmebaApp.h"
#include <QFile>
#include <QTextStream>
#include "MainWindow.h"

AmebaApp::AmebaApp(int argc, char** argv):
    QApplication(argc, argv)
{
    if (fileno(stdout) <= 0)
    {
        freopen("log.txt", "w", stdout);
    }

    loadStyle();
    loadSettings();
    start();
}

AmebaApp* AmebaApp::getInstance()
{
    return static_cast<AmebaApp*>(QApplication::instance());
}

void AmebaApp::loadStyle()
{
    QFile file("style.css");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString sheet = stream.readAll();
        setStyleSheet(sheet);
    }
    file.close();
}

void AmebaApp::loadSettings()
{
    /*auto fileName = getSettingsFilename();
    QFile file(QString::fromStdString(fileName));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        auto text = stream.readAll().toStdString();
        settings = serializer.deserialize(text);
        file.close();
    }*/
}

void AmebaApp::saveSettings()
{
    /*auto fileName = getSettingsFilename();
    QFile file(QString::fromStdString(fileName));
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    auto text = serializer.serialize(settings);
    stream << tr(text.c_str());
    file.close();*/
}

void AmebaApp::start()
{
    auto mainWindow = new MainWindow();
    mainWindow->resize(800, 600);
    mainWindow->show();
    windows.push_back(mainWindow);
}

MainWindow* AmebaApp::getMainWindow()
{
    return windows[0];
}
