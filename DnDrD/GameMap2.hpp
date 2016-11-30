//
//  GameMap2.hpp
//  C++ Testing
//
//  Created by Nelson Frank on 2016-11-03.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameMap2_hpp
#define GameMap2_hpp

#include <stdio.h>
#include "Coordinate Struct.h"
#include "GameObject.hpp"
#include <vector>
#include "SDL2/SDL.h"

enum MapType{
    MAP_START,
    MAP_INSIDE,
    MAP_END
};

enum GroundType{ //this set is obviously incomplete and mostly given for example
    STONE = 1,
    GRASS = 2,
    WATER = 3,
    WALL = 4
}; //additions to GroundType may require updating canMoveInto() and fillCell()

class GameMap2{
private:
    class BlockData{
        friend std::ostream& operator<<(std::ostream &out,   BlockData const& bd);
        friend std::istream& operator>>(std::istream &in,   BlockData & bd);
        friend GameMap2;
    private:
        //denotes whether a block is a starting point, ending point, or neither
        MapType mapType;
        
        //determines the type of terrain
        GroundType groundType;
        
        //determines what is located on the block e.g.; character, item, chest
        GameObject* containedItem;
        
        //
        Coordinate locationInMap;
        
        //helper variable, ignore
        bool v = false;
        
    public:
        //
        Coordinate getLocationInMap();
        //used to keep track of block location on gui
        SDL_Rect dstrect;
        
        //constructors
        BlockData();
        BlockData(MapType mType, GroundType gType, GameObject* cItem);
        
        //destructor
        ~BlockData();
        
        //getters & setters
        MapType getMapType();
        GroundType getGroundType();
        GameObject* getContainedItem();
        void setMapType(MapType mType);
        void setGroundType(GroundType gType);
        void setContainedItem(GameObject* cItem);
        
        bool canMoveInto();
        bool isOccupied();
        
        //3 helper methods, ignore
        bool isVisited();
        void setVisited();
        void resetV();
        
    };
    
    std::vector<std::vector<BlockData*>*>* mapArray;
    Coordinate arrayDimensions = {3,3};
    
    Coordinate startingBlock;
    Coordinate endingBlock;
    
    GameMap2* previousMap;
    GameMap2* nextMap;
    
    //helper method for validatePath()
    bool validatePathHelper(Coordinate a, Coordinate b);
    
public:
    
    //constructors
    GameMap2(); //sets default size and start/end
    GameMap2(int w, int h, Coordinate startBlock, Coordinate endBlock, GameMap2* pMap, GameMap2* nMap);
    
    //destructor
    ~GameMap2();
    
    //getters and setters for start/end blocks
    Coordinate getStartingBlock();
    Coordinate getEndingBlock();
    void setStartingBlock(Coordinate sBlock);
    void setEndingBlock(Coordinate eBlock);
    
    //getters and setter for next/previous maps
    void setNextMap(GameMap2* gm);
    void setPreviousMap(GameMap2* gm);
    GameMap2* getNextMap();
    GameMap2* getPreviousMap();
    
    //getter for arbitrary block
    BlockData* getBlock(int x, int y);
    BlockData* getBlock(int x, int y) const; //needed for << overloading
    //and alternate
    BlockData* getBlock(Coordinate block);
    
    //getter for array dimensions
    Coordinate getArrayDimensions();
    
    //add or remove a gameObject from a block
    void occupyBlock(Coordinate block, GameObject* obj);
    void deOccupyBlock(Coordinate block);
    
    //required methods as specified in assignment 1
    bool validateMap();
    void fillcell(int x, int y, char obj);
    bool isOccupied(int x, int y);
    
    //helper methods for assignment methods
    bool validatePath(Coordinate a, Coordinate b);
    void fillcell(Coordinate block, GroundType gType);
    bool isOccupied(Coordinate block);
    
    //operator overloading for input/output to file
    friend std::ostream& operator<<(std::ostream& out, GameMap2::BlockData const& bd );
    friend std::istream& operator>>(std::istream &in,  GameMap2::BlockData& bd);
    friend std::ostream& operator<<(std::ostream& out, GameMap2 const& gm);
    friend std::istream& operator>>(std::istream& out, GameMap2 & gm);
    
    
    
};










#endif /* GameMap2_hpp */
