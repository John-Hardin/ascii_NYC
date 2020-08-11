
//#include "printAnimations.h"
#include "GameLoad.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "printAnimations.h"




using namespace std;

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
	}
}
void GameLoad::draw() {
	if ((player.x == bob.x && player.y == bob.y) || (player.y == karen.y && player.x == karen.x) || (player.y == terry.y && player.x == terry.x)) {
		mapArr[player.y][player.x] = '@';
		for (int i = 0; i < height; i++) {
			cout << mapArr[i] << endl;
		}
	}
	else {
		for (int i = 0; i < height; i++) {
			cout << mapArr[i] << endl;
		}
	}

}
vector<string> GameLoad::logicMovement() {
	switch (_getch()) {
	case 'w':
		if (mapArr[player.y - 1][player.x] == '.') {
			player.py = player.y;
			player.px = player.x;
			player.y--;
			mapArr[player.y][player.x] = '@';
			mapArr[player.py][player.px] = '.';
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
			mapArr[player.y][player.x] = '@';
			mapArr[player.py][player.px] = '.';
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
			mapArr[player.y][player.x] = '@';
			mapArr[player.py][player.px] = '.';
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
			mapArr[player.y][player.x] = '@';
			mapArr[player.py][player.px] = '.';
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
void GameLoad::interaction() {
	default_random_engine randomGenerator((unsigned int)time(NULL));
	uniform_int_distribution<int> diceRoll(1, 4);
	if (player.y == bob.y && player.x == bob.x) {
		mapArr[player.y][player.x] = '@';
		mapArr[bob.pY][bob.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			this->gameOver = true;
			printAnim("mugged_and_died.txt");
			//return 1;
			//TODO create restart function
		}
		else {
			printAnim("mugged_but_survived.txt");
			//return 2;
		}
	}
	if (player.y == karen.y && player.x == karen.x) {
		mapArr[player.y][player.x] = '@';
		mapArr[karen.pY][karen.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			this->gameOver = true;
			printAnim("mugged_and_died.txt");
			//return 3;
		}
		else {
			printAnim("mugged_but_survived.txt");
			//return 4;
		}
	}
	if (player.y == terry.y && player.x == terry.x) {
		mapArr[player.y][player.x] = '@';
		mapArr[terry.pY][terry.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			this->gameOver = true;
			printAnim("mugged_and_died.txt");
			//return 5;
		}
		else {
			printAnim("mugged_but_survived.txt");
			//return 6;
		}
	}
	//return 0;
}
//void GameLoad::echo(int  statement)
//{
//	std::cout << statement << std::endl;
//}
