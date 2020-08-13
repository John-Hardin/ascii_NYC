#pragma once
#include <vector>
#include <string>
#include "Level.h"
class Game
{
	
public:
	void playGame(bool over);
	Level level;

	bool gameOver = false;


	bool enemyDirection = true;
	int lastDirection = 1;


	void printAnim(std::string fileName);
	void enemyMovement();
	std::vector <std::string> logicMovement();
	void interaction();
};

