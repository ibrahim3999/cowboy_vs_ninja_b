#include "Ninja.hpp"

namespace ariel{

    Ninja::Ninja(string name , const Point& location):Character(name,location){
    }

    void Ninja::move(Character* enemy){
        Point newLocation = Point::moveTowards(location,enemy->getLocation(),speed);
        location=newLocation;
       
    }

    void Ninja::slash(Character* enemy){
        if(isAlive() ){
            if(distance(enemy->getLocation()) <= 1 ){
                enemy->hit(40);
            }
        }
    }
    int Ninja::getAbility() const{
        return 40;
    }

    void Ninja::setSpeed(int speed){
    this->speed = speed ;
    }
    int Ninja::getSpeed(){
        return speed;

    }

void Ninja::print() {
    cout << "Ninja:";
    Character::print();  // Call the base class print function
    cout << "" << endl;
}
}

