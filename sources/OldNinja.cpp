#include"OldNinja.hpp"

namespace ariel{


    OldNinja::OldNinja(string name ,const Point& location):Ninja(name,location){
        setSpeed(8);
        setHealth(150);
    }
    //OldNinja::~OldNinja(){}

}
