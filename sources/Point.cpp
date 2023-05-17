#include "Point.hpp"
#include <cmath>
#include <iostream>


using namespace std;

namespace ariel{
    //cons...
    Point::Point():x_coord(0),y_coord(0){}

    Point::Point(double x_coord, double y_coord):x_coord(x_coord),y_coord(y_coord){}

    Point::Point(const Point& other) : x_coord(other.x_coord), y_coord(other.y_coord) {}

    double Point::distance(const Point& other) {
        double xDiff = other.x_coord - this->x_coord;
        double yDiff = other.y_coord - this->y_coord;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    Point Point::moveTowards(Point& source,  Point& destination, double distance) {

        if(distance < 0){
            std::__throw_invalid_argument("distance can not be negative ");
        }
        double currentDistance =source.distance(destination);

        if (currentDistance <= distance) {
            // The destination point is already within or at the given distance
            return destination;
        }
        double ratio = distance / currentDistance;
        double newX = source.x_coord + (destination.x_coord - source.x_coord) * ratio;
        double newY = source.y_coord + (destination.y_coord - source.y_coord) * ratio;
        return Point(newX, newY);
    }
    void Point::print() {
    cout << "Point(" << x_coord << ", " << y_coord << ")" << endl;
    }

    bool Point::operator==(const Point& other) const {
            return x_coord == other.x_coord && y_coord == other.y_coord;
        
    }
    double  Point::getX_coord(){
        return x_coord;
    }
    double  Point::getY_coord(){
        return y_coord;
    }

}