#include "Character.hpp"
using namespace std;
using namespace ariel;

Character::Character(string name, Point &location) : name(name), location(location)
{
    this->health = 0;
}

Character::Character(Character &other) : name(other.name), location(other.location) {}

Character::~Character(){};

string Character::getName()
{
    return this->name;
}

Point Character::getLocation()
{
    Point p(0, 0);
    return p;
}

bool Character::isAlive()
{
    return true;
}

double Character::distance(Character *other)
{
    return 0;
}

void Character::hit(int points_to_take)
{
    return;
}

string Character::print()
{
    string s = "";
    return s;
}

Character &Character::operator=(const Character &other)
{
    return *this;
}
