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
    Star(std::string name_, long id_, long double mass_, long double velocity_);
    Star() : Star("Star", rand(), 0, 0) {}
};

const Star SUN =  Star("Sun",   0,  1.98892 * pow(10, 30),  0);

#endif /* Stars_hpp */
