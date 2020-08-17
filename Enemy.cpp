#include "Enemy.h"
#include <vector>
#include <random>
#include <ctime>
Enemy::Enemy(std::string name, char tile, int level, int health, int attack, int defense, int expValue) {
	_name = name;
	_tile = tile;
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_expValue = expValue;
}
void Enemy::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}
std::string Enemy::getName() {
	return _name; 
}
char Enemy::getTile() {
	return _tile;
}
void Enemy::setPosition(int x, int y) {
	_x = x;
	_y = y;
}
int Enemy::attack() {
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(1, _attack);
	return attackRoll(randomEngine);
}
int Enemy::takeDamage(int attack) {
	//attack -= _defense;
	//check if attack does damage note -- change randome number to 1 here for consistent attacks
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return _expValue;
		}
	}
	return 0;
}
char Enemy::getAiMove(int playerX, int playerY) {
	static std::default_random_engine randEng(time(NULL));
	std::uniform_int_distribution<int> moveRoll(0, 10);
	int distance;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	distance = adx + ady;
	if (distance <= 7) {
		if (adx > ady) {
			//moving along X axis
			if (dx > 0) {
				return 'a';
			}
			else {
				return 'd';
			}
		}
		else {
			//moving along Y axis
			if (dy > 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}
	int randomMove = moveRoll(randEng);
	switch (randomMove) {
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2:
		return 's';
	case 3:
		return 'd';
	default:
		return '.';  //note -- not sure if need to return '.' here.
	}
}