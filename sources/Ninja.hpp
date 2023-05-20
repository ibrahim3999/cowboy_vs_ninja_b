#pragma once
#include "Character.hpp"

namespace ariel{

    class Ninja : public Character{

        public:
        
            Ninja(string name, const Point& location);

            void move(Character*);// moce to other character
            void slash(Character*);// if the dis<1 and the enemy is alive reduce health from the enemy

            //getter and setter
            void setSpeed(int);
            int getSpeed();
            void print()override;
            int getAbility() const override; 

        private:
            int speed;

        
    };


}