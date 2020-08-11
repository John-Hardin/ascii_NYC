#pragma once
#include <vector>
#include <string>

using namespace std;
//void printAnim(std::string fileName);

class GameLoad
{
public:
	const int width = 79;
	const int height = 24;
	vector <string> mapArr;
	//char playerX, playerY, previousPlayerX, previousPlayerY;
	struct robber { int x, y, pX, pY; } bob{}, karen{}, terry{};
	bool enemyDirection = true;
	int lastDirection = 0;
	bool gameOver = false;
	void loadMap();
	void enemyMovement();
	void draw();
	vector <string> logicMovement();
	void interaction();
	//void echo(int statement);
	//void printInteraction(int resultOfRoll);
	struct player {
		char x, y, px, py;
	} player;
private:
};
