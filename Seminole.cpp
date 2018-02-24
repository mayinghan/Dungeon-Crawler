//
//  Seminole.cpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.//

#include "Seminole.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructor
Seminole::Seminole(){
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
Seminole::Seminole(Player* p, Map* m){
    
    name = "Seminole";
    
    //Object of Player class allowing us to manipulate the Player
    player = p;
    map = m;
    
    health = 20;
    attack = 12;
    defense = 3;
}

//Use when Player attacks Enemy
//same code as in Player class
int Seminole::takeDamage(double playerAttack){
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
//Random 1-10, but can be high damage
void Seminole::spearAttack(){
    cout<< "The " << name << " grabbed his replica spear and poked you with it." << endl;
    int temp = player->takeDamage(rand() % attack + 1);
    cout<< "He forgot rubber is soft, and it only does " << abs(temp) << " damage to you" << endl;
}

//Weak attack for this enemy
//Either 10 or 0 damage
void Seminole::bowAttack() {
    cout << "The " << name << " appears to be taking his time to aim with his bow, or maybe he doesn't know how to use it?" << endl;
    int randomInt = rand() % 2;
    if (randomInt == 0) {
        int temp = player->takeDamage(attack);
        cout << "The " << name << " must have got a lucky shot; it does " << abs(temp) << " damage to you" << endl;
    }
}

// Determines what attack the enemy will do
void Seminole::retaliate() {
    srand(time(NULL));
    int randomNum = rand() % 4 + 1;
    
    if (randomNum == 1 || randomNum == 2 || randomNum == 3){
        spearAttack();
    } else if (randomNum == 4){
        bowAttack();
    }
}
//This the interaction between the Player and the Seminole
void Seminole::fight() {
    int userInput = 0;
    
    cout << name << " comes into view." << endl;
    
    //battle loop
    //int totalDamage = 0;
    bool beat = true;
    while (health > 0 && player->gameOver == false) {
        cout << "What will you do?" << endl<< "(1) Razzle dazzle 'em." << endl;
        cout << "(2) Timidly throw a punch." << endl << "(3) Throw shade on their alma mater" << endl;
        cout<<"(4) Run from battle." << endl;
        cin >> userInput;
        player->getHealth();
        if (userInput == 1) {
            //normal player attack
            cout << "\"Guess I will give 'em the ol' razzle dazzle.\"" << endl;
            int temp = takeDamage(player->getAttack());
            cout << "You struck the enemy with the same old move for " << abs(temp) << " damage."<<endl;
            retaliate();
        }
        else if (userInput == 2) {
            //weak player attack
            cout << "\" You hit 'em with a softy.\"" << endl;
            int temp = takeDamage((.5*player->getAttack()));
            cout << "You went easy on the fool and did " << abs(temp) << " damage."<< endl;
            retaliate();
        }
        else if (userInput == 3) {
            cout <<"You mention that you go to a top 10 public university" << endl;
            int temp = takeDamage((1.5*player->getAttack()));
            cout << "\"That's gotta hurt\" You do " << abs(temp) << " damage."<< endl;
            retaliate();
        }
        else if (userInput == 4) {
            //run or quit battle
            cout << "\"FSU forever\" the Seminole shouts after you." << endl;
            map->back();
            beat = false;
            break;
        }
        else {
            cout << "Come on dude. Why you gotta play me like that?" << endl;
        }
    }
    //when defeated drops headphones item
    cout<< name << " runs back to Tallahassee." << endl;
    if(beat) player->addItem(player->item, "headphones");
    cout<<"He incidently dropped his headphones and you picked it up. Now you have the project in your package."<<endl;
}
