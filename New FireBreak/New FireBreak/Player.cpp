#include "Player.h"
#include "Card.h"
#include "Minion.h"
#include "Vampire.h"
#include "Fireball.h"
#include "Lightning.h"
#include "Bless.h"
#include "Wall.h"
#include "Horde.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::DeckGeneration(string filename)
{
	ifstream file;
	file.open(filename);
	string newLine = "";


	string tmpType;
	int tmpTypeInt;
	string tmpName;


	while (getline(file, newLine))
	{
		stringstream ss;
		ss << newLine;

		getline(ss, tmpType, ' ');
		tmpTypeInt = std::stoi(tmpType);
		getline(ss, tmpName, ' ');

		Card* card = nullptr;

		switch (tmpTypeInt)
		{
			case 1: // Basic Minion
			{
				string tmpAttack;
				getline(ss, tmpAttack, ' ');
				int tmpAttackInt = std::stoi(tmpAttack);

				string tmpHealth;
				getline(ss, tmpHealth, '\n');
				int tmpHealthInt = std::stoi(tmpHealth);

				card = new Minion(tmpTypeInt, tmpName, tmpHealthInt, tmpAttackInt);

			}
			break;
			case 2: // Fireball
			{
				string tmpDamage;
				getline(ss, tmpDamage, '\n');
				int tmpDamageInt = stoi(tmpDamage);

				card = new Fireball(tmpTypeInt, tmpName, tmpDamageInt);
			}
			break;
			case 3: // Lightning
			{
				string tmpDamage;
				getline(ss, tmpDamage, '\n');
				int tmpDamageInt = stoi(tmpDamage);

				card = new Lightning(tmpTypeInt, tmpName, tmpDamageInt);
			}
			break;
			case 4: // Bless
			{
				string tmpAttack;
				getline(ss, tmpAttack, ' ');
				int tmpAttackInt = std::stoi(tmpAttack);

				string tmpHeal;
				getline(ss, tmpHeal, '\n');
				int tmpHealInt = std::stoi(tmpHeal);

				card = new Bless(tmpTypeInt, tmpName, tmpAttackInt, tmpHealInt);

			}
			break;
			case 5: // Vampire
			{
				string tmpAttack;
				getline(ss, tmpAttack, ' ');
				int tmpAttackInt = std::stoi(tmpAttack);

				string tmpHealth;
				getline(ss, tmpHealth, ' ');
				int tmpHealthInt = std::stoi(tmpHealth);

				string tmpHealValue;
				getline(ss, tmpHealValue, '\n');
				int tmpHealValueInt = std::stoi(tmpHealValue);

				card = new Vampire(tmpTypeInt, tmpName, tmpHealthInt, tmpAttackInt, tmpHealValueInt);
			}
			break;
			case 6: // Wall
			{
				string tmpAttack;
				getline(ss, tmpAttack, ' ');
				int tmpAttackInt = std::stoi(tmpAttack);

				string tmpHealth;
				getline(ss, tmpHealth, '\n');
				int tmpHealthInt = std::stoi(tmpHealth);

				card = new Wall(tmpTypeInt, tmpName, tmpHealthInt, tmpAttackInt);

			}
			break;
			case 7: // Horde
			{
				string tmpAttack;
				getline(ss, tmpAttack, ' ');
				int tmpAttackInt = std::stoi(tmpAttack);

				string tmpHealth;
				getline(ss, tmpHealth, ' ');
				int tmpHealthInt = std::stoi(tmpHealth);

				string tmpAttackIncrement;
				getline(ss, tmpAttackIncrement, '\n');
				int tmpAttackIncrementInt = std::stoi(tmpAttackIncrement);

				card = new Horde(tmpTypeInt, tmpName, tmpHealthInt, tmpAttackInt, tmpAttackIncrementInt);
			}
			break;
			default:
			{
				continue;
			}
			break;

		}

		// checking what type of card we have
		//Minion* isMinion = dynamic_cast<Minion*>(card);
		//Vampire* isVampire = dynamic_cast<Vampire*>(card);


		// Add the card to the deck
		Deck.push_back(move(unique_ptr<Card>(card)));
	}
}