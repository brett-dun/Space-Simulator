//
//  Universe.cpp
//  Space-Simulator
//
//  Created by Brett Duncan on 8/6/16.
//  Copyright © 2016 Brett James Duncan. All rights reserved.
//

#include "Universe.hpp"

Universe::Universe(unsigned int updateTime_, unsigned int iterations_, const SpaceObject *objects_, unsigned short numPlanets_) {
    numPlanets = numPlanets_;
    updateTime = updateTime_;
    iterations = iterations_;
    objects = new SpaceObject[numPlanets];
    for(unsigned short i=0; i < numPlanets; i++) {
        objects[i] = objects_[i];
        objects[i].setName(objects_[i].getName());
        //std::cout << objects_[i].getName() << "\n";
    }
}

Universe::Universe(unsigned int updateTime_, unsigned int iterations_, SpaceObject *objects_, unsigned short numPlanets_) {
    numPlanets = numPlanets_;
    updateTime = updateTime_;
    iterations = iterations_;
    objects = new SpaceObject[numPlanets];
    for(unsigned short i=0; i < numPlanets; i++) {
        objects[i] = objects_[i];
        objects[i].setName(objects_[i].getName());
        //std::cout << objects_[i].getName() << "\n";
    }
}

void Universe::update() {
    //Display info on the planets
    for(int i = 0; i < numPlanets; i++) {
        //std::cout << solarSystem[i].toString() << "\n";
        std::cout << this->objects[i].toSimpleString() << "\n";
        //std::cout << solarSystem[i].toCSV();
    }
    //std::cout << "\n";
    
    //Calculate forces on each planet
    double force[numPlanets][3];
    for(unsigned short i = 0; i < numPlanets; i++) {
        
        //std::cout << i << "\n";
        
        double fx = 0;
        double fy = 0;
        double fz = 0;
        
        //Calculate the gravitation force between the current planet and the other planet
        for(unsigned short j = 0; j < numPlanets; j++) {
            
            //Don't calculate the force with itself
            if(!objects[i].optomizedEquals(objects[j])) {
                
                //double* forces = objects[i].attraction(objects[j]); //get the array of forces
                double* forces = objects[i].attraction2(objects[j]);
                fx += forces[0]; //get the force in the x direction and add it
                fy += forces[1]; //get the force in the y direction and add it
                fz += forces[2];
                //delete forces; //delete the array of forces (we no longer need it)
            }
            
        }
        
        force[i][0] = fx; //set the force in the x direction for planet i
        force[i][1] = fy; //set the force in the y direction for planet i
        force[i][2] = fz;
        
    }
    
    //Move the planets
    for(unsigned short i = 0; i < numPlanets; i++) {
        
        if(objects[i].getMass() != 0) {
            //std::cout << force[i][0] << "\n";
            //objects[i].setVX( objects[i].getVX() + (force[i][0] / objects[i].getMass() * updateTime) );
            //std::cout << "vx: " << force[i][0] / solarSystem[i].mass * TIME << "\n";
            //objects[i].setVY( objects[i].getVY() + (force[i][1] / objects[i].getMass() * updateTime) );
            //objects[i].setVZ( objects[i].getVZ() + (force[i][2] / objects[i].getMass() * updateTime) );
            objects[i].setVX( objects[i].getVX() + (force[i][0] * updateTime) );
            objects[i].setVY( objects[i].getVY() + (force[i][1] * updateTime) );
            objects[i].setVZ( objects[i].getVZ() + (force[i][2] * updateTime) );
            
            objects[i].setPX( objects[i].getPX() + (objects[i].getVX() * updateTime) );
            objects[i].setPY( objects[i].getPY() + (objects[i].getVY() * updateTime) );
            objects[i].setPZ( objects[i].getPZ() + (objects[i].getVZ() * updateTime) );
        }
        
    }
    
    
    
}

void Universe::run() {
    for(unsigned short count = 0; count < iterations; count++) {
        //while (solarSystem[0].getPX() > 473.937227 * AU) {
        std::cout << "Day " << count << ":\n";
        //std::cout << sizeof(objects);
        update();
    }
    
    //std::cout << objects[0].getName() << "\n";
    //std::cout << MERCURY.getName();
    //delete objects;
}

void Universe::removeUnused() {
    for(int i = 0; i < numPlanets; i++) {
         if(objects[i].getMass() == 0) {
             int planets = numPlanets - 1;
             SpaceObject* temp = new SpaceObject[planets];
             for(int j = 0; j < i; j++) {
                 temp[j] = objects[j];
             }
             for(int j = i+1; j < numPlanets; j++) {
                 temp[j-1] = objects[j];
             }
             objects = temp;
             delete temp;
             numPlanets--;
         }
    }
}