#include "Ninja.hpp"

namespace ariel{

    Ninja::Ninja(string name , const Point& location):Character(name,location){
    }

    void Ninja::move(Character* enemy){
        Point newLocation = Point::moveTowards(location,enemy->getLocation(),speed);
        this->setLocation(newLocation);
       
    }

    void Ninja::slash(Character* enemy){
        while(isAlive() && distance(enemy->getLocation()) <= 1 ){
            enemy->hit(40);
        }

    }

    void Ninja::setSpeed(int speed){
    this->speed = speed ;
    }
    int Ninja::getSpeed(){
        return speed;

    }
}

