#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double x, double y);
        Point();
        ~Point() = default;

        double getX() const;
        double getY() const;

        void print() const;

        /**
         * @brief computes the distance of two points
         * @return the distance
         * @param other the second point to compare
         */
        double distance(const Point &other) const;

        /**
         * @param first the source point
         * @param second the destination point
         * @param distance the max distance between the two points
         * @return the closest point to the destination point
         */
        Point moveTowards(Point &first, Point &second, double distance) const;
    };
}

#endif