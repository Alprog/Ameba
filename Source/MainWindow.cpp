
#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QFileDialog>
#include <QEvent>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Ameba");
    setWindowIcon(QIcon(":/Images/Icon.png"));
    setWindowOpacity(1);
    //setCentralWidget(documents);
}

MainWindow::~MainWindow()
{
}
