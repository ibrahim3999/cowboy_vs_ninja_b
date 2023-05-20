#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name , const Point& location):Character(name,location),amountOfBalls(6){
        setHealth(110);
    }

  //  Cowboy::~Cowboy(){}

    void Cowboy::shoot(Character* enemy){
        while(isAlive() && hasboolets()){
          enemy->hit(10);
          amountOfBalls--;
        }
    }

    bool Cowboy::hasboolets(){
        
        return amountOfBalls > 0;
    }
    
    void Cowboy::reload(){
        amountOfBalls = 6;
    }

    
    int Cowboy::getAmountOfBalls(){
        return amountOfBalls;
    }
   

}