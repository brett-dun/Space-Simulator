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
    SpaceObject(std::string name_, int id_, long double mass_, long double vx_, long double vy_, long double px_, long double py_);
    SpaceObject() : SpaceObject("Space Object", rand(), 0, 0, 0, 0, 0) {}
    SpaceObject(const SpaceObject &obj);
    ~SpaceObject();
    
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
    
    std::string getName() const;
    long getID() const;
    long double getMass() const;
    
    long double getVelocity() const;
    long double getVX() const;
    long double getVY() const;
    long double getPX() const;
    long double getPY() const;
    
protected:
    
    std::string name;
    
    int id;
    
    long double mass; //kilograms (kg)
    long double velocity; //meters per second (m/s)
    long double vx; //velocity in the x direction (m/s)
    long double vy; //velocity in the y direction (m/s)
    long double px; //position in the x direction (m)
    long double py; //position in the y direction (m)
    
    
};

#endif /* SpaceObjects_hpp */
