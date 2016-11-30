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
    this->typrOfHero = Tank;
    moveCounter = 0;
    orientation = 0;
    for(int i=0;i<6;i++){
        int temp=gameDice.rollFour();
        this->abilityScore[i] = temp;
    }
    this->ip.loadContainer("defaultForNPC");
    iniCharacterBaseOnIp();
    calculateAbility();
}
Hero::Hero(Herotype a,string name){
    this->charName=name;
    this->typrOfHero = a;
    moveCounter = 0;
    orientation = 0;
    for(int i=0;i<6;i++){
        int temp=gameDice.rollFour();
        this->abilityScore[i] = temp;
    }
    switch(a){//0:str;1:dex;2:con;3:intel;4: wis;5 cha
        case Bully:
            //Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom
            this->abilityScore[0]+=12;
            this->abilityScore[2]+=10;
            this->abilityScore[1]+=8;
            this->abilityScore[3]+=6;
            this->abilityScore[5]+=4;
            this->abilityScore[4]+=2;
            break;
        case Nimble:
            //Dexterity, Constitution, Strength, Intelligence, Charisma, Wisdom
            this->abilityScore[1]+=12;
            this->abilityScore[2]+=10;
            this->abilityScore[0]+=8;
            this->abilityScore[3]+=6;
            this->abilityScore[5]+=4;
            this->abilityScore[4]+=2;
            break;
        case Tank:
            //Constitution, Dexterity, Strength, Intelligence, Charisma, Wisdom
            this->abilityScore[2]+=12;
            this->abilityScore[1]+=10;
            this->abilityScore[0]+=8;
            this->abilityScore[3]+=6;
            this->abilityScore[5]+=4;
            this->abilityScore[4]+=2;
            break;
    }
    this->ip.loadContainer("defaultForNPC");
    iniCharacterBaseOnIp();
    calculateAbility();
}

//Destructor
Hero::~Hero(){
    //doesn't need to do anything
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

void Hero::editCharacter(int type){
    switch(type){//0:str;1:dex;2:con;3:intel;4: wis;5 cha
        case 0:
            this->abilityScore[0]-=1;
            this->abilityModifier[0] = this->abilityScore[0] /2 +2;
            damage = this->abilityScore[0] + this->abilityModifier[0];
            break;
        case 1:
            this->abilityScore[0]+=1;
            this->abilityModifier[0] = this->abilityScore[0] /2 +2;
            damage = this->abilityScore[0] + this->abilityModifier[0];
            break;
        case 2:
            this->abilityScore[1]-=1;
            this->abilityModifier[1] = this->abilityScore[1] /2 +2;
            break;
        case 3:
            this->abilityScore[1]+=1;
            this->abilityModifier[1] = this->abilityScore[1] /2 +2;
            break;
        case 4:
            this->abilityScore[2]-=1;
            this->abilityModifier[2] = this->abilityScore[2] /2 +2;
            hitPoints += this->abilityScore[2] + this->abilityModifier[2];
            break;
        case 5:
            this->abilityScore[2]+=1;
            this->abilityModifier[2] = this->abilityScore[2] /2 +2;
            hitPoints += this->abilityScore[2] + this->abilityModifier[2];

            break;
        case 6:
            this->abilityScore[3]-=1;
            this->abilityModifier[3] = this->abilityScore[3] /2 +2;
            break;
        case 7:
            this->abilityScore[3]+=1;
            this->abilityModifier[3] = this->abilityScore[3] /2 +2;
            break;
        case 8:
            this->abilityScore[4]-=1;
            this->abilityModifier[4] = this->abilityScore[4] /2 +2;
            break;
        case 9:
            this->abilityScore[4]+=1;
            this->abilityModifier[4] = this->abilityScore[4] /2 +2;
            break;
        case 10:
            this->abilityScore[5]-=1;
            this->abilityModifier[5] = this->abilityScore[5] /2 +2;
            break;
        case 11:
            this->abilityScore[5]+=1;
            this->abilityModifier[5] = this->abilityScore[5] /2 +2;
            break;
        case 12:
            this->level-=1;
            reCalLevelDown();
            break;
        case 13:
            this->level+=1;
            reCalLevelUp();
            break;
    }
};
