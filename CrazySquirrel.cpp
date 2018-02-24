//  CrazySquirrel.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#include "CrazySquirrel.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Map.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructor
CrazySquirrel::CrazySquirrel() {
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
CrazySquirrel::CrazySquirrel(Player* p, Map* m) {
    
    name = "Crazy Squirrel";
    
    //Object of Player class allowing us to manipulate the Player
    this->player = p;
    this->map = m;
    
    //notice how the following values are greater and less than Player values;
    //This enemy should be killed in 1-2 turns
    //This enemy will do a small to moderate amount of damage to Player when fought
    //Classification: normal/common Enemy
    health = 15;
    attack = 3;
    defense = 1;
}

//Use when Player attacks Enemy
//same code as in Player class
int CrazySquirrel::takeDamage(double playerAttack) {
    double damageDone = defense - playerAttack;
    if (damageDone < 0) {
        //adding because damageDone will only be negative
        health = health + damageDone;
    }  else {
        damageDone = 0;
    }
    return damageDone;
}

//Basic attack for this enemy
//Will be the most common attack
void CrazySquirrel::normalAttack() {
    cout << name << " bites your finger with its razor sharp teeth!" << endl;
    int temp = player->takeDamage(attack);
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

//Weak attack for this enemy
//Does half of the normal damage
// for the squirrel, try to make this attack swipe an item from the inventory
void CrazySquirrel::weakAttack() {
    cout << name << " scratches your leg -- it was pretty pathetic." << endl;
    int temp = player->takeDamage((.5 * attack));
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

//Strong attack for this enemy
//Does 2 times normal damage
void CrazySquirrel::strongAttack() {
    cout << name << " throws an explosive acorn at your face." << endl;
    int temp = player->takeDamage(2 * attack);
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

// holds enemy AI
// determines what attack the enemy will do
void CrazySquirrel::retaliate() {
    //srand (time(NULL));
    int randomNum = rand() % 4 + 1;
    
    if (randomNum == 1) {
        weakAttack();
    } else if (randomNum == 2 || randomNum == 3) {
        normalAttack();
    } else {
        strongAttack();
    }
}

//This is where the entire interaction between the Player and this enemy takes place
void CrazySquirrel::fight() {
    int userInput = 0;
    
    cout << name << " comes into view." << endl;
    
    //battle loop
    while(health > 0 && player->gameOver == false) {
        cout << "What will you do? \n(1) Kick the squirrel, Eddy Pineiro style." << endl;
        cout << "(2) Grab the squirrel by its tail. \n(3) Run before the squirrel calls its crazy friends." << endl;
        cin >> userInput;
        player->getHealth();
        if(userInput == 1) {
            //normal player attack
            cout << "You kick the squirrel across the room into a computer screen." << endl;
            int temp = takeDamage(player->getAttack());
            cout << "The squirrel looks pretty winded -- it takes " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 2) {
            //weak player attack
            cout << "You swing the squirrel around by its tail like a helicopter rotor." << endl;
            int temp = takeDamage((.5*player->getAttack()));
            cout << "It becomes so dizzy it can't even move! Crazy Squirrel takes " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 3) {
            //run or quit battle
            cout << "You manage to escape the rabid rodent!" << endl;
            map->back();
            break;
        } else {
            cout << "Yo, not cool. Try again." << endl;
        }
    }
    cout << name << " scurries away into the shadows." << endl;
}
