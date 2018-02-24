///
//  TurlingtonTabler.cpp
//  Dungeon Crawler
//
//  Created by Yinghan Ma on 12/3/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//


//  TurlingtonTabler.cpp
//  Game Tester
//  Created by Madison Holt on 11/15/17.
//  Modified for 'Turlington Tabler' by Samuel Mercado on 11/16/17.

#include "TurlingtonTabler.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructor
TurlingtonTabler::TurlingtonTabler() {
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
TurlingtonTabler::TurlingtonTabler(Player* p, Map *m) {
    
    name = "Turlington Tabler";
    
    //Object of Player class allowing us to manipulate the Player
    this->player = p;
    this->map = m;
    
    //notice how the following values are greater and less than Player values;
    //This enemy should be killed in 4-5 turns
    //This enemy will do a moderate amount of damage to Player when fought
    //Classification: normal/common Enemy
    health = 30;
    attack = 10;
    defense = 2;
}

//Use when Player attacks Enemy
//same code as in Player class
int TurlingtonTabler::takeDamage(double playerAttack) {
    double damageDone = defense - playerAttack;
    if (damageDone < 0) {
        //adding because damageDone will only be negative
        health = health + damageDone;
    }
    return damageDone;
}

//Basic attack for this enemy
//Will be the most common attack
void TurlingtonTabler::normalAttack() {
    cout << name << " throws a shuriken-shaped-pamphlet at you." << endl;
    int temp = player->takeDamage(attack);
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

//Weak attack for this enemy
//Does half of the normal damage
void TurlingtonTabler::weakAttack() {
    cout << name << " peer pressures you into going to their event." << endl;
    int temp = player->takeDamage((.5 * attack));
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

//Strong attack for this enemy
//Does 2 times normal damage
void TurlingtonTabler::strongAttack() {
    cout << name << " babbles endlessly -- it's detrimental to your ears!" << endl;
    int temp = player->takeDamage(2 * attack);
    cout << name << " does " << abs(temp) << " damage to you." << endl;
}

// holds enemy AI
// determines what attack the enemy will do
void TurlingtonTabler::retaliate() {
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
void TurlingtonTabler::fight() {
    int userInput = 0;
    
    cout << name << " comes into view." << endl;
    bool beat = true;
    //battle loop
    while(health > 0 && player->gameOver == false) {
        cout << "What will you do? \n(1) Bash their beliefs." << endl ;
        cout << "(2) Check Inventory for anything useful. \n(3) Try to escape by avoiding eye contact." << endl;
        cin >> userInput;
        
        if(userInput == 1) {
            //normal player attack
            cout << "\"The Tabler stands in disbelief from your painful remarks.\"" << endl;
            int temp = takeDamage(player->getAttack());
            cout << "You notice a few tears fall from their face. The Tabler takes " << abs(temp) << " damage. Nice!.\n";
            retaliate();
        } else if (userInput == 2) {
            bool check = false;
            for(int i=0; i<player->item.size(); i++){
                if(player->item.at(i).compare("headphones")==0){
                    health=0;
                    check = true;
                    player->deleteItem(player->item, "headphones");
                    break;
                }
            }
            if(!check){
                cout<<"You don't have the stuff that the TA wants."<<endl;
                retaliate();
            }
            
        } else if (userInput == 3) {
            // player has 50% chance of successfully fleeing from Tabler
            int randomNum = rand() % 2 + 1;
            if (randomNum == 1) {
                cout << "\"Deciding to spare them, you run away safely.\"" << endl;
                beat = false;
                map->back();
                break;
            }
            else if (randomNum == 2) {
                cout << "\"You make a loud noise and grab the Tabler's attention again.\"" << endl;
                retaliate();
            }
        } else {
            cout << "You ain't slick -- try again." << endl;
        }
    }
    cout << name << " looks for someone else to bother." << endl;
    //drop sunglasses
    if(beat){
        player->addItem(player->item, "sunglasses");
    }
    cout<<"Before he left, you picked up a pair of sunglasses on their table."<<endl;
    
}

