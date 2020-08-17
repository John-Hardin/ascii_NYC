#pragma once
//#include "Game.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"
//#include "Game.h"

class Level 
{

public:
	//constructor
	Level();
	
	//getters
	char getTile(int &x, int &y);
	//setters
	void setTile(int x, int y, char tile);


	void loadMap(std::string fileName, int mapH, int mapW, Player& player);
	void drawLevel(int mapH, int mapW);
	void movePlayer(char input, Player& player);
	void processPlayerMove(Player& player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void updateEnemies(Player& player);

private:
	std::vector <std::string> _levelData;
	std::vector<Enemy> _enemies;
	void battleEnemy(Player &player, int targetX, int targetY);

};

