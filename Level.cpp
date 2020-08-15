#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include "Level.h"
#include "Player.h"
#include <conio.h>

Level::Level() {

}
void Level::loadMap(std::string fileName, int mapH, int mapW, Player& player) {
	//loads map
	std::ifstream inputMapFile;
	inputMapFile.open(fileName.c_str());
	if (inputMapFile.fail()) {
		perror(fileName.c_str());
	}
	std::string input;
	for (int i = 0; i < mapH; i++) {
		std::getline(inputMapFile, input);
		_levelData.push_back(input);
	}
	inputMapFile.close();
	//process level
	char tile;
	for (int i = 0; i < mapH; i++) {
		for (int c = 0; c < mapW; c++) {
			tile = _levelData[i][c];
			switch (tile) {
			case '@':
				player.setPosition(c, i);
				//("p_x= %d, p_y=%d,\n", player._x, player._y);
				break;
			}
		}
	}
}
void Level::drawLevel(int mapH, int mapW) {
	for (int i = 0; i < mapH; i++) {
		std::cout << _levelData[i] << std::endl;
	}
}
char Level::getTile(int &x, int &y) {
	return _levelData[y][x];
}
void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}
void Level::movePlayer(char input, Player &player) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	//player.getPosition(playerX, playerY);
	switch (input) {
	case 'w'://up
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's'://down
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a'://left
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd'://right
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		break;
	}
}
void Level::processPlayerMove(Player &player, int targetX, int targetY) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	//printf("p_x= %d, p_y=%d,\n pX= %d, pY=%d,\n tX=%d, tY=%d\n from before switch ^\n", player._x, player._y, playerX, playerY, targetX, targetY);
	char movetile = getTile(targetX, targetY);
	switch (movetile) {
	case '.':
		player.setPosition(targetX, targetY);
		//printf("p_x= %d, p_y=%d,\n pX= %d, pY=%d,\n tX=%d, tY=%d\n inside switch ^\n", player._x, player._y,playerX, playerY, targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	default:
		break;
	}

}



