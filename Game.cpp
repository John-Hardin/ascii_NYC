#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "Level.h"
#include "Game.h"
#include "Player.h"


//constructor
Game::Game(std::string fileName, int mapH, int mapW) {

	level.loadMap(fileName, mapH, mapW);
	player.init(1, 3, 5, 5, 0);
	//TODO -- Turn these 3 into a map load function
	//level.load("NewYorkCity.txt", "save.dat", 24, 79);
}
void Game::playGame() {
	bool over = false;
	while (over != false) {
		level.drawLevel(24, 79);
		//Game::level.drawLevel(24, 79);
	}
	//level.save(player);

}






// void Game::printAnim(std::string fileName) {
//	int width = 24;
//	int height = 79;
//	if (fileName == "mugged_but_survived.txt") {
//		std::vector<std::string> animArr;
//		std::ifstream animFile;
//		animFile.open("mugged_but_survived.txt"); //TODOmake these variable placeholder "fileName", insert actual file name 'mugged_but_survived.txt' into function call in interaction()
//		if (animFile.fail()) {                      // run if statment to see if (filename == "mugged_but_survived"){ copy/paste  code here from animArr intialization down to Sleep(5200)}
//			perror("mugged_but_survived.txt");     //repeat if/else for other file names/animations
//		}
//		std::string input;
//		for (int i = 0; i < width * 4; i++) {
//			getline(animFile, input);
//			animArr.push_back(input);
//		}
//		animFile.close();
//		for (int i = 0; i < width; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width; i < width * 2; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width * 2; i < width * 3; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width * 3; i < width * 4; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//	}
//	else if (fileName == "mugged_and_died.txt") {
//		std::vector<std::string> animArr;
//		std::ifstream animFile;
//		animFile.open("mugged_and_died.txt"); //make these variable placeholder "fileName", insert actual file name 'mugged_but_survived.txt' into function call in interaction()
//		if (animFile.fail()) {                      // run if statment to see if (filename == "mugged_but_survived"){ copy/paste  code here from animArr intialization down to Sleep(5200)}
//			perror("mugged_and_died.txt");     //repeat if/else for other file names/animations
//		}
//		std::string input;
//		for (int i = 0; i < width * 4; i++) {
//			getline(animFile, input);
//			animArr.push_back(input);
//		}
//		animFile.close();
//		for (int i = 0; i < width; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width; i < width * 2; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width * 2; i < width * 3; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//		for (int i = width * 3; i < width * 4; i++) {
//			std::cout << animArr[i] << std::endl;
//		}
//		Sleep(200);
//	}
//}
