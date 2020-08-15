#include <Windows.h>
#include <iostream>
#include <string>
#include "Level.h"
#include "Game.h"

int main() {

	Game game = Game("NewYorkCity.txt", 24, 79, game.player);
	game.playGame();
	return 0;
}
