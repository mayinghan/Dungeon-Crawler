//  SleepDeprivedStudent.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.


#include "SleepDeprivedStudent.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Constructor
SleepDeprivedStudent::SleepDeprivedStudent() {
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

// Specific constructor that player can interact with
SleepDeprivedStudent::SleepDeprivedStudent(Player* p, Map *m) {
    name = "Sleep-Deprived Student";
    
    // Object of Player class allowing us to manipulate the Player
    this->player = p;
    this->map = m;
    
    // notice how the following values are greater and less than Player values;
    // This enemy should be killed in 1-3 turns
    // This enemy will do a moderate amount of damage to Player when fought
    // Classification: normal/common Enemy
    health = 25;
    attack = 12;
    defense = 1;
}


// Use when Player attacks Enemy
// same code as in Player class
int SleepDeprivedStudent::takeDamage(double playerAttack) {
    double damageDone = defense - playerAttack;
    if (damageDone < 0) {
        // adding because damageDone will only be negative
        health = health + damageDone;
    }  else {
        damageDone = 0;
    }
    return damageDone;
}

// Basic attack for this enemy
// Will be the most common attack
void SleepDeprivedStudent::normalAttack() {
    cout << name << " loses their balance and falls into you, resulting with an unpleasant landing onto the hard floor." << endl;
    int temp = player->takeDamage(attack);
    cout << name << " the fall inflicts " << abs(temp) << " damage to you." << endl;
}

// Weak attack for this enemy
// Does half of the normal damage
void SleepDeprivedStudent::weakAttack() {
    cout << name << " cries and complains to you that the last time they had sleep was three weeks ago." << endl;
    int temp = player->takeDamage((.5 * attack));
    cout << "Listening to their sad life is tiresome, thus the " << name << " does " << abs(temp) << " damage to you." << endl;
}

// Strong attack for this enemy
// Does 2 times normal damage
void SleepDeprivedStudent::strongAttack() {
    cout << name << " throws their book-filled backpack at you in frustration." << endl;
    int temp = player->takeDamage(1.5 * attack);
    cout << "The heaviness of the " << name << "\'s bag collapses you and does " << abs(temp) << " damage to you." << endl;
}

// holds enemy AI
// determines what attack the enemy will do
void SleepDeprivedStudent::retaliate() {
    // srand (time(NULL));
    int randomNum = rand() % 4 + 1;
    
    if (randomNum == 1) {
        weakAttack();
    } else if (randomNum == 2 || randomNum == 3) {
        normalAttack();
    } else {
        strongAttack();
    }
}

// This is where the entire interaction between the Player and the Sleep-Deprived Student takes place
void SleepDeprivedStudent::fight() {
    int userInput = 0;
    
    cout << "A creepy silhouette staggers toward you, is that a... zombie?! OH, no worries, it's just a " << name << "." << endl;
    
    // battle loop
    while(health > 0 && player->gameOver == false) {
        cout << "What will you do? \n(1) Laugh at the profound bags under their eyes." << endl;
        cout << "(2) Check Inventory for anything useful. \n(3) Try to escape." << endl;
        cin >> userInput;
        player->getHealth();
        if (userInput == 1) {
            // normal player attack
            cout << "The Student just stands there helplessly as you point and laugh hysterically at them. ";
            int temp = takeDamage(player->getAttack());
            cout << "Already overwhelmed with emotions, the Student is unable to ignore you and takes " << abs(temp) << " damage.\n";
            retaliate();
        } else if (userInput == 2) {
            // check for useful items
            if (player->item.size() == 0) {
                cout << "You don't even have anything, wtf?" << endl;
                retaliate();
            } else {
                bool itemFound = false;
                for (int i = 0; i < player->item.size(); i++) {
                    if (player->item.at(i).compare("coffee") == 0) {
                        itemFound = true;
                        cout << "You withdraw the Starbucks Coffee from your bag and the Student's face lights up with joy as they take it from you and run towards the nearest library." << endl;
                        player->deleteItem(player->item, player->item[i]); // remove item
                        break;
                    }
                }
                if (!itemFound) {
                    cout << "You don't have any useful items at the moment." << endl;
                }
            }
        } else if (userInput == 3) {
            // player has 50% chance of successfully fleeing from Student
            int randomNum = rand() % 2 + 1;
            if (randomNum == 1) {
                cout << "You successfully flee from the exhausted creature." << endl;
                map->back();
                break;
            }
            else if (randomNum == 2) {
                cout << "Just as you try to run away, the Student desperately grabs your arm and pulls you back." << endl;
                retaliate();
            }
        } else {
            cout << "Nooooope. Wrong Input." << endl;
        }
    }
    cout << name << ", entirely out of energy, plops down onto the cold tile and falls into a deep slumber." << endl; // Student is defeated.
    string drop = "homework";
    
    int randomNum = rand() % 3 + 1;
    if (randomNum == 1) {
        cout << "The Student drops some completed homework. It must've taken them several hours for them to complete, but it could be useful later on so you pick it up anyway." << endl;
        player->addItem(player->item, drop);
    }
}
