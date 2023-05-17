#pragma once 
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel {

    class Character {
        
    private:
        Point location;
        string name;
        int health;
        
    public:
        Character();
        Character(const Character& other); // Copy constructor
        Character(string name, const Point& location);
        virtual ~Character();
        Character& operator=(const Character&) = default;  // Copy assignment operator
        Character(Character&&) = default;                  // Move constructor
        Character& operator=(Character&&) = default;       // Move assignment operator

        // Setter 
        void setHealth(int health);

        // Getter
        Point getLocation();
        string getName();
        int getHealth();

        bool isAlive();                    // Return true if Character health > 0
        double distance(const Point& point1);  // Distance between 2 characters
        virtual void hit(int num);         // Reduce the health of the character 
        virtual string print();            // Print: name, health, location, isAlive() 
    };

}
