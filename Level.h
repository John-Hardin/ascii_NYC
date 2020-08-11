#pragma once
#include "Game.h"
class Level : public Game
{
public:

	 bool checkIfLoaded;
	 void saveData();
	 void askSave();
	 void loadData();
	 void askLoad();
	 void initPlayer();
	 void initEnemies();
	 void loadMap();
	 void draw();
private:
};

