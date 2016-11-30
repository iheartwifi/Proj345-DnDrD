//
//  GameObject.hpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-10-31.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include "Coordinate Struct.h"

//gameObject is the super class for any object that can be placed on a map
//e.g.; characters, chests, iteractable objects
//eventually these will all be generalized up to this class
class GameObject{
    friend std::istream& operator>>(std::istream &in, GameObject &go);
    friend std::ostream& operator<<(std::ostream &in, GameObject const &go);
private:
    Coordinate locationInMap;
public:
    //destructor
    virtual ~GameObject();
    
    //getters and setters for locationInMap
    Coordinate getLocationInMap();
    void setLocationInMap(Coordinate location);
    void setLocationInMap(int x,int y);
};

#endif /* GameObject_hpp */
