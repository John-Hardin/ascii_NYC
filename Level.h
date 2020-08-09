#pragma once
#include "GameLoad.h"

class Level : GameLoad
{
public:



	

	void saveData(GameLoad game);
	void askSave(GameLoad game);
	void loadData(GameLoad &game);
	void askLoad(GameLoad &game);
private:



};

