#include "YoungNinja.hpp"

using namespace std;
using namespace ariel;

YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location)
{
    this->setHealth(100);
};