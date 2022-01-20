#include "Bless.h"
#include "Player.h"
#include "Minion.h"
#include <iostream>

int Bless::Random(const float n)
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}

Bless::Bless(int type, string name, int attack, int healValue) : Spell(type, name)
{
	Damage = attack;
	Healing = healValue;
}


Bless::~Bless()
{
}

void Bless::Cast(Player& owner, Player& enemy, int random)
{
	int r = Random((enemy.Table.size()) + (owner.Table.size()));

	if (r < enemy.Table.size())
	{
		enemy.Table[r]->TakeDamage(Damage);
		if (enemy.Table[r]->GetHP() <= 0)
		{
			std::cout << owner.Name << " casts Bless at " << enemy.Table[r]->Name << ": " << enemy.Table[r]->Name << " killed " << endl;
			enemy.Table.erase(enemy.Table.begin() + r);
		}
		else
		{
			std::cout << owner.Name << " casts Bless at " << enemy.Table[r]->Name << ": " << enemy.Table[r]->Name << " health now " << enemy.Table[r]->GetHP() << endl;
		}
	}
	else if (r == enemy.Table.size())
	{
		enemy.Health -= Damage;
		if (enemy.Health <= 0)
		{
			std::cout << owner.Name << " casts Bless at " << enemy.Name << ": " << enemy.Name << " killed " << endl;
		}
		else
		{
			std::cout << owner.Name << " casts Bless at " << enemy.Name << ": " << enemy.Name << " health now " << enemy.Health << endl;
		}
	}
	else if (r > enemy.Table.size() && r < owner.Table.size())
	{
		owner.Table[r]->TakeDamage(-Healing);
		std::cout << owner.Name << " casts Bless at " << enemy.Table[r]->Name << ": " << enemy.Table[r]->Name << " health now " << enemy.Table[r]->GetHP() << endl;
	}
	else
	{
		owner.Health += Healing;
		std::cout << owner.Name << " casts Bless and heals for " << Healing << ": " << owner.Name << " health now " << owner.Health << endl;
	}

	owner.Hand[random].release();
	owner.Hand.erase(owner.Hand.begin() + random);
}
