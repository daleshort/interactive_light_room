#include "fishManager.h"
#include "math.h"


void fishManager::setup(kinect &myKin){  //take in a kinect type pointer of the kinect
int spawnPointX = 100; //this may not be used
int spawnPointY = 100;
int catsJunk;
blobID = 0;

cout << "reset fishman";


    firstRun = true;
    blueFish.setup(1);  //load the images for the three types of fish
    yellowFish.setup(2);
    nyan.setup(3);

    kinLocation = &myKin;

    stdYellow.setup(yellowFish,true,fishList); //load the fish with data
    stdYellow.getNewPosition(spawnPointX,spawnPointY);  //assign the fish a position
    stdYellow.flip(true);  //flips appearance of fish or not


    stdBlue.setup(blueFish,true,fishList);
    stdBlue.getNewPosition(spawnPointX,spawnPointY);
    stdBlue.flip(true);

    stdNyan.setup(nyan,true,fishList);
    stdNyan.getNewPosition(spawnPointX,spawnPointY);
    stdNyan.flip(false);
}

void fishManager::draw(void){
//goes through and updates and draws every fish in the list
        for(int y = 0;
        y < fishList.size();
        y++) {
        fishList[y].update();
        fishList[y].draw();
        }

}

void fishManager::addFish(int fishToAdd, int type, int blobId){
//adds fish to the list of fish (causing them to be drawn)
    int flipVar = true;
    int maxAdd = fishList.size()+fishToAdd;
    type = (int)ofRandom(1,2.5); //change this to 3.5 to enable nyan mode.  Add fish of random type
 for(int i = fishList.size(); i<maxAdd;i++){
    if(type == 1){
        fishList.push_back(stdBlue);
    } else if(type == 2){
        fishList.push_back(stdYellow);
    }else if(type == 3){
        fishList.push_back(stdNyan);
    }
    fishList[i].flip(flipVar);  //randomly flip fish
    flipVar = !flipVar;
    fishList[i].blobId = blobId;  //store the blob id that the fish is assigned to
    }
}

void fishManager::addFishWithTarget(int fishToAdd, int type, int blobID, float x, float y){
    //similar to above but sets the fish to begin tracking a target point
    int flipVar = true;
    int maxAdd = fishList.size()+fishToAdd;
    for(int i = fishList.size(); i<maxAdd;i++){
    if(type == 1){
        fishList.push_back(stdBlue);
    } else if(type == 2){
        fishList.push_back(stdYellow);
    }else if(type == 3){
        fishList.push_back(stdNyan);
    }
    fishList[i].flip(flipVar);
    flipVar = !flipVar;
    fishList[i].blobId = blobID;
    }
}

void fishManager::targetAllFish(int& targetX, int& targetY, int& rotation){
 //unused but sets all fish to asingle target point
        for(int y = 0;
        y < fishList.size();
        y++) {
        fishList[y].getNewTarget(targetX,targetY, rotation);
        }

}

void fishManager::checkBlobs(kinect &myKin){
    //goes through and figures out if a blob is new, already detected, or if an old blob has disapeared.  (btw blobs are objects tracked by the camera)
int x;
int y;
float smallestDist = 99999999;
int dist = 0;
int cats = 0;
int checkDist = 30;
int smallID = 99999;
int current = 0;
blob kitty;
oldBlobList=blobList;  // save a copy of the current blob list for comparison before starting a new list

 bool matchFound = false;
 blobList.clear();  //clear the list
 //cout<<"Blob List Size After Clearing = " <<blobList.size()<<"\n";
 //cout<<"Kinect Blob List Size = " <<myKin.contourFinder.blobs.size()<<"\n";

//maybe need to handle first run by startign with empty old bloblist;

//go through all of the new blobs
    for(int j = 0;
        j < myKin.contourFinder.blobs.size();
        j++) {


                x = myKin.contourFinder.blobs[j].centroid.x;
                y = myKin.contourFinder.blobs[j].centroid.y;
                smallestDist = 999999;

//comparing where the blobs centroid is relative to where every blob on the old list
            for(int k = 0;
                k < oldBlobList.size();
                k++) {
                dist = pow(( pow(( x-oldBlobList[k].x),2) + pow(( y-oldBlobList[k].y),2)  ),.5) ;
                    if( dist <= smallestDist){  //made this < from > 1/19
                        smallestDist = dist;
                        smallID = k;
                    }

                }

//if the new blob is more than 150 pixels away from any of the old ones
//add a new blob to blobList, give it x,y position, give it a type, give the blob a new ID
            if( smallestDist> checkDist){ // if new
                blobList.push_back(kitty);
                current = blobList.size()-1;  //zero addressed so position is one less than number of elements
                blobList[current].type = 1;  // this is a new blob flag
                blobList[current].x = x;  //populate with position
                blobList[current].y = y;
                blobList[current].pts = myKin.contourFinder.blobs[j].pts;
                blobID ++;
                blobList[current].ID = blobID;  //assign a unique id # to it
                }
//is blobID iterated anywhere else? does it ever go down?
//reply: nope-- it grows indefinately.  Great programming, I know.
            else{
                blobList.push_back(kitty);
                current = blobList.size()-1;
                blobList[current].type = 2;  // flag this as a preexisting blob
                blobList[current].x = x;  //give it position data
                blobList[current].y = y;
                blobList[current].pts = myKin.contourFinder.blobs[j].pts;
                blobList[current].ID  = oldBlobList[smallID].ID;  //use the old ID on this blob

                }

        }

        for(int j = 0;  //check for any blobs that have disapeared
        j < oldBlobList.size();
        j++) {
            matchFound= false;
            for(int k = 0;
            k < blobList.size();
            k++) {
//what is type 3?
//reply: type 3 was going to be blobs that were no longer found in the new bloblist
                if(blobList[k].ID == oldBlobList[j].ID & oldBlobList[j].type !=3){
                matchFound = true;
                }
            }
//what's this part? should fish be deleted here with the oldBlobList[j].ID?
/*
            if(matchFound == false){
                blobList.push_back(kitty);
                current = blobList.size()-1;
                 blobList[current].type = 3;
                    cout << "meowzz \n";
                blobList[current].ID = oldBlobList[j].ID;
                }
                */
            }


//oldBlobList = blobList;
}


void fishManager::actOnBlobs(void){

       //right now the fish are using the address location of the blobs but that isn't going to work since the bloblist is constantly cleared.  the fish either need to just be told coordinates constantly based on what id they are tracking.  use new position to send them to spawn or die.

       int fishToAddPerBlob = 1;
        int fishChosen = 0;
        int fishRand = 5;
        int xrand = 0;
        int yrand = 0;
        int newx = 0;
        int newy = 0;
        int randintx=1;
        int randinty=1;
        int randPt = 0;

        for( int j = 0;  //go through every blob in list and act on it
        j < blobList.size();
        j++){

        switch(blobList[j].type){

      case 1:  //this is a new blob.  Create fish and assign them  an ID.

        fishChosen = ofRandom(fishToAddPerBlob, fishToAddPerBlob+fishRand);
        addFish(fishChosen,1,blobList[j].ID);  //add a bunch of new fish with the blob id assigned to them

            for(int y = 0;
            y < fishList.size();
            y++) {
                if(fishList[y].blobId == blobList[j].ID ){  //act on every fish in the fishlist that matches the blob id of the new blob
                fishList[y].getNewTargetNoPointer(blobList[j].x*ofGetWidth()/640,blobList[j].y*ofGetHeight()/480); //dividing by 640 or 480 scales the video coordinates to the screen coordinate system
               //this next stuff moves the fish offscreen to a random position
                xrand = ofRandom(0,ofGetWidth());
                yrand = ofRandom(0,ofGetHeight());
                randintx=(int)ofRandom(-0.5,1.5);
                randinty=(int)ofRandom(-0.5,1.5);
                newx = (xrand*pow((-1),(1-randintx)))+ofGetWidth()*randintx;
                newy = (yrand*pow((-1),(1-randinty)))+ofGetHeight()*randinty;
                //cout<<"randintx: "<<randintx<<", randinty: "<<randinty<<"\n";
                fishList[y].getNewPosition(newx,newy);


                }
            }

        break;

      case 2:  //updateFishTarget
        for(int y = 0;
        y < fishList.size();
        y++) {
            //goes through the fish list and updates the fish with the matching id
            if(fishList[y].blobId == blobList[j].ID ){
                if(ofGetElapsedTimeMillis() - fishList[y].lastTimeTargetVector > fishList[y].vectorUpdateTime){  //if the fish hasn't tracked a new point in awhile
                fishList[y].lastTimeTargetVector = ofGetElapsedTimeMillis();
                randPt = (int)ofRandom(0,blobList[j].pts.size());  //chose a random point from the list of points that represent the perimeter of the blob
                fishList[y].targetVectorX = blobList[j].pts[randPt].x - blobList[j].x;  //fish tracks a bit away from the blob as determined by the vector
                fishList[y].targetVectorY = blobList[j].pts[randPt].y - blobList[j].y;
                }

            //the logic behind the target vector is it can be scaled by 1.5 so the fish are a little off the perimeter of the blob
            fishList[y].getNewTargetNoPointer((blobList[j].x + fishList[y].targetVectorX*1.5)*ofGetWidth()/640,(blobList[j].y + fishList[y].targetVectorY*1.5)*ofGetHeight()/480);
            }
        }
        break;
        //this is a preexisting fish
       case 3:
//the fish are deleted further down in the code. should they do something first or just get deleted?
        // this is a dead fish
       break;
        }

        }

        std::vector<fish1>::iterator it;

//                        cout << "fishlist size : " << fishList.size() << "\n";
//                        cout << "bloblist size : " << blobList.size() << "\n\n";

        for ( fishListIterator=fishList.begin() ;
            fishListIterator < fishList.end(); fishListIterator++ ){

  //                      cout << "\n fish list ID : " << (*fishListIterator).blobId << "\n";

            //Go through and check the blob list of active blobs against the fish list
            bool match = false;
                        for( int k = 0;
                        k < blobList.size();
                        k++){

  //                      cout << " blob list k : " << k << "\n";

                            if((*fishListIterator).blobId == blobList[k].ID ){
                                match = true;
                            }
                    }
            // if the fish has no matching blob target it off screen and delete it once it is off the screen
            if(match == false){
                //if off screen, then death
                if ((*fishListIterator).positionX>ofGetWidth() || (*fishListIterator).positionX<0 ||
                    (*fishListIterator).positionY>ofGetHeight() || (*fishListIterator).positionY<0){
                        fishList.erase(fishListIterator);
 //                  cout << "meow \n";
                    }
                //else check where it is targetting, and if it's not aiming to go off the page, make it do so to a random point
                else if (!((*fishListIterator).targetX>ofGetWidth() || (*fishListIterator).targetX<0 ||
                    (*fishListIterator).targetY>ofGetHeight() || (*fishListIterator).targetY<0)){

                        xrand = ofRandom(0,ofGetWidth());
                        yrand = ofRandom(0,ofGetHeight());
                        randintx=(int)ofRandom(-0.5,1.5);
                        randinty=(int)ofRandom(-0.5,1.5);
                        newx = (xrand*pow((-1),(1-randintx)))+ofGetWidth()*randintx;
                        newy = (yrand*pow((-1),(1-randinty)))+ofGetHeight()*randinty;
                        (*fishListIterator).getNewTargetNoPointer(newx,newy);
                    }
            }
            }



}
