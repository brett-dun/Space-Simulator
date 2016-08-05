//
//  Stars.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Stars.hpp"

Star::Star(std::string name_, int id_, double mass_, double vx_, double vy_, double px_, double py_) {
    name = name_;
    id = id_;
    mass = mass_;
    vx = vx_;
    vy = vy_;
    px = px_;
    py = py_;
    velocity = sqrt(pow(vx, 2) + pow(vy, 2));
}