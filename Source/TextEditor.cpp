
#include <TextEditor.h>

TextEditor::TextEditor(QWidget *parent):
    QTextEdit(parent)
{
}

TextEditor::~TextEditor()
{
}

void TextEditor::mousePressEvent(QMouseEvent *e)
{
    QTextEdit::mousePressEvent(e);

    QTextCursor cursor(textCursor());
    cursor.select(QTextCursor::WordUnderCursor);
    setTextCursor(cursor);
}

void TextEditor::mouseReleaseEvent(QMouseEvent *e)
{
    QTextEdit::mouseReleaseEvent(e);
}
