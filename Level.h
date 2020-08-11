#pragma once
#include "GameLoad.h"
class Level : GameLoad
{
public:
	bool checkIfLoaded;
	void saveData(GameLoad game);
	void askSave(GameLoad game);
	void loadData(GameLoad *game);
	void askLoad();
	void initPlayer(GameLoad*);
	void initEnemies(GameLoad*);
private:
};

