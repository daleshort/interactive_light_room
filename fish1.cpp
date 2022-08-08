
#include "fish1.h"
#include "math.h"


void fish1::setup(render& sprites, bool direction, std::vector <fish1>& fishList){

targetPointer = false;
spritesLocation = &sprites;
fishListLocation = &fishList;
lastTimeTargetVector = 0;
vectorUpdateTime =1000;

//get fish parameters from render class that stores it
stroke = true;
scale = (*spritesLocation).scale;
eyeDiam = (*spritesLocation).eyeDiam;
eyePositionX = (*spritesLocation).eyePositionX;
eyePositionY = (*spritesLocation).eyePositionY;
eyeDisp = (*spritesLocation).eyeDisp;
speed = (*spritesLocation).speed + ofRandom(-(speed/2),(speed/2));
angleSpeed = (*spritesLocation).angleSpeed ;//+ (int) ofRandom(0,(speed/3));

//stores the current time.  This is crappy code.
timeLastFin = ofGetElapsedTimeMillis();
timeLastError = timeLastFin;
timeLastRotationError = timeLastError;
timeLastSwim = timeLastError;
collisionRotationRandomTime = timeLastError;
collisionTime = timeLastError;

//get fish parameters from render class that stores it
finOnTime = (*spritesLocation).finOnTime ;
finOffTime = (*spritesLocation).finOffTime;
currentState = 0;
swim1 = false;
swim2= false;
fin = true;
roll1 = 0;
roll2 = 0;
roll3 = 0;
roll4 = 0;
imageWidth = (*spritesLocation).norm.getWidth();
imageHeight = (*spritesLocation).norm.getHeight();
rightFish = direction;
lastSwimState = 2;

}
//--------------------------------------------------------------
void fish1::draw(void){

    //
    //update fish code here based on time variables/position variables
    // like myTail.update(position,time, code)
    //draw fins

    ofPushMatrix();
    ofEnableAlphaBlending();
//controls which image of the fish is actually drawn
        if(swim1 == true){
    imageLocation = &((*spritesLocation).swim1);
        } else if(swim2 == true){
    imageLocation = &((*spritesLocation).swim2);
        } else if(fin == true){
    imageLocation = &((*spritesLocation).fin);
        }else {
    imageLocation = &((*spritesLocation).norm);
        }


    ofTranslate(positionX ,positionY,0);
    //if the fish is flipped it needs to be translated so the origin is the fish's mouth
    if(rightFish == false){
        ofRotateY(180);
        ofTranslate( -imageWidth*scale, 0,0);
        }

    ofTranslate(scale*(imageWidth/2),scale*(imageHeight/2), 0);
    ofRotateZ(rotation);
    ofTranslate(-scale*imageWidth/2,-scale*imageHeight/2, 0);
    ofScale(scale,scale,1);
    (*imageLocation).draw(0,0);
    //draw the eye, including making the eye look at the target point
    ofPushStyle();
    ofFill();
    ofSetColor(0,0,0);
    ofCircle(eyePositionX+deltaX,eyePositionY+deltaY,eyeDiam);
    ofEnableSmoothing();
    ofNoFill();
    ofCircle(eyePositionX+deltaX,eyePositionY+deltaY,eyeDiam);

    ofPopStyle();
    ofPopMatrix();
}

void fish1::update(){

    if(targetPointer == true){
        targetX = (*targetXLocation);
        targetY = (*targetYLocation);
    }



    int originalTargetX = targetX;
    int originalTargetY = targetY;
    targetRotation = (*targetRotationLocation);
    targetRotation = 0; //NOTE THIS

    int originalPositionX = positionX;
    int originalPositionY = positionY;

    int distToCollision = 0;
    bool noError = false;
    int collisionX = 0;
    int collisionY = 0;
    float collisionDistX = 0;
    float collisionDistY = 0;
    int collisionPointX = 0;
    int collisionPointY = 0;
    float radiusToCheck = 0;
//collision Detection/avoidance spreads fish out from other fish

if(ofGetElapsedTimeMillis() - collisionTime > 0){
    collisionTime = ofGetElapsedTimeMillis();

collisionX = originalPositionX + (imageWidth*scale/2);
collisionY = originalPositionY - (imageHeight*scale/2);

        if( ofGetElapsedTimeMillis() - collisionRotationRandomTime > 600+roll4){
        roll4 = ofRandom(0,700);
        collisionRotationRandomTime = ofGetElapsedTimeMillis();
        collisionRotationRandom = (ofRandom(-90,90)*2*PI)/360;
        }


        bool collision = false;

        for(int y = 0;
        y < (*fishListLocation).size();
        y++) {

            if (sqrt( pow(targetX - originalTargetX,2) + pow(targetY - originalTargetY,2))<1000){
            radiusToCheck = ((*fishListLocation)[y].imageWidth*(*fishListLocation)[y].scale+ (*fishListLocation)[y].imageHeight*(*fishListLocation)[y].scale)/2;
            collisionPointX = (*fishListLocation)[y].positionX +( (*fishListLocation)[y].imageWidth*(*fishListLocation)[y].scale/2);
            collisionPointY = (*fishListLocation)[y].positionY -( (*fishListLocation)[y].imageHeight*(*fishListLocation)[y].scale/2);
            collisionDistY = collisionPointY  - collisionY;
            collisionDistX = collisionPointX  - collisionX;

            distToCollision = sqrt( pow(collisionDistX ,2) + pow(collisionDistY,2));
                if(distToCollision > radiusToCheck) {
                    collision = true;
                   noError = true;
                   collisionDistX = -collisionDistX*radiusToCheck*.25/distToCollision;
                   collisionDistY = -collisionDistY*radiusToCheck*.25/distToCollision;
                collisionDistX = (collisionDistX*cos(collisionRotationRandom)) - (collisionDistY*sin(collisionRotationRandom));
                collisionDistY = (collisionDistX*sin(collisionRotationRandom)) + (collisionDistY*cos(collisionRotationRandom));
                   targetX = targetX + collisionDistX;
                   targetY = targetY + collisionDistY;

                   }
            }

        }
}


    eyeUnTransPositionY = (eyePositionY*scale)+positionY;
    eyeUnTransPositionX = (eyePositionX*scale)+positionX;

        if(rightFish == false){
        eyeUnTransPositionX = (imageWidth*scale)-(eyePositionX*scale)+positionX;
        }
    deltaX = originalTargetX-eyeUnTransPositionX;
    deltaY = originalTargetY-eyeUnTransPositionY;
    int mag = sqrt(pow(deltaX,2)+pow(deltaY,2));
    deltaX = ((deltaX* eyeDisp)/mag);
    deltaY = ((deltaY* eyeDisp)/mag);
        if(rightFish == false){
        deltaX = -deltaX;
        }

    if( rotation!= 0 ){
        float rotationRad = (-rotation*2*PI)/360;
        deltaX = (deltaX*cos(rotationRad)) - (deltaY*sin(rotationRad));
        deltaY = (deltaX*sin(rotationRad)) + (deltaY*cos(rotationRad));
        }

//makes the fish flap fins at random time intervals
    long currentTime = ofGetElapsedTimeMillis();
    if((currentTime - timeLastFin> finOffTime+roll1) && currentState != 1){
        timeLastFin = ofGetElapsedTimeMillis();
        roll1 = (int) ofRandom(0,1000);
        fin = true;
        currentState = 1;
        swim1 = false;
        swim2= false;
    } else if( (currentTime - timeLastFin> finOnTime) && currentState == 1 ){
 //   } else if( (currentTime - timeLastFin> finOnTime+roll2) && currentState == 1 ){
        timeLastFin = ofGetElapsedTimeMillis();
        roll2 = (int) ofRandom(0,100);
        fin = false;
        currentState = 0;
        swim1 = false;
        swim2= false;
    }

    if((currentTime - timeLastSwim > (*spritesLocation).swimOnTime) && currentState != 2 && currentState!=3){
        timeLastSwim = ofGetElapsedTimeMillis();

            if(lastSwimState ==2){
            swim2= true;
            swim1 = false;
            currentState = 3;
            lastSwimState = 3;
            } else {
            lastSwimState = 2;
            currentState = 2;
            swim1 = true;
            swim2= false;
            }
    }else if( (currentTime - timeLastSwim > (*spritesLocation).swimOffTime) && currentState != 0 ){
        timeLastSwim = ofGetElapsedTimeMillis();
        currentState = 0;
        swim2= false;
        swim1 = false;
    }

    int moveTargetX =  targetX - (imageWidth*scale);
    if (rightFish == false){
        moveTargetX =  targetX;
        }
//adds some error into the rotation and position the fish tracks to give it some movement

    int moveTargetY = targetY;
    if(noError == false){

        if( currentTime - timeLastError > (*spritesLocation).errorTime + roll3){
            timeLastError = ofGetElapsedTimeMillis();
            roll3 = (int) ofRandom(0,300);
            errorTargetPositionX =  ofRandom(-(*spritesLocation).errorQty,(*spritesLocation).errorQty);
            errorTargetPositionY = ofRandom(-(*spritesLocation).errorQty,(*spritesLocation).errorQty);
        }

    }

      if( currentTime - timeLastRotationError > (*spritesLocation).errorRotationTime){
        timeLastRotationError = ofGetElapsedTimeMillis();
        errorTargetRotation =  ofRandom(-(*spritesLocation).rotationErrorQty, (*spritesLocation).rotationErrorQty);
    }


//ofCircle(moveTargetX ,moveTargetY,6);
//ofCircle(targetX,targetY,10);

    float errorX = moveTargetX + errorTargetPositionX- positionX; //error added into target position so fish always moves
    float errorY = moveTargetY + errorTargetPositionY - positionY;
    float errorRotation =targetRotation + errorTargetRotation - rotation;


    float distToTarget = sqrt( pow( errorX,2) + pow(errorY,2));

    if(distToTarget<80){
    swim1 = false;
    swim2 = false;
    }

    //cout << "\n";
  //  cout << ((errorX)  * (speed/60));
    positionX = positionX + ((errorX)  * (speed/60));
    positionY = positionY + ((errorY)  * (speed/60));
    rotation = rotation + (errorRotation * (angleSpeed/60));




}

void fish1::getNewPosition(int newX,int newY){
positionX = newX;
positionY = newY;

}

void fish1::getNewTarget(int& targetXIn,int& targetYIn, int& targetAngleIn){

targetXLocation = &targetXIn;
targetYLocation = &targetYIn;
targetRotationLocation = &targetAngleIn;

}

void fish1::getNewTargetNoPointer(int targetXIn,int targetYIn){

targetX = targetXIn;
targetY = targetYIn;

}
//fish recieves fish list vector to look up positions and ID's of other fish

void fish1::flip(bool flip){

rightFish = !flip;

}
