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
    
    const int ARRAY_SIZE = 10;
    const int TIME = 24 * 60 * 60;
    
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
    
    Planet planets[ARRAY_SIZE] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto};
    //Planet planets[ARRAY_SIZE] = {sun, mercury, venus, earth, mars};
    
    //int count = 0;
    for(int count = 0; count < 5; count++) {
        
        //Display info on the planets
        std::cout << "Day " << count << ":\n";
        for(int i = 0; i < ARRAY_SIZE; i++) {
            //std::cout << planets[i].toString() << "\n";
            std::cout << planets[i].toSimpleString() << "\n";
        }
        
        double force[ARRAY_SIZE][2];
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            double fx = 0;
            double fy = 0;
            
            for(int j = 0; j < ARRAY_SIZE; j++) {
                
                if(!planets[i].equals(planets[j])) {
                    
                    fx += planets[i].xAttraction(planets[j]);
                    fy += planets[i].yAttraction(planets[j]);
                    
                }
                
            }
            
            force[i][0] = fx;
            force[i][1] = fy;
            
        }
        
        for(int i = 0; i < ARRAY_SIZE; i++) {
            
            planets[i].vx += force[i][0] / planets[i].mass * TIME;
            planets[i].vy += force[i][1] / planets[i].mass * TIME;
            
            planets[i].px += planets[i].vx * TIME;
            planets[i].py += planets[i].vy * TIME;
            
        }


        
        //count++;
    }
    
    return 0;
}
