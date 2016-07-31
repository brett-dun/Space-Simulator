//
//  main.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include <iostream>

#include "Planets.hpp"
#include "SpaceObjects.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    const unsigned short ARRAY_SIZE = 10;
    const unsigned int TIME = (24 * 60 * 60);
    
    //Sun
    Planet sun = SUN;
    
    //Inner solar system
    Planet mercury = MERCURY;
    Planet venus = VENUS;
    Planet earth = EARTH;
    Planet mars = MARS;
    
    //Outer solar system
    Planet jupiter = JUPITER;
    Planet saturn = SATURN;
    Planet uranus = URANUS;
    Planet neptune = NEPTUNE;
    
    //Exoplanets (and dwarf planets)
    Planet pluto = PLUTO;
    
    //Planet one = Planet("one", 0, pow(10, 30), 0, AU, 0, false);
    //Planet two = Planet("two", 1, pow(10, 30), 180, AU, 0, false);
    
    Planet planets[ARRAY_SIZE];
    planets[0] = sun;
    planets[1] = mercury;
    planets[2] = venus;
    planets[3] = earth;
    planets[4] = mars;
    planets[5] = jupiter;
    planets[6] = saturn;
    planets[7] = uranus;
    planets[8] = neptune;
    planets[9] = pluto;
    //planets[0] = one;
    //planets[1] = two;
    
    
    
    std::string s;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        std::string temp = planets[i].getName();
        s += (temp + " px," + temp + " py," + temp + " vx," + temp + " vy,");
    }
    std::cout << s << "\n";
    
    //int count = 0;
    //INT_MAX
    for(unsigned short count = 0; count < 365; count++) {
        
        //Display info on the planets
        //std::cout << "Day " << count << ":\n";
        for(int i = 0; i < ARRAY_SIZE; i++) {
            //std::cout << planets[i].toString() << "\n";
            //std::cout << planets[i].toSimpleString() << "\n";
            std::cout << planets[i].toCSV();
        }
        std::cout << "\n";
        
        //Calculate forces on each planet
        long double force[ARRAY_SIZE][2];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            //std::cout << i << "\n";
            
            long double fx = 0;
            long double fy = 0;
            
            //Calculate the gravitation force between the current planet and the other planet
            for(int j = 0; j < ARRAY_SIZE; j++) {
                
                //Don't calculate the force with itself
                if(!planets[i].optomizedEquals(planets[j])) {
                    
                    long double* forces = planets[i].attraction(planets[j]); //get the array of forces
                    fx += forces[0]; //get the force in the x direction and add it
                    fy += forces[1]; //get the force in the y direction and add it
                    delete forces; //delete the array of forces (we no longer need it)
                }
                
            }
            
            force[i][0] = fx; //set the force in the x direction for planet i
            force[i][1] = fy; //set the force in the y direction for planet i
            
        }
        
        //Move the planets
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            if(planets[i].getMass() != 0) {
                planets[i].setVX( planets[i].getVX() + (force[i][0] / planets[i].getMass() * TIME) );
                //std::cout << "vx: " << force[i][0] / planets[i].mass * TIME << "\n";
                planets[i].setVY( planets[i].getVY() + (force[i][1] / planets[i].getMass() * TIME) );
                
                planets[i].setPX( planets[i].getPX() + (planets[i].getVX() * TIME) );
                planets[i].setPY( planets[i].getPY() + (planets[i].getVY() * TIME) );
            }
            
        }


        
        //count++;
    }
    
    return 0;
}
