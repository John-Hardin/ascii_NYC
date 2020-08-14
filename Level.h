#pragma once
//#include "Game.h"
#include <string>
#include "Player.h"
//#include "Game.h"

class Level 
{

public:
	Level();

	void loadMap(std::string fileName, int mapW, int mapH);
	void drawLevel(int mapH, int mapW);
	
	std::vector <std::string> _levelData;
	//void load(std::string map, std::string savedFile, int mapHeight, int mapWidth);
	//void processLevel(std::vector <std::string> _levelData, Player& player);

	//void save(Player &playerSave);

private:
};

