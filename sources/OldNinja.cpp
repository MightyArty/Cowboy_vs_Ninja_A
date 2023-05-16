#include "OldNinja.hpp"

using namespace std;
using namespace ariel;

OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
{
    this->setHealth(150);
};