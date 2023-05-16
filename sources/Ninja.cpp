#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point location) : Character(name, location) {}

string Ninja::print()
{
    string s = "";
    return s;
}

void Ninja::move(Character *other)
{
    return;
}

void Ninja::slash(Character *other)
{
    return;
}

int Ninja::getHealth()
{
    return this->health;
}

int Ninja::setHealth(int health)
{
    int new_helath = health;
    this->health = new_helath;
    return this->health;
}