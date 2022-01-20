#pragma once
#include "Minion.h"
class Horde : public Minion
{
protected:
	int Damage;
public:
	Horde(int type, string name, int health, int attack, int attackIncrement);
	~Horde();

	virtual void Attack(Player& owner, Player& enemy, int random);
};

