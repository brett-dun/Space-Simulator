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


//Using double allows the program to run over 87.6% faster compared to float and over 10.6% faster compared to long double
const double G = 6.67428e-11; //Gravitational Constant
const double AU = 149597870.7e3; //(1.495978707 * pow(10, 7)) * 10e3; //Meters
const double SPEED_OF_LIGHT = 299792458; //Meters / Second

class SpaceObject {
public:
    SpaceObject(std::string name_, int id_, double mass_, double vx_, double vy_, double px_, double py_);
    SpaceObject() : SpaceObject("Space Object", rand(), 0, 0, 0, 0, 0) {}
    SpaceObject(const SpaceObject &obj);
    //~SpaceObject();
    
    bool equals(SpaceObject other);
    bool optomizedEquals(SpaceObject other);
    
    std::string toString() const;
    std::string toSimpleString() const;
    std::string toCSV() const;
    
    double* attraction(SpaceObject other);
    double* attraction2(SpaceObject other);
    
    void setVX(double var);
    void setVY(double var);
    void setPX(double var);
    void setPY(double var);
    
    void setVZ(double var);
    void setPZ(double var);
    void setName(std::string name);
    
    std::string getName() const;
    long getID() const;
    double getMass() const;
    
    double getVelocity() const;
    double getVX() const;
    double getVY() const;
    double getPX() const;
    double getPY() const;
    
    double getVZ() const;
    double getPZ() const;
    
protected:
    
    std::string name;
    
    int id;
    
    double mass; //kilograms (kg)
    double velocity; //meters per second (m/s)
    double vx; //velocity in the x direction (m/s)
    double vy; //velocity in the y direction (m/s)
    double px; //position in the x direction (m)
    double py; //position in the y direction (m)
    
    double vz;
    double pz;
    
    
};

#endif /* SpaceObjects_hpp */
