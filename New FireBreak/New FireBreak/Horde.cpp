#include "Horde.h"
#include "Minion.h"
#include "Player.h"
#include <iostream>

using namespace std;

Horde::Horde(int type, string name, int health, int attack, int attackIncrement) : Minion(type, name, health, attack)
{
	Damage = attack;
}


Horde::~Horde()
{
}

void Horde::Attack(Player & owner, Player & enemy, int random)
{
	int ratCount = 0;
	for (auto p = enemy.Table.begin(); p != enemy.Table.end(); ++p)
	{
		if ((*p)->Type == 7)
		{
			ratCount++;
		}
	}
	for (auto p = owner.Table.begin(); p != owner.Table.end(); ++p)
	{
		if ((*p)->Type == 7)
		{
			ratCount++;
		}
	}

	//Attacks like an ordinary Minion
	if (enemy.Table.empty())
	{
		enemy.Health -= ratCount;
		cout << Name << " attacks " << enemy.Name << ":" << enemy.Name << " health now " << enemy.Health << endl;
	}
	else
	{
		bool walls = false;
		for (auto p = enemy.Table.begin(); p != enemy.Table.end(); ++p)
		{
			if ((*p)->Type == 6)
			{
				walls = true;
			}
		}

		if (walls == true)
		{
			for (auto p = enemy.Table.begin(); p != enemy.Table.end(); ++p)
			{
				if ((*p)->Type == 6)
				{
					(*p)->TakeDamage(ratCount);
					if ((*p)->GetHP() <= 0)
					{
						cout << Name << " attacks " << (*p)->Name << ": " << (*p)->Name << " killed " << endl;
						enemy.Table.erase(p);
					}
					else
					{
						cout << Name << " attacks " << (*p)->Name << ": " << (*p)->Name << " health now " << (*p)->GetHP() << endl;
					}
					break;
				}
			}
		}
		else
		{
			enemy.Table[random]->TakeDamage(ratCount);
			if (enemy.Table[random]->GetHP() <= 0)
			{
				cout << Name << " attacks " << enemy.Table[random]->Name << ": " << enemy.Table[random]->Name << " killed " << endl;
				enemy.Table.erase(enemy.Table.begin() + random);
			}
			else
			{
				cout << Name << " attacks " << enemy.Table[random]->Name << ": " << enemy.Table[random]->Name << " health now " << enemy.Table[random]->GetHP() << endl;
			}
		}
	}

}