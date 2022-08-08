
#include "ofMain.h"
#include <vector>

class backgroundManager{

    public:
        void draw(void);
        void setup(void);

        ofImage background1;
        ofImage background2;
        ofImage background3;
        std::vector <ofImage> backgroundList;

    private:
        int oldxdim;
        int oldydim;
        int x;
        int y;
        int time;
        int timeLastChange;
        int roll;
        void setsize(void);
        int timeMin;
        int timeMax;
        int backgroundNumber;


};
