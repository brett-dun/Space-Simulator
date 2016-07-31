//
//  SpaceObjects.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "SpaceObjects.hpp"

SpaceObject::SpaceObject() {
    
}

bool SpaceObject::equals(SpaceObject other) {
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

bool SpaceObject::optomizedEquals(SpaceObject other) {
    return this->id == other.id;
}

std::string SpaceObject::toString() {
    std::stringstream ss;
    ss << std::setprecision(8) << "SpaceObject [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPerihelion << ", perihelion=" << perihelion << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

std::string SpaceObject::toSimpleString() {
    std::stringstream ss;
    ss << std::setprecision(8) << name << "\t[px=" << px << "\tpy=" << py << "\tvx=" << vx << "\tvy=" << vy << "]";
    return ss.str();
}
std::string SpaceObject::toCSV() {
    std::stringstream ss;
    ss << std::setprecision(8) << px << "," << py << "," << vx << "," << vy << ",";
    return ss.str();
}

long double* SpaceObject::attraction(SpaceObject other) {
    long double x = other.px - this->px;
    long double y = other.py - this->py;
    long double d = sqrt(pow(x, 2) + pow(y, 2));
    long double* temp = new long double[2];
    temp[0] = 0;
    temp[1] = 0;
    
    if (d == 0) {
        /*if (other.mass > this->mass) {
         other.mass += this->mass;
         this->mass = 0;
         } else {
         this->mass += other.mass;
         other.mass = 0;
         }*/
        return temp;
    }
    
    long double angle = atan2(y, x);
    //std::cout << "angle: " << angle << "\n";
    long double f = G * this->mass * other.mass / pow(d, 2);
    
    //std::cout << "m: " << this->mass << "\n";
    
    //std::cout << "d: " << d << "\n";
    //std::cout << "f: " << f << "\n";
    
    temp[0] = cos(angle) * f;
    //std::cout << temp[0] << "\n";
    temp[1] = sin(angle) * f;
    //std::cout << temp[1] << "\n";
    
    return temp;
}


void SpaceObject::setVX(long double var) {
    vx = var;
}
void SpaceObject::setVY(long double var) {
    vy = var;
}
void SpaceObject::setPX(long double var) {
    px = var;
}
void SpaceObject::setPY(long double var) {
    py = var;
}


std::string SpaceObject::getName() {
    return name;
}
long SpaceObject::getID() {
    return id;
}
long double SpaceObject::getMass() {
    return mass;
}
long double SpaceObject::getLongitudeOfPerihelion() {
    return longitudeOfPerihelion;
}
long double SpaceObject::getPerihelion() {
    return perihelion;
}
long double SpaceObject::getVelocity() {
    return velocity;
}
long double SpaceObject::getVX() {
    return vx;
}
long double SpaceObject::getVY() {
    return vy;
}
long double SpaceObject::getPX() {
    return px;
}
long double SpaceObject::getPY() {
    return py;
}
bool SpaceObject::getReversed() {
    return reversed;
}