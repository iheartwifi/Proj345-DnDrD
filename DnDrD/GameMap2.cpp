//
//  GameMap2.cpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-11-03.
//  Copyright © 2016 COMP 345. All rights reserved.
//
#include <iostream>
#include "GameMap2.hpp"
using std::vector;

//Methods for inner class BlockData
//
//Constructors
GameMap2::BlockData::BlockData(){
    mapType = MAP_INSIDE;
    groundType = STONE;
    containedItem = nullptr;
}
GameMap2::BlockData::BlockData(MapType mType, GroundType gType, GameObject* cItem){
    mapType = mType;
    groundType = gType;
    containedItem = cItem;
}

//Destructor
GameMap2::BlockData::~BlockData(){
    delete containedItem;
    containedItem = nullptr;
}

//getters and setters
MapType GameMap2::BlockData::getMapType(){
    return mapType;
}
GroundType GameMap2::BlockData::getGroundType(){
    return groundType;
}
GameObject* GameMap2::BlockData::getContainedItem(){
    return containedItem;
}
void GameMap2::BlockData::setMapType(MapType mType) {
    mapType = mType;
}
void GameMap2::BlockData::setGroundType(GroundType gType) {
    groundType = gType;
}
void GameMap2::BlockData::setContainedItem(GameObject *cItem) {
    containedItem = cItem;
}

//determines if a block can be entered by a character
//may need to be updated if GroundType enum is updated
//may need to be updated if multiple forms of movement  are implemented. e.g.; flying, walking
bool GameMap2::BlockData::canMoveInto(){
    if(isOccupied() ||
       groundType == WALL ||
       groundType == WATER
       
        ){
        return false;
    }
    else{return true;}
}
//determines if block contains an item/character/etc
bool GameMap2::BlockData::isOccupied(){
    return (containedItem == nullptr)? false:true;
}
//
//-------End of Methods for inner class Block Data


//Methods for GameMap
//
//constructors
GameMap2::GameMap2(){
    //Uses other constructor
    GameMap2(arrayDimensions.x,
             arrayDimensions.y,
             Coordinate{0,0},
             Coordinate{arrayDimensions.x-1, arrayDimensions.y-1},
             nullptr,
             nullptr);

}
GameMap2::GameMap2(int w, int h, Coordinate startBlock, Coordinate endBlock, GameMap2* pMap, GameMap2* nMap){
    //set size of map
    mapArray = new vector<vector<BlockData*>*>(w);
    //mapArray->resize(w);
    for(int c = 0; c < w; c++){
        mapArray->at(c) = new vector<BlockData*>(h);
        //mapArray->at(c)->resize(h);
    }
    //fill map with default blocks
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            //make block
            mapArray->at(c)->at(r) = new BlockData();
            //set coordinates of block
            mapArray->at(c)->at(r)->locationInMap = {c,r};
        }
    }
    //set starting block
    mapArray->at(startBlock.x)->at(startBlock.y)->setMapType(MAP_START);
    startingBlock = startBlock;
    //set ending block
    mapArray->at(endBlock.x)->at(endBlock.y)->setMapType(MAP_END);
    endingBlock = endBlock;
    
    //set new array dimensions
    arrayDimensions={w,h};
    
    //sets connected maps
    this->previousMap = pMap;
    this->nextMap = nMap;
}
//destructor
GameMap2::~GameMap2(){
    for(int c = 0; c < arrayDimensions.x; c++){
        for(int r = 0; r < arrayDimensions.y; r++){
            delete mapArray->at(c)->at(r);
        }
    }
    for(int c = 0; c < arrayDimensions.x; c++){
        delete mapArray->at(c);
    }
    delete mapArray;
}

//getters and setters for start/end blocks
Coordinate GameMap2::getStartingBlock(){
    return startingBlock;
}
Coordinate GameMap2::getEndingBlock(){
    return endingBlock;
}
void GameMap2::setStartingBlock(Coordinate sBlock){
    this->getBlock(startingBlock)->setMapType(MAP_INSIDE);
    startingBlock = sBlock;
    this->getBlock(startingBlock)->setMapType(MAP_START);
}
void GameMap2::setEndingBlock(Coordinate eBlock){
    this->getBlock(endingBlock)->setMapType(MAP_INSIDE);
    endingBlock = eBlock;
    this->getBlock(endingBlock)->setMapType(MAP_END);
}
//getters and setter for next/previous maps
void GameMap2::setNextMap(GameMap2* gm){
    this->nextMap = gm;
    gm->previousMap = this;
}
void GameMap2::setPreviousMap(GameMap2* gm){
    this->previousMap = gm;
    gm->nextMap = this;
}
GameMap2* GameMap2::getNextMap(){
    return this->nextMap;
}
GameMap2* GameMap2::getPreviousMap(){
    return this->previousMap;
}

//get block at given Coordinates
GameMap2::BlockData* GameMap2::getBlock(int x, int y){
    Coordinate block = {x,y};
    return getBlock(block);
}
GameMap2::BlockData* GameMap2::getBlock(int x, int y) const{
    if(x < 0 || x > arrayDimensions.x-1){
        return nullptr;
    }
    if(y < 0 || y > arrayDimensions.y-1){
        return nullptr;
    }
    return mapArray->at(x)->at(y);
}
GameMap2::BlockData* GameMap2::getBlock(Coordinate block){
    if(block.x < 0 || block.x > arrayDimensions.x-1){
        return nullptr;
    }
    if(block.y < 0 || block.y > arrayDimensions.y-1){
        return nullptr;
    }
    return mapArray->at(block.x)->at(block.y);
}

//returns the size of the gameMap
Coordinate GameMap2::getArrayDimensions(){
    return arrayDimensions;
}

//determines if there is a navigable path from start point to end point
bool GameMap2::validateMap(){
    return validatePath(startingBlock, endingBlock);
}

//sets ground type of a given cell
//needs to be updated if groundtype is update
void GameMap2::fillcell(int x, int y, char obj){
    Coordinate block = {x,y};
    GroundType gType;
    switch (obj) {
        case 's':
            gType = STONE;
            break;
        case 'g':
            gType = GRASS;
            break;
        case 'w':
            gType = WATER;
            break;
        case 'W':
            gType = WALL;
            break;
        default:
            break;
    }
    fillcell(block, gType);
}
void GameMap2::fillcell(Coordinate block, GroundType gType){
    getBlock(block)->setGroundType(gType);
}

//determines if a block has a gameobject in it
bool GameMap2::isOccupied(int x, int y){
    Coordinate block = {x,y};
    return isOccupied(block);
}
bool GameMap2::isOccupied(Coordinate block){
    return getBlock(block)->isOccupied();
}

//add or remove a gameObject froma block
void GameMap2::occupyBlock(Coordinate block, GameObject *obj){
    this->getBlock(block)->setContainedItem(obj);
    obj->setLocationInMap(block);
}
void GameMap2::deOccupyBlock(Coordinate block){
    this->getBlock(block)->setContainedItem(nullptr);
}


//--Validate Path Methods--//
//these 3 fuctions serve to help the validatePath method
bool GameMap2::BlockData::isVisited(){
    return this->v;
}
void GameMap2::BlockData::resetV(){
    this->v = false;
}
void GameMap2::BlockData::setVisited(){
    this->v = true;
}
//determines if there is a navigable path from two points
//does prepwork before calling validatePathHelper() which checks the path recursively
bool GameMap2::validatePath(Coordinate a, Coordinate b){
    //reset v
    for(int c = 0; c < arrayDimensions.y; c++){
        for(int r = 0; r < arrayDimensions.x; r++){
            getBlock(c, r)->resetV();
        }
    }
    return validatePathHelper(a, b);
    
}
//recursive part of validatePath algorithm
bool GameMap2::validatePathHelper(Coordinate a, Coordinate b){
    BlockData* current = getBlock(a);
    current->setVisited();
    if(a.x == b.x && a.y == b.y){
        return true;
    }
    else{
        Coordinate upC = {a.x,a.y+1};
        Coordinate downC = {a.x,a.y-1};
        Coordinate leftC = {a.x-1,a.y};
        Coordinate rightC = {a.x+1,a.y};
        BlockData* up = getBlock(upC);
        BlockData* down = getBlock(downC);
        BlockData* left = getBlock(leftC);
        BlockData* right = getBlock(rightC);
        
        if(right != NULL && right !=nullptr && right->canMoveInto() && !(right->isVisited())){
            if(validatePathHelper(rightC, b)){
                return true;
            }
        }
        if(up != NULL && up != nullptr && up->canMoveInto() && !(up->isVisited())){
            if(validatePathHelper(upC, b)){
                return true;
            }
        }
        if(down != NULL && down != nullptr && down->canMoveInto() && !(down->isVisited())){
            if(validatePathHelper(downC, b)){
                return true;
            }
        }
        if(left != NULL && left!= nullptr && left->canMoveInto() && !(left->isVisited())){
            if(validatePathHelper(leftC, b)){
                return true;
            }
        }
        return false;
    }
}
//--end of Validate Path Methods--//

std::ostream &operator<<( std::ostream& out, GameMap2::BlockData const& bd ){
    out << (int) bd.mapType << "," << (int) bd.groundType << ",";
    if(bd.containedItem == nullptr || bd.containedItem == NULL ){
        out << 'N';
    }
    else{
        out << bd.containedItem;
    }
    return out;
}
std::istream& operator>>(std::istream &in,   GameMap2::BlockData& bd){
    int mType, gType;
    char junkHolder;
    in >> mType; bd.mapType = (MapType) mType;
    in >> junkHolder; //get rid of comma
    in >> gType; bd.groundType = (GroundType) gType;
    in >> junkHolder; //get rid of comma
    
    GameObject cItem;
    char peek = in.peek();
    if(peek != 'N'){
        in >> cItem; bd.containedItem = &cItem;
    }
    else{
        in >> junkHolder; //get rid of the N
        bd.containedItem = nullptr;
    }
    
    return in;
}

std::ostream &operator<<(std::ostream& out, GameMap2 const& gm){
    //output array dimensions
    out << gm.arrayDimensions.x<< ',' <<gm.arrayDimensions.y <<std::endl;
    //output Coordinates of starting block
    out << gm.startingBlock.x << ',' << gm.startingBlock.y << std::endl;
    //output Coordinates of ending block
    out << gm.endingBlock.x << ',' << gm.endingBlock.y << std::endl;
    //output this map
    //
    for(int c = 0; c < gm.arrayDimensions.x; c++){
        for(int r = 0; r < gm.arrayDimensions.y; r++){
            out << *gm.getBlock(r, c) << std::endl;
        }
    }
    //
    //output next map
    if(gm.nextMap !=nullptr && gm.nextMap != NULL){
        out << *gm.nextMap << std::endl;
    }
    else{
        out << "E" << std::endl;
    }
    
    return out;
}

std::istream &operator>>(std::istream& in, GameMap2 & gm){
    //input array dimensions
    char junkHolder;
    Coordinate dimensions;
    in >> dimensions.x >> junkHolder >> dimensions.y;
    gm.arrayDimensions = dimensions;
    //input Coordinates of starting block
    Coordinate startingBlock;
    in >> startingBlock.x >> junkHolder >> startingBlock.y;
    gm.startingBlock = startingBlock;
    //input Coordinates of ending block
    Coordinate endingBlock;
    in >> endingBlock.x >> junkHolder >> endingBlock.y;
    gm.endingBlock = endingBlock;
    
    //replace gm mapArray with new map of correct dimensions
    {
        //delete gm.mapArray;
        gm.mapArray = new vector<vector<GameMap2::BlockData*>*>(dimensions.x);
        for(int c = 0; c < dimensions.x; c++){
            gm.mapArray->at(c) = new vector<GameMap2::BlockData*>(dimensions.y);
        }
        //fill map with default blocks
        for (int r = 0; r < dimensions.y; r++) {
            for (int c = 0; c < dimensions.x; c++) {
                gm.mapArray->at(c)->at(r) = new GameMap2::BlockData();
            }
        }
    }
    
    //update each block
    for(int c = 0; c < gm.arrayDimensions.x; c++){
        for(int r = 0; r < gm.arrayDimensions.y; r++) {
            in >> *(gm.getBlock(c, r));
        }
    }
    
    gm.previousMap = nullptr;
    in.get();
    char a = in.peek();
    if(a != 'E' && a != -1){
        GameMap2* next = new GameMap2();
        in >> *next;
        gm.setNextMap(next);
    }
    else{
        gm.nextMap = nullptr;
    }
    

    
    return in;
}



