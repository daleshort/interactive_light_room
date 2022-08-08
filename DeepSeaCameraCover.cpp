#include "DeepSeaCameraCover.h"
#define _CAMERA_WIDTH 160
#define _CAMERA_HEIGHT 120

DeepSeaCameraCover::DeepSeaCameraCover(){
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(640,480);

    colorImg.allocate(640,480);
	grayImage.allocate(_CAMERA_WIDTH,_CAMERA_HEIGHT);
	grayBg.allocate(_CAMERA_WIDTH,_CAMERA_HEIGHT);
	grayDiff.allocate(_CAMERA_WIDTH,_CAMERA_HEIGHT);

	bLearnBakground = true;
	threshold = 45;
	brightness=0.5;
	contrast=1.0;
	setupblackimage();

}

void DeepSeaCameraCover::updateimages(){
	colorImg.resize(640,480);
    bool bNewFrame = false;
    vidGrabber.grabFrame();
    bNewFrame = vidGrabber.isFrameNew();
    //the program runs faster than the webcam, so this is necessary
    if (bNewFrame){
        colorImg.setFromPixels(vidGrabber.getPixels(), 640,480);
        colorImg.resize(_CAMERA_WIDTH,_CAMERA_HEIGHT);

        grayImage = colorImg; //casting the color image into a grayscale image
		if (bLearnBakground == true){ //which is true when ' ' is pressed
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayImage.brightnessContrast(brightness,contrast);
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		contourFinder.findContours(grayDiff, 20, _CAMERA_WIDTH*_CAMERA_HEIGHT/3, 10, false); //false to not find holes
	}
}

void DeepSeaCameraCover::clearvectors(){
    while (centroids.size()>0){
        centroids.pop_back();
    }
    while (radii.size()>0){
        radii.pop_back();
    }
}

void DeepSeaCameraCover::draw(){
    updateimages();
	// draw the incoming, the grayscale, the bg and the thresholded difference

	//grayDiff.draw(ofGetWidth()-320,ofGetHeight()-240);
	// then draw the contours:

	// we could draw the whole contour finder
	//contourFinder.draw(360,540);

	// or, instead we can draw each blob individually,
	// this is how to get access to them:
	clearvectors();
    while (centroids.size()<contourFinder.nBlobs){
        ofPoint p;
        centroids.push_back(p);
        radii.push_back(0);
    }
    for (int i = 0; i < contourFinder.nBlobs; i++){
        //contourFinder.blobs[i].draw(0,0);
        ofFill();
        ofSetColor(255,255,255);
        centroids[i].x=contourFinder.blobs[i].centroid.x;
        centroids[i].y=contourFinder.blobs[i].centroid.y;
        if (sqrt(contourFinder.blobs[i].area/PI)>0&&sqrt(contourFinder.blobs[i].area/PI)<(_CAMERA_WIDTH*_CAMERA_HEIGHT)/2.0){
            radii[i]=sqrt(contourFinder.blobs[i].area/PI);
        }
        else radii[i]=0;
        //ofCircle(centroids[i].x,centroids[i].y,radii[i]);
    }

    int width=ofGetWidth();
    int height=ofGetHeight();
    ///*
    DeepSeaCover=blackimage;
    DeepSeaCover.setImageType(OF_IMAGE_COLOR_ALPHA);
    unsigned char * array = DeepSeaCover.getPixels();
    ///*
    int index;
    for (int i=0;i<_CAMERA_WIDTH;i++){
        for (int j=0;j<_CAMERA_HEIGHT;j++){
             index = j*_CAMERA_WIDTH*4 + i*4;
             array[index]=0;
             array[index+1]=0;
             array[index+2]=0;
             int m;
             for (m=0;m<contourFinder.nBlobs;m++){
                if (ofDist(i,j,centroids[m].x,centroids[m].y)<radii[m]){
                    array[index+3]=(ofDist(i,j,centroids[m].x,centroids[m].y))/radii[m]*255.0;
                    break;
                }
             }
             if (m==contourFinder.nBlobs){
                array[index+3]=255;
             }
        }
    }
    /*
    for (int i=0;i<contourFinder.nBlobs;i++){
        ofPoint centroidi=centroids[i];
        float radiii=radii[i];
        for (int j=centroidi.x-abs(radiii);j<centroidi.x+abs(radiii);j++){
            if (j>0 && j<_CAMERA_WIDTH){
                for (int k=(int)centroidi.y-(int)abs(radiii);k<(int)centroidi.y+(int)abs(radiii);k++){
                    if (k>0 && k<_CAMERA_HEIGHT){
                        float distance=ofDist(j,k,centroidi.x,centroidi.y);
                        if (distance<radiii){
                            array[k*_CAMERA_WIDTH*4+j*4+3]=(distance/radiii)*255;
                        }


                    }
                }
            }
        }
    }
    */
    DeepSeaCover.resize(width,height);
    DeepSeaCover.draw(0,0);
    DeepSeaCover.resize(_CAMERA_WIDTH,_CAMERA_HEIGHT);
    //*/
}

void DeepSeaCameraCover::setupblackimage(){
    blackimage.allocate(_CAMERA_WIDTH,_CAMERA_HEIGHT,OF_IMAGE_COLOR_ALPHA);
    int index;
    unsigned char * array = blackimage.getPixels();
    for (int i=0;i<_CAMERA_WIDTH;i++){
        for (int j=0;j<_CAMERA_HEIGHT;j++){
             index = j*_CAMERA_WIDTH*4 + i*4;
             array[index]=0;
             array[index+1]=0;
             array[index+2]=0;
             array[index+3]=255;
        }
    }
}

void DeepSeaCameraCover::changebrightnesscontrastby(float b,float c){
    brightness+=b;
    contrast+=c;
    if (brightness>1.0) brightness=1.0;
    else if (brightness<-1.0) brightness=-1.0;
    if (contrast>1.0) contrast=1.0;
    else if (contrast<-1.0) contrast=-1.0;
}

/*

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
	}
}

*/
