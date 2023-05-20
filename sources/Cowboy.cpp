#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name , const Point& location):Character(name,location),amountOfBalls(6){
        setHealth(110);
    }

  //  Cowboy::~Cowboy(){}

    void Cowboy::shoot(Character* enemy){
        if(enemy == NULL){
            throw runtime_error("NULL POINTER");
        }
        else if(!this->isAlive()){
            throw runtime_error("COWBOY IS DEAD");
        }
        else if(isAlive() && hasboolets()){
          enemy->hit(10);
          amountOfBalls--;
        }
        else if(!hasboolets()){
            reload();
        }
    }

    bool Cowboy::hasboolets(){
        return amountOfBalls > 0;
    }
    
    void Cowboy::reload(){
        if(isAlive()){
            amountOfBalls = 6;
        }
        
    }
    int Cowboy::getAbility()const{
        return 10;
    }

    
    int Cowboy::getAmountOfBalls(){
        return amountOfBalls;
    }

    void Cowboy::print() {
        cout << "Cowboy:";
        Character::print();  // Call the base class print function
        cout << "Bullets: " << amountOfBalls << endl;
    }
}
   
