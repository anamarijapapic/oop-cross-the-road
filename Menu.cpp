/*
    [OP] - FINALNI PROJEKT: Console ASCII igre - Cross the Road
    @file Menu.cpp
    @author Anamarija Papic
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Menu.hpp"
using namespace std;

void Menu::color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

bool Menu::DisplayMenu() {
    char key;
    do {
        system("cls");
        PrintWelcomeMessage();
        color(menuChoice[0]); cout << "\t\t\t\t\t\t\tSTART" << endl;
        color(menuChoice[1]); cout << "\t\t\t\t\t\t\tINSTRUCTIONS" << endl;
        color(menuChoice[2]); cout << "\t\t\t\t\t\t\tCREDITS" << endl;
        color(menuChoice[3]); cout << "\t\t\t\t\t\t\tEXIT" << endl;
        color(WHITE);

        key = _getch();

        if (key == KEY_UP && selected > 1) selected--;
        if (key == KEY_DOWN && selected < 4) selected++;

        menuChoice[0] = menuChoice[1] = menuChoice[2] = menuChoice[3] = WHITE;
        menuChoice[selected - 1] = AQUA;

        if (key == KEY_ENTER) {
            switch (selected) {
            case 1:
                return true;
                break;
            case 2:
                ShowInstructions();
                break;
            case 3:
                ShowCredits();
                break;
            case 4:
                exit(0);
                break;
            }
        }
    } while (true);
}

void Menu::PrintWelcomeMessage() {
    color(BLUE);
    cout << "                   _ _ _     _                      _          _   _                            " << endl;
    cout << "                  | | | |___| |___ ___ _____ ___   | |_ ___   | |_| |_ ___    ___ ___ _____ ___ " << endl;
    cout << "                  | | | | -_| |  _| . |     | -_|  |  _| . |  |  _|   | -_|  | . | .'|     | -_|" << endl;
    cout << "                  |_____|___|_|___|___|_|_|_|___|  |_| |___|  |_| |_|_|___|  |_  |__,|_|_|_|___|" << endl;
    cout << "                                                                             |___|              " << endl;
    color(YELLOW);
    cout << " _______  ______    _______  _______  _______    _______  __   __  _______    ______    _______  _______  ______ " << endl;
    cout << "|       ||    _ |  |       ||       ||       |  |       ||  | |  ||       |  |    _ |  |       ||   _   ||      |" << endl;
    cout << "|       ||   | ||  |   _   ||  _____||  _____|  |_     _||  |_|  ||    ___|  |   | ||  |   _   ||  |_|  ||  _    |" << endl;
    cout << "|       ||   |_||_ |  | |  || |_____ | |_____     |   |  |       ||   |___   |   |_||_ |  | |  ||       || | |   |" << endl;
    cout << "|      _||    __  ||  |_|  ||_____  ||_____  |    |   |  |       ||    ___|  |    __  ||  |_|  ||       || |_|   |" << endl;
    cout << "|     |_ |   |  | ||       | _____| | _____| |    |   |  |   _   ||   |___   |   |  | ||       ||   _   ||       |" << endl;
    cout << "|_______||___|  |_||_______||_______||_______|    |___|  |__| |__||_______|  |___|  |_||_______||__| |__||______| " << endl << endl << endl;
    color(WHITE);
}

void Menu::ShowInstructions() {
    system("cls");
    color(PURPLE);
    cout << "  ___           _                   _   _                     " << endl;
    cout << " |_ _|_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___   _ " << endl;
    cout << "  | || '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __| (_)" << endl;
    cout << "  | || | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\  _ " << endl;
    cout << " |___|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/ (_)" << endl << endl;
    color(WHITE);
    cout << "CONTROLS:" << endl;
    cout << "Use arrow keys to move:" << endl;
    cout << "\t* Press right arrow key to move right" << endl;
    cout << "\t* Press left arrow key to move left" << endl;
    cout << "\t* Press up arrow key to move up" << endl;
    cout << "\t* Press down arrow key to move down" << endl;
    cout << "Press p to pause the game" << endl;
    cout << "Press escape key (Esc) to end the game" << endl << endl;
    cout << "Return to menu:" << endl;
    system("pause");
}

void Menu::ShowCredits() {
    system("cls");
    color(GREEN);
    cout << "                 ____              _ _ _           " << endl;
    cout << "                / ___|_ __ ___  __| (_) |_ ___   _ " << endl;
    cout << "               | |   | '__/ _ \\/ _` | | __/ __| (_)" << endl;
    cout << "               | |___| | |  __/ (_| | | |_\\__ \\  _ " << endl;
    cout << "                \\____|_|  \\___|\\__,_|_|\\__|___/ (_)" << endl << endl;
    color(WHITE);
    cout << "   ___                            _   _        ___            _    " << endl;
    cout << "  / _ | ___  ___ ___ _  ___ _____(_) (_)__ _  / _ \\___ ____  (_)_//" << endl;
    cout << " / __ |/ _ \\/ _ `/  ' \\/ _ `/ __/ / / / _ `/ / ___/ _ `/ _ \\/ / __/" << endl;
    cout << "/_/ |_/_//_/\\_,_/_/_/_/\\_,_/_/ /_/_/ /\\_,_/ /_/   \\_,_/ .__/_/\\__/ " << endl;
    cout << "                                |___/                /_/           " << endl << endl;
    cout << "               SRC119 - Object Oriented Programming" << endl;
    cout << "University of Split - University Department of Professional Studies" << endl;
    cout << "                         January 2022." << endl << endl;
    cout << "Return to menu:" << endl;
    system("pause");
}