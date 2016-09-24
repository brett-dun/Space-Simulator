//
//  Moons.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef Moons_hpp
#define Moons_hpp

#include <stdio.h>

#include "SpaceObjects.hpp"

class Moon : public SpaceObject {
public:
    Moon(std::string name_, int id_, double mass_, double longitude_, double pericenter_, double velocity_, bool retrograde_);
    Moon() : Moon("Moon", rand(), 0, 0, 0, 0, false) {}
    
    std::string toString();
    
    bool equals(Moon other);
    
    double getLongitudeOfPericenter();
    double getPericenter();
    bool isRetrograde();
    
private:
    double longitudeOfPericenter; //meters (m)
    double pericenter; //meters (m)
    
    bool retrograde;
};

const Moon GANYMEDE =   Moon();
const Moon TITAN =      Moon();
const Moon CALLISTO =   Moon();
const Moon IO =         Moon();
const Moon MOON =       Moon();
const Moon EUROPA =     Moon();
const Moon TRITAN =     Moon();
const Moon TITANIA =    Moon();
const Moon RHEA =       Moon();
const Moon OBERON =     Moon();
const Moon IAPETUS =    Moon();
const Moon CHARON =     Moon();
const Moon UMBRIEL =    Moon();
const Moon ARIEL =      Moon();
const Moon DIONE =      Moon();
const Moon TETHYS =     Moon();


#endif /* Moons_hpp */
