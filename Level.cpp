#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
//#include "Game.h"  note-- commented out
#include "Level.h"
#include "Player.h"
#include <conio.h>
#include "Enemy.h"
#include <cstdio>


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
			case 'C': //Crook
				_enemies.push_back(Enemy("Crook", tile, 3, 7, 7, 7, 7));
				_enemies.back().setPosition(c, i);
				break;
			case 'R': //Robber
				_enemies.push_back(Enemy("Robber", tile, 6, 6, 6, 6, 8));
				_enemies.back().setPosition(c, i);

				break;
			case 'H'://Hobo
				_enemies.push_back(Enemy("Hobo", tile, 9, 19, 50, 9, 9));
				_enemies.back().setPosition(c, i);

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
void Level::updateEnemies(Player& player) {
	char aiMove;
	int playerX, playerY, enemyX, enemyY;
	player.getPosition(playerX, playerY);

	for (int c = 0; c < _enemies.size(); c++){
		aiMove = _enemies[c].getAiMove(playerX, playerY);
		_enemies[c].getPosition(enemyX, enemyY);
		switch (aiMove) {
		case 'w'://up
			processEnemyMove(player, c, enemyX, enemyY - 1);
			break;
		case 's'://down
			processEnemyMove(player, c, enemyX, enemyY + 1);
			break;
		case 'a'://left
			processEnemyMove(player, c, enemyX - 1, enemyY);
			break;
		case 'd'://right
			processEnemyMove(player, c, enemyX + 1, enemyY);
			break;
		default:
			break;
		}
	}

}




//TODO-- read breadth-first search algorithm to make a maximum view radius or something so enemies can't see through walls.
void Level::battleEnemy(Player& player, int targetX, int targetY) {
	int enemyX, enemyY, attackRoll, attackResult, playerX, playerY;
	std::string enemyName;
	player.getPosition(playerX, playerY);

	for (int c = 0; c < _enemies.size(); c++) {
		_enemies[c].getPosition(enemyX, enemyY);
		enemyName = _enemies[c].getName();
		if (targetX == enemyX && targetY == enemyY) {

			//Battle
			attackRoll = player.attack();
			printf("Player attacked %s with %d\n", enemyName.c_str(), attackRoll);
			attackResult = _enemies[c].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, ' ');
				drawLevel(24, 79);
				printf("Monster died!\n");
				_enemies[c] = _enemies.back();//remove enemies from array
				_enemies.pop_back();          // ..
				c--;
				system("PAUSE");
				player.addExperience(attackResult);
				
				return;
			}
			//monster turn
			attackRoll = _enemies[c].attack();
			attackResult = player.takeDamage(attackRoll);
			printf("%s attacked player with %d\n", enemyName.c_str(), attackRoll);
			if (attackResult != 0) {
				setTile(playerX, playerY, 'X');
				drawLevel(24, 79);
				printf("You died!\n");
				system("PAUSE");
				exit(0);	
			}
			system("PAUSE");

			return;
		}
	}
}



