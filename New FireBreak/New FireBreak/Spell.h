#pragma once
#include "Card.h"

class Player;

class Spell : public Card
{
public:
	Spell(int type, string name);
	~Spell();
};

