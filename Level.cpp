#include "GameLoad.h"
#include "Level.h"

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>


void Level::loadData(GameLoad *game) {
	if (checkIfLoaded){
		std::ifstream file("savedgame.dat", std::ios::in | std::ios::binary);
		file.read((char*)&game->player, sizeof(game->player));
		printf("\tfile.read now\n");
		if (!file) {
			printf("file.gcount() result is: %d ", file.gcount());
			file.clear();
			printf("\tfile load failed\t");
			checkIfLoaded = false;
		}
		else {
			printf("\tfile loaded\n");
			checkIfLoaded = true;
		}
	}
}
void Level::askLoad() {
	printf("Load last saved game?\n");
	//Sleep(3000);
	printf("\t(Yes, yes, or y) to load, hit ENTER key...\n");
	string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
			checkIfLoaded = true;
	}
	else {
		checkIfLoaded = false;
	}
}
void Level::saveData(GameLoad game) {
	std::ofstream file("savedgame.dat", std::ios::out | std::ios::binary | std::ios::trunc);
	if (file.fail()) {
		perror("savedgame.dat");
		printf("savedgame.dat was not created previous error is my perror...");
	}
	else {
		file.write((char*)&game.player, sizeof(game.player));
		printf(" x is %d, y is %d, px is %d, py is %d ;", game.player.x, game.player.y, game.player.px, game.player.py);
		printf("file.write, check for savedgame.dat file");
		file.close();
	}
}
void Level::askSave(GameLoad game)
{
	printf("\tWould you like to SAVE GAME?  Or hit enter to quit game.\n");
	std::string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
		saveData(game);
		printf("\tsaving...");
		return;
	}
	else {
		printf("\tSure?  (Yes, yes, y) will save.  Or hit enter to quit game.\n");
		std::cin >> input;
		if (input == "Yes" || input == "yes" || input == "y") {
			printf("\tsaving...");
			return;
		}
		printf("\tDid not save game...");
		return;
	}
}
void Level::initPlayer(GameLoad *game) {
	if (!checkIfLoaded) {
		for (int i = 0; i < game->height; i++) {
			for (int j = 0; j < game->width; j++) {
				if (game->mapArr[i][j] == '^') {
					game->player.x = j;
					game->player.y = i;
					game->player.px = j;
					game->player.py = i;
					game->mapArr[game->player.y][game->player.x] = '@';
					return;
				}
			}
		}
	}
	else {
		for (int i = 0; i < game->height; i++) {
			for (int j = 0; j < game->width; j++) {
				if (game->mapArr[i][j] == '^') {
					game->mapArr[i][j] = '.';
					game->mapArr[game->player.y][game->player.x] = '@';
					return;
				}
			}
		}
	}
}
void Level::initEnemies(GameLoad* game) {
	for (int i = 0; i < game->height; i++) {
		for (int j = 0; j < game->width; j++) {
			if (game->mapArr[i][j] == '%' || game->mapArr[i][j] == '@') {
				game->bob.x = j;
				game->bob.y = i;
				game->bob.pX = j;
				game->bob.pY = i;
				i = game->height;
				j = game->width;
			}
		}
	}
	for (int i = game->bob.y + 1; i < game->height; i++) {
		for (int j = 0; j < game->width; j++) {
			if (game->mapArr[i][j] == '%' || game->mapArr[i][j] == '@') {
				game->karen.x = j;
				game->karen.y = i;
				game->karen.pX = j;
				game->karen.pY = i;
				i = game->height;
				j = game->width;

			}
		}
	}
	if (checkIfLoaded) {
		for (int i = game->karen.y + 1; i < game->height; i++) {
			for (int j = 0; j < game->width; j++) {
				if (game->mapArr[i][j] == '%' || game->mapArr[i][j] == '@') {
					game->terry.x = j;
					game->terry.y = i;
					game->terry.pX = j;
					game->terry.pY = i;
					i = game->height;
					j = game->width;
				}
			}
		}
	}
	else {
		for (int i = game->karen.y + 1; i < game->height; i++) {
			for (int j = 0; j < game->width; j++) {
				if (game->mapArr[i][j] == '%') {
					game->terry.x = j;
					game->terry.y = i;
					game->terry.pX = j;
					game->terry.pY = i;
					i = game->height;
					j = game->width;
				}
			}
		}
	}

}

