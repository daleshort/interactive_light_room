#pragma once

#include "fishManager.h"
#include "backgroundManager.h"
#include "ofMain.h"
#include "kinect.h"



class testApp : public ofBaseApp{

	public:
        void customexit(ofEventArgs& args);
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );

		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void mouseDragged(int x, int y, int button);

        backgroundManager bkground;

        int cats;
        int meow;

		float 	counter;
		bool	bSmooth;
		fishManager fish;
		kinect myKin;
    private:
    bool kinectDebug;
    ofImage seaweed1;
    ofImage seaweed3;
    ofImage seaweed4;
    ofImage seaweed2;


};

