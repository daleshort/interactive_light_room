#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofAddListener(ofEvents.exit,this,&testApp::customexit);
	kinectDebug = false;
	counter = 0;
	ofSetCircleResolution(50);
	ofBackground(0,0,102);
	ofSeedRandom();
	ofEnableAlphaBlending();

    myKin.setup();

	bSmooth = false;
    cats = 1;
    meow = 500;
    fish.setup(myKin);
    bkground.setup();

    //load and scale some seaweed
    seaweed1.loadImage("data/seaweedsm-01.png");
    seaweed1.resize(1.5*seaweed1.width*ofGetHeight()/1050,1.5*seaweed1.height*ofGetHeight()/1050);
    seaweed3.loadImage("data/seaweed-03.png");
    seaweed3.resize(.85*seaweed3.width*ofGetHeight()/1050,.85*seaweed3.height*ofGetHeight()/1050);
    seaweed4.loadImage("data/seaweedsm-04.png");
    seaweed2.loadImage("data/seaweedsm-02.png");
    seaweed4.resize(1.2*seaweed4.width*ofGetHeight()/1050,1.2*seaweed4.height*ofGetHeight()/1050);
    seaweed2.resize(1.2*seaweed2.width*ofGetHeight()/1050,1.2*seaweed2.height*ofGetHeight()/1050);



	ofSetWindowTitle("graphics example");

	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void testApp::update(){
myKin.update();
fish.checkBlobs(myKin);
fish.actOnBlobs();
}

//--------------------------------------------------------------
void testApp::draw(){

    //draw the seaweed
    bkground.draw();
    seaweed2.draw(ofGetWidth()-seaweed2.width-10,ofGetHeight()-seaweed2.getHeight()+15);
    seaweed2.draw((ofGetWidth()/2)-100,ofGetHeight()-seaweed2.getHeight()+205);
    seaweed4.draw(-90,ofGetHeight()-seaweed4.height+45);
    seaweed1.draw(ofGetWidth()/4,ofGetHeight()-seaweed1.getHeight()+15);
	fish.draw();
	seaweed1.draw(ofGetWidth()/2,ofGetHeight()-seaweed1.getHeight()+205);
	seaweed1.draw(ofGetWidth()-seaweed1.width+150,ofGetHeight()-seaweed1.getHeight()+25);
	seaweed3.draw(ofGetWidth()*.6,ofGetHeight()-seaweed3.getHeight()+15);

	//draws the kinect diagnostic screen and little rectangles showing where the fish are tracking
	if(kinectDebug == true){
        myKin.draw();
        for(int i=0;i<fish.fishList.size();i++){
            ofSetColor(255,0,0);
            ofRect(fish.fishList[i].targetX*400.0/ofGetWidth()+10,fish.fishList[i].targetY*300.0/ofGetHeight()+320,10,10);
              //note all the scaling/shifting the locate the points to be over the video feed
            ofSetColor(0,255,0);
            ofRect(fish.fishList[i].positionX*400.0/ofGetWidth()+10,fish.fishList[i].positionY*300.0/ofGetHeight()+320,10,10);
        }
    ofSetColor(255,255,255);
    }
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

  	if(kinectDebug == true){
        myKin.keyPressed(key);
	}

	if (key=='k'){
        kinectDebug=!kinectDebug;  //will draw kinect debug
	}
	else if(key == 'f' ){
        ofToggleFullscreen();
	}

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::customexit(ofEventArgs& args){
   //I wrote my own exit function to tell the kinect to close on exit.  It works at cooper but not at PS347?  Weirdness
    int meow =0;
    meow++;
    cout<<"cats";
    myKin.exit();
}

