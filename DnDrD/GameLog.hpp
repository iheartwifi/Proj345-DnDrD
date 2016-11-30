//
//  GameLog.hpp
//  DnDrD
//
//  Created by Nelson Frank on 2016-11-30.
//  Copyright © 2016 COMP 345. All rights reserved.
//

#ifndef GameLog_hpp
#define GameLog_hpp

#include <iostream>
#include <vector>

enum Source{
    LOG_GAME_CONTROLLER, //the game controller records the events happening in every game phase (game setup, map loading, player turns switching, end phase
    
    LOG_GAME_MAP, //The map records every movement made on the map
    LOG_CHARACTER, //the character records every attack attempted and its result
    LOG_DICE //the dice records every dice roll
};

struct LogEntry{
    std::string entry;
    Source source;
};

class GameLog{
private:
    bool controllerEnabled = true;
    bool mapEnabled = true;
    bool characterEnabled = true;
    bool diceEnabled = true;
    
    std::vector<LogEntry> fullLog;
    int logDisplacement = 0;
    
    bool isEnabled(Source s);
public:
    std::string toString();
    void pushLogEntry(std::string entry, Source source);
    
    void toggleSource(Source s);
};


#endif /* GameLog_hpp */
