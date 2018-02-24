//
//  PresidentFuchs.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#ifndef PresidentFuchs_hpp
#define PresidentFuchs_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <stdio.h>
#include <string>

using namespace std;

class PresidentFuchs: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
public:
    PresidentFuchs();
    PresidentFuchs(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void fight();
    void healPlayer();
};
#endif /* PresidentFuchs_hpp */
