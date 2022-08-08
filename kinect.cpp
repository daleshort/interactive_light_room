#include "kinect.h"

#define COOPER 1
#define SCHOOL 2
#define ANYWHERE 3
#define EOYS 4
//--------------------------------------------------------------
void kinect::setup() {
    int location = COOPER;

	ofSetLogLevel(OF_LOG_VERBOSE);

    // enable depth->rgb image calibration
	kinect.setRegistration(false);

	kinect.init();
	//kinect.init(true); // shows infrared instead of RGB video image
	//kinect.init(false, false); // disable video image (faster fps)
	kinect.open();

#ifdef USE_TWO_KINECTS
	kinect2.init();
	kinect2.open();
#endif

	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThreshNear.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);

	nearThreshold = 255;
	farThreshold = 120;
	bThreshWithOpenCV = true;

	ofSetFrameRate(60);

	// zero the tilt on startup
	angle = 0;
	kinect.setCameraTiltAngle(angle);

	// start from the front
	bDrawPointCloud = false;

	currentWarp = 0;

	switch(location){

	    //these are the points of the corners of the screen as seen by the camera.
	    //you can minipulate them with keys 1-5 when the kinect dianostic display is brought up
	case ANYWHERE:
        warpPoints[0].x = 0;
        warpPoints[0].y = 0;
        warpPoints[1].x = grayImage.getWidth();
        warpPoints[1].y = 0;
        warpPoints[2].x = grayImage.getWidth();
        warpPoints[2].y = grayImage.getHeight();
        warpPoints[3].x = 0;
        warpPoints[3].y = grayImage.getHeight();
        break;
    case COOPER:
    	angle = -17;
        kinect.setCameraTiltAngle(angle);
        warpPoints[0].x = 91;
        warpPoints[0].y = 91;
        warpPoints[1].x = 623;
        warpPoints[1].y = 74;
        warpPoints[2].x = 581;
        warpPoints[2].y = 431;
        warpPoints[3].x = 141;
        warpPoints[3].y = 432;
        nearThreshold = 123;
        farThreshold = 90;
        break;
    case SCHOOL:  //PS.347
        warpPoints[0].x = 0;
        warpPoints[0].y = 0;
        warpPoints[1].x = grayImage.getWidth();
        warpPoints[1].y = 0;
        warpPoints[2].x = grayImage.getWidth();
        warpPoints[2].y = grayImage.getHeight();
        warpPoints[3].x = 0;
        warpPoints[3].y = grayImage.getHeight();
        break;

    case EOYS:
            warpPoints[0].x = 51;
        warpPoints[0].y = 112;
        warpPoints[1].x = 597;
        warpPoints[1].y = 127;
        warpPoints[2].x = 547;
        warpPoints[2].y = 480;
        warpPoints[3].x = 84;
        warpPoints[3].y = 466;
	nearThreshold = 180;
	farThreshold = 98;

	break;
	}
}

//--------------------------------------------------------------
void kinect::update() {

	ofBackground(100, 100, 100);

	kinect.update();

	// there is a new frame and we are connected
	if(kinect.isFrameNew()) {

		// load grayscale depth image from the kinect source
		grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);

		// we do two thresholds - one for the far plane and one for the near plane
		// we then do a cvAnd to get the pixels which are a union of the two thresholds
		if(bThreshWithOpenCV) {
			grayThreshNear = grayImage;
			grayThreshFar = grayImage;
			grayThreshNear.threshold(nearThreshold, true);
			grayThreshFar.threshold(farThreshold);
			cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		} else {

			// or we do it ourselves - show people how they can work with the pixels
			unsigned char * pix = grayImage.getPixels();

			int numPixels = grayImage.getWidth() * grayImage.getHeight();
			for(int i = 0; i < numPixels; i++) {
				if(pix[i] < nearThreshold && pix[i] > farThreshold) {
					pix[i] = 255;
				} else {
					pix[i] = 0;
				}
			}
		}

		// update the cv images
		grayImage.warpPerspective(warpPoints[0],warpPoints[1],warpPoints[2],warpPoints[3]); //I've added this to correct for perspective.
		grayImage.flagImageChanged();

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
	}

#ifdef USE_TWO_KINECTS
	kinect2.update();
#endif
}

//--------------------------------------------------------------
void kinect::draw() {

	ofSetColor(255, 255, 255);

	if(bDrawPointCloud) {
		easyCam.begin();
		drawPointCloud();
		easyCam.end();
	} else {
		// draw from the live kinect

		ofPushMatrix();
		ofTranslate(10,10,0);
		kinect.drawDepth(0, 0, 400, 300);
        ofPushStyle();
        ofSetColor(255,0,0);
        for( int i = 0; i<=3;i++){
        ofCircle(warpPoints[i].x * .625 ,warpPoints[i].y*.625,3);
        }
        ofPopMatrix();
        ofPopStyle();

		ofPushMatrix();
		ofTranslate(420,10,0);
		kinect.draw(0, 0, 400, 300);
        ofPushStyle();
        ofSetColor(255,0,0);
        for( int i = 0; i<=3;i++){
        ofCircle(warpPoints[i].x * .625 ,warpPoints[i].y*.625,3);
        }
        ofPopMatrix();
        ofPopStyle();

        ofPushMatrix();
        ofTranslate(10,320,0);
        grayImage.draw(0, 0, 400, 300);
        ofPushStyle();
        ofPushMatrix();
        ofSetColor(255,0,0);
        for( int i = 0; i<=3;i++){
        //ofCircle(warpPoints[i].x * .625 ,warpPoints[i].y*.625,3);
        }
        ofPopMatrix();
        ofPopStyle();
		ofPopMatrix();
		contourFinder.draw(10, 320, 400, 300);

#ifdef USE_TWO_KINECTS
		kinect2.draw(420, 320, 400, 300);
#endif
	}

	// draw instructions
	ofSetColor(255, 255, 255);
	stringstream reportStream;
	reportStream << "accel is: " << ofToString(kinect.getMksAccel().x, 2) << " / "
	<< ofToString(kinect.getMksAccel().y, 2) << " / "
	<< ofToString(kinect.getMksAccel().z, 2) << endl
	<< "press p to switch between images and point cloud, rotate the point cloud with the mouse" << endl
	<< "using opencv threshold = " << bThreshWithOpenCV <<" (press spacebar)" << endl
	<< "set near threshold " << nearThreshold << " (press: + -)" << endl
	<< "set far threshold " << farThreshold << " (press: < >) num blobs found " << contourFinder.nBlobs
	<< ", fps: " << ofGetFrameRate() << endl
	<< "press c to close the connection and o to open it again, connection is: " << kinect.isConnected() << endl
	<< "press UP and DOWN to change the tilt angle: " << angle << " degrees" << endl
	<< "current warp point:" << currentWarp << " x= " << warpPoints[currentWarp].x<< " y= " << warpPoints[currentWarp].y<< endl;
	ofDrawBitmapString(reportStream.str(),20,652);
}

void kinect::drawPointCloud() {
	int w = 640;
	int h = 480;
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);
	int step = 2;
	for(int y = 0; y < h; y += step) {
		for(int x = 0; x < w; x += step) {
			if(kinect.getDistanceAt(x, y) > 0) {
				mesh.addColor(kinect.getColorAt(x,y));
				mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
			}
		}
	}
	glPointSize(3);
	ofPushMatrix();
	// the projected points are 'upside down' and 'backwards'
	ofScale(1, -1, -1);
	ofTranslate(0, 0, -1000); // center the points a bit
	glEnable(GL_DEPTH_TEST);
	mesh.drawVertices();
	glDisable(GL_DEPTH_TEST);
	ofPopMatrix();
}

//--------------------------------------------------------------
void kinect::exit() {
	kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();

#ifdef USE_TWO_KINECTS
	kinect2.close();
#endif
}

//--------------------------------------------------------------
void kinect::keyPressed (int key) {
	switch (key) {
		case ' ':
			bThreshWithOpenCV = !bThreshWithOpenCV;
			break;

		case'p':
			bDrawPointCloud = !bDrawPointCloud;
			break;

		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;

		case '<':
		case ',':
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;

		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;

		case '-':
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;

		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;

		case 'o':
			kinect.setCameraTiltAngle(angle); // go back to prev tilt
			kinect.open();
			break;

		case 'c':
			kinect.setCameraTiltAngle(0); // zero the tilt
			kinect.close();
			break;

		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;

		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
        case '1':
            warpPoints[currentWarp].x--;
            break;
        case '2':
            warpPoints[currentWarp].x++;
            break;
        case '3':
            warpPoints[currentWarp].y--;
            break;
        case '4':
            warpPoints[currentWarp].y++;
            break;
        case '5':
            currentWarp++;
            if(currentWarp == 4){
            currentWarp = 0;
            }
            break;
	}
}

//--------------------------------------------------------------
void kinect::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void kinect::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void kinect::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void kinect::windowResized(int w, int h)
{}
