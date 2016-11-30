//
//  character.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-28.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef character_hpp
#define character_hpp
#include <string>
#include <stdio.h>
#include "defines.h"
#include <iostream>
#include <fstream>
#include "Dice.hpp"
#include "InventoryPanel.h"
using namespace std;
/*
 Level up : 20+level*20
 */
class character {
public:
    character();
    character(string ruleString);
    
    void saveToFile();
    void LoadFromFile(string address);
    void setNewName(string name);
    void addExp(int value);
    void reCalLevelUp();
    void reCalLevelDown();
    void iniCharacterBaseOnIp();
    void calculateAbility();
    void subValueTogetOriginV();
    //dice object
    Dice gameDice;
    
    string charName = "defaultName";
    int level=1;
    int hitPoints = characterDefaultValue;
    int damage = 30;
    int exp = 0;
    int attackBonus = 1;
    int attackPerRound = 1;
    int armorClass = 2;
    InventoryPanel ip;
    ItemContainer ic;
    
    int abilityScore[6]={characterDefaultValue,characterDefaultValue,characterDefaultValue,
        characterDefaultValue,characterDefaultValue,characterDefaultValue};
    //0:str;1:dex;2:con;3:intel;4: wis;5 cha
    
    int abilityModifier[6]={characterDefaultValue,characterDefaultValue,characterDefaultValue,
        characterDefaultValue,characterDefaultValue,characterDefaultValue};
    //0:str;1:dex;2:con;3:intel;4: wis;5 cha
private:
    
   
    
};
#endif /* character_hpp */
