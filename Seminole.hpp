//
//  Seminole.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#ifndef Seminole_hpp
#define Seminole_hpp

#include "Enemy.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <stdio.h>
#include <string>

using namespace std;

class Seminole: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
public:
    Seminole();
    Seminole(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void spearAttack();
    void bowAttack();
    void retaliate();
    void fight();
    
};

#endif /* Seminole_hpp */
