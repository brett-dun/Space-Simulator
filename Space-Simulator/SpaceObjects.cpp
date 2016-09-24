//
//  SpaceObjects.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/30/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "SpaceObjects.hpp"

SpaceObject::SpaceObject(std::string name_, int id_, double mass_, double vx_, double vy_, double px_, double py_) {
    name = name_;
    id = id_;
    mass = mass_;
    vx = vx_;
    vy = vy_;
    px = px_;
    py = py_;
    velocity = sqrt(pow(vx, 2) + pow(vy, 2));
    
    vz = 0;
    pz = 0;
}
SpaceObject::SpaceObject(const SpaceObject &obj) {
    //name = obj.name;
    id = obj.id;
    mass = obj.mass;
    vx = obj.vx;
    vy = obj.vy;
    px = obj.px;
    py = obj.py;
    velocity = obj.velocity;
    
    vz = obj.vz;
    pz = obj.pz;
}
/*SpaceObject::~SpaceObject() {
    this->name.~basic_string();
    id = NULL;
    mass = NULL;
    vx = NULL;
    vy = NULL;
    px = NULL;
    py = NULL;
    velocity = NULL;
    
    vz = NULL;
    pz = NULL;
}*/


bool SpaceObject::equals(SpaceObject other) {
    if(this->mass != other.mass) {
        return false;
    }
    if(this->velocity != other.velocity) {
        return false;
    }
    if(this->px != other.px) {
        return false;
    }
    if(this->py != other.py) {
        return false;
    }
    if(this->vx != other.vx) {
        return false;
    }
    if(this->vy != other.vy) {
        return false;
    }
    if(this->pz != other.pz) {
        return false;
    }
    if(this->vz != other.vz) {
        return false;
    }
    return true;
}

bool SpaceObject::optomizedEquals(SpaceObject other) {
    return this->id == other.id;
}

std::string SpaceObject::toString() const {
    std::stringstream ss;
    ss << std::setprecision(16) << "SpaceObject [name=" << name << ", id=" << id << ", mass=" << mass << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", pz=" << pz << ", vx=" << vx << ", vy=" << vy << ", vz=" << vz << "]";
    return ss.str();
}

std::string SpaceObject::toSimpleString() const {
    std::stringstream ss;
    //std::cout << name << "\n";
    ss << std::setprecision(16) << this->name << "\t[px=" << px << "\tpy=" << py << "\tpz=" << pz << "\tvx=" << vx << "\tvy=" << vy << "\tvz=" << vz << "]";
    return ss.str();
    //return "";
}
std::string SpaceObject::toCSV() const {
    std::stringstream ss;
    ss << std::setprecision(16) << px << "," << py << "," << pz << "," << vx << "," << vy << "," << vz << ",";
    return ss.str();
}

double* SpaceObject::attraction(SpaceObject other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double z = other.pz - this->pz;
    double d = sqrt(x*x + y*y +  z*z);
    double* temp = new double[3];
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    
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
    
    double angle1 = atan2(z, d*d-z*z);
    double angle2 = atan2(y, x);
    //std::cout << "angle: " << angle << "\n";
    double f = G * this->mass * other.mass / pow(d, 2);
    
    //std::cout << "m: " << this->mass << "\n";
    
    //std::cout << "d: " << d << "\n";
    //std::cout << "f: " << f << "\n";
    
    temp[0] = cos(angle1) * cos(angle2) * f;
    //std::cout << temp[0] << "\n";
    temp[1] = cos(angle1) * sin(angle2) * f;
    //std::cout << temp[1] << "\n";
    temp[2] = sin(angle1) * f; //Check this math
    
    return temp;
}

double* SpaceObject::attraction2(SpaceObject other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double z = other.pz - this->pz;
    double d = sqrt(x*x + y*y +  z*z);
    double* temp = new double[3];
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    
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
    
    double angle1 = atan2(z, d*d-z*z);
    double angle2 = atan2(y, x);
    double f = G * other.mass / pow(d, 2);
    
    temp[0] = cos(angle1) * cos(angle2) * f;
    temp[1] = cos(angle1) * sin(angle2) * f;
    temp[2] = sin(angle1) * f; //Check this math
    
    return temp;
}


void SpaceObject::setVX(double var) {
    vx = var;
}
void SpaceObject::setVY(double var) {
    vy = var;
}
void SpaceObject::setVZ(double var) {
    vz = var;
}
void SpaceObject::setPX(double var) {
    px = var;
}
void SpaceObject::setPY(double var) {
    py = var;
}
void SpaceObject::setPZ(double var) {
    pz = var;
}
void SpaceObject::setName(std::string var) {
    name = var;
}




std::string SpaceObject::getName() const {
    return name;
}
long SpaceObject::getID() const {
    return id;
}
double SpaceObject::getMass() const {
    return mass;
}

double SpaceObject::getVelocity() const {
    return velocity;
}
double SpaceObject::getVX() const {
    return vx;
}
double SpaceObject::getVY() const {
    return vy;
}
double SpaceObject::getPX() const {
    return px;
}
double SpaceObject::getPY() const {
    return py;
}

double SpaceObject::getVZ() const {
    return vz;
}
double SpaceObject::getPZ() const {
    return pz;
}