#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        /**
         * @brief Main constructor for the TrainedNinja object
         * @param name the name of the TrainedNinja
         * @param location the location of the TrainedNinja on the board
         */
        TrainedNinja(string name, Point location);
    };
}

#endif