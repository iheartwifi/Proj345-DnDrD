//
//  GameObject.cpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-10-31.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "GameObject.hpp"
#include <iostream>

std::istream& operator>>(std::istream &in, GameObject &go){
    //TODO or make virtual
    //the following is a placeholder
    std::string a;
    in >> a;
    return in;
}
std::ostream& operator<<(std::ostream &out, GameObject const &go){
    //TODO or make virtual
    //the following is a placeholder
    out << "AWIMAWAY";
    return out;
}
//destructor
GameObject::~GameObject(){
    //doesn't need to do anything
}

//getter and setters for locationInMap
Coordinate GameObject::getLocationInMap(){
    return locationInMap;
}
void GameObject::setLocationInMap(Coordinate location){
    this->locationInMap = location;
}
void GameObject::setLocationInMap(int x, int y){
    Coordinate temp = {x,y};
    setLocationInMap(temp);
}
