//
//  Alligator.cpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#include "Alligator.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructor
Alligator::Alligator(){
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
Alligator::Alligator(Player* p, Map* m){
    
    name = "Alligator";
    
    //Object of Player class allowing us to manipulate the Player
    player = p;
    map = m;
    //notice how the following values are greater and less than Player values;
    //This enemy should be killed in 1-2 turns
    //This enemy will do a moderate amount of damage to Player when fought
    //Classification: normal/common Enemy
    health = 5;
    attack = (m->currentLevel) * 5 + 3;
    defense = (m->currentLevel) * 5 - 1;
}

//Use when Player attacks Enemy
//same code as in Player class
int Alligator::takeDamage(double playerAttack){
    double damageDone = defense - playerAttack;
    if(damageDone < 0){
        //adding because damageDone will only be negative
        health = health + damageDone;
    }  else {
        damageDone = 0;
    }
    return damageDone;
    
}

//Basic attack for this enemy
//Will be the most common attack
void Alligator::chompAttack(){
    cout << "The "<< name << " hasn't seen any easy prey (Seminoles) recently, his stomach takes control..." << endl;
    int temp = player->takeDamage(attack);
    cout<< "The "<< name << " does " << abs(temp) << " damage to you" << endl;
}

//Weak attack for this enemy
//Does only a portion of attack
void Alligator::allicaneAttack(){
    cout<<"What is this?! A hurricane has started... but... there's alligators in it... like sharknado?"<< endl;
    int temp = player->takeDamage(attack-2);
    cout<<"An "<< name << " is hurled from the sky. He catches you with an accidental but skillful ariel attack, and you take " << abs(temp) << " damage." << endl;
}

//Strong attack for this enemy
//Does 2 times normal damage
void Alligator::stalkAttack(){
    cout<< "The "<< name << " watches you from a distance, eyes just above the horizon of the water..." << endl;
    int temp = player->takeDamage(2*attack);
    cout<<"The "<< name << " attacks you with no warning! Your defense was low and you took " << abs(temp) << " damage." << endl;
    
}

// holds enemy AI
// determines what attack the enemy will do
void Alligator::retaliate(){
    //srand (time(NULL));
    int randomNum = rand() % 5 + 1;
    
    if(randomNum == 1 || randomNum == 2 || randomNum == 3){
        chompAttack();
    } else if (randomNum == 4){
        allicaneAttack();
    } else {
        stalkAttack();
    }
}
//This is where the entire interaction between the Player and this enemy takes place
void Alligator::fight(){
    int userInput = 0;
    
    cout<<"An "<< name << " in the dungeon? It must've escaped from Lake Alice!" << endl;
    
    //battle loop
    while(health > 0 && player->gameOver == false){
        cout<< "What will you do? \n(1) Slay the sacred alligator with a normal attack." << endl ;
        cout<<"(2) Hit your mascot with a gentle, yet noticable blow (weak attack). \n(3) Run!!!!!" << endl;
        cin>>userInput;
        player->getHealth();
        if(userInput == 1){
            //normal player attack
            cout<< "\"No mercy! This gator has high defense and I'm going to need to hit him hard to survive!\"" << endl;
            int temp = takeDamage(player->getAttack());
            cout<<"The gator intakes the blow like a tank, but it still does " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 2){
            //weak enemy attack
            cout<< "\" It's hard to hurt the one I love...\"" << endl;
            int temp = takeDamage((.5*player->getAttack()));
            cout<<"You couldn't muster the courage to attack the gators you normally praise, and you only do " << abs(temp) << " damage.\n";
            retaliate();
        } else if(userInput == 3) {
            //run or quit battle
            cout<<"The Alligator hisses at you as you run away." << endl;
            map->back();
            break;
        } else {
            cout<<"The Alligator does not appreciate you joking around right now." << endl;
        }
    }
    cout<< name << " returns to Lake Alice." << endl;
}
