#include"TrainedNinja.hpp"

namespace ariel{
    TrainedNinja::TrainedNinja(string name, const Point& location):Ninja(name,location){
        setSpeed(12);
        this->setHealth(120);
    }

   // TrainedNinja::~TrainedNinja(){}
}