#pragma once
#include <iostream>
using namespace std;

class TextEditor {
private:
    string text;
    string undoStack[100];
    string redoStack[100];
    int undoTop;
    int redoTop;

public:
    TextEditor();

    void typeText(string input);
    void deleteChar();
    void undo();
    void redo();
    void showText();
};
