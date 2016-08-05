//
//  main.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include <iostream>
#include <ctime>

#include "Planets.hpp"
#include "Stars.hpp"
#include "SpaceObjects.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    /*double d = 1.23456789012345678901234567890l; std::cout << std::setprecision(31) << d << "\n"; std::cout << sizeof(d) << "\n";
    double ld = 1.23456789012345678901234567890l; std::cout << std::setprecision(31) << ld << "\n"; std::cout << sizeof(ld) << "\n";
    */
    
    
    
    /*long double a = 2;
    long double b = 3;
    long double c = 0;
    long double d = 0;
    long double f = 10;
    
    const clock_t s = clock();
    
    for(int i = 0; i < 100000; i++) {
        c += pow(a,f);
        d += pow(b,f);
    }
    
    clock_t e = clock();
    std::cout << e-s << "\n";
    
    
    return 0;*/
    
    const unsigned short ARRAY_SIZE = 10; //Number of space objects that will exist in this simulation
    const unsigned int TIME = (24 * 60 * 60);  //The amount of time that goes by between each object moving
    
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
    
    const clock_t start = clock(); //std::cout << start << "\n";
    
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
        double force[ARRAY_SIZE][2];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            //std::cout << i << "\n";
            
            double fx = 0;
            double fy = 0;
            
            //Calculate the gravitation force between the current planet and the other planet
            for(int j = 0; j < ARRAY_SIZE; j++) {
                
                //Don't calculate the force with itself
                if(!solarSystem[i].optomizedEquals(solarSystem[j])) {
                    
                    double* forces = solarSystem[i].attraction(solarSystem[j]); //get the array of forces
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
    
    clock_t end = clock();
    
    std::cout << end-start << "\n";
    
    return 0;
}
