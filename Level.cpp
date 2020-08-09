#include "Level.h"
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>




void Level::loadData(GameLoad const *game) {
	//char buffer[20];
	std::ifstream file("savedgame.dat", std::ios::in | std::ios::binary);
	file.read((char*) &game->player, sizeof(game->player));
	printf("\tfile.read now\n");
	if (!file) {
		printf("file.gcount() result is: %d ", file.gcount());
		file.clear();
		printf("\tfile load failed\t");
	}
}

void Level::askLoad(GameLoad &game, bool &checkIfLoaded) {

	printf("Load last saved game?\n");
	//Sleep(3000);
	printf("\t(Yes, yes, or y) to load, hit ENTER key...\n");
	string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
		loadData(&game);
		printf("\tGame Loading...");
		//Sleep(2000);
		checkIfLoaded = true;
		

	}
	else {
		printf("\tDid not load game.\n");
		//Sleep(2000);
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
		//save game
		saveData(game);

		printf("\tsaving...");
		return;
	}
	else {
		printf("\tSure?  (Yes, yes, y) will save.  Or hit enter to quit game.\n");
		std::cin >> input;
		if (input == "Yes" || input == "yes" || input == "y") {
			//save game
			
			printf("\tsaving...");
			return;
		}
		printf("\tDid not save game...");
		return;
	}
}


