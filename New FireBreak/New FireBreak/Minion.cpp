#include "Minion.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>
using namespace std;

Minion::Minion(int type, string name, int health, int attack) : Card(type, name)
{
	HP = health;
	BaseAttack = attack;
}


Minion::~Minion()
{
}

void Minion::Attack(Player& owner, Player& enemy, int random)
{
	int attack = GetAttackDamage();
	Card* card = nullptr;

	if (enemy.Table.empty())
	{
		enemy.Health -= attack;
		cout << Name << " attacks "<< enemy.Name << ":" << enemy.Name<< " health now " << enemy.Health << endl;
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
					(*p)->TakeDamage(attack);
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
			enemy.Table[random]->TakeDamage(attack);
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

void Minion::Cast(Player & owner, Player & enemy,int random)
{
	// Spawn the minion on the owners table

	// Stops the unique_pointer from deleting the minion when its deleted
	owner.Hand[random].release();
	owner.Hand.erase(owner.Hand.begin() + random);

	owner.Table.push_back(move(unique_ptr<Minion>(this)));
	cout << owner.Name <<" plays " << owner.Table.back()->Name << endl;

}

int Minion::GetAttackDamage()
{
	return BaseAttack;
}

void Minion::TakeDamage(int d)
{
	HP -= d;
}

int Minion::GetHP()
{
	return HP;
}
