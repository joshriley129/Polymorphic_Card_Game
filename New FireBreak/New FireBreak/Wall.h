#pragma once
#include "Minion.h"
class Wall : public Minion
{
public:
	Wall(int type, string name, int health, int attack);
	~Wall();

	virtual void Attack(Player& owner, Player& enemy, int random);
};

