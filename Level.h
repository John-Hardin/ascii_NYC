#pragma once
//#include "Game.h"
#include <string>
class Level 
{
public:
	Level();
	std::vector <std::string> mapArr;
	struct player {	char x, y, px, py; } player{};
	struct robber { char x, y, pX, pY; } bob{}, karen{}, terry{};
	//static const int width = 79;
	//static const int height = 24;
	
	bool checkIfLoaded = false;
	void saveData();
	void askSave();
	void loadData(std::string fileName);
	void askLoad();
	void initPlayer(int mapHeight, int mapWidth);
	void initEnemies(int mapHeight, int mapWidth);
	void loadMap(std::string fileName, int mapHeight);
	void draw(int mapHeight);
	 
};

