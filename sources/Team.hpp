#ifndef TEAM_HPP
#define TEAM_HPP

#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"

#include <vector>

namespace ariel
{
    class Team
    {
    private:
        Character *team_leader;
        vector<Character *> warriors_group{10};

    public:
        // Constructor and Deconstructor
        Team(Character *other);
        ~Team();

        /**
         * @brief adding new member to the team
         * @param member the new Character that would be added
         */
        void add(Character *member);

        /**
         * @brief function to attak the other team
         * @param other_team the enemy team to attak
         */
        void attack(Team *other_team);

        /**
         * @brief Checking if the team is alive
         * @return the number of members that are still alive
         */
        int stillAlive();

        void print();
    };
}

#endif