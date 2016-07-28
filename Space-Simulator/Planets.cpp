//
//  Planets.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Planets.hpp"

Planet::Planet(std::string n, long i, double m, double longitude, double p, double v, bool r) {
    name = n;
    id = i;
    mass = m;
    longitudeOfPerihelion = (M_PI / 180) * longitude;
    perihelion = p;
    velocity = v;
    px = perihelion * cos(longitudeOfPerihelion);
    py = perihelion * sin(longitudeOfPerihelion);
    vx = velocity * sin(longitudeOfPerihelion);
    vy = velocity * cos(longitudeOfPerihelion);
    reversed = r;
    
    if( longitudeOfPerihelion >= 0 && longitudeOfPerihelion <= (M_PI / 2) ) {
        vx = fabs(vx);
        vy = -fabs(vy);
    } else if( longitudeOfPerihelion >= (M_PI / 2) && longitudeOfPerihelion <= M_PI ) {
        vx = fabs(vx);
        vy = fabs(vy);
    } else if( longitudeOfPerihelion >= M_PI && longitudeOfPerihelion <= (3 * M_PI / 2) ){
        vx = -fabs(vx);
        vy = -fabs(vy);
    } else if( (longitudeOfPerihelion >= 3*M_PI/2 && longitudeOfPerihelion <= 2*M_PI) || (longitudeOfPerihelion <= 0 && longitudeOfPerihelion >= -M_PI/2) ) {
        vx = -fabs(vx);
        vy = fabs(vy);
    }
    
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

bool Planet::optomizedEquals(Planet other) {
    return this->id == other.id;
}

std::string Planet::toString() {
    std::stringstream ss;
    ss << "Planet [name=" << name << ", id=" << id << ", mass=" << mass << ", longitudeOfPerihelion=" << longitudeOfPerihelion << ", perihelion=" << perihelion << ", velocity=" << velocity << ", px=" << px << ", py=" << py << ", vx=" << vx << ", vy=" << vy << ", reversed=" << reversed << "]";
    return ss.str();
}

std::string Planet::toSimpleString() {
    std::stringstream ss;
    ss << name << "\t[px=" << px << "\tpy=" << py << "\tvx=" << vx << "\tvy=" << vy << "]";
    return ss.str();
}
std::string Planet::toCSV() {
    std::stringstream ss;
    ss << px << "," << py << "," << vx << "," << vy << ",";
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
        return temp;
    }
    
    double angle = atan2(y, x);
    double f = G * this->mass * other.mass / pow(d, 2);
    
    //std::cout << f;
    
    temp[0] = cos(angle) * f;
    temp[1] = sin(angle) * f;
    
    return temp;
}

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