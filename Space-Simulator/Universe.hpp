//
//  Universe.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 8/6/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef Universe_hpp
#define Universe_hpp

#include <stdio.h>

#include "SpaceObjects.hpp"
    #include "StarSystemObjects.hpp"
        #include "Planets.hpp"
    #include "MassiveObjects.hpp"
        #include "Stars.hpp"
    #include "Moons.hpp"

class Universe {
public:
    Universe(unsigned int updateTime_, unsigned int iterations_, const SpaceObject *objects_, unsigned short numPlanets_);
    Universe(unsigned int updateTime_, unsigned int iterations_, SpaceObject *objects_, unsigned short numPlanets_);
    //void setObjects(SpaceObject *object_);
    void update();
    void run();
    void removeUnused();
private:
    unsigned short numPlanets;
    unsigned int updateTime;
    unsigned int iterations;
    SpaceObject *objects;
};

const SpaceObject SOLAR_SYSTEM[11] = {SUN, MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO, ERIS};
const SpaceObject INNER_SOLAR_SYSTEM[5] = {SUN, MERCURY, VENUS, EARTH, MARS};
const SpaceObject OUTER_SOLAR_SYSTEM[7] = {SUN, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO, ERIS};

#endif /* Universe_hpp */
