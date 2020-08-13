#include <Windows.h>
#include <iostream>
//#include "Level.h"
#include "Game.h"
int main() {
	
	//Level();
	Game game = Game();
	//level.askLoad();
	//level.loadMap();
	//level.loadData();
	//level.initEnemies();
	//level.initPlayer();

	game.playGame(game.gameOver);
	//while (level.gameOver == false){
	//	level.draw();
	//	level.logicMovement();
	//	level.enemyMovement();
	//	level.interaction();
	//}
	/*level.askSave();*/
	return 0;
}
