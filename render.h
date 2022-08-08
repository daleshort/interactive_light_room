#include "ofMain.h"
#include <vector>
class fish1;

class render{

    public:
    void setup(int);
    ofImage norm;
    ofImage fin;
    ofImage swim1;
    ofImage swim2;

    float scale;
    float eyeDiam;
    int eyePositionX;
    int eyePositionY;
    int finOnTime;
    int finOffTime;
    int errorTime;
    int errorQty ;
    int rotationErrorQty;
    int errorRotationTime;
    int swimOnTime;
    int swimOffTime;
    float speed;
    float angleSpeed;
    float k;
    int eyeDisp;
};
