#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        /**
         * @brief Main constructor for the YouNinja object
         * @param name the name of the YoungNinja
         * @param location the location of the YoungNinja on the board
         */
        YoungNinja(string name, Point location);
    };
}

#endif