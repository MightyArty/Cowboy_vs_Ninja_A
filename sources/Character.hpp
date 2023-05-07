#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int point;
        string name;

    public:
        Character(string name, Point &location, int point);
        Character();
        ~Character() = default;

        string getName() const;
        Point getLocation() const;

        /**
         * @return true if the given Character is alive, false otherwise
         */
        bool isAlive() const;

        /**
         * @return the distance between the two Characters
         * @param other the second Character to compare
         */
        double distance(const Character &other) const;

        /**
         * @brief reduces the given points from the health of the Character
         * @param points the amount of health to take
         */
        void hit(int points);

        void print();
    };
}

#endif
