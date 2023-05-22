#pragma once 
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel {

    class Character {

    protected: 
        Point location;
        int health;

    private:
        string name;
        bool joinedTeam;

        
    public:
        //Character();
        Character(const Character& other); // Copy constructor
        Character(string name, const Point& location);
        virtual ~Character();
        Character& operator=(const Character&) = default;  // Copy assignment operator
        Character(Character&&) = default;                  // Move constructor
        Character& operator=(Character&&) = default;       // Move assignment operator

        // Setter 
        void setHealth(int health);
        void setLocation( Point&);
        // Getter
        Point getLocation();
        string getName();
        int getHealth();
        bool getJoinedTeam();
        void setJoinedteam();
        double distance (Character* other);

        string toString();
        bool isAlive();                    // Return true if Character health > 0
        double distance(const Point& other);  // Distance between 2 characters
        virtual void hit(int num);         // Reduce the health of the character 
        virtual void print();            // Print: name, health, location, isAlive() 
        virtual int getAbility() const = 0;
        virtual void attack(Character*)=0;
    };

}
