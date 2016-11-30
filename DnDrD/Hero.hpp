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
#include "character.hpp"
#include "ItemContainer.h"

enum Orientation{
    ORIENTATION_LEFT,
    ORIENTATION_RIGHT,
    ORIENTATION_DOWN,
    ORIENTATION_UP
};

enum Herotype{
    Bully,//Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom
    Nimble,//Dexterity, Constitution, Strength, Intelligence, Charisma, Wisdom
    Tank//Constitution, Dexterity, Strength, Intelligence, Charisma, Wisdom
};

class Hero : public GameObject,public character{ //TODO: define virtual destructor
private:
    int moveCounter;
    int orientation;
    Herotype typrOfHero;
public:
    //constructors
    Hero();
    Hero(Herotype a,string name);
    //destructor
    virtual ~Hero();
    
    //getter and mutator for moveCounter
    void incrementMoveCounter();
    int getMoveCounter();
    
    //getter and setter for orientation
    int getOrientation();
    void setOrientation(int o);

    void editCharacter(int type);

};


#endif /* Hero_hpp */
