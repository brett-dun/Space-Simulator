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

class Star : public SpaceObject {
public:
    Star(std::string name_, int id_, double mass_, double vx_, double vy_, double px_, double py_);
    Star() : Star("Star", rand(), 0, 0, 0, 0, 0) {}
};

const Star SUN =                Star("Sun",                 0,      1.98892e30,             0, 0, 0, 0);
const Star PROXIMA_CENTAURI =   Star("Proxima Centauri",    rand(), 0.123 * SUN.getMass(),  0, 0, 0, 0);
const Star ALPHA_CENTAURI_A =   Star("Alpha Centauri A",    rand(), 1.100 * SUN.getMass(),  0, 0, 0, 0);
const Star ALPHA_CENTAURI_B =   Star("Alpha Centauri B",    rand(), 0.907 * SUN.getMass(),  0, 0, 0, 0);
const Star BARNARDS_STAR =      Star("Barnards Star",       rand(), 0.144 * SUN.getMass(),  0, 0, 0, 0);
const Star LUHMAN_16A =         Star("Luhman 16A",          rand(), 0.04 * SUN.getMass(),   0, 0, 0, 0);
const Star LUUMAN_16B =         Star("Luhman 16B",          rand(), 0.03 * SUN.getMass(),   0, 0, 0, 0);
const Star WISE_0855_0714 =     Star("Wise 0855-0714",      rand(), 0,                      0, 0, 0, 0);
const Star WOLF_359 =           Star("Wolf 359",            rand(), 0.09 * SUN.getMass(),   0, 0, 0, 0);
const Star LALANDE_21185 =      Star("Lalande 21185",       rand(), 0.46 * SUN.getMass(),   0, 0, 0, 0);
const Star SIRIUS_A =           Star("Sirius A",            rand(), 2.02 * SUN.getMass(),   0, 0, 0, 0);
const Star SIRIUS_B =           Star("Sirius B",            rand(), 0.978 * SUN.getMass(),  0, 0, 0, 0);


#endif /* Stars_hpp */
