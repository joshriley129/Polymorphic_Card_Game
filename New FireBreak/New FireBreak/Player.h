#pragma once
#include <deque>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Card;
class Minion;
class Fireball;
class Bless;

using CardList = deque<unique_ptr<Card>>;
using MinionList = deque<unique_ptr<Minion>>;

class Player
{
public:
	Player();
	~Player();

	int Health = 30;
	CardList Deck;
	MinionList Table;
	CardList Hand;
	string Name;

	void DeckGeneration(string filename);
};

