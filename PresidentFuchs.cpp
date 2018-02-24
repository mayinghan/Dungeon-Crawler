//  PresidentFuchs.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

#include "PresidentFuchs.hpp"
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
PresidentFuchs::PresidentFuchs() {
    name = "";
    health = 0;
    attack = 0;
    defense = 0;
}

//Specific constructor that player can interact with
PresidentFuchs::PresidentFuchs(Player* p, Map *m) {
    
    name = "President Fuchs";
    
    //Object of Player class allowing us to manipulate the Player
    this->player = p;
    this->map = m;
    
    //notice how the following values are greater and less than Player values;
    //Classification: very rare (non-enemy) character
    health = 100;
    attack = 100;
    defense = 100;
}

void PresidentFuchs::healPlayer() {
    player->fullHeal();
}

//This is where the entire interaction between the Player and The President takes place
void PresidentFuchs::fight() {
    int userInput = 0;
    
    cout << "Wow, look who it is! The famous " << name << " appears out of the darkness. It's relieving to finally find someone that seems to be normal in this crazy place." << endl;
    
    //battle loop
    while(health > 0) {
        cout << "What will you do? \n(1) Take your chances, and spark up a conversation with the Prez." << endl;
        cout << "(2) Run away because the paranoia from The Dungeon has consumed you, and has made you become untrusting of everyone you encounter." << endl;
        cin >> userInput;
        
        if(userInput == 1) {
            cout << "YOU: \"Hey President Fuchs, what are you doing in such a cold, cruel place like this???\"" << endl;
            cout << "PRESIDENT FUCHS: \"Greetings my fellow Gator! I was just doing my usual rounds throughout campus, "
            << "and I just couldn't help but hear the screams and sorrows pouring out of the CISE building today... "
            << "It was just far more than the usual amount, so I had to check out the scene for myself.\"" << endl;
            cout << "YOU: \"Yeah, this place is cursed! I've been trying to escape for hours but I can't seem to find a way out." << endl;
            cout << "PRESIDENT FUCHS: \"Oh dear, I am sorry to leave so quickly, but I must return to my duties. You are indeed a Gator, "
            << "so I have faith that you can make it out of here, just don't give up!\"" << endl;
            cout << "All of a sudden, President Fuchs vanishes to nothing right before your eyes. Now you really feel like you're going crazy. "
            << "On the bright side, you feel very replenished and all fatigue has been lifted from you." << endl;
            healPlayer();
            break;
        } else if (userInput == 2) {
            cout << "The UF President looks deeply saddened that you didn't stop to talk to him. ";
            int rudeness = 5;
            cout << "The guilt brings down your will to continue by " << rudeness << " points." << endl;
            player->takeDamage(rudeness);
            break;
        } else {
            cout << "You're not making this any easier for either of us. Please, just pick a choice." << endl;
        }
    }
}
