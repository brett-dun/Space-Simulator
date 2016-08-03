//
//  Planets.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Planets.hpp"

Planet::Planet(std::string name_, int id_, long double mass_, long double longitude_, long double periastron_, long double velocity_, bool reversed_, unsigned short numMoons_) {
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

Planet::Planet(std::string n, int i, long double m, long double pX, long double pY, long double vX, long double vY) {
    name = n;
    id = i;
    mass = m;
    longitudeOfPeriastron = 0;
    periastron = 0;
    px = pX;
    py = pY;
    vx = vX;
    vy = vY;
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

long double* Planet::attraction(Planet other) {
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
        /*return temp;
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


void Planet::setVX(long double var) {
    vx = var;
}
void Planet::setVY(long double var) {
    vy = var;
}
void Planet::setPX(long double var) {
    px = var;
}
void Planet::setPY(long double var) {
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
long double Planet::getMass() {
    return mass;
}
long double Planet::getLongitudeOfPerihelion() {
    return longitudeOfPerihelion;
}
long double Planet::getPerihelion() {
    return perihelion;
}
long double Planet::getVelocity() {
    return velocity;
}
long double Planet::getVX() {
    return vx;
}
long double Planet::getVY() {
    return vy;
}
long double Planet::getPX() {
    return px;
}
long double Planet::getPY() {
    return py;
}
bool Planet::getReversed() {
    return reversed;
}*/

/*long double Planet::yAttraction(Planet other) {
    long double x = other.px - this->px;
    long double y = other.py - this->py;
    long double d = sqrt(pow(x, 2) + pow(y, 2));
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