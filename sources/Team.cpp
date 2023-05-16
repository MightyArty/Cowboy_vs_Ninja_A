#include "Team.hpp"

using namespace std;
using namespace ariel;

Team::Team(Character *other) : team_leader(other){};

Team::~Team(){};

void Team::add(Character *member) {}

void Team::attack(Team *other_team) {}

int Team::stillAlive()
{
    return 0;
}

void Team::print() {}
