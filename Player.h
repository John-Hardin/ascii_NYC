#pragma once
class Player
{
public:
	//constructor
	Player();
	void init(int level, int health, int attack, int defense, int exp);

	int attack();


	//setters
	void setPosition(int x, int y);
	void addExperience(int addExpValue);
	int takeDamage(int attack);
	//getters
	void getPosition(int &x, int &y);

private:
	//properties
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _exp;
	int _x;
	int _y;
};

