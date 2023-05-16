#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets; // Cowboy starts with 6

    public:
        /**
         * @brief Main constructor of Cowboy
         * @param name the name of the Cowboy
         * @param location the location of the Cowboy on the board
         */
        Cowboy(string name, Point location);

        /**
         * @brief if the Cowboy is alive and has boolets, he shoots the enemy and
         * decrease from the enemy 10 points, and looses 1 boolet.
         * Otherwise - the enemy will take no damage
         * @param other the enemy to shoot at
         */
        void shoot(Character *other);

        /**
         * @return true if the Cowboy as boolets, false otherwise
         */
        bool hasBoolets();

        /**
         * @brief reload the gun with 6 new boolets
         */
        void reload();

        string print() override;
    };
}

#endif