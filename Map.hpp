//
//  Map.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#ifndef Map_hpp
#define Map_hpp

#include "Player.hpp"

#include <stdio.h>

class Map{
    private:
        int maxLevel;
        char objects [3][3];
        int lastX;
        int lastY;
        Player* player;
    public:
        int currentLevel;
        Map();
        Map(Player* p);
        void newLevel();
        void printMap();
        void move();
        void back();
    
};
#endif /* Map_hpp */
