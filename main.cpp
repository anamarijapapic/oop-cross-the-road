/*
	[OP] - FINALNI PROJEKT: Console ASCII igre - Cross the Road
	@file main.cpp
	@author Anamarija Papic
*/

#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <deque>
#include <vector>
#include <ctime>
#include "Menu.hpp"
#define WIDTH 30
#define HEIGHT 5
using namespace std;

void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Player {
public:
	int x, y;
	Player() { x = WIDTH / 2; y = 0; }
};

class RoadLane {
	deque<bool> obstacles;
	bool right;
public:
	RoadLane() {
		for (int i = 0; i < WIDTH; i++)
			obstacles.push_front(true);
		right = rand() % 2;
	}

	void Move() {
		if (right) {
			if (rand() % 10 == 1)
				obstacles.push_front(true);
			else
				obstacles.push_front(false);
			obstacles.pop_back();
		}
		else {
			if (rand() % 10 == 1)
				obstacles.push_back(true);
			else
				obstacles.push_back(false);
			obstacles.pop_front();
		}

	}

	bool CheckPosition(int position) { return obstacles[position]; }

	void ChangeDirection() { right = !right; }
};

class Game {
	bool quit;
	int numberOfRoadLanes;
	int width;
	int level;
	int score;
	int highscore;
	Player* player;
	vector<RoadLane*> roads;
public:
	Game() {
		quit = false;
		numberOfRoadLanes = HEIGHT;
		width = WIDTH;
		level = 1;
		score = 0;
		highscore = 0;
		ifstream ifile;
		ifile.open("Highscore.txt");
		if (ifile.is_open()) {
			while (!ifile.eof()) {
				ifile >> highscore;
			}
		}
		ifile.close();
		for (int i = 0; i < numberOfRoadLanes; i++)
			roads.push_back(new RoadLane());
		player = new Player();
	}

	~Game() {
		delete player;
		for (size_t i = 0; i < roads.size(); i++) {
			RoadLane* current = roads.back();
			roads.pop_back();
			delete current;
		}
	}

	void Input() {
		if (_kbhit()) {
			mciSendString(TEXT("play Sound.wav"), NULL, 0, NULL);
			int ch;
			switch ((ch = _getch())) {
			case KEY_UP:
				if (player->y > 0)
					player->y--;
				break;
			case KEY_DOWN:
				if (player->y < numberOfRoadLanes)
					player->y++;
				break;
			case KEY_LEFT:
				if (player->x > 0)
					player->x--;
				break;
			case KEY_RIGHT:
				if (player->x < WIDTH - 1)
					player->x++;
				break;
			case KEY_ESC:
				quit = true;
				break;
			case 'p':
				system("pause");
				break;
			default:
				break;
			}
		}
	}

	void Display() {
		system("cls");
		cout << "LEVEL: " << level << endl;
		cout << "SCORE: " << score << "\tHIGHSCORE: " << highscore << endl << endl;
		for (int i = 0; i < numberOfRoadLanes; i++) {
			if (i == 0) cout << "  S     T     A     R     T  " << endl;
			else cout << "______________________________" << endl;
			for (int j = 0; j < width; j++) {
				if (roads[i]->CheckPosition(j) && i != 0 && i != numberOfRoadLanes - 1) {
					color(rand() % 6 + 1);
					cout << "X";
					color(WHITE);
				}
				else if (player->x == j && player->y == i)
					cout << "O";
				else
					cout << " ";
			}
			cout << endl;
		}
		cout << "    F   I   N   I   S   H    " << endl << endl;
	}

	void Logic() {
		for (int i = 1; i < numberOfRoadLanes - 1; i++) {
			if (rand() % 10 == 1)
				roads[i]->Move();
			if (roads[i]->CheckPosition(player->x) && player->y == i) {
				quit = true;
			}
		}

		if (player->y == numberOfRoadLanes - 1) {
			score++;
			if (score % 5 == 0) {
				mciSendString(TEXT("play Levelup.wav"), NULL, 0, NULL);
				level++;
				roads.push_back(new RoadLane());
				numberOfRoadLanes++;
			}

			if (score > highscore)
				highscore = score;

			player->y = 0;
			mciSendString(TEXT("play Score.wav"), NULL, 0, NULL);
			roads[rand() % numberOfRoadLanes]->ChangeDirection();
		}
	}

	void Run() {
		while (!quit) {
			Input();
			Display();
			Logic();
		}

		ofstream ofile;
		ofile.open("Highscore.txt");
		if (ofile.is_open())
			ofile << highscore;
		ofile.close();

		mciSendString(TEXT("play Gameover.wav"), NULL, 0, NULL);
		color(RED);
		cout << " _______  _______  __   __  _______    _______  __   __  _______  ______    __  " << endl;
		cout << "|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  |  | " << endl;
		cout << "|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  |  | " << endl;
		cout << "|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ |  | " << endl;
		cout << "|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  ||__| " << endl;
		cout << "|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | __  " << endl;
		cout << "|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_||__| " << endl << endl;
		color(WHITE);
	}
};

int main() {
	SetConsoleTitle(TEXT("Cross the Road Game"));
	mciSendString(TEXT("play Background.mp3 repeat"), NULL, 0, NULL);
	srand((unsigned)time(NULL));
	Menu menu;
	menu.DisplayMenu();
	char choice;
	do {
		Game game;
		game.Run();
		cout << "Do you want to play again? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
	return 0;
}