#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Cowboy
    {
    private:
        int bullets; // needs to be 6 at start
        Point location;
        string name;

    public:
        Cowboy(string name, Point &location);
        Cowboy();
        ~Cowboy() = default;

        string getName() const;
        Point getLocation() const;

        /**
         * @brief if the Cowboy is alive and has boolets, he shoots the enemy and
         * decrease from the enemy 10 points, and looses 1 boolet.
         * Otherwise - the enemy will take no damage
         * @param other the enemy
         */
        void shoot(Character &other);

        /**
         * @return true if the Cowboy as boolets, false otherwise
         */
        bool hasBoolets() const;

        /**
         * @brief reload the gun with 6 new boolets
         */
        void reload() const;

        /**
         * @return true if the Cowboy is alive, false otherwise
         */
        bool isAlive() const;

        void print();
    };
}

#endif