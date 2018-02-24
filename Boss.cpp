//
//  Boss.cpp
//  Dungeon Crawler
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//
#include "Boss.hpp"
#include "Player.hpp"

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using std::chrono::system_clock;
//constructor
Boss::Boss(){
    name="";
    health =0;
    attack=0;
    defense=0;
}

Boss::Boss(Player* P, Map* m){
    name= "Professor Kavalan";
    
    health= 60;
    attack = 2;
    defense= 8;
    
    player = P;
    map = m;
}

int Boss::takeDamage(double playerAttack){
    double damageDone=playerAttack- defense;
    if(damageDone>0){
        health=health-damageDone;
        //print the statement
        //cout<<"You just did "<< fabs(damageDone) <<" damage to "<<name<<endl;
        return damageDone;
    }
    else{
        cout<<"Emmmm.... Your attack is too weak"<<endl;
        return 0;
    }
}

//normal attack
void Boss::normalAttack(){
    cout<<name<<" cannot understand your answer to one question in the exam."<<endl;
    double dmg=player->takeDamageBoss(1.1*attack);
    cout<<name<<" makes your GPA reduce by "<<abs(dmg)<<"."<<endl;
}

//strong attack 1.5 times dmg
void Boss::strongAttack(){
    cout<<name<<" just found out that you have too many bugs in your project."<<endl;
    double dmg=player->takeDamageBoss(1.3*attack);
    cout<<name<<" makes your GPA plummet by "<<abs(dmg)<<"."<<endl;
}

//weak attack 0.8 times dmg
void Boss::weakAttack(){
    cout<<name<<" left his office during this office hour, so he cannot answer your questions or deal with your request of changing grades."<<endl;
    double dmg=player->takeDamageBoss(1.2*attack);
    cout<<name<<" make your GPA reduce by "<< abs(dmg)<<"."<<endl;
}

//AI: determine which attack the enemy will make
void Boss::retaliate(){
    srand( (unsigned int) time(NULL));
    int randomNum=rand()%4+1;
    
    if (randomNum==1){
        weakAttack();
    }else if (randomNum==2|| randomNum==3){
        normalAttack();
    }else{
        strongAttack();
    }
}


//interaction between the player and this enermy
void Boss::fight(){
    int userInput = 0;
    cout<< name <<" just show up in front of you."<<endl;
    
    //battle loop
    while(health > 0 && player->gameOver == false) {
        player->getHealth();
        cout<< "What will you do?" << endl <<"(1) Ask him to round your grade from a 49.9 to a 95" << endl ;
        cout<< "(2) Attend lecture" << endl << "(3) Make him the final boss of your game" << endl;
        cout<<"(4) Give professor something which can please him" << endl <<"(5) Run....." << endl;
        cin>>userInput;
        
        switch (userInput) {
            case 1:{
                cout<<"You ask " << name << " to round your grade up." << endl;
                sleep_until(system_clock::now() + 4s);
                cout<<"He refuses."<<endl;
                sleep_until(system_clock::now() + 1s);
                cout<<"You both sit there in an awkward silence"<< endl;
                sleep_until(system_clock::now() + 7s);
                retaliate();
                break;
            }
            case 2: {
                cout<<"You decide to actually wake up early and go to class. And what do you know? You actually learned something!" << endl;
                sleep_until(system_clock::now() + 4s);
                int damage = takeDamage(player->getAttack());
                cout<<"With your new found knowledge you crush your exam! You do " << abs(damage) << " damage to " << name << endl;
                sleep_until(system_clock::now() + 3s);
                retaliate();
                break;
            }
            case 3: {
                int multiplier;
                cout<<"You made him the final boss in your game ... bold move." << endl;
                sleep_until(system_clock::now() + 2s);
                cout<<"So how did we do Professor? (1) Poor (2) Good (3) Excellent" << endl;
                cin>> multiplier;
                
                int damage = takeDamage(multiplier*player->getAttack());
                cout<<"You do " << abs(damage) << " damage to " << name << endl;
                sleep_until(system_clock::now() + 4s);
                retaliate();
                break;
            }
            case 4:{
                if(player->item.size()==0){
                    cout<<"You don't even have anything in your inventory."<<endl;
                    int dmg=player->takeDamageBoss(attack+.01);
                    cout<<"You get "<<dmg<<" attack from the professor."<<endl;
                }
                else{
                    for(int i=0; i<player->item.size(); i++){
                        
                        if(player->item.at(i).compare("homework")==0){
                            for(int j=0; j< player->item.size();j++){
                                if(player->item.at(i).compare("project")==0){
                                    cout<<"You just hand in your homework, and now he has to grade your homework because he gets paid to do so, so he won't have too much time to attack you."<<endl;
                                    sleep_until(system_clock::now() + 4s);
                                    cout<<"You reduced half of the professor's hp"<<endl;
                                    health=health/2;
                                }else{
                                    cout<<"You dont have the item that professor wants."<<endl;
                                    int dmg=player->takeDamageBoss(attack);
                                    cout<<"You get "<<dmg<<" attack from the professor."<<endl;
                                }
                            }
                            
                        }else{
                            if(i==player->item.size()-1 ){
                                cout<<"You dont have the item that professor wants."<<endl;
                                int dmg=player->takeDamageBoss(attack);
                                cout<<"You get "<<dmg<<" attack from the professor."<<endl;
                            }
                        }
                        
                    }
                }
                
                break;
            }
            case 5:{
                //50% chance that cannot run away
                srand((unsigned int) time(NULL));
                int ranNum= rand()%2;
                if(ranNum==0){
                    cout<<"You run away successfully. "<<endl;
                    map->back();
                    break;
                }else{
                    cout<<"Oops.... Our beloved professor doesn't want you to leave his office~"<<endl;
                    retaliate();
                    break;
                }
                
                break;
                
            }
            default:{
                cout<<"Please follow the game instruction, or you will fall into an unknown abyss and may never come back to the real world."<<endl;
                break;
            }
        }
        
        
    }
    
    if(health<=0){
            userInput = 0;
            cout<<"You have defeated " << name << endl;
            cout<<"After a truly epic showdown, you and the professor alone remain on the field of battle."<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"Broken, battered, and bruised, you stare each other down, breathless and completely unable to fight anymore." << endl;
            sleep_until(system_clock::now() + 4s);
            cout<<"(1) to catch your breath." << endl;
            while (userInput != 1) {
                cin>>userInput;
            }
            userInput = 0;
            cout<<"\"Alright I admit it, "<< player->getName() <<",\" "<< name <<" says, gasping for air, \"you might be the best computer science student I’ve ever met. You remind me of myself when I was younger.\""<<endl;
            sleep_until(system_clock::now() + 7s);
            cout<<"\"I appreciate that, Professor,\" you say in a steely voice, \"but you know that doesn’t help me right now. You know what I want.\"" << endl;
            sleep_until(system_clock::now() + 5s);
            cout<< name <<" sighs. \"Of course... Well, I suppose you’ve earned it.\""<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"He hands you a key card, identical to the others you’ve collected from the Teaching Assistants, save that this one is plated in gold and has a large, red ‘A’ written on it in flowery font." << endl;
            sleep_until(system_clock::now() + 10s);
            cout<<"(1) to collect your reward." << endl;
            while (userInput != 1) {
                cin>>userInput;
            }
            userInput = 0;
            cout<<"You take the key from the Professor."<<endl;
            sleep_until(system_clock::now() + 3s);
            cout<<"\"Go on then.\" He says, \"It’s time for you to be moving on.\"" << endl;
            sleep_until(system_clock::now() + 4s);
            cout<<" The Professor gestures to the final staircase behind him, the door to which is fashioned from hard tempered steel and secured with an electronic security system."<<endl;
            sleep_until(system_clock::now() + 6s);
            cout<<"(1) to insert key card." << endl;
            while (userInput != 1) {
                cin>>userInput;
            }
            userInput = 0;
            cout<<"You insert the key card, and with a mechanical whir the heavily guarded door slides open."<<endl;
            sleep_until(system_clock::now() + 4s);
            cout<<"You ascend the winding staircase, and find another door, this one dilapidated and practically falling off its hinges. You gently push on it, and the door falls back with a clatter." << endl;
            sleep_until(system_clock::now() + 6s);
            cout<<"You are instantly blinded by an intense white light. As you squint and your eyes adjust to the visual assault, you realize that you are standing on the roof of the CISE building."<<endl;
            sleep_until(system_clock::now() + 6s);
            cout<<"You step over the fallen door and out into the middle of the roof. " << endl;
            sleep_until(system_clock::now() + 3s);
            cout<<"(1) to bask in the warmth of the sun." << endl;
            while (userInput != 1) {
                cin>>userInput;
            }
            userInput = 0;
            cout<<"As you put your head back and let the sunshine wash over your chilled body, you notice a dull roaring sound gradually getting louder."<<endl;
            sleep_until(system_clock::now() + 9s);
            cout<<"As you open your eyes to check out the disturbance, a black apache helicopter erupts into your field of vision. It lands on edge of the roof, and a dozen armed figures dressed in black jump out." << endl;
            sleep_until(system_clock::now() + 9s);
            cout<<"They rapidly surround you, bind your hands and feet with rope, and start dragging you toward the helicopter. "<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"(1) to struggle against your captors." << endl;
            while (userInput != 1) {
                cin>>userInput;
            }
            cout<<"Your efforts quickly prove futile against what are clearly government blackwater-operations personnel."<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"As they load you onto the aircraft, you see the Professor stride onto the roof, eyes beaming with excitement." << endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"\" "<< name <<", where are you taking me?!?\" you shout at him as the helicopter begins to take off."<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"The Professor laughs a hearty laugh that makes your heart drop into your stomach." << endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"\"Did you really think this was the end?\" He yells against the maelstrom of wind emanating from the propellers."<<endl;
            sleep_until(system_clock::now() + 5s);
            cout<<"Oh no, I’ve got plans for you… big plans. You’re going to my secret research island, codename COP3530, where you will be trained as my newest Teaching Assistant." << endl;
            sleep_until(system_clock::now() + 8s);
            cout<<"Congrats, "<< player->getName() << ". You made it through the course ... but did you really win?" << endl;
            sleep_until(system_clock::now() + 3s);
            cout<<endl<<endl<<"Your final stats are: ";
            player->getHealth();
            sleep_until(system_clock::now() + 15s);
            exit(0);
    }
}

