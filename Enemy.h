#pragma once
#include <string>

class Enemy
{
public:
	//contructor
	Enemy(std::string name, char tile, int level, int health, int attack, int defense, int expValue);

	int attack();
	int takeDamage(int attack);

	char _tile;
	std::string _name;
	//setters
	void setPosition(int x, int y);
	//getters
	void getPosition(int& x, int& y);
	std::string getName();
	char getTile();

	//gets AI move command
	char getAiMove(int, int);
private:
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _expValue;
	int _x;
	int _y;
};

