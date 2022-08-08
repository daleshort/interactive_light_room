#include "fish1.h"
#include <vector>
#include "kinect.h"
#include "ofxCvBlob.h"
//#include "blob.h"

class fishManager{
    public:
    void setup(kinect&);
    void draw(void);
    void addFish(int, int, int);
    void addFishWithTarget(int , int , int, float, float);
    render  blueFish;
    render yellowFish;
    render nyan;
    fish1 stdBlue;
    fish1 stdYellow;
    fish1 stdNyan;
    void targetAllFish(int&, int&, int&);
    void actOnBlobs(void);
    void checkBlobs(kinect&);

    kinect* kinLocation;
    std::vector <fish1> fishList;
    std::vector<fish1>::iterator fishListIterator;

    vector<blob>  blobList;
    vector<blob> oldBlobList;
    float mouseX;
    float mouseY;
    int blobID;
    private:
    bool firstRun;

};
