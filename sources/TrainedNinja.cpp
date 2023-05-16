#include "TrainedNinja.hpp"

using namespace std;
using namespace ariel;

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
    this->setHealth(120);
}