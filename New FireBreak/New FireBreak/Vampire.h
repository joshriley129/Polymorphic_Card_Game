#pragma once
#include "Minion.h"
class Vampire : public Minion
{
protected:
	int Healing;
public:
	Vampire(int type, string name, int health, int attack, int healValue);
	~Vampire();

	virtual void Attack(Player& owner, Player& enemy, int random);
};

