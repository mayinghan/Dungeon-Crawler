//
//  PresFuchs.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#ifndef PresFuchs_hpp
#define PresFuchs_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <stdio.h>
#include <string>

using namespace std;

class PresFuchs: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
public:
    PresFuchs();
    PresFuchs(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void fight();
};

#endif /* PresFuchs_hpp */
