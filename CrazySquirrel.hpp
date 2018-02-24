//  CrazySquirrel.hpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.


#ifndef CrazySquirrel_hpp
#define CrazySquirrel_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <stdio.h>
#include <string>

using namespace std;

class CrazySquirrel: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
public:
    CrazySquirrel();
    CrazySquirrel(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void normalAttack();
    void weakAttack();
    void strongAttack();
    void retaliate();
    void fight();
};
#endif /* CrazySquirrel_hpp */
