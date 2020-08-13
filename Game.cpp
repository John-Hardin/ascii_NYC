#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "Level.h"
#include "Game.h"


Game::Game() {
	level.askLoad();
	level.loadMap("NewYorkCity.txt", 24);
	level.loadData("savedgame.dat");
	level.initEnemies(24, 79);
	level.initPlayer(24, 79);
	
}
void Game::playGame(bool &over) {
	while (over == false) {
		level.draw(24);
		logicMovement();
		enemyMovement();
		interaction();
	}
	level.askSave();

}

 void Game::enemyMovement() {
	 std::default_random_engine random((unsigned int)time(NULL));
	 std::uniform_int_distribution<int> eMoveDirection(1, 4);
	 int direction = eMoveDirection(random);
	if (enemyDirection) {

		level.bob.pX = level.bob.x;
		level.bob.pY = level.bob.y;
		level.bob.y = level.bob.y + lastDirection;
		level.mapArr[level.bob.y][level.bob.x] = '%';
		level.mapArr[level.bob.pY][level.bob.pX] = '.';

		level.karen.pX = level.karen.x;
		level.karen.pY = level.karen.y;
		level.karen.x = level.karen.x + lastDirection;
		level.mapArr[level.karen.y][level.karen.x] = '%';
		level.mapArr[level.karen.pY][level.karen.pX] = '.';

		level.terry.pX = level.terry.x;
		level.terry.pY = level.terry.y;
		level.terry.x = level.terry.x - lastDirection;
		level.mapArr[level.terry.y][level.terry.x] = '%';
		level.mapArr[level.terry.pY][level.terry.pX] = '.';
		enemyDirection = false;
	}
	else {
		level.bob.pX = level.bob.x;
		level.bob.pY = level.bob.y;
		level.bob.y = level.bob.y - lastDirection;
		level.mapArr[level.bob.y][level.bob.x] = '%';
		level.mapArr[level.bob.pY][level.bob.pX] = '.';


		level.karen.pX = level.karen.x;
		level.karen.pY = level.karen.y;
		level.karen.x = level.karen.x - lastDirection;
		level.mapArr[level.karen.y][level.karen.x] = '%';
		level.mapArr[level.karen.pY][level.karen.pX] = '.';

		level.terry.pX = level.terry.x;
		level.terry.pY = level.terry.y;
		level.terry.x = level.terry.x + lastDirection;
		level.mapArr[level.terry.y][level.terry.x] = '%';
		level.mapArr[level.terry.pY][level.terry.pX] = '.';
		enemyDirection = true;
		lastDirection = direction;
	}
}
 std::vector<std::string> Game::logicMovement() {
	switch (_getch()) {
	case 'w':
		if (level.mapArr[level.player.y - 1][level.player.x] == '.') {
			level.player.py = level.player.y;
			level.player.px = level.player.x;
			level.player.y--;
			level.mapArr[level.player.y][level.player.x] = '@';
			level.mapArr[level.player.py][level.player.px] = '.';
			return level.mapArr;
		}
		else {
			return level.mapArr;
		}
		break;
	case 's':
		if (level.mapArr[level.player.y + 1][level.player.x] == '.') {
			level.player.py = level.player.y;
			level.player.px = level.player.x;
			level.player.y++;
			level.mapArr[level.player.y][level.player.x] = '@';
			level.mapArr[level.player.py][level.player.px] = '.';
			return level.mapArr;
		}
		else {
			return level.mapArr;
		}
		break;
	case 'a':
		if (level.mapArr[level.player.y][level.player.x - 1] == '.') {
			level.player.py = level.player.y;
			level.player.px = level.player.x;
			level.player.x--;
			level.mapArr[level.player.y][level.player.x] = '@';
			level.mapArr[level.player.py][level.player.px] = '.';
			return level.mapArr;
		}
		else {
			return level.mapArr;
		}
		break;
	case 'd':
		if (level.mapArr[level.player.y][level.player.x + 1] == '.') {
			level.player.py = level.player.y;
			level.player.px = level.player.x;
			level.player.x++;
			level.mapArr[level.player.y][level.player.x] = '@';
			level.mapArr[level.player.py][level.player.px] = '.';
			return level.mapArr;
		}
		else {
			return level.mapArr;
		}
		break;
	case 27:
		gameOver = true;
		break;
	default:
		break;
	}
	return level.mapArr;
}
 void Game::interaction() {
	std::default_random_engine randomGenerator((unsigned int)time(NULL));
	std::uniform_int_distribution<int> diceRoll(1, 4);
	if (level.player.y == level.bob.y && level.player.x == level.bob.x) {
		//level.mapArr[level.player.y][level.player.x] = '@';
		//level.mapArr[level.bob.pY][level.bob.pX] = '%';
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
	if (level.player.y == level.karen.y && level.player.x == level.karen.x) {
		//level.mapArr[level.player.y][level.player.x] = '@';
		//level.mapArr[level.karen.pY][level.karen.pX] = '%';
		if (diceRoll(randomGenerator) % 2 == 0) {
			//gameOver = true;
			printAnim("mugged_and_died.txt");
		}
		else {

			printAnim("mugged_but_survived.txt");
		}
	}
	if (level.player.y == level.terry.y && level.player.x == level.terry.x) {
		//level.mapArr[level.player.y][level.player.x] = '@';
		//level.mapArr[level.terry.pY][level.terry.pX] = '%';
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
		}
		Sleep(200);
		for (int i = width; i < width * 2; i++) {
			std::cout << animArr[i] << std::endl;
		}
		Sleep(200);
		for (int i = width * 2; i < width * 3; i++) {
			std::cout << animArr[i] << std::endl;
		}
		Sleep(200);
		for (int i = width * 3; i < width * 4; i++) {
			std::cout << animArr[i] << std::endl;
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
		}
		Sleep(200);
		for (int i = width; i < width * 2; i++) {
			std::cout << animArr[i] << std::endl;
		}
		Sleep(200);
		for (int i = width * 2; i < width * 3; i++) {
			std::cout << animArr[i] << std::endl;
		}
		Sleep(200);
		for (int i = width * 3; i < width * 4; i++) {
			std::cout << animArr[i] << std::endl;
		}
		Sleep(200);
	}
}
