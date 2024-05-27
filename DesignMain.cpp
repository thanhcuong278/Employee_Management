#include "DesignMain.h"
#include <iostream>

void setFullScreen() {
    HWND consoleWindow = GetConsoleWindow(); // Lấy handle của cửa sổ console
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void clearScreen() {
    system("cls");
}

void setConsoleColor(WORD attributes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attributes);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void centerAlign(const std::string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int spaces = (columns - text.length()) / 2;

    gotoXY(spaces, csbi.dwCursorPosition.Y);
    std::cout << text << std::endl;
}

void centerAlignChoicePrompt() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int spaces = columns / 2 - 1; 
    gotoXY(spaces, csbi.dwCursorPosition.Y);
}