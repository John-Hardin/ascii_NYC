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
	}
	level.askSave();
	return 0;
}
