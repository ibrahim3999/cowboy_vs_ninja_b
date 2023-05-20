#include "YoungNinja.hpp"

namespace ariel{

    YoungNinja::YoungNinja(string name ,const Point& location): Ninja(name,location){
        setSpeed(14);
        this->setHealth(100);
    }
    //YoungNinja::~YoungNinja(){}
}