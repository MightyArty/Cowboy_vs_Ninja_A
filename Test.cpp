#include "doctest.h"
#include "sources/Team.hpp"

#include <math.h>
#include <vector>
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("Point")
{
    SUBCASE("Constructor and getters")
    {
        Point p(2.5, 3.7);
        CHECK(p.getX() == 2.5);
        CHECK(p.getY() == 3.7);
    }

    SUBCASE("Empty Constructor")
    {
        Point p;
        CHECK(p.getX() == 0.0);
        CHECK(p.getY() == 0.0);
    }

    SUBCASE("Setters")
    {
        Point p;
        p.setX(2.5);
        p.setY(3.7);
        CHECK(p.getX() == 2.5);
        CHECK(p.getY() == 3.7);
    }

    SUBCASE("Print")
    {
        Point p(3.2, 4.8);
        ostringstream oss;
        streambuf *old_buf = cout.rdbuf();
        cout.rdbuf(oss.rdbuf());
        p.print();
        cout.rdbuf(old_buf);
        CHECK(oss.str() == "(3.2, 4.8)");
    }

    SUBCASE("Distance")
    {
        Point p1(1.0, 2.0);
        Point p2(4.0, 6.0);
        CHECK(p1.distance(p2) == 5.0);

        Point p3(2, 2);
        Point p4(3, 3);
        CHECK(p3.distance(p4) == sqrt(2));
    }

    SUBCASE("Move Towards")
    {
        Point p1(1.0, 1.0);
        Point p2(4.0, 5.0);
        double distance = 4.0;
        Point p3 = p1.moveTowards(p1, p2, distance);
        CHECK(p3.getX() == 2.0);
        CHECK(p3.getY() == 3.0);
    }
}

TEST_CASE("Character")
{

    Point location(1, 1);
    Character *cowboy1 = new Cowboy("Tom", location);
    Character *cowboy2 = new Cowboy("Neta", location);

    SUBCASE("Getter")
    {
        CHECK(cowboy1->getName() == "Tom");
        CHECK(cowboy2->getName() == "Neta");
    }

    SUBCASE("Distance")
    {
        CHECK(cowboy1->distance(cowboy2) == 0.0);
    }

    SUBCASE("Location")
    {
        CHECK(cowboy1->getLocation().distance(location) == 0.0);
    }

    SUBCASE("isAlive")
    {
        CHECK(cowboy1->isAlive() == true);
    }

    SUBCASE("Hit")
    {
        cowboy1->hit(110);
        CHECK(cowboy1->isAlive() == false);
        cowboy2->hit(5);
        CHECK(cowboy2->isAlive() == true);
    }
}

TEST_CASE("Ninja")
{
    Point location1(2, 2);
    Point location2(3, 3);
    Ninja *ninja1 = new Ninja("Samuray Jack", location1);
    Ninja *ninja2 = new Ninja("Son Tzu", location2);

    SUBCASE("Getter for Ninja")
    {
        CHECK(ninja1->getName() == "Samuray Jack");
        CHECK(ninja2->getName() == "Son Tzu");
    }

    SUBCASE("Slash for Ninja")
    {
        Point p1(2, 5);
        Cowboy *cowboy = new Cowboy("Arthur", p1);
        ninja1->slash(cowboy);
        CHECK(cowboy->isAlive() == false);
    }

    SUBCASE("Move Towards for Ninja")
    {
        Cowboy *cowboy = new Cowboy("Nicka", location2);
        ninja1->move(cowboy);
        CHECK(ninja1->getLocation().distance(location2) < 1.5);
    }
}

TEST_CASE("Old Ninja")
{
    Point location1(2, 2);
    Point location2(3, 3);
    OldNinja *old_ninja = new OldNinja("Grandpa", location1);

    SUBCASE("Getter for Old Ninja")
    {
        CHECK(old_ninja->getName() == "Grandpa");
        CHECK(old_ninja->getHealth() == 150);
    }

    SUBCASE("Move towards for Old Ninja")
    {
        Cowboy *cowboy = new Cowboy("Gendalf", location2);
        old_ninja->move(cowboy);
        CHECK(old_ninja->getLocation().distance(location2) < 1.5);
    }

    SUBCASE("Slash for Old Ninja")
    {
        Point p1(2, 5);
        Cowboy *cowboy = new Cowboy("Arthur", p1);
        old_ninja->slash(cowboy);
        CHECK(cowboy->isAlive() == false);
    }
}

TEST_CASE("Young Ninja")
{
    Point location1(2, 2);
    Point location2(3, 3);
    YoungNinja *child_ninja = new YoungNinja("ChildNinja", location1);

    SUBCASE("Getter for Young Ninja")
    {
        CHECK(child_ninja->getName() == "ChildNinja");
        CHECK(child_ninja->getHealth() == 100);
    }

    SUBCASE("Move towards for Young Ninja")
    {
        Cowboy *cowboy = new Cowboy("Arthur", location2);
        child_ninja->move(cowboy);
        CHECK(child_ninja->getLocation().distance(location2) < 1.5);
    }

    SUBCASE("Slash for Old Ninja")
    {
        Point p1(2, 5);
        Cowboy *cowboy = new Cowboy("Arthur", p1);
        child_ninja->slash(cowboy);
        CHECK(cowboy->isAlive() == false);
    }
}

TEST_CASE("Trained Ninja")
{
    Point location1(2, 2);
    Point location2(3, 3);
    TrainedNinja *good_ninja = new TrainedNinja("goodNinja", location1);

    SUBCASE("Getter for Young Ninja")
    {
        CHECK(good_ninja->getName() == "goodNinja");
        CHECK(good_ninja->getHealth() == 120);
    }

    SUBCASE("Move towards for Young Ninja")
    {
        Cowboy *cowboy = new Cowboy("Arthur", location2);
        good_ninja->move(cowboy);
        CHECK(good_ninja->getLocation().distance(location2) < 1.5);
    }

    SUBCASE("Slash for Old Ninja")
    {
        Point p1(2, 5);
        Cowboy *cowboy = new Cowboy("Arthur", p1);
        good_ninja->slash(cowboy);
        CHECK(cowboy->isAlive() == false);
    }
}

TEST_CASE("Cowboy")
{
    Point location(5, 6);
    Cowboy *cowboy = new Cowboy("Arthur", location);

    SUBCASE("Getters")
    {
        CHECK(cowboy->getName() == "Arthur");
        CHECK(cowboy->hasBoolets() == true);
        CHECK(cowboy->isAlive() == true);
    }

    SUBCASE("Shoot - reload")
    {
        Point p(6, 7);
        OldNinja *old = new OldNinja("Old", p);
        for (int i = 0; i < 6; i++)
        {
            cowboy->shoot(old);
        }
        CHECK(old->isAlive() == false);
        CHECK(cowboy->hasBoolets() == false);
        cowboy->reload();
        CHECK(cowboy->hasBoolets() == true);
    }
}

TEST_CASE("Team")
{
    Point p1(2, 3);
    Point p2(4, 5);
    Point p3(6, 7);
    Point p4(8, 9);
    Cowboy *cowboy = new Cowboy("Arthur Morgan", p1);
    YoungNinja *ninja = new YoungNinja("Ninja Jack", p2);
    Team *red_team = new Team(cowboy);
    Team *blue_team = new Team(ninja);

    SUBCASE("Add members and check how much members there is")
    {
        CHECK(red_team->stillAlive() == 1);
        CHECK(blue_team->stillAlive() == 1);

        Cowboy *cowboy2 = new Cowboy("Cowboy", p3);
        TrainedNinja *ninja2 = new TrainedNinja("Trained Ninja", p4);
        red_team->add(cowboy2);
        blue_team->add(ninja2);
        CHECK(red_team->stillAlive() == 2);
        CHECK(blue_team->stillAlive() == 2);

        OldNinja *old_ninja = new OldNinja("Old ninja", p1);
        Cowboy *cowboy3 = new Cowboy("Tom", p2);
        red_team->add(old_ninja);
        blue_team->add(cowboy3);
        CHECK(red_team->stillAlive() == 3);
        CHECK(blue_team->stillAlive() == 3);
    }

    SUBCASE("Attack")
    {
        blue_team->attack(red_team);
        CHECK(blue_team->stillAlive() == 0);
    }
}