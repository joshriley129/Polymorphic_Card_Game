#pragma once
#include "Spell.h"
class Player;

class Lightning : public Spell
{
protected:
	int Damage;

private:

public:
	Lightning(int type, string name, int damage);
	~Lightning();

	virtual void Cast(Player& owner, Player& enemy, int random);
};

