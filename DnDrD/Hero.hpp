//
//  Hero.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-13.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp

#include <stdio.h>
#include "GameMap2.hpp"

enum Orientation{
    ORIENTATION_LEFT,
    ORIENTATION_RIGHT,
    ORIENTATION_DOWN,
    ORIENTATION_UP
};

class Hero : public GameObject{ //TODO: define virtual destructor
private:
    int moveCounter;
    int orientation;
public:
    //constructors
    Hero();
    //destructor
    virtual ~Hero();
    
    //getter and mutator for moveCounter
    void incrementMoveCounter();
    int getMoveCounter();
    
    //getter and setter for orientation
    int getOrientation();
    void setOrientation(int o);
};


#endif /* Hero_hpp */
