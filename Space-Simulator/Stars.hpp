//
//  Stars.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef Stars_hpp
#define Stars_hpp

#include <stdio.h>

#include "SpaceObjects.hpp"

class Star : protected SpaceObject {
public:
    Star(std::string name_, int id_, long double mass_, long double velocity_);
    Star() : Star("Star", rand(), 0, 0) {}
};

const Star SUN =                Star("Sun",   0,  1.98892 * pow(10, 30),  0);
const Star PROXIMA_CENTAURI =   Star();
const Star ALPHA_CENTAURI_A =   Star();
const Star ALPHA_CENTAURI_B =   Star();
const Star BARNARDS_STAR =      Star();
const Star LUHMAN_16A =         Star();
const Star LUUMAN_16B =         Star();
const Star WISE_0855_0714 =     Star();
const Star WOLF_359 =           Star();
const Star LALANDE_21185 =      Star();
const Star SIRIUS_A =           Star();
const Star SIRIUS_B =           Star();


#endif /* Stars_hpp */
