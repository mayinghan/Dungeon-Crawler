//
//  Junior.cpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#include "Junior.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
//Constructor
Junior::Junior(){
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
Junior::Junior(Player* p, Map* m){
    
    name = "Junior by Credits";
    
    //Object of Player class allowing us to manipulate the Player
    player = p;
    map = m;
    //notice how the following values are greater and less than Player values;
    //This enemy should be killed in 4-5 turns
    //This enemy will do a moderate amount of damage to Player when fought
    //Classification: normal/common Enemy
    health = 20;
    attack = (m->currentLevel - 1) * 5;
    defense = (m->currentLevel - 1) * 5 +1;
}

//Use when Player attacks Enemy
//same code as in Player class
int Junior::takeDamage(double playerAttack){
    double damageDone = defense - playerAttack;
    if(damageDone < 0){
        //adding because damageDone will only be negative
        health = health + damageDone;
    } else {
        damageDone = 0;
    }
    return damageDone;
}

//Basic attack for this enemy
//Will be the most common attack
void Junior::normalAttack(){
    cout<< name << " used: \"Work Hard Play Hard\"" << endl;
    int temp = player->takeDamage(attack);
    cout<< name << " annoys you doing " << abs(temp) << " damage to you" << endl;
}

//Weak attack for this enemy
//Does half of the normal damage
void Junior::weakAttack(){
    cout<< name << " stops you to say \"I'm actually a Junior by Credits\" again" << endl;
    int temp = player->takeDamage((.5*attack));
    cout<< name << " it bores you doing " << abs(temp) << " damage to you" << endl;
}

//Strong attack for this enemy
//Does 2 times normal damage
void Junior::strongAttack(){
    cout<< name << " used: \"I Suffer from Success\"" << endl;
    int temp = player->takeDamage(2*attack);
    cout<< name << " does " << abs(temp) << " damage to you" << endl;
    
}

// holds enemy AI
// determines what attack the enemy will do
void Junior::retaliate(){
    //srand (time(NULL));
    int randomNum = rand() % 4 + 1;
    
    if(randomNum == 1){
        weakAttack();
    } else if (randomNum == 2 || randomNum == 3){
        normalAttack();
    } else {
        strongAttack();
    }
}
//This is where the entire interaction between the Player and this enemy takes place
void Junior::fight(){
    int userInput = 0;
    
    cout<< name << " shows up." << endl;
    
    //battle loop
    while(health > 0 && player->gameOver == false){
        cout<< "What will you do? \n(1) Say that you are an actual Junior" << endl ;
        cout<<"(2) Taunt them with your life experience \n(3) Use Gator \n(4) Ignore."  << endl;
        cin>>userInput;
        player->getHealth();
        if(userInput == 1){
            //normal player attack
            int temp = takeDamage(player->getAttack());
            cout<<"He says: \"Sorry Master\"  you did " << abs(temp) << " points damage." << endl;
            retaliate();
        } else if (userInput == 2){
            //weak enemy attack
            cout<< "\"Wow, I see how it is...\"" << endl;
            int temp = takeDamage((.5*player->getAttack()));
            cout<<"Afraid, you did " << abs(temp) << " damage." << endl;
            retaliate();
        } else if(userInput == 3) {
            //if (hasGator = true)
            //eat Junior By Credits "Tasty"
            //you win
            //if (hasGator = false)
            cout<<"Sorry, you don't have a Gator. (shame) "<< endl;
            //break;
        }else if(userInput == 4) {
            //run or quit battle
            cout<<"\"You escaped the clutches of " << name << " \"" << endl;
            map->back();
            break;
        }
        else {
            cout<<"What was that? That's not an option." << endl;
        }
    }
    cout<< name << " retires." << endl;
}


