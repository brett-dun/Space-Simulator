//
//  Planets.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef Planets_hpp
#define Planets_hpp

#include <stdio.h>
#include <string>
#include <math.h>
#include <sstream>
//#include <iostream>

const double G = 6.67428e-11;
const double AU = (1.495978707 * 10e8) * 10e3;

class Planet {
public:
    
    //Planet(name, mass, longitudeOfPerihelion, periHelion, velocity, reversed)
    Planet(std::string n, long i, double m, double longitude, double p, double v, bool r);
    Planet() : Planet("Planet", rand(), 0, 0, 0, 0, false) {}
    
    bool equals(Planet other);
    bool optomizedEquals(Planet other);
    
    std::string toString();
    std::string toSimpleString();
    std::string toCSV();
    
    double* attraction(Planet other);
    //double yAttraction(Planet other);
    
    std::string name;
    long id;
    double mass; //kilograms (kg)
    double longitudeOfPerihelion; //meters (m)
    double perihelion; //meters (m)
    double velocity; //meters per second (m/s)
    double vx; //velocity in the x direction (m/s)
    double vy; //velocity in the y direction (m/s)
    double px; //position in the x direction (m/s)
    double py; //position in the y direction (m/s)
    bool reversed;
    
};

const Planet SUN =      Planet("Sun",       0,  1.98892 * pow(10, 30),  0, 0, 0, false);
const Planet MERCURY =  Planet("Mercury",   1,  0.33011 * pow(10, 24),  77.45645,   46.00 * pow(10, 6) * pow(10, 3),    58.98 * pow(10, 3), false);
const Planet VENUS =    Planet("Venus",     2,  4.8675 * pow(10, 24),   131.53298,  107.48 * pow(10, 6) * pow(10, 3),   35.26 * pow(10, 3), true);
const Planet EARTH =    Planet("Earth",     3,  5.9723 * pow(10, 24),   102.94719,  147.09 * pow(10, 6) * pow(10, 3),   30.29 * pow(10, 3), false);
const Planet MARS =     Planet("Mars",      4,  0.64171 * pow(10, 24),  336.04084,  206.62 * pow(10, 6) * pow(10, 3),   26.50 * pow(10, 3), false);
const Planet JUPITER =  Planet("Jupiter",   5,  1898.19 * pow(10, 24),  14.75385,   740.52 * pow(10, 6) * pow(10, 3),   13.72 * pow(10, 3), false);
const Planet SATURN =   Planet("Saturn",    6,  568.34 * pow(10, 24),   92.43194,   1352.55 * pow(10, 6) * pow(10, 3),  10.18 * pow(10, 3), false);
const Planet URANUS =   Planet("Uranus",    7,  86.813 * pow(10, 24),   170.96424,  2741.30 * pow(10, 6) * pow(10, 3),  7.11 * pow(10, 3), false);
const Planet NEPTUNE =  Planet("Neptune",   8,  102.413 * pow(10, 24),  44.97135,   4444.45 * pow(10, 6) * pow(10, 3),  5.50 * pow(10, 3), false);
const Planet PLUTO =    Planet("Pluto",     9,  0.01303 * pow(10, 24),  224.06676,  4436.82 * pow(10, 6) * pow(10, 3),  6.10 * pow(10, 3), false);

#endif /* Planets_hpp */
