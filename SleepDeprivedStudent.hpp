//  SleepDeprivedStudent.hpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.


#ifndef SleepDeprivedStudent_hpp
#define SleepDeprivedStudent_hpp

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include <stdio.h>
#include <string>

using namespace std;

class SleepDeprivedStudent: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
public:
    SleepDeprivedStudent();
    SleepDeprivedStudent(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void normalAttack();
    void weakAttack();
    void strongAttack();
    void retaliate();
    void fight();
};
#endif /* SleepDeprivedStudent_hpp */
