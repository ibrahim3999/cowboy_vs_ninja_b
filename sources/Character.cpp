#include "Character.hpp"
using namespace std;

namespace ariel{

    //Character::Character(){}

    Character::Character(string name , const Point &location):name(name),location(location),joinedTeam(false){
    }
    Character::~Character(){}


    bool Character::isAlive(){
        return health > 0;
    }
    double Character::distance (const Point& other){
        return this->location.distance(other);
    }
    double Character::distance (Character* other){
        return this->location.distance(other->getLocation());
    }
   
    //setter
    void setLocation( Point& location){
        location = Point(location);
    
    }
    void Character::setHealth(int health){

        this->health = health;
    }
    bool Character::getJoinedTeam(){
        return joinedTeam;
    }
    void Character::setJoinedteam(){
            joinedTeam = !joinedTeam;
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
        if(num < 0){
            throw invalid_argument(" Damage cant be -num");
        }
        health-= num;
        if(health<0)health=0;
 
    }

    string Character::print() {
       return toString() ;
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
