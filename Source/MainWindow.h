
#pragma once
#include <QMainWindow>
#include <TextEditor.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void onButtonClicked();

private:
    TextEditor* textEditor;
};
