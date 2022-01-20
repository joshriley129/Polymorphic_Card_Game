#pragma once
#include "Spell.h"

class Player;

class Bless : public Spell
{
protected:
	int Healing;
	int Damage;

private:
	int Random(const float n);

public:
	Bless(int type, string name, int attack, int healValue);
	~Bless();

	virtual void Cast(Player& owner, Player& enemy, int random);
};

