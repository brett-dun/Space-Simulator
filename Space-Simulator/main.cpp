//
//  main.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include <iostream>

#include "Planets.hpp"
#include "Stars.hpp"
#include "SpaceObjects.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    const unsigned short ARRAY_SIZE = 10;
    const unsigned int TIME = (24 * 60 * 60);
    
    //Sun
    Star sun = SUN;
    
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
    
    //Planet one = Planet("one", 0, 9.10938356e-31, 0, 500 * AU, 0, false, 0);
    //Planet two = Planet("two", 1, 1.98892e30 * 12e9, 0, 0, 0, false, 0);
    
    SpaceObject solarSystem[ARRAY_SIZE];
    solarSystem[0] = sun;
    solarSystem[1] = mercury;
    solarSystem[2] = venus;
    solarSystem[3] = earth;
    solarSystem[4] = mars;
    solarSystem[5] = jupiter;
    solarSystem[6] = saturn;
    solarSystem[7] = uranus;
    solarSystem[8] = neptune;
    solarSystem[9] = pluto;
    //solarSystem[0] = one;
    //solarSystem[1] = two;
    
    
    
    /*std::string s;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        std::string temp = solarSystem[i].getName();
        s += (temp + " px," + temp + " py," + temp + " vx," + temp + " vy,");
    }
    std::cout << s << "\n";*/
    
    //int count = 0;
    //INT_MAX
    for(unsigned short count = 0; count < 365; count++) {
    //while (solarSystem[0].getPX() > 473.937227 * AU) {
        
        //Display info on the planets
        std::cout << "Day " << count << ":\n";
        for(int i = 0; i < ARRAY_SIZE; i++) {
            //std::cout << solarSystem[i].toString() << "\n";
            std::cout << solarSystem[i].toSimpleString() << "\n";
            //std::cout << solarSystem[i].toCSV();
        }
        //std::cout << "\n";
        
        //Calculate forces on each planet
        long double force[ARRAY_SIZE][2];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            //std::cout << i << "\n";
            
            long double fx = 0;
            long double fy = 0;
            
            //Calculate the gravitation force between the current planet and the other planet
            for(int j = 0; j < ARRAY_SIZE; j++) {
                
                //Don't calculate the force with itself
                if(!solarSystem[i].optomizedEquals(solarSystem[j])) {
                    
                    long double* forces = solarSystem[i].attraction(solarSystem[j]); //get the array of forces
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
            
            if(solarSystem[i].getMass() != 0) {
                solarSystem[i].setVX( solarSystem[i].getVX() + (force[i][0] / solarSystem[i].getMass() * TIME) );
                //std::cout << "vx: " << force[i][0] / solarSystem[i].mass * TIME << "\n";
                solarSystem[i].setVY( solarSystem[i].getVY() + (force[i][1] / solarSystem[i].getMass() * TIME) );
                
                solarSystem[i].setPX( solarSystem[i].getPX() + (solarSystem[i].getVX() * TIME) );
                solarSystem[i].setPY( solarSystem[i].getPY() + (solarSystem[i].getVY() * TIME) );
            }
            
        }


        
        //count++;
    }
    
    return 0;
}
