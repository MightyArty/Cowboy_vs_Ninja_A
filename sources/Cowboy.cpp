#include "Cowboy.hpp"

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point location) : Character(name, location), bullets(6){};

void Cowboy::shoot(Character *other)
{
    return;
}

bool Cowboy::hasBoolets()
{
    return true;
}

void Cowboy::reload()
{
    return;
}

string Cowboy::print()
{
    string s = "";
    return s;
}