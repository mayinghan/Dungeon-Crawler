//  Player.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
#include <iostream>
#include <string>

#include "Player.hpp"

using namespace std;

//constructor
//sets everything to null
Player::Player(){
    name = "";
    GPA = 0;
    stamina = 0;
    attack = 0;
    defense = 0;
    playerX = 0;
    playerY = 0;
    gameOver = NULL;
}

//Specific Constructor
//sets all private variables to starter values
Player::Player(string name){
    this->name = name;
    GPA = 4.0;
    stamina = 100;
    attack = 5;
    defense = 5;
    defenseGPA = defense*.1;
    playerX = 0;
    playerY = 0;
    gameOver = false;
    //fill inventory with null Item instances
}

//Use in Enemy subclass when attacking Player to reduce stamina
//Only reduces stamina if denfense < enAttack
int Player::takeDamage(double enAttack){
    int damageDone = defense - enAttack;
    if(damageDone < 0){
        //adding because damageDone will only be negative
        stamina= stamina + damageDone;
        if(stamina <= 0){
            gameOver = true;
        }
    } else {
        damageDone = 0;
    }
    return damageDone;
}

//Use in boss and mini boss classes to reduce GPA
double Player::takeDamageBoss(double bossAttack){
    double damageDone = defenseGPA - bossAttack;
    if(damageDone < 0){
        //adding because damageDone will only be negative
        GPA = GPA + damageDone;
        if(GPA <= 0){
            gameOver = true;
        }
    }
    return damageDone;
}
// getter functions for name, attack, GPA, and Stamina to access those variables
string Player::getName(){
    return name;
}
int Player::getAttack(){
    return attack;
}
void Player::getHealth(){
    cout<< "Stamina: " << stamina << " GPA: " << GPA <<endl;
}
//fully heal player
void Player::fullHeal(){
    stamina = 100;
    GPA = 4;
}
// Set stamina to 100   // increase attack, stamina defense, and GPA defense when you go up a level
void Player::levelUp(){
    
    if(stamina < 90){
        stamina+= 10;
    } else {
        stamina = 100;
    }
    
    attack += 5;
    defense += 5;
    defenseGPA = defense*.1;
}
// push function for item vector
void Player::addItem(vector<string> &item, string drop){
    item.push_back(drop);
}
// pop function for item vector
void Player::deleteItem(vector<string> &item, string del){
    item.erase(remove(item.begin(), item.end(), del), item.end());
}


