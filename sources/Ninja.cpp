#include "Ninja.hpp"

namespace ariel{

    Ninja::Ninja(string name , const Point& location):Character(name,location){
    }

    void Ninja::move(Character* enemy){
        Point newLocation = Point::moveTowards(location,enemy->getLocation(),speed);
        location=newLocation;
       
    }

    void Ninja::slash(Character* enemy){
        if(enemy == nullptr){
            throw runtime_error("null Pointer");
        }
        else if(!enemy->isAlive()){
            throw runtime_error("enemy dead");
        }
        else if(this== enemy){
            throw runtime_error(" cant slash yourself ");
        }else if(!this->isAlive()){
            throw runtime_error("Ninja dead");
        }
        else if(isAlive() ){
            if(distance(enemy->getLocation()) < 1 ){
                enemy->hit(40);
                isAttack = true;
            }
            else if(distance(enemy->getLocation())>=1){
                isAttack=false;
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
string Ninja::print() {
    string output = "Ninja: ";
    output += Character::print(); 
    output += "\n";
    return output;
}

    void Ninja::attack(Character* enemy){
        if(this->distance(enemy)>=1){
            this->move(enemy);
        }else{
             this->slash(enemy);
        }
  
    }


}

