//  Player.hpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Player{
    private:
        string name;
        double GPA;
        double stamina;
        int attack;
        int defense;
        double defenseGPA;
    
    public:
        int playerX;
        int playerY;
        bool gameOver;
        vector<string> item;
        Player();
        Player(string name);
        int takeDamage(double enAttack);
        double takeDamageBoss(double bossAttack);
        string getName();
        int getAttack();
        void getHealth();
        void fullHeal();
        void levelUp();
        void addItem(vector<string> &item, string drop);
        void deleteItem(vector<string> &item, string del);
    
};
#endif /* Player_hpp */
