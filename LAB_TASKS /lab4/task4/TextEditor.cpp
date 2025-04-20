#include "TextEditor.h"

TextEditor::TextEditor() {
    text = "";
    undoTop = -1;
    redoTop = -1;
}

void TextEditor::typeText(string input) {
    undoStack[++undoTop] = text;
    text += input;
    redoTop = -1;
}

void TextEditor::deleteChar() {
    if (text.length() > 0) {
        undoStack[++undoTop] = text;
        text = text.substr(0, text.length() - 1);
        redoTop = -1;
    }
    else {
        cout << "Nothing to delete." << endl;
    }
}

void TextEditor::undo() {
    if (undoTop >= 0) {
        redoStack[++redoTop] = text;
        text = undoStack[undoTop--];
    }
    else {
        cout << "Nothing to undo." << endl;
    }
}

void TextEditor::redo() {
    if (redoTop >= 0) {
        undoStack[++undoTop] = text;
        text = redoStack[redoTop--];
    }
    else {
        cout << "Nothing to redo." << endl;
    }
}

void TextEditor::showText() {
    cout << "\nCurrent Text: " << text << endl;
}
