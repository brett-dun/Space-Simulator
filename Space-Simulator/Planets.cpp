//
//  Planets.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Planets.hpp"

Planet::Planet(std::string n, double m, double longitude, double p, double v, bool r) {
    name = n;
    mass = m;
    longitudeOfPerihelion = M_PI / 180 * longitude;
    perihelion = p;
    velocity = v;
    px = perihelion * cos(longitudeOfPerihelion);
    py = perihelion * sin(longitudeOfPerihelion);
    vx = 0.0;
    vy = 0.0;
    
    if( longitudeOfPerihelion >= 0 && longitudeOfPerihelion <= (M_PI / 180 * 90) ) {
        vx = fabs(vx);
        vy = -fabs(vy);
    } else if( longitudeOfPerihelion >= (M_PI / 180 * 90) && longitudeOfPerihelion <= (M_PI / 180 * 180) ) {
        vx = fabs(vx);
        vy = fabs(vy);
    } else if( longitudeOfPerihelion <= 0 && longitudeOfPerihelion >= (M_PI / 180 * -90) ){
        vx = -fabs(vx);
        vy = -fabs(vy);
    } else if( longitudeOfPerihelion <= (M_PI / 180 * -90) && longitudeOfPerihelion >= (M_PI / 180 * -180) ) {
        vx = fabs(vx);
        vy = fabs(vy);
    }
    
    reversed = r;
    if(reversed) {
        vx = -vx;
        vy = -vy;
    }
}
    
bool Planet::equals(Planet other) {
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

std::string Planet::toString() {
    std::stringstream ss;
    ss << "Planet [name=" << name << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPerihelion << ", perihelion=" << perihelion << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

std::string Planet::toSimpleString() {
    std::stringstream ss;
    ss << name << "\t[px=" << px << "\tpy=" << py << "\tvx=" << vx << "\tvy" << vy << "]";
    return ss.str();
}

double Planet::xAttraction(Planet other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double d = sqrt(pow(x, 2) + pow(y, 2));
    if (d == 0) {
        if (other.mass > this->mass) {
            other.mass += this->mass;
            this->mass = 0;
            this->px = 0;
            this->py = 0;
            this->vx = 0;
            this->vy = 0;
        } else {
            this->mass += other.mass;
            other.mass = 0;
            other.px = 0;
            other.py = 0;
            other.vx = 0;
            other.vy = 0;
        }
        return 0;
    }
    
    return cos(atan2(x, y)) * (G * this->mass * other.mass / pow(d, 2));
}

double Planet::yAttraction(Planet other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double d = sqrt(pow(x, 2) + pow(y, 2));
    if (d == 0) {
        if (other.mass > this->mass) {
            other.mass += this->mass;
            this->mass = 0;
            //this->px = 0;
            //this->py = 0;
            //this->vx = 0;
            //this->vy = 0;
        } else {
            this->mass += other.mass;
            other.mass = 0;
            //other.px = 0;
            //other.py = 0;
            //other.vx = 0;
            //other.vy = 0;
        }
        return 0;
    }
    
    return sin(atan2(x, y)) * (G * this->mass * other.mass / pow(d, 2));
}