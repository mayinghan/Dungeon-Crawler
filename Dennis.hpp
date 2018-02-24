//
//  Dennis.hpp
//  Dungeon Crawler
//
//  Created by Yinghan Ma on 11/28/17.

#ifndef Dennis_hpp
#define Dennis_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Dennis: public Enemy {
private:
    string name;
    double health;
    int attack;  //do to the players' GPA
    int defense;
    Player* player;
    
public:
    //constructor
    Dennis();
    Dennis(Player* p);
    //functions
    int takeDamage(double playerAttack);
    void fight();
    
    //when implementing Item class
    //void dropItem();
    
    
};

#endif /* TA_h */

