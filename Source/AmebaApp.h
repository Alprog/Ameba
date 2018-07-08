
#pragma once

#include <QApplication>
#include <vector>
#include <string>
#include "MainWindow.h"

class AmebaApp : public QApplication
{
    Q_OBJECT

    friend int main(int argc, char *argv[]);

    AmebaApp(int argc, char** argv);

public:
    static AmebaApp* getInstance();
    void saveSettings();
    MainWindow* getMainWindow();

private:
    void start();
    void loadStyle();
    void loadSettings();

private:
    std::vector<MainWindow*> windows;
};
