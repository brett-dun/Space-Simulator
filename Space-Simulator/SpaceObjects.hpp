//
//  SpaceObjects.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef SpaceObjects_hpp
#define SpaceObjects_hpp

#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
#include <iostream>
#include <iomanip>

const long double G = 6.67428e-11;
const long double AU = 149597870.7e3; //(1.495978707 * pow(10, 7)) * 10e3;

class SpaceObject {
public:
    SpaceObject(std::string name_, long id_, long double mass_, long double vx_, long double vy_, long double px_, long double py_);
    SpaceObject() : SpaceObject("Space Object", rand(), 0, 0, 0, 0, 0) {}
    
    bool equals(SpaceObject other);
    bool optomizedEquals(SpaceObject other);
    
    std::string toString();
    std::string toSimpleString();
    std::string toCSV();
    
    long double* attraction(SpaceObject other);
    
    void setVX(long double var);
    void setVY(long double var);
    void setPX(long double var);
    void setPY(long double var);
    
    std::string getName();
    long getID();
    long double getMass();
    
    long double getVelocity();
    long double getVX();
    long double getVY();
    long double getPX();
    long double getPY();
    
protected:
    
    std::string name;
    
    long id;
    
    long double mass; //kilograms (kg)
    long double velocity; //meters per second (m/s)
    long double vx; //velocity in the x direction (m/s)
    long double vy; //velocity in the y direction (m/s)
    long double px; //position in the x direction (m)
    long double py; //position in the y direction (m)
    
    
};

#endif /* SpaceObjects_hpp */
