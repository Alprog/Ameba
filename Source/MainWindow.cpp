
#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QFileDialog>
#include <QEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Ameba");
    setWindowIcon(QIcon(":/Images/Icon.png"));
    setWindowOpacity(1);


    auto layout = new QVBoxLayout();
    {
        layout->setMargin(0);

        auto hLayout = new QHBoxLayout();
        {
            hLayout->setMargin(0);

            button = new QPushButton("Button");

            button->setIcon(QIcon());
            button->setMaximumSize(300, 130);
            hLayout->addWidget(button);
            connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

            hLayout->addWidget(new QWidget);
        }
        layout->addLayout(hLayout);

        textEditor = new TextEditor(nullptr);
        layout->addWidget(textEditor);
    }

    button->setFocusProxy(textEditor);

    auto widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonClicked()
{
    printf("%i\n", textEditor->textCursor().position());

    QTextCursor cursor(textEditor->textCursor());
    cursor.select(QTextCursor::WordUnderCursor);
    textEditor->setTextCursor(cursor);
    //textEditor->setFocus();
}
