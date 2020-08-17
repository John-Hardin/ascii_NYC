#include "Player.h"
#include <random>
#include <ctime>


Player::Player() {
		_x = 0;
		_y = 0;
		_level = 40;
		_health = 100;
		_attack = 65;
		_defense = 30;
		_exp = 0;
}
void Player::init(int level, int health, int attack, int defense, int exp) {
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_exp = exp;
}
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}
void Player::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}
int Player::attack() {
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, _attack);
	return attackRoll(randomEngine);
}
void Player::addExperience(int addExpValue) {
	_exp += addExpValue;

	//level up
	while (_exp > 20) {
		printf("Leveled up!");
		_exp -= 50;
		_attack += 8;
		_defense += 4;
		_health += 7;
		_level++;
	}
}
int Player::takeDamage(int attack) {
	//dattack -= _defense;
	//check if attack does damage note -- change randome number to 1 here for consistent attacks
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return 1;
		}
	}
	return 0;
}
