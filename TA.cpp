//  TA.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#include "TA.hpp"
//#include "ExampleEnemy.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Constructor
TA::TA(){
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
TA::TA(Player* p, Map* m){
    
    name = "Teaching Assistant ";
    
    //Object of Player class allowing us to manipulate the Player
    player = p;
    map = m;
    
    //notice how the following values are greater and less than Player values;
    //This enemy will take 4-5 turns to kill
    //This enemy will do a moderate to high amount of damage to Player when fought
    //Classification: Mini-Boss (Set Piece)
    health = 20;
    attack = m->currentLevel * .55;
    defense = m->currentLevel * 4;
}

//Use when Player attacks Enemy
//same code as in Player class
int TA::takeDamage(double playerAttack){
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
void TA::normalBossAttack(){
    cout<< name << " looks over your last exam." << endl;
    cout<< "\"What is this nonsense?!?\" he exclaims. \"Points off!!\"" << endl;
    int temp = player->takeDamageBoss(1.1*attack);
    cout<< name << " reduces your GPA by " << abs(temp) << " points." << endl;
}

//Weak attack for this enemy
//Does half of the normal damage
void TA::weakBossAttack(){
    cout<< "You walk into the lab session, but the TA is nowhere to be found." << endl;
    cout<< "You and the other students wait around for 20 minutes until he finally shows up, panting and out of breath." << endl;
    cout<< "\"Sorry I'm late guys, now let's get started\" he says, still breathing heavily." << endl;
    cout<< "\"Well,\" you think to yourself, \"that was a huge waste of time.\"" << endl;
    
    int temp = player->takeDamageBoss((1*attack));
    cout<< name << " reduces your GPA by " << abs(temp) << " points." << endl;
}

//Strong attack for this enemy
//Does 2 times normal damage
void TA::strongBossAttack(){
    cout<< name << " gives a long, boring tutorial on inheritance during lab session." << endl;
    cout<< "You start to doze off during class..." << endl;
    cout<< "...ZZZ...ZZZ...ZZZ..." << endl;
    cout<< "\"Now, did everyone understand that?\" he asks." << endl;
    cout<< "You wake up with a start, still not knowing anything about inheritance." << endl;
    int temp = player->takeDamageBoss(2*attack);
    cout<< name << " reduces your GPA by " << abs(temp) << " points." << endl;
    
}

// holds enemy AI
// determines what attack the enemy will do
void TA::retaliate(){
    //srand (time(NULL));
    int randomNum = rand() % 4 + 1;
    
    if(randomNum == 1){
        weakBossAttack();
    } else if (randomNum == 2 || randomNum == 3){
        normalBossAttack();
    } else {
        strongBossAttack();
    }
}
//This is where the entire interaction between the Player and this enemy takes place
void TA::fight(){
    int userInput = 0;
    
    cout<< name << " " << endl;
    bool beat = true;
    //battle loop
    while(health > 0 && player->gameOver == false){
        cout<< "What will you do? \n(1) Ask interesting questions during lab session to show you're engaged." << endl ;
        cout<<"(2) Rummage in your backpack, looking for items. \n(3) Never go to lab session and fail the class." << endl;
        cin>>userInput;
        player->getHealth();
        if(userInput == 1){
            //normal player attack
            cout<<"The TA is shocked! 'WOW!' he exclaims, 'great question. The answer is actually pretty interesting...' and launches into a huge, excited rant. \n";
            int temp = takeDamage(player->getAttack()*2);
            cout<< "Upset that his students are not meeting expectations, his harsh grading lowers by " << abs(temp) << " points.\n";
            retaliate();
        } else if (userInput == 2){
            bool check = false;
            for(int i=0; i<player->item.size(); i++){
                if(player->item.at(i).compare("project")==0){
                    health=0;
                    check = true;
                    player->deleteItem(player->item, "project");
                    break;
                }
            }
            if(!check){
                cout<<"You don't have the stuff that the TA wants."<<endl;
                retaliate();
            }
        } else if(userInput == 3) {
            //run or quit battle
            cout<<"\"Well, that didn't go great. Maybe you should try again later.\"" << endl;
            map->back();
            beat = false;
            break;
        } else {
            cout<<"Input a whole number, dummy! Don’t you know what a number is?" << endl;
        }
    }
    cout<< name << " decides teaching isn't really his thing." << endl;
    cout<< "He quits being a TA to focus on his new tech startup: delivering puppies to elderly people via drones. This oughta be good..." << endl;
    
    if(beat){
        player->addItem(player->item, "key");
    }
    cout<<"Now you have the key to the stairs."<<endl;
    
    
}
