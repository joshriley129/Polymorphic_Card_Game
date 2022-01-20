#include "Lightning.h"
#include "Player.h"
#include "Minion.h"
#include <iostream>

using namespace std;


Lightning::Lightning(int type, string name, int damage) : Spell(type, name)
{
	Damage = damage;
}


Lightning::~Lightning()
{
}

void Lightning::Cast(Player& owner, Player& enemy, int random)
{
	if (enemy.Table.size() != NULL)
	{

		for (auto p = enemy.Table.begin(); p != enemy.Table.end(); ++p)
		{
			(*p)->TakeDamage(Damage);

			if ((*p)->GetHP() <= 0)
			{
				cout << owner.Name << " casts Lightning: " << (*p)->Name << " killed " << endl;
			}
			else
			{
				cout << owner.Name << " casts Lightning: " << (*p)->Name << " health now " << (*p)->GetHP() << endl;
			}
		}
	}
	enemy.Health -= Damage;
	cout << owner.Name << " casts Lightning: " << enemy.Name << " health now " << enemy.Health << endl;

	deque <unique_ptr <Minion> >::iterator p;
	p = enemy.Table.begin();
	for (auto& elt : enemy.Table)
	{
		if ((*p)->GetHP() <= 0)
		{
			enemy.Table.erase(p);
		}
	}

	//Deletes this card from the users hand
	owner.Hand[random].release();
	owner.Hand.erase(owner.Hand.begin() + random);
}
