


#include <Windows.h>
#include <iostream>

#include "Level.h"
#include "Game.h"



int main() {
	Game game;
	Level level;

	level.askLoad();
	level.loadMap();
	level.loadData();

	level.initEnemies();
	level.initPlayer();
	while (level.gameOver == false){
		level.draw();
		level.logicMovement();
		level.enemyMovement();
		level.interaction();
		//game.printInteraction(game.interaction());  //interaction here causes printAnim() to happen a second time
	}
	//game.echo( game.player.x);
	level.askSave();
	//Sleep(4000);
	return 0;
}
