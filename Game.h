#pragma once
#include <vector>
#include <string>
#include "Level.h"
#include "Player.h"
class Game
{
public:
	//constructor
	Game(std::string fileName, int mapH, int mapW, Player& player);

	Level level;
	Player player;


	void playGame();
	bool gameOver = false;
	void playerMove();



	//void printAnim(std::string fileName);
private:
};

