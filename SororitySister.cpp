//  SororitySister.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#include "SororitySister.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constructor
SororitySister::SororitySister() {
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

// Specific constructor that player can interact with
SororitySister::SororitySister(Player* p, Map *m) {
    name = "Sorority Sister";
    
    // Object of Player class allowing us to manipulate the Player
    this->player = p;
    this->map = m;
    
    // notice how the following values are greater and less than Player values;
    // This enemy should be killed in 1-3 turns
    // This enemy will do a moderate amount of damage to Player when fought
    // Classification: normal/common Enemy
    health = 30;
    attack = 8;
    defense = 2;
}


// Use when Player attacks Enemy
// same code as in Player class
int SororitySister::takeDamage(double playerAttack) {
    double damageDone = defense - playerAttack;
    if (damageDone < 0) {
        // adding because damageDone will only be negative
        health = health + damageDone;
    }  else {
        damageDone = 0;
    }
    return damageDone;
}


// Normal attack for this enemy
// Does half of the normal damage
void SororitySister::normalAttack() {
    cout << name << " makes fun of you because you aren't in Greek Life." << endl;
    int temp = player->takeDamage(attack);
    cout << "Now you feel like a total loser. The " << name << " succeeded, and did " << abs(temp) << " damage to you." << endl;
}

// Strong attack for this enemy
// Does 2 times normal damage
void SororitySister::strongAttack() {
    cout << name << " forces you to listen to the latest scoop of UF's Greek Gossip." << endl;
    int temp = player->takeDamage(2 * attack);
    cout << "She talks faster than your brain can process words, and the " << name << " does " << abs(temp) << " damage to you." << endl;
}

// holds enemy AI
// determines what attack the enemy will do
void SororitySister::retaliate() {
    // srand (time(NULL));
    int randomNum = rand() % 3 + 1;
    
    if (randomNum == 1 || randomNum == 2) {
        normalAttack();
    } else {
        strongAttack();
    }
}

// This is where the entire interaction between the Player and the Sorority Sister takes place
void SororitySister::fight() {
    int userInput = 0;
    
    cout << "An infuriated " << name << " steps into your view." << endl;
    
    // battle loop
    while(health > 0 && player->gameOver == false) {
        cout << "What will you do? \n(1) Tell her that her sorority is the worst one at UF." << endl;
        cout << "(2) Tear off the sorority sticker from her laptop. \n(3) Try to escape while she's texting her other Sorority Sisters." << endl;
        cin >> userInput;
        player->getHealth();
        if (userInput == 1) {
            // normal player attack
            cout << "The Sorority Sister stands in disbelief. ";
            int temp = takeDamage(player->getAttack());
            cout << "Trying as hard as she can to hold back tears, she takes " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 2) {
            // normal player attack
            cout << "Wow, she looks pretty upset. ";
            int temp = takeDamage(player->getAttack());
            cout << "She took that way too seriously, but it's in your favor since she takes " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 3) {
            cout << "You successfully flee from the enraged Sorority Sister." << endl;
            map->back();
            break;
        } else {
            cout << "That's just disrespectful, man." << endl;
        }
    }
    cout << name << ", runs away looking for her beloved Sisters." << endl; // Sister is defeated.
    string drop = "coffee";
    
    int randomNum = rand() % 3 + 1;
    if (randomNum == 1) {
        cout << "The Sorority Sister drops some freshly bought Starbucks Coffee. You quickly grab it without hesitating." << endl;
        player->addItem(player->item, drop);
    }
}
