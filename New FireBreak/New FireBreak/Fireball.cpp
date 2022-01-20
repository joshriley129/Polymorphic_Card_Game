#include "Fireball.h"
#include "Player.h"
#include "Minion.h"
#include <iostream>

using namespace std;

Fireball::Fireball(int type, string name, int damage) : Spell(type, name)
{
	Damage = damage;
}


Fireball::~Fireball()
{
}

void Fireball::Cast(Player& owner, Player& enemy, int random)
{
	int r = Random(enemy.Table.size());
	if (r == enemy.Table.size())
	{
		enemy.Health -= Damage;
		cout << owner.Name << " casts Fireball at " << enemy.Name << ": " << enemy.Name << " health now " << enemy.Health << endl;
	}
	else
	{
		enemy.Table[r]->TakeDamage(Damage);
		if (enemy.Table[r]->GetHP() <= 0)
		{
			cout << owner.Name << " casts Fireball at " << enemy.Table[r]->Name << ": " << enemy.Table[r]->Name << " killed " << endl;
			enemy.Table.erase(enemy.Table.begin() + r);
		}
		else
		{
			cout << owner.Name << " casts Fireball at " << enemy.Table[r]->Name << ": " << enemy.Table[r]->Name << " health now " << enemy.Table[r]->GetHP() << endl;
		}
	}

	owner.Hand[random].release();
	owner.Hand.erase(owner.Hand.begin() + random);
}

int Fireball::Random(const float n)
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}