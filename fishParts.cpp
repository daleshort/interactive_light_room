#include "fishParts.h"
 //not used

//each bodypart class can have an update function here
std::vector< std::vector< float > >& tail::getTail(void){
    return tailData;  //this can update and change what is returned based on time and position
}

std::vector< std::vector< float > >& head::getHead(void){
    return fish1HeadClosedMouth;  //this can update and change what is returned based on time and position
}

std::vector< std::vector< float > >& body::getBody(void){
    return bodyrework;  //this can update and change what is returned based on time and position
}

std::vector< std::vector< float > >& eyeBrow::getEyeBrow(void){
    return fish1EyeBrow;
}

std::vector< std::vector< float > >& mouthLine::getMouthLine(void){
    return fish1MouthLine;
}

std::vector< std::vector< float > >& outerEye::getOuterEye(void){
    return fish1OuterEye;
}

std::vector< std::vector< float > >& topFin::getTopFin(void){
    return fish1TopFin;
    }

std::vector< std::vector< float > >& bottomFin::getBottomFin(void){
    return fish1BottomFin;
    }
