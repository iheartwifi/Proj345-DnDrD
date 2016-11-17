//
//  Hero.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-13.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "Hero.hpp"

//Constructors
Hero::Hero(){
    moveCounter = 0;
    orientation = 0;
}
//Destructor
Hero::~Hero(){
    //doesn't need to do anything yet
}

//getter and mutator for moveCounter
int Hero::getMoveCounter(){
    return moveCounter;
}
void Hero::incrementMoveCounter(){
    moveCounter = (moveCounter + 1) % 4;
}

//getter and setter for orientation
int Hero::getOrientation(){
    return orientation;
}
void Hero::setOrientation(int o){
    if(o >= 0 && o <= 4){
        this->orientation = o;
    }
}
