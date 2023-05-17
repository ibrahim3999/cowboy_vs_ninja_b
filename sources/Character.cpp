#include "Character.hpp"

namespace ariel{

    Character::Character(){

    }

    Character::Character(string name , const Point &location):name(name),location(location){

    }
   Character::~Character(){}


    bool Character::isAlive(){
        return true;
    }
    double Character::distance (const Point& point1){
        return 0;
    }
   
    //setter

    void Character::setHealth(int health){

    }


    //getter
    Point Character::getLocation(){
        return location;
    }

    string Character::getName(){
        return name;
        
    }
    int Character::getHealth(){
        return health;
    }
    void Character::hit(int num) {
    // Implementation of hit function
    // Reduce the health of the character by the specified amount
    }

    string Character::print() {
    // Implementation of print function
    // Generate a string containing the character's name, health, location, and alive status
    // Return the generated string
     return "";
    }


}
           
           
           
        
        