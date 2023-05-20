#include "Character.hpp"
using namespace std;

namespace ariel{

    //Character::Character(){}

    Character::Character(string name , const Point &location):name(name),location(location){
    }
    Character::~Character(){}


    bool Character::isAlive(){
        return this->health > 0;
    }
    double Character::distance (const Point& other){
        return this->location.distance(other);
    }
   
    //setter
    void Character::setLocation( Point& location){
        location = Point(location);
    
    }
    void Character::setHealth(int health){

        this->health = health;
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
        health-= num;
    }

    void Character::print() {
       cout << toString() << endl;
    }
  
    string Character::toString() {
        string result;

        if (isAlive()) {
            result = "Name: " + name + ", Health: " + std::to_string(health) + ", Location: (" + std::to_string(location.getX_coord()) + ", " + std::to_string(location.getY_coord()) + ")";
        } else {
            result = "Name: (" + name + "), Location: (" + std::to_string(location.getX_coord()) + ", " + std::to_string(location.getY_coord()) + ")";
        }
        return result;
    }



    


}