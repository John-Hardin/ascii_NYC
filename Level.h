#pragma once
#include "GameLoad.h"

class Level : GameLoad
{
public:



	

	void saveData(GameLoad game);
	void askSave(GameLoad game);
	void loadData(GameLoad const *game);
	void askLoad(GameLoad &game, bool& checkIfLoaded);
private:



};

