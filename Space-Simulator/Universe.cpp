//
//  Universe.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 8/6/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Universe.hpp"

Universe::Universe(unsigned short numPlanets_, unsigned short updateTime_, unsigned short iterations_, SpaceObject *objects_) {
    numPlanets = numPlanets_;
    updateTime = updateTime_;
    iterations = iterations_;
    objects = objects_;
}


void Universe::run() {
    for(unsigned short count = 0; count < iterations; count++) {
        //while (solarSystem[0].getPX() > 473.937227 * AU) {
        
        //Display info on the planets
        std::cout << "Day " << count << ":\n";
        for(int i = 0; i < numPlanets; i++) {
            //std::cout << solarSystem[i].toString() << "\n";
            std::cout << objects[i].toSimpleString() << "\n";
            //std::cout << solarSystem[i].toCSV();
        }
        //std::cout << "\n";
        
        //Calculate forces on each planet
        double force[numPlanets][2];
        for(int i = 0; i < numPlanets; i++) {
            
            //std::cout << i << "\n";
            
            double fx = 0;
            double fy = 0;
            
            //Calculate the gravitation force between the current planet and the other planet
            for(int j = 0; j < numPlanets; j++) {
                
                //Don't calculate the force with itself
                if(!objects[i].optomizedEquals(objects[j])) {
                    
                    double* forces = objects[i].attraction(objects[j]); //get the array of forces
                    fx += forces[0]; //get the force in the x direction and add it
                    fy += forces[1]; //get the force in the y direction and add it
                    delete forces; //delete the array of forces (we no longer need it)
                }
                
            }
            
            force[i][0] = fx; //set the force in the x direction for planet i
            force[i][1] = fy; //set the force in the y direction for planet i
            
        }
        
        //Move the planets
        for(int i = 0; i < numPlanets; i++) {
            
            if(objects[i].getMass() != 0) {
                objects[i].setVX( objects[i].getVX() + (force[i][0] / objects[i].getMass() * updateTime) );
                //std::cout << "vx: " << force[i][0] / solarSystem[i].mass * TIME << "\n";
                objects[i].setVY( objects[i].getVY() + (force[i][1] / objects[i].getMass() * updateTime) );
                
                objects[i].setPX( objects[i].getPX() + (objects[i].getVX() * updateTime) );
                objects[i].setPY( objects[i].getPY() + (objects[i].getVY() * updateTime) );
            }
            
        }
        
        /*
         if(solarSystem[i].getMass() != 0) {
            numPlanets--;
            SpaceObject* temp = new SpaceObject[numPlanets];
            for(int j = 0; j < i; j++) {
                temp[j] = solarSystem[j];
            }
            for(int j = i+1; j < numPlanets; j++) {
                temp[j-1] = solarSystem[j];
            }
            delete solarSystem;
            solarSystem = temp;
         */
        
        //count++;
    }
    
    //delete objects;
}