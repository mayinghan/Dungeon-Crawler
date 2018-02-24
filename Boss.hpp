//
//  Boss.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#ifndef Boss_hpp
#define Boss_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Boss: public Enemy {
private:
    string name;
    double health;
    double attack;  //do to the players' GPA
    int defense;
    Player* player;
    Map* map;
    
public:
    //constructor
    Boss();
    Boss(Player* p, Map* m);
    //function
    int takeDamage(double playerAttack);
    void normalAttack();
    void weakAttack();
    void strongAttack();
    void retaliate();
    void fight();
    
    //when implementing Item class
    //void dropItem();
    
    
};

#endif /* Boss_hpp */
