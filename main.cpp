
#include "GameLoad.h"
#include "Level.h"
#include <Windows.h>
#include <iostream>




int main() {
	GameLoad game;
	Level level;
	level.askLoad();
	game.loadMap();
	level.loadData(&game);

	level.initEnemies(&game);
	level.initPlayer(&game);
	while (game.gameOver == false){
		game.draw();
		game.logicMovement();
		game.enemyMovement();
		game.interaction();
		//game.printInteraction(game.interaction());  //interaction here causes printAnim() to happen a second time
	}
	//game.echo( game.player.x);
	level.askSave(game);
	//Sleep(4000);
	return 0;
}
