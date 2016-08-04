//
//  StarSystemObjects.hpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/31/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#ifndef StarSystemObjects_hpp
#define StarSystemObjects_hpp

#include <stdio.h>

#include "SpaceObjects.hpp"

class StarSystemObject : public SpaceObject {
public:
    
    StarSystemObject(std::string name_, int id_, long double mass_, long double longitude_, long double periastron_, long double velocity_, bool reversed_);
    StarSystemObject() : StarSystemObject("Star System Object", rand(), 0, 0, 0, 0, false) {}
    StarSystemObject(const StarSystemObject &obj);
    ~StarSystemObject();
    
    std::string toString();
    
    bool equals(StarSystemObject other);
    
    long double getLongitudeOfPeriastron();
    long double getPeriastron();
    bool isReversed();
    
protected:
    
    long double longitudeOfPeriastron; //meters (m)
    long double periastron; //meters (m)
    
    bool reversed;
    
};

#endif /* StarSystemObjects_hpp */
