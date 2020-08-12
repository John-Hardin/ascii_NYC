#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

#include "Game.h"
#include "Level.h"

 void Game::enemyMovement() {
	 std::default_random_engine random((unsigned int)time(NULL));
	 std::uniform_int_distribution<int> eMoveDirection(1, 4);
	 int direction = eMoveDirection(random);
	if (enemyDirection) {

		bob.pX = bob.x;
		bob.pY = bob.y;
		bob.y = bob.y + lastDirection;
		mapArr[bob.y][bob.x] = '%';
		mapArr[bob.pY][bob.pX] = '.';

		karen.pX = karen.x;
		karen.pY = karen.y;
		karen.x = karen.x + lastDirection;
		mapArr[karen.y][karen.x] = '%';
		mapArr[karen.pY][karen.pX] = '.';

		terry.pX = terry.x;
		terry.pY = terry.y;
		terry.x = terry.x - lastDirection;
		mapArr[terry.y][terry.x] = '%';
		mapArr[terry.pY][terry.pX] = '.';
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
		lastDirection = direction;
	}
}
 std::vector<std::string> Game::logicMovement() {
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
 void Game::interaction() {
	std::default_random_engine randomGenerator((unsigned int)time(NULL));
	std::uniform_int_distribution<int> diceRoll(1, 4);
	if (player.y == bob.y && player.x == bob.x) {
		//mapArr[player.y][player.x] = '@';
		//mapArr[bob.pY][bob.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			//TODO uncomment gameOver, all 3
			//gameOver = true;
			printAnim("mugged_and_died.txt");
			//TODO create restart function for when you die
		}
		else {
			
			printAnim("mugged_but_survived.txt");
			//TODO possibly move these print functions out of interaction function, and use a return variable to call print function
		}
	}
	if (player.y == karen.y && player.x == karen.x) {
		//mapArr[player.y][player.x] = '@';
		//mapArr[karen.pY][karen.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			//gameOver = true;
			printAnim("mugged_and_died.txt");
		}
		else {

			printAnim("mugged_but_survived.txt");
		}
	}
	if (player.y == terry.y && player.x == terry.x) {
		//mapArr[player.y][player.x] = '@';
		//mapArr[terry.pY][terry.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			//gameOver = true;
			printAnim("mugged_and_died.txt");
		}
		else {

			printAnim("mugged_but_survived.txt");
		}
	}
}
 void Game::printAnim(std::string fileName) {
	int width = 24;
	int height = 79;

	if (fileName == "mugged_but_survived.txt") {
		std::vector<std::string> animArr;
		std::ifstream animFile;
		animFile.open("mugged_but_survived.txt"); //make these variable placeholder "fileName", insert actual file name 'mugged_but_survived.txt' into function call in interaction()
		if (animFile.fail()) {                      // run if statment to see if (filename == "mugged_but_survived"){ copy/paste  code here from animArr intialization down to Sleep(5200)}
			perror("mugged_but_survived.txt");     //repeat if/else for other file names/animations
		}
		std::string input;
		for (int i = 0; i < width * 4; i++) {
			getline(animFile, input);
			animArr.push_back(input);
		}
		animFile.close();

		for (int i = 0; i < width; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width; i < width * 2; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width * 2; i < width * 3; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width * 3; i < width * 4; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
	}
	else if (fileName == "mugged_and_died.txt") {
		std::vector<std::string> animArr;
		std::ifstream animFile;
		animFile.open("mugged_and_died.txt"); //make these variable placeholder "fileName", insert actual file name 'mugged_but_survived.txt' into function call in interaction()
		if (animFile.fail()) {                      // run if statment to see if (filename == "mugged_but_survived"){ copy/paste  code here from animArr intialization down to Sleep(5200)}
			perror("mugged_and_died.txt");     //repeat if/else for other file names/animations
		}
		std::string input;
		for (int i = 0; i < width * 4; i++) {
			getline(animFile, input);
			animArr.push_back(input);
		}
		animFile.close();

		for (int i = 0; i < width; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width; i < width * 2; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width * 2; i < width * 3; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
		for (int i = width * 3; i < width * 4; i++) {
			std::cout << animArr[i] << std::endl;
			//Sleep(100);
		}
		Sleep(200);
	}
}
