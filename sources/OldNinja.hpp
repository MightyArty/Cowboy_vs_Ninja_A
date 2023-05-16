#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        /**
         * @brief Main constructor for OldNinja object
         * @param name the OldNinja name
         * @param location the location of the OldNinja on the board
         */
        OldNinja(string name, Point location);
    };
}

#endif