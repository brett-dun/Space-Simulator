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
    Universe(unsigned short numPlanets_, unsigned short updateTime_, unsigned short iterations_, SpaceObject *objects_);
    void run();
private:
    unsigned short numPlanets;
    unsigned short updateTime;
    unsigned short iterations;
    SpaceObject *objects;
};

#endif /* Universe_hpp */
