//  Enemy.hpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Enemy{
    protected:
        string name;
        double health;
        int attack;
        int defense;
    
    public:
        virtual void fight() = 0;
        virtual int takeDamage(double playerAttack) = 0;
};
#endif /* Enemy_hpp */
