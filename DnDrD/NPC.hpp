//
//  NPC.hpp
//  DnDrD
//
//  Created by oscar on 2016-11-16.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef NPC_hpp
#define NPC_hpp

#include <stdio.h>
#include "GameMap2.hpp"
#include "Hero.hpp"

enum dir{
    dir_LEFT,
    dir_RIGHT,
    dir_DOWN,
    dir_UP
};

enum BehaviorType{
    aggressive,
    normal,
};

class NPC : public GameObject, public character{
private:
    int moveCounter;
    int orientation;
public:
    //constructors
    NPC();
    //destructor
    virtual ~NPC();
    int size;
    //gu
    int xCood=2;
    int yCood=2;
    
    int canGainExp = 20;
    
    void getMiniMap(Coordinate a);
    Coordinate subMap[5][5];
    void Move(GameMap2 *game_map,Hero *a);
    bool moveNPC(dir direction,GameMap2 *game_map);
    bool inRange(dir a);
    void HeroDect(Hero *a);
    Coordinate currentLocInSubMap=subMap[xCood][yCood];
    
    BehaviorType type=normal;
    //getter and mutator for moveCounter
    void incrementMoveCounter();
    int getMoveCounter();
    
    //getter and setter for orientation
    int getOrientation();
    void setOrientation(int o);
    
    void editCharacter(int type);
};
#endif /* NPC_hpp */
