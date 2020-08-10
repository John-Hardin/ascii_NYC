#include "GameLoad.h"
#include "Level.h"
#include <Windows.h>
#include <iostream>

int main() {
	GameLoad game;
	Level level;
	level.askLoad(game);
	game.loadMap();
	game.playerStartPosition(game.isLoaded);
	while (game.gameOver == false){
		game.draw();
		game.logicMovement();
		game.enemyMovement();
		game.interaction();
		game.printInteraction(game.interaction());
	}
	game.echo( game.player.x);
	level.askSave(game);
	//Sleep(4000);
	return 0;
}
