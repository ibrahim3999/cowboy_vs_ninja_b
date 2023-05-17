#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name , const Point& location):Character(name,location),amountOfBalls(15){

    }

  //  Cowboy::~Cowboy(){}

    void Cowboy::shoot(Character* enemy){

    }

    bool Cowboy::hasBullets(){
        return true;
    }
    
    void Cowboy::reload(){

    }

    
    int Cowboy::getAmountOfBalls(){
        return 0;
    }
    


}