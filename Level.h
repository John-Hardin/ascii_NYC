#pragma once
#include "GameLoad.h"

class Level : GameLoad
{
public:
	void saveData(GameLoad game);
	void askSave(GameLoad game);
	bool loadData(GameLoad *game, bool checkIfLoaded);
	void askLoad(GameLoad &game);
private:
};

