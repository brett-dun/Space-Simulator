//
//  main.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include <iostream>
#include "Planets.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //std::cout << RAND_MAX << "\n";
    
    const unsigned short ARRAY_SIZE = 2;
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
    
    Planet one = Planet("one", 0, pow(10, 30), 0, AU, 0, false);
    Planet two = Planet("two", 1, pow(10, 30), 180, AU, 0, false);
    
    Planet planets[ARRAY_SIZE];
    /*planets[0] = sun;
    planets[1] = mercury;
    planets[2] = venus;
    planets[3] = earth;
    planets[4] = mars;
    planets[5] = jupiter;
    planets[6] = saturn;
    planets[7] = uranus;
    planets[8] = neptune;
    planets[9] = pluto;
    //planets[9].mass = 1;*/
    planets[0] = one;
    planets[1] = two;
    
    
    
    /*std::string s;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        std::string temp = planets[i].name;
        s += (temp + " px," + temp + " py," + temp + " vx," + temp + " vy,");
    }
    std::cout << s << "\n";*/
    
    //int count = 0;
    //INT_MAX
    for(unsigned short count = 0; count < 16000; count++) {
        
        //Display info on the planets
        std::cout << "Day " << count << ":\n";
        for(int i = 0; i < ARRAY_SIZE; i++) {
            //std::cout << planets[i].toString() << "\n";
            std::cout << planets[i].toSimpleString() << "\n";
            //std::cout << planets[i].toCSV();
        }
        //std::cout << "\n";
        
        //Calculate forces on each planet
        double force[ARRAY_SIZE][2];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            double fx;
            double fy;
            double* forces;
            
            //Calculate the gravitation force between the current planet and the other planet
            for(int j = 0; j < ARRAY_SIZE; j++) {
                
                //Don't calculate the force with itself
                if(!planets[i].optomizedEquals(planets[j])) {
                    
                    
                    
                    forces = planets[i].attraction(planets[j]); //get the array of forces
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
            
            if(planets[i].mass != 0) {
                planets[i].vx += force[i][0] / planets[i].mass * TIME;
                planets[i].vy += force[i][1] / planets[i].mass * TIME;
                
                planets[i].px += planets[i].vx * TIME;
                planets[i].py += planets[i].vy * TIME;
            }
            
        }


        
        //count++;
    }
    
    return 0;
}
