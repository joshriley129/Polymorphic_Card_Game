#pragma once
#include <string>
using namespace std;


class Player;

class Card
{
public:
	Card(int type, string name);
	~Card();

	virtual void Cast(Player& owner, Player& enemy, int random) = 0;

	int Type;
	string Name;
};

