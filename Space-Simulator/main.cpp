//
//  main.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 7/25/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include <iostream>
#include <ctime>

#include "Universe.hpp"
#include "Planets.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    using namespace std;
    
    //SpaceObject inner_solar_system[4] = {Planet(MERCURY), Planet(VENUS), Planet(EARTH), Planet(MARS)};
    //cout << SOLAR_SYSTEM[0].getName()  << " " << MERCURY.getName() << "\n";
    
    
    while(true) {
        unsigned int time, iterations, planets, continue_;
        
        for(unsigned short i = 0; i < 15; i++) {
            cout << "-----";
        }
        cout << "\n\t\t\t\t\t\t\tSPACE-SIMULATOR\n";
        
        cout << "Time per Iteration in Seconds:\t";
        cin >> time;
        cout << "Number of Iterations:\t\t\t";
        cin >> iterations;
        cout << "Set of Planets:\t\t\t\t\t";
        cin >> planets;
        
        
        cout << "Running ";
        
        Universe universe = Universe(time, iterations, SOLAR_SYSTEM, 10);
        
        switch (planets) {
            case 0:
                universe = Universe(time, iterations, SOLAR_SYSTEM, 10);
                cout << "full ";
                break;
            case 1:
                universe = Universe(time, iterations, INNER_SOLAR_SYSTEM, 4);
                cout << "inner ";
                break;
            case 2:
                universe = Universe(time, iterations, OUTER_SOLAR_SYSTEM, 6);
                cout << "outer ";
                break;
            default:
                cout << "default ";
                break;
        }
        
        cout << "solar system simulation for " << iterations << " iterations @ " << time << " second pace.\n";
        for(unsigned short i = 0; i < 15; i++) {
            cout << "-----";
        }
        cout << "\n";
        
        universe.run();
        
        for(unsigned short i = 0; i < 15; i++) {
            cout << "-----";
        }
        cout << "\nSimulation ended.  Continue?\t";
        cin >> continue_;
        
        for(unsigned short i = 0; i < 15; i++) {
            cout << "-----";
        }
        cout << "\n";
        
        //
        
        //cout << MERCURY.getName();
        
        if ( continue_ == 0 ) {
            return 0;
        }
    
    }
    return 0;
}
