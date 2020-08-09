#pragma once



#include <vector>
#include <string>
using namespace std;



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
	bool isLoaded;


	void loadMap();
	void playerStartPosition(bool &checkIfLoaded);
	void enemyMovement();
	void draw();
	vector <string> logicMovement();
	bool interaction();
	void echo(int statement);

	struct player {
		char x, y, px, py;

	} player;


private:

};

