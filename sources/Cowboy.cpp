#include "Cowboy.hpp"


namespace ariel{

    Cowboy::Cowboy(string name , const Point& location):Character(name,location),amountOfBalls(6){
        setHealth(110);
    }

  //  Cowboy::~Cowboy(){}
    void Cowboy::shoot(Character* enemy) {
    if (enemy == nullptr) {
        throw std::invalid_argument("NULL POINTER");
    } 
    if (!this->isAlive()) {
        throw std::runtime_error("Cowboy is dead");
    } 
    if(!enemy->isAlive()){
        throw std::runtime_error("enemy is dead(Cowboy)");
    }  
    if (this == enemy) {
        throw std::runtime_error("Can't shoot yourself");
    }
    if (hasboolets() && this->isAlive()) {
        enemy->hit(10);
        amountOfBalls--;
    }
}

    bool Cowboy::hasboolets(){
        return amountOfBalls > 0;
    }
    
    void Cowboy::reload(){
        if(isAlive()){
            amountOfBalls=6;
        }else{
            throw runtime_error("the cowboy is dead cant reload");
        }
        
    }
    int Cowboy::getAbility()const{
        return 10;
    }

    
    int Cowboy::getAmountOfBalls(){
        return amountOfBalls;
    }

  string Cowboy::print() {
    string output = "Cowboy: ";
    output += Character::print();  // Call the base class print function
    output += "Bullets: " + to_string(amountOfBalls) + "\n";
    return output;
}


    void Cowboy::attack(Character* enemy){
        this->shoot(enemy);
    }
}
   
