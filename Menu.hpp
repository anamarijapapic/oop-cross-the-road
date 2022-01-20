/*
    [OP] - FINALNI PROJEKT: Console ASCII igre - Cross the Road
    @file Menu.hpp
    @author Anamarija Papic
*/

#pragma once
#define BLUE 1
#define GREEN 2
#define AQUA  3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

class Menu {
    int menuChoice[4] = { AQUA, WHITE, WHITE, WHITE };
    int selected = 1;
public:
    void color(int color);
    bool DisplayMenu();
    void PrintWelcomeMessage();
    void ShowInstructions();
    void ShowCredits();
};