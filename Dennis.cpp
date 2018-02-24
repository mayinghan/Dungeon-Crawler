//  Dennis.cpp
//  Dungeon Crawler
//
//  Created by Yinghan Ma on 11/28/17.

#include "Dennis.hpp"
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
Dennis::Dennis(){
    name="";
    health=0;
    attack=0;
    defense=0;
}

Dennis::Dennis(Player* P){
    name = "Dennis";
    health =1;
    attack =0;
    defense = 0;
    player = P;
}

int Dennis::takeDamage(double playerAttack){
    cout<<"Nope, Dennis is undefeatable, sit down and listen to his words and then you can leave."<<endl;
    return 0;
}

void Dennis::fight(){
    cout<<"Find a comfortable position and sit down. Now listen to Dennis: "<<endl;
    cout<<"(You have to input 'yes'(lower case) after each of his sentence.)"<<endl;
    vector<string> words;
    int flag=0;
    string input;
    string p = "Yes it's true, I fled UCLA because of that pesky murder warrant, LOL. Naw, you probably know I was homeless, and now I'm not! I bought me a cheap little mobile home that's just off of the UF campus. I would say it was something on the order of 100 times cheaper than the cheapest place in Westwood! This is where I came to school as a freshman in 1993, so I feel really comfortable here. I've been working out like a madman and my clothes have gotten even sexier. I was kind of lost and socially intimidated at UCLA, but I am owning this place like nobody's business. I'm like a whirlwind of pure love. My dancing is way better. I just use headphones now, so that really frees me up. I wasn't really able to make any friends there, which I guess is a result of both my homelessness and UCLA students' social \"sophistication\", or whatever. I flirt with countless beauties every day. So many of them want to take pictures with me, and now they are really starting to feel comfortable with me. It's only been flirty talk so far, but things are about to start happening. This place is a party school par excellence, I am like a rock n' roll god here. I've put the frat boys on notice. They are so annoyingly cocky here at UF. All I want to do is steal away their sorority girlfriends, LOL. I don't like those kinds of guys, never have, never will. Anyhoo, the love is about to start happening over here, and love causes peace. I told you guys I was there to start a real peace movement! My site is luvluvluv dot info.";
    int count=0;
    
    for(int i=0; i<p.length(); i++){
        if(p.at(i)!=','||p.at(i)!='.'||p.at(i)!='!'){
            count++;
            
        }
        if (p.at(i)==','||p.at(i)=='.'||p.at(i)=='!') {
            
            string sent = p.substr(flag,count);
            cout<<sent<<endl;
            flag = i+2;
            count=0;
            
            bool contin=true;
            while(contin){
                
                cin>>input;
                if(input.compare("yes")==0){
                    contin=false;
                    break;
                }else{
                    cout<<"please type yes to continue, you cannot leave unless you quit this game."<<endl;
                    contin=true;
                }
            }
        }
    }
    cout<<"Thank you for listening. Now you are Dennis' best friend."<<endl;
    health=0;
    
    
}
