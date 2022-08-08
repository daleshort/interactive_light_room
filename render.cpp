
#include "render.h"
#include <vector>

//handles the slight differences between the fish and stores the images that make up the fish
//this mostly stores data used in the fish class

void render::setup(int type){
    if(type==1){
norm.loadImage("data/fishBlueYellow3.png");
fin.loadImage("data/fishBlueYellow4.png");
swim1.loadImage("data/fishBlueYellow1.png");
swim2.loadImage("data/fishBlueYellow2.png");

eyePositionX = 359;
eyePositionY = 85;
scale = .4;
eyeDiam = 6;
eyeDisp = 5;
finOnTime = 100;
finOffTime = 1000;
errorTime = 80;
errorRotationTime = 1500;
errorQty = 80;
//errorQty = 0;
rotationErrorQty = 30;

swimOnTime = 100;
swimOffTime= 100;

speed = .9; //pixels/sec
angleSpeed = 4;
k = 2 ; //fish controller gain

    }

        if(type==2){
norm.loadImage("YellowAngelSprites-02.png");
fin.loadImage("YellowAngelSprites-03.png");
swim1.loadImage("YellowAngelSprites-04.png");
swim2.loadImage("YellowAngelSprites-05.png");

eyePositionX = 784;
eyePositionY = 462;
scale = .2;
eyeDiam = 11;
eyeDisp = 10;
finOnTime = 100;
finOffTime = 1000;
errorTime = 80;
errorRotationTime = 1500;
errorQty = 80;
//errorQty = 0;
rotationErrorQty = 30;

swimOnTime = 100;
swimOffTime= 100;

speed = .9; //pixels/sec
angleSpeed = 4;
k = 2 ; //fish controller gain

    }

            if(type==3){
norm.loadImage("nyan1.png");
fin.loadImage("nyan3.png");
swim1.loadImage("nyan4.png");
swim2.loadImage("nyan2.png");

eyePositionX = 784;
eyePositionY = 462;
scale = .2;
eyeDiam = 0;
eyeDisp = 10;
finOnTime = 100;
finOffTime = 1000;
errorTime = 80;
errorRotationTime = 1500;
errorQty = 80;
//errorQty = 0;
rotationErrorQty = 30;

swimOnTime = 100;
swimOffTime= 100;

speed = 1; //pixels/sec
angleSpeed = 4;
k = 2 ; //fish controller gain

    }
}
