
#include "ofMain.h"
#include "render.h"
#include "blob.h"


class fish1 {



	public:

        bool targetPointer;
		void draw(void);
		void setup(render&,bool, std::vector <fish1>&);
		void setColors(int);
		void update();
		void getNewPosition(int, int);
		void getNewTarget(int&, int&,int&);
		void getNewTargetNoPointer(int, int);
		void flip(bool);


        float eyeDiam;
        int finOnTime;
        int finOffTime;
        int currentState;
		float 	counter;
		bool	stroke;
		render * spritesLocation;
		std::vector <fish1> * fishListLocation;
        int * targetXLocation;
        int * targetYLocation;
        int * targetRotationLocation;
        ofImage * imageLocation;
		float targetX;
		float targetY;
		int targetRotation;
		int blobId;

		float targetVectorX;
		float targetVectorY;
        int lastTimeTargetVector;
        int vectorUpdateTime;


		float scale;

		int rotation;

		bool rightFish;

		long timeLastFin;
		bool fin;
		bool swim1;
		bool swim2;


		int eyePositionX;
		int eyePositionY;
        int eyeUnTransPositionX;
		int eyeUnTransPositionY;
		float positionX;
		float positionY;
		int eyeDisp;
        float deltaX;
        float deltaY;
        int imageWidth;
		int imageHeight;

        private:

        int roll1;
        int roll2;
        int errorTargetPositionX;
        int errorTargetPositionY;
        int errorTargetRotation;
        long timeLastError;
        long timeLastRotationError;
        long timeLastSwim;
        int roll3;
        int roll4;
        float speed;
        float angleSpeed;
        int lastSwimState;
        float collisionRotationRandom;
        long collisionRotationRandomTime;
        long collisionTime;
};
