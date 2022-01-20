#include "Wall.h"
#include "Player.h"
#include <iostream>

using namespace std;

Wall::Wall(int type, string name, int health, int attack) : Minion(type, name, health, attack)
{
}


Wall::~Wall()
{
}

void Wall::Attack(Player& owner, Player& enemy, int random)
{
}