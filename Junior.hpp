//
//  Junior.hpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#ifndef Junior_hpp
#define Junior_hpp

#include <stdio.h>
#include <stdio.h>

#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Junior: public Enemy {
private:
    string name;
    double health;
    int attack;
    int defense;
    Player* player;
    Map* map;
    
public:
    Junior();
    Junior(Player* p, Map* m);
    int takeDamage(double playerAttack);
    void normalAttack();
    void weakAttack();
    void strongAttack();
    void retaliate();
    void fight();
    
};

#endif /* Junior_hpp */
