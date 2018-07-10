
#include <TextEditor.h>
#include <QInputMethod>
#include <AmebaApp.h>

TextEditor::TextEditor(QWidget *parent):
    QTextEdit(parent)
{
}

TextEditor::~TextEditor()
{
}

bool TextEditor::event(QEvent *e)
{
    if (e->type() == QEvent::FocusIn)
    {
        focusInEvent((QFocusEvent*)e);
        return true;
    }
    return QTextEdit::event(e);
}

void TextEditor::inputMethodEvent(QInputMethodEvent *e)
{
    QTextEdit::inputMethodEvent(e);
}

void TextEditor::focusInEvent(QFocusEvent *e)
{
    QTextEdit::focusInEvent(e);
}

void TextEditor::mousePressEvent(QMouseEvent *e)
{
    QTextEdit::mousePressEvent(e);

    /*QTextCursor cursor(textCursor());
    cursor.select(QTextCursor::WordUnderCursor);
    setTextCursor(cursor);*/

    //this->setFocus();

    //AmebaApp::inputMethod()->show();
}

void TextEditor::mouseMoveEvent(QMouseEvent *e)
{
    //QTextEdit::mouseMoveEvent(e);
}

void TextEditor::mouseReleaseEvent(QMouseEvent *e)
{
    QTextEdit::mouseReleaseEvent(e);
}
