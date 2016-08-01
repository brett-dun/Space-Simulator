//
//  Moons.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Moons.hpp"

Moon::Moon(std::string name_, long id_, long double mass_, long double longitude_, long double pericenter_, long double velocity_, bool retrograde_){
    name = name_;
    id = id_;
    longitudeOfPericenter = longitude_;
    pericenter = pericenter_;
    velocity = velocity_;
    px = pericenter * cos(longitudeOfPericenter);
    py = pericenter * sin(longitudeOfPericenter);
    vx = velocity * sin(longitudeOfPericenter);
    vy = velocity * cos(longitudeOfPericenter);
    retrograde = retrograde_;
    
    if( vx < 0 ) {
        vx = -vx;
    }
    
    if( vy < 0 ) {
        vy = -vy;
    }
    
    if( longitudeOfPericenter >= 0 && longitudeOfPericenter <= (M_PI / 2) ) {
        //vx = vx;
        vy = -vy;
    } else if( longitudeOfPericenter >= (M_PI / 2) && longitudeOfPericenter <= M_PI ) {
        //vx = vx;
        //vy = vy;
    } else if( longitudeOfPericenter >= M_PI && longitudeOfPericenter <= (3 * M_PI / 2) ){
        vx = -vx;
        vy = -vy;
    } else if( (longitudeOfPericenter >= 3*M_PI/2 && longitudeOfPericenter <= 2*M_PI) || (longitudeOfPericenter <= 0 && longitudeOfPericenter >= -M_PI/2) ) {
        vx = -vx;
        //vy = vy;
    }
    
    if(retrograde) {
        vx = -vx;
        vy = -vy;
    }
}


std::string Moon::toString() {
    std::stringstream ss;
    ss << std::setprecision(8) << "Moon [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPericenter=" << longitudeOfPericenter << ", pericenter=" << pericenter << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", retrograde=" << retrograde << "]";
    return ss.str();
}

bool Moon::equals(Moon other) {
    if(this->mass != other.mass) {
        return false;
    } else if(this->longitudeOfPericenter != other.longitudeOfPericenter) {
        return false;
    } else if(this->pericenter != other.pericenter) {
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
    } else if(this->retrograde != other.retrograde) {
        return false;
    }
    return true;
}

long double Moon::getLongitudeOfPericenter() {
    return longitudeOfPericenter;
}
long double Moon::getPericenter() {
    return pericenter;
}
bool Moon::isRetrograde() {
    return retrograde;
}