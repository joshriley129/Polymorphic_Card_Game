#include "Vampire.h"
#include "Minion.h"
#include "Player.h"
#include <iostream>



Vampire::Vampire(int type, string name, int health, int attack, int healValue) : Minion(type, name, health, attack)
{
	Healing = healValue;
}


Vampire::~Vampire()
{
}

void Vampire::Attack(Player & owner, Player & enemy, int random)
{
	//Attacks like an ordinary Minion
	Minion::Attack(owner, enemy, random);
	// Vampire gaining life
	HP += Healing;
	std::cout << "Vampire heals for " << Healing << endl;
}
