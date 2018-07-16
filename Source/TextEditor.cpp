
#include <TextEditor.h>
#include <QInputMethod>
#include <QPainter.h>
#include <QTextBlock>
#include <AmebaApp.h>

TextEditor::TextEditor(QWidget *parent):
    QTextEdit(parent)
{
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChanged()));
}

TextEditor::~TextEditor()
{
}

bool TextEditor::event(QEvent *e)
{
    if (e->type() == QEvent::Paint)
    {
        auto r = ((QPaintEvent*)e)->rect();
        printf("%i %i %i %i\n", r.left(), r.top(), r.right(), r.bottom());
        fflush(stdout);
    }
    else if (e->type() == QEvent::FocusIn)
    {
        focusInEvent((QFocusEvent*)e);
        return true;
    }
    return QTextEdit::event(e);
}

void TextEditor::inputMethodEvent(QInputMethodEvent* e)
{
    QTextEdit::inputMethodEvent(e);
}

void TextEditor::focusInEvent(QFocusEvent* e)
{
    QTextEdit::focusInEvent(e);
}

void TextEditor::paintEvent(QPaintEvent* e)
{
    const int iconSize = 32;

    QTextEdit::paintEvent(e);

    auto textCursor = this->textCursor();
    auto selectionDelta = textCursor.position() - textCursor.anchor();
    if (selectionDelta == 0)
    {
        return;
    }

    auto anchorCursor = textCursor;
    anchorCursor.setPosition(textCursor.anchor());

    auto inverted = selectionDelta < 0;

    auto leftHandleRect = cursorRect(inverted ? textCursor : anchorCursor);
    auto rightHandleRect = cursorRect(inverted ? anchorCursor : textCursor);

    QPixmap leftIcon(":/Images/LeftHandle.png");
    QPixmap rightIcon(":/Images/RightHandle.png");
    QPainter painter(viewport());
    painter.drawPixmap(leftHandleRect.left() - iconSize, leftHandleRect.bottom(), iconSize, iconSize, leftIcon);
    painter.drawPixmap(rightHandleRect.left(), rightHandleRect.bottom(), iconSize, iconSize, rightIcon);
    painter.end();
}

void TextEditor::mousePressEvent(QMouseEvent* e)
{
    QTextEdit::mousePressEvent(e);

    /*QTextCursor cursor(textCursor());
    cursor.select(QTextCursor::WordUnderCursor);
    setTextCursor(cursor);*/

    //this->setFocus();

    //AmebaApp::inputMethod()->show();
    viewport()->repaint();
}

void TextEditor::mouseMoveEvent(QMouseEvent* e)
{
    //QTextEdit::mouseMoveEvent(e);
}

void TextEditor::mouseReleaseEvent(QMouseEvent* e)
{
    QTextEdit::mouseReleaseEvent(e);
    viewport()->repaint();
}

void TextEditor::onCursorPositionChanged()
{
    viewport()->repaint();
}
