//
//  Alligator.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#ifndef Alligator_hpp
#define Alligator_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <stdio.h>
#include <string>

using namespace std;

class Alligator: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
    
public:
    Alligator();
    Alligator(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void chompAttack();
    void allicaneAttack();
    void stalkAttack();
    void retaliate();
    void fight();
};
#endif /* ExampleEnemy_hpp */
