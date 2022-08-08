#ifndef _DEEP_SEA_CAMERA_COVER
#define _DEEP_SEA_CAMERA_COVER

#include "ofMain.h"
#include "ofxOpenCv.h"

class DeepSeaCameraCover{

	public:
        DeepSeaCameraCover();
        void draw();
        void updateimages();
        void changebrightnesscontrastby(float b,float c );
        ofVideoGrabber 		vidGrabber;

        ofxCvColorImage		colorImg;
        ofxCvGrayscaleImage 	grayImage;
		ofxCvGrayscaleImage 	grayBg;
		ofxCvGrayscaleImage 	grayDiff;

        ofxCvContourFinder 	contourFinder;

		int 				threshold;
		bool				bLearnBakground;
		float brightness,contrast;
		vector <ofPoint> centroids;
		vector <float> radii;
        ofImage DeepSeaCover;
        ofImage blackimage;
        void setupblackimage();
        void clearvectors();

};

#endif
