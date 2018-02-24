//  main.cpp
//  Game Tester
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.

//Classes
#include "Player.hpp"
#include "Enemy.hpp"
#include "Dennis.hpp"
//#include "ExampleEnemy.hpp"
#include "Junior.hpp"
#include "CrazySquirrel.hpp"
#include "TurlingtonTabler.hpp"
#include "Seminole.hpp"
#include "SleepDeprivedStudent.hpp"
#include "SororitySister.hpp"
#include "PresFuchs.hpp"
#include "Alligator.hpp"
#include "TA.hpp"
#include "Boss.hpp"
#include "Map.hpp"

//Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

//Methods
void spawn(Enemy** e, Player* p, Map* m);

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using std::chrono::system_clock;
int main(int argc, const char * argv[]) {
    
    //initialize a random seed
    //makes it so that we can continually regenerate random numbers
    srand((unsigned)time(0));
    //init other variables
    int randomNum;
    int userInput = 0;
    string name;
    Enemy* e = NULL;
  
    // Have user input their name and name the player object
    cout<<"Please input your name: ";
    cin>>name;
    Player* p = new Player(name);
    Map* m = new Map(p);
    
    // Intro Text -- Storyline (includes pauses and user prompts) -- Big block of text
    cout<<"Harsh, florescent lights beam down on you, jolting you out of your peaceful rest." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"A gentle mechanical whir seems to emanate from every corner of the room." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"And it’s cold... so deeply, bone-chillingly cold." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"You should have brought a jacket..." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"(1) To take stock of your surroundings." << endl;
    while (userInput != 1) {
        cin>>userInput;
    }
    userInput = 0;
    cout<<"You look around. Rows of monitors project an eerie blue light." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"The walls are covered in writings of a seemingly foreign language,";
    sleep_until(system_clock::now() + 3s);
    cout<<"filled with lines upon lines of strange symbols you don’t understand." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"In the distance, you hear the tortured wails of graduate students ";
    cout<<"doing last minute projects contemplating alternate lives as fast food workers.”" << endl;
    sleep_until(system_clock::now() + 5s);
    cout<<"(1) to get the heck out of there." <<endl;
    while (userInput != 1) {
        cin>>userInput;
    }
    userInput = 0;
    cout<<"You try the nearest door and realize it’s locked." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<" Across the building, you can barely make out a shape that looks vaguely like a staircase." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"It would appear that the only way out, is up…" << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"(1) to reflect on your situation" <<endl;
    while (userInput != 1) {
        cin>>userInput;
    }
    userInput = 0;
    cout<<"With a creeping horror, you recognize where you are." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"You’ve heard the stories, but you thought they were just urban legends." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"But the place you now find yourself in now is no myth." << endl;
    sleep_until(system_clock::now() + 3s);
    cout<<"You’re trapped in… the CISE Dungeon!" <<endl;
    sleep_until(system_clock::now() + 5s);
    cout<<"Welcome, " << name << ", to the CISE Dungeon Crawler!" << endl;
     sleep_until(system_clock::now() + 3s);
    cout<< "Better strap in you've got a long semester ahead of you. Good Luck!" << endl;
    sleep_until(system_clock::now() + 3s);
    
    //map legend
    cout<<"\'X\' = Player Location \n\'B\' = Boss Location \n\'S\' = Stair Location " << endl;
    
    while (p->gameOver != true) {
        // print map, both before and after moving
        m->printMap();
        m->move();
        m->printMap();
        
        //cout<< p->playerX << " , " << p-> playerY << endl;
        // print stats (GPA and Stamina)
        p->getHealth();
        
        // key to staircase (ability to go up a level): not had initially
        bool haveKey = false;
        
        // check that player is at staircase and has the key
        if(p->playerX == 2 && p-> playerY == 2){
            for(int i=0; i<p->item.size(); i++){
                if(p->item.at(i).compare("key")==0){
                    m->newLevel();
                    haveKey = true;
                    p->deleteItem(p->item, "key");
                }
            }
            if(!haveKey){
                cout<<"You don't have the key."<<endl;
                m->back();
            }
        } else {
            // pass enemy pointer, player object, and map object to the spawn function. Enemy appears
            spawn(&e, p, m);
            cout<< "An enemy has appeared. What will you do? \n(1) Approach it \n(2) Run away \n(3) Quit Game" << endl;
            cin>> userInput;
            
            if(userInput == 1){
                // call fight function
                e->fight();
            } else if (userInput == 2){
                // 50% chance to run away from enemy
                randomNum = (rand() % 2) + 1;
                
                if(randomNum == 1){
                    cout<< "You ran away successfully." << endl;
                    m->back();
                } else if (randomNum == 2){
                    cout<< "You could not run away." << endl;
                    e->fight();
                }
                
            } else if(userInput == 3){
                // rage quit game -- WILL HAVE TO START FROM BEGINNING IF THIS OPTION IS CHOSEN
                cout<< "Well have a good one then." << endl;
                break;
            } else {
                // catches invalid user input
                cout<< "Dude... That's not an option. Really?" << endl;
            }
        }
    }
}

//spawns a random enemy
void spawn(Enemy** e, Player* p, Map* m){
    
    if(p->playerX == 1 && p->playerY == 2){
        // if at boss map location, will spawn either TA or Professor, depending on level
        // these boss enemies will reduce GPA
        if(m->currentLevel != 4) {
            *e = new TA(p, m);
        } else {
            *e = new Boss(p, m);
        }
    } else if(m->currentLevel == 4 && p->playerX == 1 && p->playerY == 1){
        *e = new PresFuchs(p, m);
    } else {
        srand((unsigned)time(0));
        int random = rand() % 15 + 1;
        //cout<<random<<endl;
         // list of non-boss enemies that reduce Stamina
        if(random == 1 || random == 2){
            *e = new Seminole(p, m);
        } else if (random == 3 || random == 4){
            *e = new TurlingtonTabler(p, m);
        } else if (random == 5 || random == 6){
            *e = new CrazySquirrel(p, m);
        } else if (random == 7 || random == 8){
            *e = new Junior(p, m);
        } else if (random == 9 || random == 10){
             *e = new Alligator(p,m);
        } else if (random == 11 || random == 12){
            *e = new SororitySister(p,m);
        } else if (random == 13 || random == 14){
            *e = new SleepDeprivedStudent(p, m);
        } else {
            *e = new Dennis(p);
        }
    }
    // continue for any new enemies during further development
}
