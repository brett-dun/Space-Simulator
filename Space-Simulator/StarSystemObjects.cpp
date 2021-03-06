//
//  StarSystemObjects.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/31/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "StarSystemObjects.hpp"

StarSystemObject::StarSystemObject(std::string name_, int id_, double mass_, double longitude_, double periastron_, double velocity_, bool reversed_) {
    name = name_;
    id = id_;
    mass = mass_;
    longitudeOfPeriastron = (M_PI / 180) * longitude_;
    periastron = periastron_;
    velocity = velocity_;
    inclination = 0;
    pz = periastron * sin(inclination); //Check the math on this
    px = periastron * cos(inclination) * cos(longitudeOfPeriastron);
    py = periastron * cos(inclination) * sin(longitudeOfPeriastron);
   
    vz = velocity * sin(inclination);
    vx = velocity * cos(inclination) * cos(longitudeOfPeriastron);
    vy = velocity * cos(inclination) * sin(longitudeOfPeriastron);
    
    reversed = reversed_;
    
    if( vx < 0 ) {
        vx = -vx;
    }
    
    if( vy < 0 ) {
        vy = -vy;
    }
    
    if( vz < 0) {
        vz = -vz;
    }
    
    /*if( longitudeOfPeriastron >= 0 && longitudeOfPeriastron <= (M_PI / 2) ) {
        //vx = vx;
        vy = -vy;
    } else if( longitudeOfPeriastron >= (M_PI / 2) && longitudeOfPeriastron <= M_PI ) {
        //vx = vx;
        //vy = vy;
    } else if( longitudeOfPeriastron >= M_PI && longitudeOfPeriastron <= (3 * M_PI / 2) ){
        vx = -vx;
        vy = -vy;
    } else if( (longitudeOfPeriastron >= 3*M_PI/2 && longitudeOfPeriastron <= 2*M_PI) || (longitudeOfPeriastron <= 0 && longitudeOfPeriastron >= -M_PI/2) ) {
        vx = -vx;
        //vy = vy;
    }*/
    
    if( longitudeOfPeriastron >= M_PI && longitudeOfPeriastron <= M_PI * 2 ) {
        vx = -vx;
    }
    
    if( (longitudeOfPeriastron >= 0 && longitudeOfPeriastron <= (M_PI / 2)) || (longitudeOfPeriastron >= M_PI && longitudeOfPeriastron <= (3 * M_PI / 2)) || (longitudeOfPeriastron <= 0 && longitudeOfPeriastron >= -M_PI/2) ) {
        vy = -vy;
    }
    
    if( (inclination >= 0 && inclination <= M_PI) ) {
        vz = -vz;
    }
    
    if(reversed) {
        vx = -vx;
        vy = -vy;
        vz = -vz;
    }
}
StarSystemObject::StarSystemObject(const StarSystemObject &obj) {
    name = obj.name;
    id = obj.id;
    mass = obj.mass;
    vx = obj.vx;
    vy = obj.vy;
    vz = obj.vz;
    px = obj.px;
    py = obj.py;
    pz = obj.pz;
    velocity = obj.velocity;
    
    longitudeOfPeriastron = obj.longitudeOfPeriastron;
    periastron = obj.periastron;
    reversed = obj.reversed;
    
}
/*StarSystemObject::~StarSystemObject() {
    this->name.~basic_string();
    id = NULL;
    mass = NULL;
    vx = NULL;
    vy = NULL;
    vz = NULL;
    px = NULL;
    py = NULL;
    pz = NULL;
    velocity = NULL;
    
    longitudeOfPeriastron = NULL;
    periastron = NULL;
    inclination = NULL;
    reversed = NULL;
}*/



std::string StarSystemObject::toString() {
    std::stringstream ss;
    ss << std::setprecision(8) << "SpaceObject [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPeriastron << ", perihelion=" << periastron << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

bool StarSystemObject::equals(StarSystemObject other) {
    if(this->mass != other.mass) {
        return false;
    } else if(this->longitudeOfPeriastron != other.longitudeOfPeriastron) {
        return false;
    } else if(this->periastron != other.periastron) {
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

double StarSystemObject::getLongitudeOfPeriastron() {
    return longitudeOfPeriastron;
}
double StarSystemObject::getPeriastron() {
    return periastron;
}
bool StarSystemObject::isReversed() {
    return reversed;
}