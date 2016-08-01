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
    
    std::string toString();
    
    bool equals(StarSystemObject other);
    
    long double getLongitudeOfPeriastron();
    long double getPeriastron();
    bool isReversed();
    
protected:
    
    long double longitudeOfPerihelion; //meters (m)
    long double perihelion; //meters (m)
    
    bool reversed;
    
};

#endif /* StarSystemObjects_hpp */
