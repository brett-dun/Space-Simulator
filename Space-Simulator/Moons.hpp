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

class Moon : protected SpaceObject {
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

const Moon Ganymede =   Moon();
const Moon Titan =      Moon();
const Moon Callisto =   Moon();
const Moon Io =         Moon();
const Moon moon =       Moon();
const Moon Europa =     Moon();
const Moon Triton =     Moon();
const Moon Titania =    Moon();
const Moon Rhea =       Moon();
const Moon Oberon =     Moon();
const Moon Iapetus =    Moon();
const Moon Charon =     Moon();
const Moon Umbriel =    Moon();
const Moon Ariel =      Moon();
const Moon Dione =      Moon();
const Moon Tethys =     Moon();


#endif /* Moons_hpp */
