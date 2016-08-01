//
//  StarSystemObjects.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/31/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "StarSystemObjects.hpp"

std::string StarSystemObject::toString() {
    std::stringstream ss;
    ss << std::setprecision(8) << "SpaceObject [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPerihelion << ", perihelion=" << perihelion << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

bool StarSystemObject::equals(StarSystemObject other) {
    if(this->mass != other.mass) {
        return false;
    } else if(this->longitudeOfPerihelion != other.longitudeOfPerihelion) {
        return false;
    } else if(this->perihelion != other.perihelion) {
        return false;
    } else if(this->velocity != other.velocity) {
        return false;
    } else if(this->px != other.px) {
        return false;
    } else if(this->py != other.py) {
        return false;
    } else if(this->vx != other.vx) {
        return false;
    } else if(this->vy != other.vy) {
        return false;
    } else if(this->reversed != other.reversed) {
        return false;
    }
    return true;
}

long double StarSystemObject::getLongitudeOfPeriastron() {
    return longitudeOfPerihelion;
}
long double StarSystemObject::getPeriastron() {
    return perihelion;
}
bool StarSystemObject::isReversed() {
    return reversed;
}