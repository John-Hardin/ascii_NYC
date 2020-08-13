#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

#include "Game.h"
#include "Level.h"



 void Level::loadMap(std::string fileName, static const int &mapHeight) {
	//strange error in function declaration, possibly due to "#include <Windows.h>"
	std::ifstream inputMapFile;
	inputMapFile.open(fileName.c_str());
	if (inputMapFile.fail()) {
		perror(fileName.c_str());
	}
	std::string input;
	for (int i = 0; i < mapHeight; i++) {
		std::getline(inputMapFile, input);
		mapArr.push_back(input);
	}
	inputMapFile.close();
}
 void Level::loadData(std::string fileName) {
	if (checkIfLoaded){
		std::ifstream file(fileName, std::ios::in | std::ios::binary);
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
	if ((player.x == player.x && player.y == bob.y) || (player.y == karen.y && player.x == karen.x) || (player.y == terry.y && player.x == terry.x)) {
//TODO add function here to set enemy location to previous location so % gets printed in previous location instead of location
		// because it prints over the player's @ character
		printf("hello from inside draw(), line before setEnemiesToPreviousLocation\n");
		setEnemyToPreviousLocation();
		printf("hello from inside draw(), line AFTER setEnemiesToPreviousLocation\n");
		for (int i = 0; i < height; i++) {
			std::cout << mapArr[i] << std::endl;
		}
	}
	else {
		//TODO -- I think this else statement is broken, it prints percent character instead of period character after player
		// enemy overlapping, THE IF STATEMENT is close though, might be correct...

		setEnemyToPreviousLocation();
		for (int i = 0; i < height; i++) {
			std::cout << mapArr[i] << std::endl;

		}
		printf("hello from else statement, inside draw() if((player.x == bob.x && player.y == bob.y) || (player.y == karen.y && player.x == karen.x) || (player.y == terry.y && player.x == terry.x))");

	}
}
 void Level::setEnemyToPreviousLocation() {
	 //if (player.x == bob.x && player.y == bob.y) {
		// ////bob.x = bob.pX;
		// ////bob.y = bob.pY;

		// mapArr[player.y][player.x] = '@';
		// mapArr[bob.pY][bob.pX] = '%';
		// //mapArr[bob.y][bob.x] = '.'; try moving this above mapArr[player.y][player.x] = '@';
		// printf("hello from inside setEnemyToPreviousLocation(), just after mapArr[bob.pY][bob.pX] = '%';\n bob.x is: %d, bob.y is: %d\n", bob.x, bob.y);
		// printf("bob.pX is: %d, bob.pY is: %d\n", bob.pX, bob.pY);
	 //}
	 //else {
		// mapArr[player.y][player.x] = '@';
		// mapArr[bob.pY][bob.pX] = '.';

	 }//finish -- bob is pretty much set up correctly, propagate changes to karen and terry in this setEnemiesToPreviousLocation function
	 
	  //if (player.x == karen.x && player.y == karen.y) {
		// //karen.x = karen.pX;
		// //karen.y = karen.pY;
		// mapArr[player.y][player.x] = '@';
		// mapArr[karen.pY][karen.pX] = '%';
	 //}
	 //if (player.x == terry.x && player.y == terry.y) {
		// //terry.x = terry.pX;
		// //terry.y = terry.pY;
		// mapArr[player.y][player.x] = '@';
		// mapArr[terry.pY][terry.pX] = '%';
	 //}
 
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
 void Level::askSave() {
	printf("\tWould you like to SAVE GAME?  Or hit enter to quit \n");
	std::string input;
	std::cin >> input;
	if (input == "Yes" || input == "yes" || input == "y") {
		saveData();
		printf("\tsaving...");
		return;
	}
	else {
		printf("\tSure?  (Yes, yes, y) will save.  Or hit enter to quit \n");
		std::cin >> input;
		if (input == "Yes" || input == "yes" || input == "y") {
			printf("\tsaving...");
			return;
		}
		printf("\tDid not save ..");
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


