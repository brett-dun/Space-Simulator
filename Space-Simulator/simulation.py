#!/usr/bin/env python

import math
from turtle import *

# The gravitational constant G
G = 6.67428e-11

# Assumed scale: 100 pixels = 1AU.
AU = (149597870.7 * 10**3)     # 149.6 million km, in meters.
#SCALE = 250 / AU
SCALE = 50 / AU

TIMESTOP = 24*60*60

class Body(Turtle):
    """Subclass of Turtle representing a gravitationally-acting body.
        
        Extra attributes:
        mass : mass in kg
        vx, vy: x, y velocities in m/s
        px, py: x, y positions in m
        """
    
    name = 'Body'
    mass = None
    longitudeOfPerihelion = 0.0
    periHelion = 0.0
    velocity = 0.0
    reversed = False
    vx = vy = 0.0
    px = py = 0.0
    
    
    def attraction(self, other):
        """(Body): (fx, fy)
            
            Returns the force exerted upon this body by the other body.
            """
        # Report an error if the other object is the same as this one.
        if self is other:
            raise ValueError("Attraction of object %r to itself requested"
                             % self.name)
        
        # Compute the distance of the other body.
        sx, sy = self.px, self.py
        ox, oy = other.px, other.py
        dx = (ox-sx)
        dy = (oy-sy)
        d = math.sqrt(dx**2 + dy**2)
        
        # Report an error if the distance is zero; otherwise we'll
        # get a ZeroDivisionError exception further down.
        if d == 0:
            raise ValueError("Collision between objects %r and %r"
                             % (self.name, other.name))
        
        # Compute the force of attraction
        f = G * self.mass * other.mass / (d**2)
        
        print(f)
        
        # Compute the direction of the force.
        theta = math.atan2(dy, dx)
        fx = math.cos(theta) * f
        fy = math.sin(theta) * f
        return fx, fy

    def update_start(self):
        self.px = self.periHelion * math.cos(self.longitudeOfPerihelion)
        self.py = self.periHelion * math.sin(self.longitudeOfPerihelion)
        #print( math.cos(self.longitudeOfPerihelion)**2 + math.sin(self.longitudeOfPerihelion)**2)
        #print(math.degrees( math.cos(self.longitudeOfPerihelion) ))
        self.vx = self.velocity * math.sin(self.longitudeOfPerihelion)
        self.vy = self.velocity * math.cos(self.longitudeOfPerihelion)
        if self.longitudeOfPerihelion >= 0 and self.longitudeOfPerihelion <= math.radians(90):
            self.vx = math.fabs(self.vx)
            self.vy = -math.fabs(self.vy)
        elif self.longitudeOfPerihelion >= math.radians(90) and self.longitudeOfPerihelion <= math.radians(180):
            self.vx = math.fabs(self.vx)
            self.vy = math.fabs(self.vy)
        elif self.longitudeOfPerihelion <= 0 and self.longitudeOfPerihelion >= math.radians(-90):
            self.vx = -math.fabs(self.vx)
            self.vy = -math.fabs(self.vy)
        elif self.longitudeOfPerihelion <= math.radians(-90) and self.longitudeOfPerihelion >= math.radians(-180):
            self.vx = -math.fabs(self.vx)
            self.vy = math.fabs(self.vy)
        if self.reversed:
            self.vx = -self.vx
            self.vy = -self.vy


def update_info(step, bodies):
    """(int, [Body])
        
        Displays information about the status of the simulation.
        """
    print('Step #{}'.format(step))
    for body in bodies:
        s = '{:<8}  Pos.={:>6.2f} {:>6.2f} Vel.={:>10.3f} {:>10.3f}'.format(
                                                                            body.name, body.px/AU, body.py/AU, body.vx, body.vy)
        print(s)
    #print()

def loop(bodies):
    """([Body])
        
        Never returns; loops through the simulation, updating the
        positions of all the provided bodies.
        """
    
    for body in bodies:
        body.penup()
        body.hideturtle()
    
    step = 0
        #while step < 5:
    while True:
        update_info(step, bodies)
        step += 1
        
        force = {}
        for body in bodies:
            # Add up all of the forces exerted on 'body'.
            total_fx = total_fy = 0.0
            for other in bodies:
                # Don't calculate the body's attraction to itself
                if body is other:
                    continue
                fx, fy = body.attraction(other)
                total_fx += fx
                total_fy += fy
            
            # Record the total force exerted.
            force[body] = (total_fx, total_fy)
        
        # Update velocities based upon on the force.
        for body in bodies:
            fx, fy = force[body]
            body.vx += fx / body.mass * TIMESTOP
            body.vy += fy / body.mass * TIMESTOP
            
            # Update positions
            body.px += body.vx * TIMESTOP
            body.py += body.vy * TIMESTOP
            body.goto(body.px*SCALE, body.py*SCALE)
            body.dot(1)


def main():
    
    #print('Hello, World!')
    
    sun = Body()
    sun.name = 'Sun'
    sun.mass = 1.98892 * 10**30
    sun.pencolor('yellow')
    
    """star2 = Body()
        star2.name = 'star 2'
        star2.mass = 2 * 10**30
        star2.px = 1 * AU
        star2.pencolor('orange')"""
    
    # http://nssdc.gsfc.nasa.gov/planetary/factsheet/mercuryfact.html
    # https://en.wikipedia.org/wiki/Mercury_(planet)
    mercury = Body()
    mercury.name = 'Mercury'
    mercury.mass = 0.33011 * 10**24
    mercury.periHelion = 0.307491008 * AU
    mercury.velocity = 47.36 * 10**3
    mercury.longitudeOfPerihelion = math.radians(48.331)
    mercury.update_start()
    #mercury.px = mercury.periHelion
    mercury.pencolor('grey')
    
    # Venus parameters taken from
    # http://nssdc.gsfc.nasa.gov/planetary/factsheet/venusfact.html
    # https://en.wikipedia.org/wiki/Venus
    venus = Body()
    venus.name = 'Venus'
    venus.mass = 4.8685 * 10**24
    venus.periHelion = 0.723 * AU
    venus.velocity = 35.02 * 10**3
    venus.longitudeOfPerihelion = math.radians(76.680)
    venus.reversed = True
    venus.update_start()
    venus.pencolor('green')
    
    # http://nssdc.gsfc.nasa.gov/planetary/factsheet/earthfact.html
    # https://en.wikipedia.org/wiki/Earth
    earth = Body()
    earth.name = 'Earth'
    earth.mass = 5.9742 * 10**4
    earth.periHelion = 1*AU
    earth.velocity = 29.783 * 10**3           # 29.783 km/sec
    earth.longitudeOfPerihelion = math.radians(-11.26064)
    earth.update_start()
    earth.pencolor('blue')
    
    # http://nssdc.gsfc.nasa.gov/planetary/factsheet/marsfact.html
    # https://en.wikipedia.org/wiki/Mars
    mars = Body()
    mars.name = 'Mars'
    mars.mass = 0.64171 * 10**24
    mars.periHelion = 1.38116939 * AU
    mars.velocity = 24.07 * 10**3
    mars.longitudeOfPerihelion = math.radians(49.558)
    mars.update_start()
    mars.pencolor('red')
    
    # http://nssdc.gsfc.nasa. gov/planetary/factsheet/jupiterfact.html
    # https://en.wikipedia.org/wiki/Jupiter
    jupiter = Body()
    jupiter.name = 'Jupiter'
    jupiter.mass = 1898.19 * 10**24
    jupiter.periHelion = 4.95007046 * AU
    jupiter.velocity = 13.06 * 10**3
    jupiter.longitudeOfPerihelion = math.radians(100.464)
    jupiter.update_start()
    jupiter.pencolor('orange')
    
    obj1 = Body()
    obj1.name = 'obj1'
    obj1.mass = 10**30
    obj1.periHelion = AU
    obj1.update_start()
    obj1.pencolor('red')

    obj2 = Body()
    obj2.name = 'obj2'
    obj2.mass = 10**30
    obj2.periHelion = AU
    obj2.longitudeOfPerihelion = math.radians(-180)
    obj2.update_start()
    obj2.pencolor('red')
    
    #update_info(0, [sun, mercury, venus, earth, mars, jupiter])
    
    #loop([sun, mercury, venus, earth, mars, jupiter])
    #loop([sun, mercury, venus, ])
    loop([obj1, obj2])

if __name__ == '__main__':
    main()