#pragma once
#include <iostream>
namespace ariel {

    class Point {

    private:
        double x_coord;
        double y_coord;

    public:
        Point();

        Point(double x_coord, double y_coord);
        //copy cons..
        Point(const Point& other);

        double distance(const Point& other);//return the distance stance between 2 points 
        
        static Point moveTowards( Point& source, Point& destination ,double distance);// return the closet point 
        
        void print() ;//printf Point 

        bool operator==(const Point& other) const ;

        //getter and setter
        double getX_coord();
        double getY_coord();

        
    };
}


