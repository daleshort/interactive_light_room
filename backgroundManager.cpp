#include "backgroundManager.h"

void backgroundManager::draw(void){

x=ofGetWidth();
y=ofGetHeight();

if(x != oldxdim){
    oldxdim = x;
    setsize();
    }

if(ofGetElapsedTimeMillis() - timeLastChange >roll){
    timeLastChange = ofGetElapsedTimeMillis();
   // backgroundNumber = ofRandom(1,3);
   backgroundNumber +=1;
        if(backgroundNumber>3){
        backgroundNumber = 1;
        }
}

switch(backgroundNumber){
    case 1:
    background1.draw(0,0);
    break;
    case 2:
    background2.draw(0,0);
    break;
    case 3:
    background3.draw(0,0);
    break;
}

}

void backgroundManager::setup(void){
backgroundNumber = 1;

timeMin = 900;
timeMax = 2001;
roll = ofRandom(timeMin, timeMax);

x=ofGetWidth();
y=ofGetHeight();
oldxdim = x;
oldydim = y;

background1.loadImage("data/bk1.png");
background2.loadImage("data/bk2.png");
background3.loadImage("data/bk3.png");

background1.resize(x,y);
background2.resize(x,y);
background3.resize(x,y);


setsize();
}

void backgroundManager::setsize(void){

x=ofGetWidth();
y=ofGetHeight();

background1.resize(x,y);
background2.resize(x,y);
background3.resize(x,y);

}
