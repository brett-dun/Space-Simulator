//
//  MassiveObjects.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 8/5/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef MassiveObjects_hpp
#define MassiveObjects_hpp

#include <stdio.h>
#include "SpaceObjects.hpp"

class MassiveObject : public SpaceObject {
public:
    MassiveObject(std::string name_, int id_, double mass_, double vx_, double vy_, double px_, double py_);
    MassiveObject() : MassiveObject("Star", rand(), 0, 0, 0, 0, 0) {}
    ~MassiveObject();
};


#endif /* MassiveObjects_hpp */
