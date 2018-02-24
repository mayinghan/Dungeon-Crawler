//
//  TA.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#ifndef TA_hpp
#define TA_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <stdio.h>
#include <string>

using namespace std;

class TA: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
    
public:
    TA();
    TA(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void normalBossAttack();
    void weakBossAttack();
    void strongBossAttack();
    void retaliate();
    void fight();
    
    //when implementing Item class
    //void dropItem();
    //TA's will drop keys to the staircases; implement dropItem here
};
#endif /* TA.hpp */
