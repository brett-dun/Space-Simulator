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
#include <iostream>
#include <iomanip>

#include "StarSystemObjects.hpp"
#include "Moons.hpp"

class Planet : public StarSystemObject {
public:
    
    //Planet(name, mass, longitudeOfPerihelion, periastron, velocity, reversed, numMoons)
    Planet(std::string name_, int id_, long double mass_, long double longitude_, long double periastron_, long double velocity_, bool reversed_, unsigned short numMoons_);
    Planet(std::string n, int i, long double m, long double pX, long double pY, long double vX, long double vY);
    Planet() : Planet("Planet", rand(), 0, 0, 0, 0, false, 0) {}
    
    /*bool equals(Planet other);
    bool optomizedEquals(Planet other);
    
    std::string toString();
    std::string toSimpleString();
    std::string toCSV();
    
    long double* attraction(Planet other);
    //long double yAttraction(Planet other);
    
    void setVX(long double var);
    void setVY(long double var);
    void setPX(long double var);
    void setPY(long double var);*/
    void addMoon(unsigned short pos, Moon m);
    
    /*std::string getName();
    long getID();
    long double getMass();
    long double getLongitudeOfPerihelion();
    long double getPerihelion();
    long double getVelocity();
    long double getVX();
    long double getVY();
    long double getPX();
    long double getPY();
    bool getReversed();*/
    
private:
    //Original Stuff
    /*std::string name;
    long id;
    long double mass; //kilograms (kg)
    long double longitudeOfPerihelion; //meters (m)
    long double perihelion; //meters (m)
    long double velocity; //meters per second (m/s)
    long double vx; //velocity in the x direction (m/s)
    long double vy; //velocity in the y direction (m/s)
    long double px; //position in the x direction (m)
    long double py; //position in the y direction (m)
    bool reversed;
    //New Stuff*/
    unsigned short numMoons;
    Moon* moons;
    
};

//const Planet SUN =      Planet("Sun",       0,  1.98892 * pow(10, 30),  0, 0, 0, false);

const Planet MERCURY =  Planet("Mercury",   1,  0.33011 * pow(10, 24),  77.45645,   46.00e6 * pow(10, 3),    58.98 * pow(10, 3), false, 0);
const Planet VENUS =    Planet("Venus",     2,  4.8675 * pow(10, 24),   131.53298,  107.48e6 * pow(10, 3),   35.26 * pow(10, 3), true, 0);
const Planet EARTH =    Planet("Earth",     3,  5.9723 * pow(10, 24),   102.94719,  147.09e6 * pow(10, 3),   30.29 * pow(10, 3), false, 1);
const Planet MARS =     Planet("Mars",      4,  0.64171 * pow(10, 24),  336.04084,  206.62e6 * pow(10, 3),   26.50 * pow(10, 3), false, 2);
const Planet JUPITER =  Planet("Jupiter",   5,  1898.19 * pow(10, 24),  14.75385,   740.52e6 * pow(10, 3),   13.72 * pow(10, 3), false, 0);
const Planet SATURN =   Planet("Saturn",    6,  568.34 * pow(10, 24),   92.43194,   1352.55e6 * pow(10, 3),  10.18 * pow(10, 3), false, 0);
const Planet URANUS =   Planet("Uranus",    7,  86.813 * pow(10, 24),   170.96424,  2741.30e6 * pow(10, 3),  7.11 * pow(10, 3), false, 0);
const Planet NEPTUNE =  Planet("Neptune",   8,  102.413 * pow(10, 24),  44.97135,   4444.45e6 * pow(10, 3),  5.50 * pow(10, 3), false, 0);
const Planet PLUTO =    Planet("Pluto",     9,  0.01303 * pow(10, 24),  224.06676,  4436.82e6 * pow(10, 3),  6.10 * pow(10, 3), false, 1);
//http://cs.mcgill.ca/~rwest/wikispeedia/wpcd/wp/e/Eris_%2528dwarf_planet%2529.htm
const Planet ERIS =     Planet("Eris",      10, 1.66e22,                150.977,    5.723e9 * pow(10, 3),               4.126e3, false, 0);

#endif /* Planets_hpp */
