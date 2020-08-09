#include "GameLoad.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "Level.h"
using namespace std;







void GameLoad::playerStartPosition(bool &checkIfLoaded) {
	if (!isLoaded) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mapArr[i][j] == '^') {
					player.x = j;
					player.y = i;
					mapArr[player.y][player.x] = '@';
				}
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (mapArr[i][j] == '%') {
				bob.x = j;
				bob.y = i;
				bob.pX = j;
				bob.pY = i;
				i = height;
				j = width;
			}
		}
	}
	for (int i = bob.y + 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (mapArr[i][j] == '%') {
				karen.x = j;
				karen.y = i;
				karen.pX = j;
				karen.pY = i;
				i = height;
				j = width;
			}
		}
	}
	for (int i = karen.y + 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (mapArr[i][j] == '%') {
				terry.x = j;
				terry.y = i;
				terry.pX = j;
				terry.pY = i;
				i = height;
				j = width;
			}
		}
	}
}

void GameLoad::loadMap() {

	ifstream inputMapFile;
	inputMapFile.open("NewYorkCity.txt");
	if (inputMapFile.fail()) {
		perror("NewYorkCity.txt");
	}
	string input;
	for (int i = 0; i < height; i++) {
		getline(inputMapFile, input);
		mapArr.push_back(input);
	}
	inputMapFile.close();
	
}

void GameLoad::enemyMovement() {




	default_random_engine random((unsigned int)time(NULL));
	uniform_int_distribution<int> eMoveDirection(1, 4);

	int direction = eMoveDirection(random);
	//cout << "direction before if else: " << direction << endl;
	//cout << "lastDirection before if else: " << lastDirection << endl;

	if (enemyDirection) {

		bob.pX = bob.x;
		bob.pY = bob.y;
		bob.y = bob.y + direction;
		mapArr[bob.y][bob.x] = '%';
		mapArr[bob.pY][bob.pX] = '.';


		karen.pX = karen.x;
		karen.pY = karen.y;
		karen.x = karen.x + direction;
		

		mapArr[karen.y][karen.x] = '%';
		mapArr[karen.pY][karen.pX] = '.';

		terry.pX = terry.x;
		terry.pY = terry.y;
		terry.x = terry.x - direction;
		

		mapArr[terry.y][terry.x] = '%';
		mapArr[terry.pY][terry.pX] = '.';


		lastDirection = direction;
		enemyDirection = false;
		//cout << "direction after if statment: " << direction << endl;
		//cout << "lastDirection after if statment: " << lastDirection << endl;

	}
	else {
		bob.pX = bob.x;
		bob.pY = bob.y;
		bob.y = bob.y - lastDirection;

		mapArr[bob.y][bob.x] = '%';
		mapArr[bob.pY][bob.pX] = '.';

		karen.pX = karen.x;
		karen.pY = karen.y;
		karen.x = karen.x - lastDirection;

		mapArr[karen.y][karen.x] = '%';
		mapArr[karen.pY][karen.pX] = '.';

		terry.pX = terry.x;
		terry.pY = terry.y;
		terry.x = terry.x + lastDirection;

		mapArr[terry.y][terry.x] = '%';
		mapArr[terry.pY][terry.pX] = '.';


		enemyDirection = true;
		//cout << "direction after else statment: " << direction << endl;
		//cout << "lastDirection after else statment: " << lastDirection << endl;

	}


}
void GameLoad::draw() {
	for (int i = 0; i < height; i++) {
		cout << mapArr[i] << endl;
	}
}

vector<string> GameLoad::logicMovement() {
	

	switch (_getch()) {
	case 'w':
		if (mapArr[player.y - 1][player.x] == '.') {
			player.py = player.y;
			player.px = player.x;
			player.y--;

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					mapArr[player.y][player.x] = '@';
					mapArr[player.py][player.px] = '.';

				}
			}
			return mapArr;
		}
		else {
			return mapArr;
		}
		break;
	case 's':
		if (mapArr[player.y + 1][player.x] == '.') {
			player.py = player.y;
			player.px = player.x;
			player.y++;

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					mapArr[player.y][player.x] = '@';
					mapArr[player.py][player.px] = '.';

				}
			}
			return mapArr;
		}
		else {
			return mapArr;
		}
		break;
	case 'a':
		if (mapArr[player.y][player.x - 1] == '.') {
			player.py = player.y;
			player.px = player.x;
			player.x--;

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					mapArr[player.y][player.x] = '@';
					mapArr[player.py][player.px] = '.';

				}
			}
			return mapArr;
		}
		else {
			return mapArr;
		}
		break;
	case 'd':
		if (mapArr[player.y][player.x + 1] == '.') {
			player.py = player.y;
			player.px = player.x;
			player.x++;

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					mapArr[player.y][player.x] = '@';
					mapArr[player.py][player.px] = '.';

				}
			}
			return mapArr;
		}
		else {
			return mapArr;
		}
		break;
	case 27:
		gameOver = true;
		break;

	default:
		break;
	}
	return mapArr;
}

bool GameLoad::interaction() {

	default_random_engine randomGenerator((unsigned int)time(NULL));
	uniform_int_distribution<int> diceRoll(1, 4);
	//uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

	if (player.y == bob.y && player.x == bob.x) {
		if (diceRoll(randomGenerator) % 2 == 0) {
			// even roll
			cout << "even roll, you were mugged by bob, game over" << endl;
			gameOver = true;
		}
		else {
			// odd roll
			cout << "odd roll, you were mugged by bob, but you survived" << endl;
		}
	}
	if (player.y == karen.y && player.x == karen.x) {
		if (diceRoll(randomGenerator) % 2 == 0) {
			// even roll
			cout << "even roll, you were mugged by karen, game over" << endl;
			gameOver = true;
		}
		else {
			// odd roll
			cout << "odd roll, you were mugged karen, but you survived" << endl;
		}
	}
	if (player.y == terry.y && player.x == terry.x) {
		if (diceRoll(randomGenerator) % 2 == 0) {
			// even roll
			cout << "even roll, you were mugged by terry, game over" << endl;
			gameOver = true;
		}
		else {
			// odd roll
			cout << "odd roll, you were mugged by terry, but you survived" << endl;
		}
	}

	//if overlap, allow fight, random generate win/loss, print result to screen, 

	//if win fight, do something
	//if notWinFight, set gameOver to true

	return gameOver;



}

void GameLoad::echo(int  statement)
{
	std::cout << statement << std::endl;
}


