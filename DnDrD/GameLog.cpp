//
//  GameLog.cpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#include "GameLog.hpp"
#include "defines.h"

std::string GameLog::toString(){
    std::string returnString = "";
    
    for(int i = logDisplacement, j = 0; i < fullLog.size() && i>0 && j < MAX_LOG_ENTRIES_SHOWN ; i++, j++){
        if(isEnabled(fullLog[i].source)){
           returnString += fullLog[i].entry + "\n";
        }
    }
    
    return returnString;
}

void GameLog::pushLogEntry(std::string entry, Source source){
    LogEntry newEntry = {entry, source};
    fullLog.push_back(newEntry);
}

bool GameLog::isEnabled(Source s){
    switch (s) {
        case LOG_GAME_CONTROLLER:
            return controllerEnabled;
            break;
        case LOG_GAME_MAP:
            return mapEnabled;
            break;
        case LOG_CHARACTER:
            return characterEnabled;
            break;
        case LOG_DICE:
            return diceEnabled;
            break;
        default:
            return false;
            break;
    }
}

void GameLog::toggleSource(Source s){
    bool* target;
    *target = false;
    
    switch (s) {
        case LOG_GAME_CONTROLLER:
             target = &controllerEnabled;
            break;
        case LOG_GAME_MAP:
            target = &mapEnabled;
            break;
        case LOG_CHARACTER:
            target = &characterEnabled;
            break;
        case LOG_DICE:
            target = &diceEnabled;
            break;
        default:
            break;
    }
    
    *target = !*target;
}
