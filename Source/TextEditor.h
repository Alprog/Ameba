
#pragma once
#include <QTextEdit>

class TextEditor : public QTextEdit
{
    Q_OBJECT

public:
    TextEditor(QWidget* parent = 0);
    ~TextEditor();

protected:
    bool event(QEvent* e) override;
    void focusInEvent(QFocusEvent* e) override;
    void paintEvent(QPaintEvent* e) override;
    void mousePressEvent(QMouseEvent* e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void mouseReleaseEvent(QMouseEvent* e) override;
    void inputMethodEvent(QInputMethodEvent* e) override;

private slots:
    void onCursorPositionChanged();
};
