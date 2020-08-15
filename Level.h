#pragma once
//#include "Game.h"
#include <string>
#include <vector>
#include "Player.h"
//#include "Game.h"

class Level 
{

public:
	Level();
	
	//getters
	char getTile(int &x, int &y);
	//setters
	void setTile(int x, int y, char tile);


	void loadMap(std::string fileName, int mapH, int mapW, Player& player);
	void drawLevel(int mapH, int mapW);


	void movePlayer(char input, Player& player);

	
	std::vector <std::string> _levelData;
	//void load(std::string map, std::string savedFile, int mapHeight, int mapWidth);
	//void processLevel(std::vector <std::string> _levelData, Player& player);

	//void save(Player &playerSave);
	void processPlayerMove(Player& player, int targetX, int targetY);

private:

};

