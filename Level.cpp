#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


#include "Game.h"
#include "Level.h"
#include "Player.h"
#include <conio.h>

Level::Level() {


}
void Level::loadMap(std::string fileName, int mapH, int mapW, Player& player) {
	//loads map
	std::ifstream inputMapFile;
	inputMapFile.open(fileName.c_str());
	if (inputMapFile.fail()) {
		perror(fileName.c_str());
	}
	std::string input;
	for (int i = 0; i < mapH; i++) {
		std::getline(inputMapFile, input);
		_levelData.push_back(input);
	}
	inputMapFile.close();
	//process level
	char tile;
	for (int i = 0; i < mapH; i++) {
		for (int c = 0; c < mapW; c++) {
			tile = _levelData[i][c];
			switch (tile) {
			case '@':
				player.setPosition(c, i);
				printf("p_x= %d, p_y=%d,\n", player._x, player._y);

				break;
			}
		}
	}
}
void Level::drawLevel(int mapH, int mapW) {
	for (int i = 0; i < mapH; i++) {
		std::cout << _levelData[i] << std::endl;
	}
}
char Level::getTile(int &x, int &y) {
	return _levelData[y][x];
}
void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}
void Level::movePlayer(char input, Player &player) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	//player.getPosition(playerX, playerY);
	switch (input) {
	case 'w'://up
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's'://down
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a'://left
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd'://right
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		break;
	}
}
void Level::processPlayerMove(Player &player, int targetX, int targetY) {
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	printf("p_x= %d, p_y=%d,\n pX= %d, pY=%d,\n tX=%d, tY=%d\n from before switch ^\n", player._x, player._y, playerX, playerY, targetX, targetY);
	char movetile = getTile(targetX, targetY);
	switch (movetile) {
	case '.':
		player.setPosition(targetX, targetY);
		printf("p_x= %d, p_y=%d,\n pX= %d, pY=%d,\n tX=%d, tY=%d\n inside switch ^\n", player._x, player._y,playerX, playerY, targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	default:
		break;
	}

}
// void Level::load(std::string map, std::string savedFile, int mapHeight, int mapWidth) {
//	printf("Load last saved game?\n");
//	printf("\t(Yes, yes, or y) to load, (No, no, or n) to start new game.  Then hit (ENTER) key...\n");
//	std::string input;
//	std::cin >> input;
//	if (input == "Yes" || input == "yes" || input == "y") {
//		//loading saved data
//		std::ifstream file(savedFile, std::ios::in | std::ios::binary);
//		//file.read((char*)Game::&player, sizeof(Game::player));//TODO -- change data to current player model
//		if (!file) {
//			printf("file.gcount() result is: %d ", file.gcount());
//			file.clear();
//			file.close();
//			printf("\tfile load failed\t");
//		}
//		else {
//			file.close();
//			printf("\tfile loaded..\n");
//			//loading map
//			std::ifstream file;
//			file.open(map.c_str());
//			if (file.fail()) {
//				perror(map.c_str());
//			}
//			std::string input;
//			for (int i = 0; i < mapHeight; i++) {
//				std::getline(file, input);
//				_levelData.push_back(input);
//			}
//			file.close();
//		}
//	}
//	else if (input == "No" || input == "no" || input == "n" || input == "") {
//		//skip loading saved data, straight to loading map
//		std::ifstream file;
//		file.open(map.c_str());
//		if (file.fail()) {
//			perror(map.c_str());
//		}
//		std::string input;
//		for (int i = 0; i < mapHeight; i++) {
//			std::getline(file, input);
//			_levelData.push_back(input);
//		}
//		file.close();
//	}
//	else {
//		std::cout << "\n\nINVALID choice.\n";
//		std::cout << "Please type one of these, then hit ENTER key: Yes, yes, y, No, no, no.\n";
//			std::cin >> input;
//	}
//}
// //void Level::processLevel(std::vector <std::string> _levelData, Player &player) {
//	// char tile;
//	// for (int i = 0; i < _levelData[i].size(); i++) {
//	//	 for (int j = 0; j < _levelData[i].size(); j++) {
//	//		 tile = _levelData[i][j];
//	//		 switch (tile) {
//	//		 case '@':
//	//			 player.setPosition(j, i);
//	//		 }
//	//	 }
//	// }
// //}

 //std::ostream& operator<< (std::ostream& farle, Game& playerSave) {
	// farle << playerSave.player._x << "Hellow";
	// return farle;
 //}
// void Level::save(Player &playerSave) {
//	 printf("\tWould you like to SAVE GAME?\n");
//	 printf("(Yes, yes, or y) to save game, (No, no, or n) to exit.  Then hit (ENTER) key...\n");
//	std::string input;
//	std::cin >> input;//note-- possibly use _getch() here
//	if (input == "Yes" || input == "yes" || input == "y") {
//		//TODO -- write save file, any kind
//		//note -- any kind of save file.
//		std::ostream& file = file;
//		
//		file.write("save.dat", std::ios::out | std::ios::binary | std::ios::trunc);
//		file << playerSave.player._x;
//		printf("playerSave.player._x = ", playerSave.player._x);
//		_getch();
//		return;
//	}
//	else {
//		printf("\tDid not save ..");
//		return;
//	}
//}


