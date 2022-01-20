#pragma once
#include "Card.h"

class Player;

class Minion : public Card
{
protected:
	int HP;
	int BaseAttack;
	bool Equipment;
public:
	Minion(int type, string name, int health, int attack);
	~Minion();

	virtual void Attack(Player& owner, Player& enemy, int random);
	virtual void Cast(Player& owner, Player& enemy, int random);
	int GetAttackDamage();
	void TakeDamage(int d);
	int GetHP();
};

