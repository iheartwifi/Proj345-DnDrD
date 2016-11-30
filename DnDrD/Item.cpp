//! @file
//! @brief Implementation file for the Item class
//!


#include "Item.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//! default constructor
Item::Item()
{
    i_name = "";
    i_type = I_NONE;
    for (int i = 0; i < 9; i++)
    {
        i_enhances[i] = 0;
    }
}

//constructor with param
Item::Item(string item_name, iType item_type, int str, int dex, int con, int intel, int wis, int cha, int armor, int atk, int dmg)
{
    i_name = item_name;
    i_type = item_type;
    i_enhances[0] = str;
    i_enhances[1] = dex;
    i_enhances[2] = con;
    i_enhances[3] = intel;
    i_enhances[4] = wis;
    i_enhances[5] = cha;
    i_enhances[6] = armor;
    i_enhances[7] = atk;
    i_enhances[8] = dmg;
}

//get type
iType Item::getType()
{
    return i_type;
}

//get name
string Item::getName()
{
    return i_name;
}

//set name
void Item::setName(string item_name)
{
    i_name = item_name;
}

//set type
void Item::setType(iType item_type)
{
    i_type = item_type;
}

//set abilityscorea and modifiers
void Item::setStr(int str)
{
    i_enhances[0] = str;
}
void Item::setDex(int dex)
{
    i_enhances[1] = dex;
}
void Item::setCon(int con)
{
    i_enhances[2] = con;
}
void Item::setIntel(int intel)
{
    i_enhances[3] = intel;
}
void Item::setWis(int wis)
{
    i_enhances[4] = wis;
}
void Item::setCha(int cha)
{
    i_enhances[5] = cha;
}
void Item::setArmor(int armor)
{
    i_enhances[6] = armor;
}
void Item::setAtk(int atk)
{
    i_enhances[7] = atk;
}
void Item::setDmg(int dmg)
{
    i_enhances[8] = dmg;
}

//get abilityscorea and modifiers
int Item::getStr()
{
    return i_enhances[0];
}
int Item::getDex( )
{
    return i_enhances[1];
}
int Item::getCon( )
{
    return i_enhances[2];
}
int Item::getIntel( )
{
    return i_enhances[3];
}
int Item::getWis( )
{
    return i_enhances[4];
}
int Item::getCha( )
{
    return i_enhances[5];
}
int Item::getArmor( )
{
    return i_enhances[6];
}
int Item::getAtk( )
{
    return i_enhances[7];
}
int Item::getDmg( )
{
    return i_enhances[8];
}
int* Item::getEnhances()
{
    return i_enhances;
}


//to_string
void Item::to_string()
{
    cout << "Item_Name: " << i_name << endl;
    cout << "Item_Type: " << i_type << endl;
    cout << "Strength: " << i_enhances[0] << endl;
    cout << "Dexterity: " << i_enhances[1] << endl;
    cout << "Constitution: " << i_enhances[2] << endl;
    cout << "Intellegence: " << i_enhances[3] << endl;
    cout << "Wisdom: " << i_enhances[4] << endl;
    cout << "Charisma: " << i_enhances[5] << endl;
    cout << "Armor_Class: " << i_enhances[6] << endl;
    cout << "Attack_Bonus: " << i_enhances[7] << endl;
    cout << "Damage_Bonus: " << i_enhances[8] << endl;
}

//saving item to file
void Item::saveItem(string filename)
{
    
    if (validateItem() == true)
    {
        ofstream save;
        save.open("items/"+filename + ".txt");
        
        save << i_name << endl;
        save << i_type << endl;
        
        for (int i = 0; i < 9; i++)
        {
            save << i_enhances[i] << endl;
        }
        
        save.close();
        
        cout << "Saving item..." << endl << endl;
    }
    else
        cout << "Item is not valid!!! Failed to save.... " << endl;
    
}

std::ostream &operator<<(std::ostream& os, Item const& item){
    //Output I to declare Item
    os << "I ";
    
    //output name in quotes
    os << "\"" << item.i_name << " \" ";
    
    //output type
    os << item.i_type << " ";
    
    //output all 9 enhancements
    for(int i = 0; i < 9; i++){
        os << item.i_enhances[i] << " ";
    }
    
    //output E to declare end of item
    os << "E";
    
    return os;
}

std::istream &operator>>(std::istream& is, Item & item){
    char junkHolder;
    
    //remove the I
    is >> junkHolder;
    
    //remove first quotation mark
    is >> junkHolder;
    
    //load name
    std::string name = "";
    std::string add = "";
    bool done = false;
    while(!done){
        is >> add;
        if(add == "\""){
            done = true;
        }
        else{
            name += add + " ";
        }
    }
    name.pop_back();
    item.i_name = name;
    
    //load type
    int type;
    is >> type;
    switch(type){
        case 1:
        {
            item.i_type = HELMET;
            break;
        }
        case 2:
        {
            item.i_type = ARMOR;
            break;
        }
        case 3:
        {
            item.i_type = SHIELD;
            break;
        }
        case 4:
        {
            item.i_type = RING;
            break;
        }
        case 5:
        {
            item.i_type = BELT;
            break;
        }
        case 6:
        {
            item.i_type = BOOTS;
            break;
        }
        case 7:
        {
            item.i_type = WEAPON;
            break;
        }
        default:
            break;
    }
    
    //load all 9 enhancements
    for(int i = 0; i < 9; i++){
        is >> item.i_enhances[i];
    }
    
    //remove the E
    is >> junkHolder;
    
    return is;
}


void Item::loadItem(string filename)
{
    ifstream load;
    load.open("items/"+filename + ".txt");
    
    getline(load, i_name);
    
    int type;
    load >> type;
    switch(type)
    {
        case 1:
        {
            i_type = HELMET;
            break;
        }
        case 2:
        {
            i_type = ARMOR;
            break;
        }
        case 3:
        {
            i_type = SHIELD;
            break;
        }
        case 4:
        {
            i_type = RING;
            break;
        }
        case 5:
        {
            i_type = BELT;
            break;
        }
        case 6:
        {
            i_type = BOOTS;
            break;
        }
        case 7:
        {
            i_type = WEAPON;
            break;
        }
        default:
            break;
    }
    
    for (int i = 0; i < 9; i++)
    {
        load >> i_enhances[i];
    }
    
    load.close();
    
    cout << "Loading item..." << endl << endl;
}

//validate item
bool Item::validateItem(){
    bool b = true;
    switch (i_type)
    {
        case HELMET:
        {
            if (getStr() != 0 || getDex() != 0 || getCon() != 0 || getCha() != 0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case ARMOR:
        {
            if (getStr() != 0 || getDex() != 0 || getCon() != 0 || getIntel() != 0 || getWis() != 0 || getCha() != 0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case SHIELD:
        {
            if (getStr() != 0 || getDex() != 0 || getCon() != 0 || getIntel() != 0 || getWis() != 0 || getCha() != 0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case RING:
        {
            if (getDex() != 0 || getIntel() != 0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case BELT:
        {
            if (getDex() != 0 || getIntel() != 0 || getWis() != 0 || getCha() != 0 || getArmor() !=0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case BOOTS:
        {
            if (getStr() != 0 || getCon() != 0 || getIntel() != 0 || getWis() != 0 || getCha() != 0 || getAtk() != 0 || getDmg() != 0)
                b = false;
            break;
        }
            
        case WEAPON:
        {
            if (getStr() != 0 || getDex() != 0 || getCon() != 0 || getIntel() != 0 || getWis() != 0 || getCha() != 0 || getArmor() != 0)
                b = false;
            break;
        }
            
            
        default:
            break;
    }
    return b;
}
