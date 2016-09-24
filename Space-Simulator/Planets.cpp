//
//  Planets.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Planets.hpp"

Planet::Planet(std::string name_, int id_, double mass_, double longitude_, double periastron_, double velocity_, bool reversed_, unsigned short numMoons_) {
    name = name_;
    id = id_;
    mass = mass_;
    longitudeOfPeriastron = (M_PI / 180) * longitude_;
    periastron = periastron_;
    velocity = velocity_;
    px = periastron * cos(longitudeOfPeriastron);
    py = periastron * sin(longitudeOfPeriastron);
    vx = velocity * sin(longitudeOfPeriastron);
    vy = velocity * cos(longitudeOfPeriastron);
    reversed = reversed_;
    
    if( vx < 0 ) {
        vx = -vx;
    }
    
    if( vy < 0 ) {
        vy = -vy;
    }
    
    if( longitudeOfPeriastron >= 0 && longitudeOfPeriastron <= (M_PI / 2) ) {
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
    }
    
    if(reversed) {
        vx = -vx;
        vy = -vy;
    }
    
    numMoons = numMoons_;
    
    moons = new Moon[numMoons];
}

Planet::Planet(const Planet & obj) {
    name = obj.name;
    id = obj.id;
    mass = obj.mass;
    longitudeOfPeriastron = obj.longitudeOfPeriastron;
    periastron = obj.periastron;
    px = obj.px;
    py = obj.py;
    pz = obj.pz;
    vx = obj.vx;
    vy = obj.vy;
    vz = obj.vz;
    velocity = sqrt(pow(vx, 2) + pow(vy, 2));
    reversed = false;
    moons = NULL;
}

Planet::Planet(std::string n, int i, double m, double pX, double pY, double pz_, double vX, double vY, double vz_) {
    name = n;
    id = i;
    mass = m;
    longitudeOfPeriastron = 0;
    periastron = 0;
    px = pX;
    py = pY;
    pz = pz_;
    vx = vX;
    vy = vY;
    vz = vz_;
    velocity = sqrt(pow(vx, 2) + pow(vy, 2));
    reversed = false;
    moons = NULL;
}
    
/*bool Planet::equals(Planet other) {
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

bool Planet::optomizedEquals(Planet other) {
    return this->id == other.id;
}

std::string Planet::toString() {
    std::stringstream ss;
    ss << std::setprecision(8) << "Planet [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPerihelion << ", perihelion=" << perihelion << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

std::string Planet::toSimpleString() {
    std::stringstream ss;
    ss << std::setprecision(8) << name << "\t[px=" << px << "\tpy=" << py << "\tvx=" << vx << "\tvy=" << vy << "]";
    return ss.str();
}
std::string Planet::toCSV() {
    std::stringstream ss;
    ss << std::setprecision(8) << px << "," << py << "," << vx << "," << vy << ",";
    return ss.str();
}

double* Planet::attraction(Planet other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double d = sqrt(pow(x, 2) + pow(y, 2));
    double* temp = new double[2];
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
        /*return temp;
    }
    
    double angle = atan2(y, x);
    //std::cout << "angle: " << angle << "\n";
    double f = G * this->mass * other.mass / pow(d, 2);
    
    //std::cout << "m: " << this->mass << "\n";
    
    //std::cout << "d: " << d << "\n";
    //std::cout << "f: " << f << "\n";
    
    temp[0] = cos(angle) * f;
    //std::cout << temp[0] << "\n";
    temp[1] = sin(angle) * f;
    //std::cout << temp[1] << "\n";
    
    return temp;
}


void Planet::setVX(double var) {
    vx = var;
}
void Planet::setVY(double var) {
    vy = var;
}
void Planet::setPX(double var) {
    px = var;
}
void Planet::setPY(double var) {
    py = var;
}*/

void Planet::addMoon(unsigned short pos, Moon m) {
    moons[pos] = m;
}


/*std::string Planet::getName() {
    return name;
}
long Planet::getID() {
    return id;
}
double Planet::getMass() {
    return mass;
}
double Planet::getLongitudeOfPerihelion() {
    return longitudeOfPerihelion;
}
double Planet::getPerihelion() {
    return perihelion;
}
double Planet::getVelocity() {
    return velocity;
}
double Planet::getVX() {
    return vx;
}
double Planet::getVY() {
    return vy;
}
double Planet::getPX() {
    return px;
}
double Planet::getPY() {
    return py;
}
bool Planet::getReversed() {
    return reversed;
}*/

/*double Planet::yAttraction(Planet other) {
    double x = other.px - this->px;
    double y = other.py - this->py;
    double d = sqrt(pow(x, 2) + pow(y, 2));
    if (d == 0) {
        if (other.mass > this->mass) {
            other.mass += this->mass;
            this->mass = 0;
        } else {
            this->mass += other.mass;
            other.mass = 0;
        }
        return 0;
    }
    
    return sin(atan2(x, y)) * (G * this->mass * other.mass / pow(d, 2));
}*/

