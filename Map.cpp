//
//  Map.cpp
//  Game Tester
//
//  Created by Yinghan Ma on 11/22/17.
//  Copyright © 2017 Yinghan Ma. All rights reserved.
//

#include "Map.hpp"
#include "Player.hpp"

#include <iostream>

using namespace std;
//generic constructor
Map::Map(){
    currentLevel = 0;
    maxLevel = 0;
    lastX = 0;
    lastY = 0;
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            objects[x][y] = ' ';
        }
    }
}
//specific constructor
// create map object, pass in player pointer
Map::Map(Player* p){
    player = p;
    player->playerX = 0;
    player->playerY = 0;
    lastX = 0;
    lastY = 0;
    currentLevel = 1;
    maxLevel = 4;
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            objects[x][y] = ' ';
        }
    }
    objects[0][0] = 'X';
    objects[1][2] = 'B';
    objects[2][2] = 'S';
}
// reset the map when you go up a level
// map layout is the same for all 4 levels --  something to consider changing in future work
void Map::newLevel(){
    if(currentLevel != maxLevel){
        currentLevel++;
    }
    //Player level up and reset positions
    player->levelUp();
    player->playerX = 0;
    player->playerY = 0;
    
    //Redraw Map to starting position
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            objects[x][y] = ' ';
        }
    }
    objects[0][0] = 'X';
    objects[1][2] = 'B';
    objects[2][2] = 'S';
    
    cout<< "Congrats you made it to level " << currentLevel <<"!!!"<< endl;
}
// print map -- call this after moving
void Map::printMap(){
    cout<< endl;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            cout<< "| " << objects[x][y] << " |";
        }
        
        cout<< "\n_______________\n";
    }
    cout<< endl;
}
// move player from room to room (square to square) on each level
void Map::move(){
    lastX = player->playerX;
    lastY = player->playerY;
    int UserInput;
    bool isValid = false;
    
    while(isValid == false){
        cout<<"Where would you like to go? \n(1) North \n(2) East \n(3) South \n(4) West" << endl;
        cin>>UserInput;

        if(UserInput == 1){
            //if possible move player North
            if(player->playerX != 0){
                player->playerX -= 1;
                objects[lastX][lastY] = ' ';
                objects[player->playerX][player->playerY] = 'X';
                break;
            } else { //if wall or other problem prevents movement
                cout<<"You can't go that way" << endl;
            }
        } else if (UserInput == 2){
            //if possible move player East
            if(player->playerY != 2){
                player->playerY++;
                objects[lastX][lastY] = ' ';
                objects[player->playerX][player->playerY] = 'X';
                break;
            } else { //if wall or other problem prevents movement
                cout<<"You can't go that way" << endl;
            }
        } else if (UserInput == 3){
            //if possible move player South
            if(player->playerX != 2){
                player->playerX += 1;
                objects[lastX][lastY] = ' ';
                objects[player->playerX][player->playerY] = 'X';
                break;
            } else {
                cout<<"You can't go that way" << endl;
            }
        } else if (UserInput == 4){
            //if possible move player West
            if(player->playerY != 0){
                player->playerY -= 1;
                objects[lastX][lastY] = ' ';
                objects[player->playerX][player->playerY] = 'X';
                break;
            } else {
                cout<<"You can't go that way" << endl;
            }
        } else { //checks for valid user input
            cout<<"That wasn't an option" << endl;
        }
    }
}
// if player runs from battle, call this to move to the space player was at earlier
void Map::back(){
    //temp
    int x = lastX;
    int y = lastY;
    
    //reassign lastX and lastY to current player position
    lastX = player->playerX;
    lastY= player->playerY;
    
    //move player to last position
    player->playerX = x;
    player->playerY = y;
    
    //switch output
    objects[player->playerX][player->playerY]='X';
    if(lastX == 1 && lastY == 2){
         objects[lastX][lastY]='B';
    } else if(lastX == 2 && lastY == 2) {
        objects[lastX][lastY]='S';
    } else {
         objects[lastX][lastY]=' ';
    }
    
}
