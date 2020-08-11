#pragma once
#include <vector>
#include <string>


//void printAnim(std::string fileName);

class Game
{
public:

	static const int width = 79;
	static const int height = 24;
	bool gameOver = false;


	std::vector <std::string> mapArr;
	struct robber { int x, y, pX, pY; } bob{}, karen{}, terry{};
	bool enemyDirection = true;
	int lastDirection = 0;

	 void printAnim(std::string fileName);
	 void enemyMovement();
	 std::vector <std::string> logicMovement();
	 void interaction();
	//void echo(int statement);
	//void printInteraction(int resultOfRoll);
	 struct player {
		 char x, y, px, py;
	 } player{};
	private:
};

