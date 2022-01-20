#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Minion.h"
#include <fstream>

using namespace std;

int Random(const float n);
int ReadIn();
void draw(int roundCounter, Player& Wizard, Player& Sorceress);

int main()
{
	//Variable Declarations
	Player Wizard;
	Player Sorceress;
	int roundCounter = 0;
	int roundMaximum = 30;
	int random = 0;
	string filename = "wizard.txt";
	

	//Main Program
	//Setup
	int seed = ReadIn();
	srand(seed);
	Wizard.Name = "Wizard";
	Sorceress.Name = "Sorceress";
	Wizard.DeckGeneration(filename);
	filename = "sorceress.txt";
	Sorceress.DeckGeneration(filename);

	//The Duel
	//Pre-Loop
	draw(roundCounter, Wizard, Sorceress);
	cout << "Sorceress begins with " << Sorceress.Hand.back()->Name << endl;
	cout << "Wizard begins with " << Wizard.Hand.back()->Name << endl;
	cout << endl;

	while (roundCounter < roundMaximum && Wizard.Health > 0 && Sorceress.Health > 0)
	{
		//Pre-Round

		draw(roundCounter, Wizard, Sorceress);
		cout << "Round " << roundCounter + 1 << endl;

		//Sorceress Round
		if (Sorceress.Health > 0)
		{
			cout << "Sorceress draws " << Sorceress.Hand.back()->Name << endl;
			random = Random(Sorceress.Hand.size() - 1);
			Sorceress.Hand[random]->Cast(Sorceress, Wizard, random);
			cout << "Cards on table: ";
			for (auto p = Sorceress.Table.begin(); p != Sorceress.Table.end(); ++p)
			{
				cout << (*p)->Name << "(" << (*p)->GetHP() << ")  ";
			}
			cout << endl;
			for (auto p = Sorceress.Table.begin(); p != Sorceress.Table.end(); ++p)
			{
				random = Random(Wizard.Table.size() - 1);
				(*p)->Attack(Sorceress, Wizard, random);
			}
			cout << endl;
			cout << endl;
		}

		//Wizard Round
		if (Wizard.Health > 0)
		{
			cout << "Wizard draws " << Wizard.Hand.back()->Name << endl;
			random = Random(Wizard.Hand.size() - 1);
			Wizard.Hand[random]->Cast(Wizard, Sorceress, random);
			cout << "Cards on table: ";
			for (auto p = Wizard.Table.begin(); p != Wizard.Table.end(); ++p)
			{
				cout << (*p)->Name << "(" << (*p)->GetHP() << ")  ";
			}
			cout << endl;
			for (auto p = Wizard.Table.begin(); p != Wizard.Table.end(); ++p)
			{
				random = Random(Sorceress.Table.size() - 1);
				(*p)->Attack(Wizard, Sorceress, random);
			}
			cout << endl;
			cout << endl;
		}

		system("pause");
		system("CLS");
		roundCounter++;
	}

	system("pause");
}

int Random(const float n)
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}
void draw(int roundCounter, Player& Wizard, Player& Sorceress)
{
	for (auto p = Wizard.Deck.begin(); p != Wizard.Deck.end(); ++p)
	{
		Wizard.Hand.push_back(move(*p));
		Wizard.Deck.erase(p);
		break;
	}

	for (auto p = Sorceress.Deck.begin(); p != Sorceress.Deck.end(); ++p)
	{
		Sorceress.Hand.push_back(move(*p));
		Sorceress.Deck.erase(p);
		break;

	}
}
int ReadIn()
{
	ifstream file("seed.txt");
	int seed = 0;
	file >> seed;
	return seed;
}