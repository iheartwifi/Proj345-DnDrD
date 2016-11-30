//
//  NPC.cpp
//  DnDrD
//
//  Created by oscar on 2016-11-16.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "NPC.hpp"

//Constructors Assignment 3
NPC::NPC(Strategy *s){
    size=5;
    moveCounter = 0;
    orientation = 0;
    this->strategy = s;
}

void NPC::setStrategy(Strategy *s){
    this->strategy=s;
};

//Destructor
NPC::~NPC(){
    //doesn't need to do anything
}

//getter and mutator for moveCounter
int NPC::getMoveCounter(){
    return moveCounter;
}
void NPC::incrementMoveCounter(){
    moveCounter = (moveCounter + 1) % 4;
}

//getter and setter for orientation
int NPC::getOrientation(){
    return orientation;
}
void NPC::setOrientation(int o){
    if(o >= 0 && o <= 4){
        this->orientation = o;
    }
}

void NPC::getMiniMap(Coordinate a){
    int rows =  sizeof subMap / sizeof subMap[0];
    int step = -rows/2;
    for(int i=0;i<rows;i++){
        int steptemp=-rows/2;
        for(int j=0;j<rows;j++){
            this->subMap[i][j]={a.x+steptemp,a.y+step};
            steptemp++;
        }
        step++;
    }
//    this->subMap[0][0]={a.x-1,a.y-1};
//    this->subMap[0][1]={a.x,a.y-1};
//    this->subMap[0][2]={a.x+1,a.y-1};
//    this->subMap[1][0]={a.x-1,a.y};
//    this->subMap[1][1]={a.x,a.y};
//    this->subMap[1][2]={a.x+1,a.y};
//    this->subMap[2][0]={a.x-1,a.y+1};
//    this->subMap[2][1]={a.x,a.y+1};
//    this->subMap[2][2]={a.x+1,a.y+1};
}

void NPC::HeroDect(Hero *a){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a->getLocationInMap().x==subMap[i][j].x and a->getLocationInMap().y==subMap[i][j].y)
                this->type=aggressive;
        }
    }
}

//Assignment 3
void NPC::Move(GameMap2 *game_map,Hero *a){
    switch(type){
        case normal:
        {
//            int temp = 0 + (rand() % (int)(3 - 0 + 1));
//            switch (temp) {
//                case 0:
//                    this->moveNPC(dir_UP,game_map);
//                    break;
//                case 1:
//                    this->moveNPC(dir_DOWN,game_map);
//                    break;
//                case 2:
//                    this->moveNPC(dir_LEFT,game_map);
//                    break;
//                case 3:
//                    this->moveNPC(dir_RIGHT,game_map);
//                    break;
//            }
            this->setStrategy(new FriendlyStrategy());
            this->strategy->NextMove(this, game_map);

        }
            break;
        case aggressive:
        {
//            if(this->getLocationInMap().x-a->getLocationInMap().x>0)
//                this->moveNPC(dir_LEFT,game_map);
//            if(this->getLocationInMap().x-a->getLocationInMap().x<0)
//                this->moveNPC(dir_RIGHT,game_map);
//            if(this->getLocationInMap().y-a->getLocationInMap().y>0)
//                this->moveNPC(dir_DOWN,game_map);
//            if(this->getLocationInMap().y-a->getLocationInMap().y<0)
//                this->moveNPC(dir_UP,game_map);
            this->setStrategy(new AggressorStrategy());
            this->strategy->NextMove(this, game_map,a);
        }
            break;
    }
}

bool NPC::inRange(dir a){
    bool flag=false;
    switch (a) {
        case dir_UP:
            if(yCood+1<=4)
                flag=true;
            break;
        case dir_DOWN:
            if(yCood-1>=0)
                flag=true;
            break;
        case dir_LEFT:
            if(xCood-1>=0)
                flag=true;
            break;
        case dir_RIGHT:
            if(xCood+1<=4)
                flag=true;
            break;
    }
    return flag;
};

bool NPC::moveNPC(dir direction,GameMap2 *game_map){
    this->incrementMoveCounter();
    setOrientation(direction);
    
    //determine coordinate of next block
    Coordinate nextBlock = this->getLocationInMap();
    switch (direction) {
        case ORIENTATION_UP:
            if(inRange(direction))
            {
                nextBlock.y++;
                if(game_map->getBlock(nextBlock)->canMoveInto()){
                    yCood++;
                }
            }
            break;
        case ORIENTATION_DOWN:
            if(inRange(direction))
            {
                nextBlock.y--;
                if(game_map->getBlock(nextBlock)->canMoveInto()){
                    yCood--;
                }
            }
            break;
        case ORIENTATION_RIGHT:
            if(inRange(direction))
            {
                nextBlock.x++;
                if(game_map->getBlock(nextBlock)->canMoveInto()){
                    xCood++;
                }
            }
            break;
        case ORIENTATION_LEFT:
            if(inRange(direction))
            {
                nextBlock.x--;
                if(game_map->getBlock(nextBlock)->canMoveInto()){
                    xCood--;
                }
            }
            break;
        default:
            break;
    }
    
    //exit function if next block does not in map
    if(nextBlock.x < 0 ||
       nextBlock.x >= game_map->getArrayDimensions().x ||
       nextBlock.y < 0 ||
       nextBlock.y >= game_map->getArrayDimensions().y){
        return false;
    }
    //set current block to empty
    game_map->deOccupyBlock(this->getLocationInMap());
    //move character to next block
    game_map->occupyBlock(nextBlock, this);
    return true;
}
