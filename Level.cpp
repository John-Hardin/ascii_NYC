#include "Game.h"
#include "Level.h"

#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

//Level::Level() {
//	
//}


void Level::loadMap() {
	
	std::ifstream inputMapFile;
	inputMapFile.open("NewYorkCity.txt");
	if (inputMapFile.fail()) {
		perror("NewYorkCity.txt");
	}
	std::string input;
	for (int i = 0; i < Game::height; i++) {
		std::getline(inputMapFile, input);
		Game::mapArr.push_back(input);
	}
	inputMapFile.close();
}


 void Level::loadData() {
	if (checkIfLoaded){
		std::ifstream file("savedgame.dat", std::ios::in | std::ios::binary);
		file.read((char*)&player, sizeof(player));
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
	std::string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
			checkIfLoaded = true;
	}
	else {
		checkIfLoaded = false;
	}
}
 void Level::draw() {
	if ((player.x == bob.x && player.y == bob.y) || (player.y == karen.y && player.x == karen.x) || (player.y == terry.y && player.x == terry.x)) {
		mapArr[player.y][player.x] = '@';
		for (int i = 0; i < height; i++) {
			std::cout << mapArr[i] << std::endl;
		}
	}
	else {
		for (int i = 0; i < height; i++) {
			std::cout << mapArr[i] << std::endl;
		}
	}

}
 void Level::saveData() {
	std::ofstream file("savedgame.dat", std::ios::out | std::ios::binary | std::ios::trunc);
	if (file.fail()) {
		perror("savedgame.dat");
		printf("savedgame.dat was not created previous error is my perror...");
	}
	else {
		file.write((char*)&player, sizeof(player));
		printf(" x is %d, y is %d, px is %d, py is %d ;", player.x, player.y, player.px, player.py);
		printf("file.write, check for savedgame.dat file");
		file.close();
	}
}
 void Level::askSave()
{
	printf("\tWould you like to SAVE GAME?  Or hit enter to quit game.\n");
	std::string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
		saveData();
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
 void Level::initPlayer() {
	if (!checkIfLoaded) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mapArr[i][j] == '^') {
					player.x = j;
					player.y = i;
					player.px = j;
					player.py = i;
					mapArr[player.y][player.x] = '@';
					return;
				}
			}
		}
	}
	else {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mapArr[i][j] == '^') {
					mapArr[i][j] = '.';

					mapArr[player.y][player.x] = '@';
					return;
				}
			}
		}
	}
}
 void Level::initEnemies() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (mapArr[i][j] == '%' || mapArr[i][j] == '@') {
				bob.x = j;
				bob.y = i;
				bob.pX = j;
				bob.pY = i;
				i = height;
				j = width;
			}
		}
	}
	for (int i = bob.y + 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (mapArr[i][j] == '%' || mapArr[i][j] == '@') {
				karen.x = j;
				karen.y = i;
				karen.pX = j;
				karen.pY = i;
				i = height;
				j = width;

			}
		}
	}
	if (checkIfLoaded) {
		for (int i = karen.y + 1; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mapArr[i][j] == '%' || mapArr[i][j] == '@') {
					terry.x = j;
					terry.y = i;
					terry.pX = j;
					terry.pY = i;
					i = height;
					j = width;
				}
			}
		}
	}
	else {
		for (int i = karen.y + 1; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (mapArr[i][j] == '%') {
					terry.x = j;
					terry.y = i;
					terry.pX = j;
					terry.pY = i;
					i = height;
					j = width;
				}
			}
		}
	}

}

