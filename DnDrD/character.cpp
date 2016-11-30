//
//  character.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-28.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "character.hpp"

character::character(){
    for(int i=0;i<6;i++){
        int temp=gameDice.roll("2d6");
        this->abilityScore[i]+=temp;
    }
    this->ip.loadContainer("defaultForNPC");
    iniCharacterBaseOnIp();
    calculateAbility();
}

character::character(string ruleString){
    for(int i=0;i<6;i++){
        int temp=gameDice.roll("2d6");
        this->abilityScore[i]+=temp;
    }
    this->ip.loadContainer("defaultForNPC");
    iniCharacterBaseOnIp();
    calculateAbility();
};

void character::calculateAbility(){
    for(int i=0;i<6;i++){
        this->abilityModifier[i] = this->abilityScore[i] /2 +2;
    }
    damage = this->abilityScore[0] + this->abilityModifier[0];
    hitPoints = this->abilityScore[2] + this->abilityModifier[2];
    this->armorClass+=this->abilityModifier[1];
}

void character::iniCharacterBaseOnIp(){
    vector<Item> temp=this->ip.getItems();
    int *arrayTemp;
    for(int j=0;j<temp.size();j++){
        arrayTemp = temp[j].getEnhances();
        for(int i=0;i<6;i++){
            this->abilityScore[i]+=*(arrayTemp + i);
        }
        this->attackBonus+=*(arrayTemp + 7);
        this->armorClass+=*(arrayTemp + 8);
    }
};

void character::setNewName(string name){
    this->charName=name;
};

void character::subValueTogetOriginV(){
    vector<Item> temp=this->ip.getItems();
    int *arrayTemp;
    for(int j=0;j<temp.size();j++){
        arrayTemp = temp[j].getEnhances();
        for(int i=0;i<6;i++){
            this->abilityScore[i]-=*(arrayTemp + i);
        }
        this->attackBonus-=*(arrayTemp + 7);
        this->armorClass-=*(arrayTemp + 8);
    }
};

void character::saveToFile(){
    this->ic.setName(this->charName+"_IC");
    this->ip.setName(this->charName+"_IP");
    
    this->ic.saveContainer(this->ic.getName());
    this->ip.saveIP(this->ip.getName());
    
    int temp=this->armorClass-this->abilityModifier[1];
    subValueTogetOriginV();
    calculateAbility();
    std::ofstream outfile ("save_character/"+this->charName+".txt");
    outfile<<"C "<<" ";
    outfile<<this->charName<<" ";
    outfile<<this->ip.getName()<<" ";
    outfile<<this->hitPoints<<" ";
    outfile<<this->damage<<" ";
    outfile<<temp<<" ";
    outfile<<this->level<<" ";
    outfile<<this->abilityScore[0]<<" ";
    outfile<<this->abilityScore[1]<<" ";
    outfile<<this->abilityScore[2]<<" ";
    outfile<<this->abilityScore[3]<<" ";
    outfile<<this->abilityScore[4]<<" ";
    outfile<<this->abilityScore[5]<<" ";
    outfile<<this->exp<<" ";
    outfile<<this->attackBonus<<" ";
    outfile<<this->attackPerRound<<endl;
    cout<<"Done"<<endl;
    outfile.close();
};

void character::LoadFromFile(string address){
    std::ifstream inputfile ("save_character/"+address+".txt");
    string line;
    inputfile>>line;
    inputfile>>line;
    this->charName=address;
    inputfile>>line;
    this->ip.loadContainer(line);
    inputfile>>this->hitPoints>>this->damage>>this->armorClass>>this->level>>
    this->abilityScore[0]>>this->abilityScore[1]>>this->abilityScore[2]>>
    this->abilityScore[3]>>this->abilityScore[4]>>this->abilityScore[5]>>
    this->exp>>this->attackBonus>>this->attackPerRound;
    iniCharacterBaseOnIp();
    calculateAbility();
    //place holder for items
}

void character::reCalLevelUp(){
    for(int i=0;i<6;i++){
        int temp=gameDice.roll("1d10");
        this->abilityScore[i] += temp;
        this->abilityModifier[i] = this->abilityScore[i] /2 +2;
    }
    
    damage = this->abilityScore[0] + this->abilityModifier[0];
    hitPoints += this->abilityScore[2] + this->abilityModifier[2];
    
    //level up
    string temp="1d10+"+to_string(this->abilityModifier[2]);
    this->hitPoints +=this->gameDice.roll(temp);
    this->attackBonus++;
    this->attackPerRound = (this->level-1) / 5 +1;
};

void character::reCalLevelDown(){
    for(int i=0;i<6;i++){
        int temp=gameDice.roll("1d10");
        this->abilityScore[i] -= temp;
        this->abilityModifier[i] = this->abilityScore[i] /2 +2;
    }
    
    damage = this->abilityScore[0] + this->abilityModifier[0];
    hitPoints += this->abilityScore[2] + this->abilityModifier[2];
    
    //level down
    string temp="1d10+"+to_string(this->abilityModifier[2]);
    this->hitPoints -=this->gameDice.roll(temp);
    this->attackBonus--;
    this->attackPerRound = (this->level-1) / 5 +1;
};

void character::addExp(int value){
    int threshold = 20+this->level*20;
    int tempValue = this->exp+value;
    if(tempValue >= threshold){
        this->exp=tempValue-threshold;
        this->level++;
        reCalLevelUp();
    }
    else
        this->exp=tempValue;
};

