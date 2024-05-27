#ifndef DESIGN_H
#define DESIGN_H
#include <string>
#include <windows.h>

void setFullScreen();

void clearScreen();

// void setConsoleColor(WORD attributes);
void setConsoleBackgroundColor(WORD backgroundColor);

void gotoXY(int x, int y);

void centerAlign(const std::string& text);

void centerAlignChoicePrompt();

#endif