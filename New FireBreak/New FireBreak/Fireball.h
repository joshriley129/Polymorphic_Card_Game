#pragma once
#include "Spell.h"
class Player;

class Fireball : public Spell
{
protected:
	int Damage;
private:
	int Random(const float n);

public:
	Fireball(int type, string name, int damage);
	~Fireball();

	virtual void Cast(Player& owner, Player& enemy, int random);
};

