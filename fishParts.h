//#include "ofMain.h"

#include <vector>

class tail {

	public:
    std::vector< std::vector< float > >& getTail(void);
    std::vector<std::vector< float > > tailData;
    tail() : tailData( 37, std::vector<float>(2) ) {
    tailData[0][0] = -18.6575;
    tailData[0][1] = 202.4687;
    tailData[1][0] = -18.6575;
    tailData[1][1] = 202.4687;
    tailData[2][0] = -6.6067;
    tailData[2][1] = 204.0141;
    tailData[3][0] = -2.3030;
    tailData[3][1] = 190.6196;
    tailData[4][0] = 2.0002;
    tailData[4][1] = 177.2250;
    tailData[5][0] = 1.5705;
    tailData[5][1] = 162.2851;
    tailData[6][0] = -0.1512;
    tailData[6][1] = 154.5571;
    tailData[7][0] = -1.8729;
    tailData[7][1] = 146.8295;
    tailData[8][0] = -17.3665;
    tailData[8][1] = 135.4960;
    tailData[9][0] = -22.5306;
    tailData[9][1] = 132.9194;
    tailData[10][0] = -22.5306;
    tailData[10][1] = 132.9194;
    tailData[11][0] = -7.8978;
    tailData[11][1] = 128.7978;
    tailData[12][0] = -7.4676;
    tailData[12][1] = 118.4946;
    tailData[13][0] = -7.0374;
    tailData[13][1] = 108.1908;
    tailData[14][0] = -17.7967;
    tailData[14][1] = 94.2812;
    tailData[15][0] = -22.5306;
    tailData[15][1] = 87.5839;
    tailData[16][0] = -27.2645;
    tailData[16][1] = 80.8867;
    tailData[17][0] = -25.9734;
    tailData[17][1] = 78.8261;
    tailData[18][0] = -15.6443;
    tailData[18][1] = 54.6127;
    tailData[19][0] = -5.3157;
    tailData[19][1] = 30.3993;
    tailData[20][0] = -1.1321;
    tailData[20][1] = 18.0346;
    tailData[21][0] = 1.0798;
    tailData[21][1] = 6.7011;
    tailData[22][0] = 1.0798;
    tailData[22][1] = 6.7011;
    tailData[23][0] = 6.7346;
    tailData[23][1] = 44.3090;
    tailData[24][0] = 33.8479;
    tailData[24][1] = 57.7035;
    tailData[25][0] = 60.9611;
    tailData[25][1] = 71.0986;
    tailData[26][0] = 66.9865;
    tailData[26][1] = 74.1894;
    tailData[27][0] = 66.9865;
    tailData[27][1] = 74.1894;
    tailData[28][0] = 66.9865;
    tailData[28][1] = 74.1894;
    tailData[29][0] = 67.8718;
    tailData[29][1] = 140.5136;
    tailData[30][0] = 67.8718;
    tailData[30][1] = 140.5136;
    tailData[31][0] = 67.8718;
    tailData[31][1] = 140.5136;
    tailData[32][0] = 56.2268;
    tailData[32][1] = 173.6186;
    tailData[33][0] = 35.5695;
    tailData[33][1] = 195.7709;
    tailData[34][0] = 14.9113;
    tailData[34][1] = 217.9242;
    tailData[35][0] = -18.6575;
    tailData[35][1] = 202.4687;
    tailData[36][0] = -18.6575;
    tailData[36][1] = 202.4687;

    };
};
class bottomFin{
	public:
	std::vector< std::vector< float > >& getBottomFin(void);
 	std::vector< std::vector< float > > fish1BottomFin;
 	bottomFin() :fish1BottomFin( 13, std::vector<float>(2)){
	fish1BottomFin[0][0] = 159.9367;
 	fish1BottomFin[0][1] = 74.0185;
 	fish1BottomFin[1][0] = 159.9367;
 	fish1BottomFin[1][1] = 74.0185;
 	fish1BottomFin[2][0] = 124.6037;
 	fish1BottomFin[2][1] = 40.6850;
 	fish1BottomFin[3][0] = 93.6037;
 	fish1BottomFin[3][1] = 48.6850;
 	fish1BottomFin[4][0] = 93.6037;
 	fish1BottomFin[4][1] = 48.6850;
 	fish1BottomFin[5][0] = 85.9367;
 	fish1BottomFin[5][1] = 40.6845;
 	fish1BottomFin[6][0] = 116.6037;
 	fish1BottomFin[6][1] = 27.3515;
 	fish1BottomFin[7][0] = 147.2707;
 	fish1BottomFin[7][1] = 14.0185;
 	fish1BottomFin[8][0] = 265.6408;
 	fish1BottomFin[8][1] = 35.9081;
 	fish1BottomFin[9][0] = 301.5607;
 	fish1BottomFin[9][1] = 62.8700;
 	fish1BottomFin[10][0] = 301.5607;
 	fish1BottomFin[10][1] = 62.8700;
 	fish1BottomFin[11][0] = 169.9367;
 	fish1BottomFin[11][1] = 52.0185;
 	fish1BottomFin[12][0] = 159.9367;
 	fish1BottomFin[12][1] = 74.0185;

 	 }
 };
class topFin{
	public:
    std::vector< std::vector< float > >& getTopFin(void);
 	std::vector< std::vector< float > > fish1TopFin;

 	topFin() :fish1TopFin( 13, std::vector<float>(2)){
	fish1TopFin[0][0] = 97.4191;
 	fish1TopFin[0][1] = 148.0619;
 	fish1TopFin[1][0] = 97.4191;
 	fish1TopFin[1][1] = 148.0619;
 	fish1TopFin[2][0] = 199.5402;
 	fish1TopFin[2][1] = 235.6005;
 	fish1TopFin[3][0] = 179.0207;
 	fish1TopFin[3][1] = 261.5712;
 	fish1TopFin[4][0] = 179.0207;
 	fish1TopFin[4][1] = 261.5712;
 	fish1TopFin[5][0] = 240.3449;
 	fish1TopFin[5][1] = 263.8344;
 	fish1TopFin[6][0] = 275.3400;
 	fish1TopFin[6][1] = 231.5200;
 	fish1TopFin[7][0] = 310.3352;
 	fish1TopFin[7][1] = 199.2055;
 	fish1TopFin[8][0] = 300.1955;
 	fish1TopFin[8][1] = 210.4550;
 	fish1TopFin[9][0] = 300.1955;
 	fish1TopFin[9][1] = 210.4550;
 	fish1TopFin[10][0] = 300.1955;
 	fish1TopFin[10][1] = 210.4550;
 	fish1TopFin[11][0] = 198.1467;
 	fish1TopFin[11][1] = 217.8910;
 	fish1TopFin[12][0] = 97.4191;
 	fish1TopFin[12][1] = 148.0619;

 	 }
 };
class outerEye{

	public:
	std::vector< std::vector< float > >& getOuterEye(void);
 	std::vector< std::vector< float > > fish1OuterEye;

 	outerEye() :fish1OuterEye( 13, std::vector<float>(2)){
	fish1OuterEye[0][0] = 317.4465;
 	fish1OuterEye[0][1] = 179.6205;
 	fish1OuterEye[1][0] = 317.4465;
 	fish1OuterEye[1][1] = 175.3862;
 	fish1OuterEye[2][0] = 314.0139;
 	fish1OuterEye[2][1] = 171.9535;
 	fish1OuterEye[3][0] = 309.7795;
 	fish1OuterEye[3][1] = 171.9535;
 	fish1OuterEye[4][0] = 305.5451;
 	fish1OuterEye[4][1] = 171.9535;
 	fish1OuterEye[5][0] = 302.1135;
 	fish1OuterEye[5][1] = 175.3862;
 	fish1OuterEye[6][0] = 302.1135;
 	fish1OuterEye[6][1] = 179.6205;
 	fish1OuterEye[7][0] = 302.1135;
 	fish1OuterEye[7][1] = 183.8544;
 	fish1OuterEye[8][0] = 305.5451;
 	fish1OuterEye[8][1] = 187.2870;
 	fish1OuterEye[9][0] = 309.7795;
 	fish1OuterEye[9][1] = 187.2870;
 	fish1OuterEye[10][0] = 314.0139;
 	fish1OuterEye[10][1] = 187.2870;
 	fish1OuterEye[11][0] = 317.4465;
 	fish1OuterEye[11][1] = 183.8544;
 	fish1OuterEye[12][0] = 317.4465;
 	fish1OuterEye[12][1] = 179.6205;

 	 }
 };
class eyeBrow{
    std::vector< std::vector< float > >& getEyeBrow(void);
	public:
 	std::vector< std::vector< float > > fish1EyeBrow;

 	eyeBrow() :fish1EyeBrow( 4, std::vector<float>(2)){
	fish1EyeBrow[0][0] = 289.4455;
 	fish1EyeBrow[0][1] = 206.6205;
 	fish1EyeBrow[1][0] = 289.4455;
 	fish1EyeBrow[1][1] = 206.6205;
 	fish1EyeBrow[2][0] = 276.7795;
 	fish1EyeBrow[2][1] = 200.6200;
 	fish1EyeBrow[3][0] = 273.4455;
 	fish1EyeBrow[3][1] = 187.2870;

 	 }
 };
class body{

	public:
	std::vector< std::vector< float > >& getBody(void);
 	std::vector< std::vector< float > > fish1BodyClosedMouth;
    std::vector< std::vector< float > > fish1BodyOpenMouth;
    std::vector< std::vector< float > > bodyrework;
 	body() :fish1BodyClosedMouth( 28, std::vector<float>(2)),
        fish1BodyOpenMouth( 31, std::vector<float>(2)),
        bodyrework( 12, std::vector<float>(2))
    {

	bodyrework[0][0] = 67.7605;
 	bodyrework[0][1] = 142.3029;
 	bodyrework[1][0] = 99.7523;
 	bodyrework[1][1] = 155.3503;
 	bodyrework[2][0] = 166.1648;
 	bodyrework[2][1] = 195.5416;
 	bodyrework[3][0] = 240.0015;
 	bodyrework[3][1] = 220.1998;
 	bodyrework[4][0] = 289.1519;
 	bodyrework[4][1] = 217.3119;
 	bodyrework[5][0] = 357.1929;
 	bodyrework[5][1] = 138.2426;
 	bodyrework[6][0] = 332.5622;
 	bodyrework[6][1] = 130.6570;
 	bodyrework[7][0] = 351.9994;
 	bodyrework[7][1] = 122.2438;
 	bodyrework[8][0] = 351.7075;
 	bodyrework[8][1] = 120.0851;
 	bodyrework[9][0] = 312.9998;
 	bodyrework[9][1] = 59.7409;
 	bodyrework[10][0] = 150.9904;
 	bodyrework[10][1] = 70.8876;
 	bodyrework[11][0] = 66.9456;
 	bodyrework[11][1] = 73.4221;


	fish1BodyClosedMouth[0][0] = 66.9860;
 	fish1BodyClosedMouth[0][1] = 127.2651;
 	fish1BodyClosedMouth[1][0] = 66.9860;
 	fish1BodyClosedMouth[1][1] = 127.2651;
 	fish1BodyClosedMouth[2][0] = 66.9860;
 	fish1BodyClosedMouth[2][1] = 73.7348;
 	fish1BodyClosedMouth[3][0] = 66.9860;
 	fish1BodyClosedMouth[3][1] = 73.7348;
 	fish1BodyClosedMouth[4][0] = 66.9860;
 	fish1BodyClosedMouth[4][1] = 73.7348;
 	fish1BodyClosedMouth[5][0] = 129.5168;
 	fish1BodyClosedMouth[5][1] = 77.0507;
 	fish1BodyClosedMouth[6][0] = 161.7307;
 	fish1BodyClosedMouth[6][1] = 68.0497;
 	fish1BodyClosedMouth[7][0] = 193.9445;
 	fish1BodyClosedMouth[7][1] = 59.0488;
 	fish1BodyClosedMouth[8][0] = 292.4787;
 	fish1BodyClosedMouth[8][1] = 25.8881;
 	fish1BodyClosedMouth[9][0] = 324.2180;
 	fish1BodyClosedMouth[9][1] = 74.6821;
 	fish1BodyClosedMouth[10][0] = 348.5041;
 	fish1BodyClosedMouth[10][1] = 112.0180;
 	fish1BodyClosedMouth[11][0] = 352.9377;
 	fish1BodyClosedMouth[11][1] = 121.5214;
 	fish1BodyClosedMouth[12][0] = 352.9377;
 	fish1BodyClosedMouth[12][1] = 121.5214;
 	fish1BodyClosedMouth[13][0] = 352.9377;
 	fish1BodyClosedMouth[13][1] = 121.5214;
 	fish1BodyClosedMouth[14][0] = 361.2912;
 	fish1BodyClosedMouth[14][1] = 135.3188;
 	fish1BodyClosedMouth[15][0] = 357.0285;
 	fish1BodyClosedMouth[15][1] = 138.3979;
 	fish1BodyClosedMouth[16][0] = 352.7648;
 	fish1BodyClosedMouth[16][1] = 141.4775;
 	fish1BodyClosedMouth[17][0] = 316.6594;
 	fish1BodyClosedMouth[17][1] = 218.1674;
 	fish1BodyClosedMouth[18][0] = 275.4455;
 	fish1BodyClosedMouth[18][1] = 220.0619;
 	fish1BodyClosedMouth[19][0] = 234.2316;
 	fish1BodyClosedMouth[19][1] = 221.9570;
 	fish1BodyClosedMouth[20][0] = 207.0324;
 	fish1BodyClosedMouth[20][1] = 218.5595;
 	fish1BodyClosedMouth[21][0] = 155.5725;
 	fish1BodyClosedMouth[21][1] = 189.3232;
 	fish1BodyClosedMouth[22][0] = 105.0285;
 	fish1BodyClosedMouth[22][1] = 160.6074;
 	fish1BodyClosedMouth[23][0] = 84.9255;
 	fish1BodyClosedMouth[23][1] = 142.9179;
 	fish1BodyClosedMouth[24][0] = 67.8718;
 	fish1BodyClosedMouth[24][1] = 141.9701;
 	fish1BodyClosedMouth[25][0] = 67.8718;
 	fish1BodyClosedMouth[25][1] = 141.9701;
 	fish1BodyClosedMouth[26][0] = 66.9860;
 	fish1BodyClosedMouth[26][1] = 127.2651;
 	fish1BodyClosedMouth[27][0] = 66.9860;
 	fish1BodyClosedMouth[27][1] = 127.2651;

 	fish1BodyOpenMouth[0][0] = 66.9860;
 	fish1BodyOpenMouth[0][1] = 127.2651;
 	fish1BodyOpenMouth[1][0] = 66.9860;
 	fish1BodyOpenMouth[1][1] = 127.2651;
 	fish1BodyOpenMouth[2][0] = 66.9860;
 	fish1BodyOpenMouth[2][1] = 73.7348;
 	fish1BodyOpenMouth[3][0] = 66.9860;
 	fish1BodyOpenMouth[3][1] = 73.7348;
 	fish1BodyOpenMouth[4][0] = 66.9860;
 	fish1BodyOpenMouth[4][1] = 73.7348;
 	fish1BodyOpenMouth[5][0] = 129.5168;
 	fish1BodyOpenMouth[5][1] = 77.0507;
 	fish1BodyOpenMouth[6][0] = 161.7307;
 	fish1BodyOpenMouth[6][1] = 68.0497;
 	fish1BodyOpenMouth[7][0] = 193.9445;
 	fish1BodyOpenMouth[7][1] = 59.0488;
 	fish1BodyOpenMouth[8][0] = 292.4787;
 	fish1BodyOpenMouth[8][1] = 25.8881;
 	fish1BodyOpenMouth[9][0] = 324.2180;
 	fish1BodyOpenMouth[9][1] = 74.6821;
 	fish1BodyOpenMouth[10][0] = 348.5041;
 	fish1BodyOpenMouth[10][1] = 112.0180;
 	fish1BodyOpenMouth[11][0] = 352.9377;
 	fish1BodyOpenMouth[11][1] = 121.5214;
 	fish1BodyOpenMouth[12][0] = 352.9377;
 	fish1BodyOpenMouth[12][1] = 121.5214;
 	fish1BodyOpenMouth[13][0] = 352.9377;
 	fish1BodyOpenMouth[13][1] = 121.5214;
 	fish1BodyOpenMouth[14][0] = 306.1256;
 	fish1BodyOpenMouth[14][1] = 132.7557;
 	fish1BodyOpenMouth[15][0] = 358.2106;
 	fish1BodyOpenMouth[15][1] = 134.3820;
 	fish1BodyOpenMouth[16][0] = 357.0285;
 	fish1BodyOpenMouth[16][1] = 138.3979;
 	fish1BodyOpenMouth[17][0] = 356.2357;
 	fish1BodyOpenMouth[17][1] = 138.9705;
 	fish1BodyOpenMouth[18][0] = 353.6206;
 	fish1BodyOpenMouth[18][1] = 143.2758;
 	fish1BodyOpenMouth[19][0] = 336.5365;
 	fish1BodyOpenMouth[19][1] = 171.8581;
 	fish1BodyOpenMouth[20][0] = 306.0773;
 	fish1BodyOpenMouth[20][1] = 218.6539;
 	fish1BodyOpenMouth[21][0] = 275.4455;
 	fish1BodyOpenMouth[21][1] = 220.0619;
 	fish1BodyOpenMouth[22][0] = 234.2316;
 	fish1BodyOpenMouth[22][1] = 221.9570;
 	fish1BodyOpenMouth[23][0] = 207.0324;
 	fish1BodyOpenMouth[23][1] = 218.5595;
 	fish1BodyOpenMouth[24][0] = 155.5725;
 	fish1BodyOpenMouth[24][1] = 189.3232;
 	fish1BodyOpenMouth[25][0] = 105.0285;
 	fish1BodyOpenMouth[25][1] = 160.6074;
 	fish1BodyOpenMouth[26][0] = 84.9255;
 	fish1BodyOpenMouth[26][1] = 142.9179;
 	fish1BodyOpenMouth[27][0] = 67.8718;
 	fish1BodyOpenMouth[27][1] = 141.9701;
 	fish1BodyOpenMouth[28][0] = 67.8718;
 	fish1BodyOpenMouth[28][1] = 141.9701;
 	fish1BodyOpenMouth[29][0] = 66.9860;
 	fish1BodyOpenMouth[29][1] = 127.2651;
 	fish1BodyOpenMouth[30][0] = 66.9860;
 	fish1BodyOpenMouth[30][1] = 127.2651;


 	 }
 };
class head{

	public:

	std::vector< std::vector< float > >& getHead(void);; //LOL
 	std::vector< std::vector< float > > fish1HeadClosedMouth;
    std::vector< std::vector< float > > fish1HeadOpenMouth;

 	head() :fish1HeadClosedMouth( 19, std::vector<float>(2)),fish1HeadOpenMouth( 23, std::vector<float>(2)){
	fish1HeadClosedMouth[0][0] = 276.2531;
 	fish1HeadClosedMouth[0][1] = 220.2753;
 	fish1HeadClosedMouth[1][0] = 317.3312;
 	fish1HeadClosedMouth[1][1] = 216.4316;
 	fish1HeadClosedMouth[2][0] = 353.5725;
 	fish1HeadClosedMouth[2][1] = 141.6908;
 	fish1HeadClosedMouth[3][0] = 357.8361;
 	fish1HeadClosedMouth[3][1] = 138.6113;
 	fish1HeadClosedMouth[4][0] = 362.0988;
 	fish1HeadClosedMouth[4][1] = 135.5322;
 	fish1HeadClosedMouth[5][0] = 353.7453;
 	fish1HeadClosedMouth[5][1] = 121.7348;
 	fish1HeadClosedMouth[6][0] = 353.7453;
 	fish1HeadClosedMouth[6][1] = 121.7348;
 	fish1HeadClosedMouth[7][0] = 353.7453;
 	fish1HeadClosedMouth[7][1] = 121.7348;
 	fish1HeadClosedMouth[8][0] = 349.3117;
 	fish1HeadClosedMouth[8][1] = 112.2314;
 	fish1HeadClosedMouth[9][0] = 325.0256;
 	fish1HeadClosedMouth[9][1] = 74.8954;
 	fish1HeadClosedMouth[10][0] = 311.9729;
 	fish1HeadClosedMouth[10][1] = 54.8281;
 	fish1HeadClosedMouth[11][0] = 287.6232;
 	fish1HeadClosedMouth[11][1] = 48.6220;
 	fish1HeadClosedMouth[12][0] = 261.2355;
 	fish1HeadClosedMouth[12][1] = 48.8964;
 	fish1HeadClosedMouth[13][0] = 261.2355;
 	fish1HeadClosedMouth[13][1] = 48.8964;
 	fish1HeadClosedMouth[14][0] = 240.5871;
 	fish1HeadClosedMouth[14][1] = 69.5546;
 	fish1HeadClosedMouth[15][0] = 244.5871;
 	fish1HeadClosedMouth[15][1] = 134.5815;
 	fish1HeadClosedMouth[16][0] = 248.5871;
 	fish1HeadClosedMouth[16][1] = 199.6083;
 	fish1HeadClosedMouth[17][0] = 273.2893;
 	fish1HeadClosedMouth[17][1] = 220.5527;
 	fish1HeadClosedMouth[18][0] = 276.2531;
 	fish1HeadClosedMouth[18][1] = 220.2753;

 	fish1HeadOpenMouth[0][0] = 276.2531;
 	fish1HeadOpenMouth[0][1] = 220.2753;
 	fish1HeadOpenMouth[1][0] = 317.3312;
 	fish1HeadOpenMouth[1][1] = 216.4316;
 	fish1HeadOpenMouth[2][0] = 353.5725;
 	fish1HeadOpenMouth[2][1] = 141.6908;
 	fish1HeadOpenMouth[3][0] = 356.5422;
 	fish1HeadOpenMouth[3][1] = 139.6496;
 	fish1HeadOpenMouth[4][0] = 358.5306;
 	fish1HeadOpenMouth[4][1] = 136.5989;
 	fish1HeadOpenMouth[5][0] = 353.8458;
 	fish1HeadOpenMouth[5][1] = 135.1004;
 	fish1HeadOpenMouth[6][0] = 323.9353;
 	fish1HeadOpenMouth[6][1] = 130.3401;
 	fish1HeadOpenMouth[7][0] = 349.7553;
 	fish1HeadOpenMouth[7][1] = 122.9307;
 	fish1HeadOpenMouth[8][0] = 353.7453;
 	fish1HeadOpenMouth[8][1] = 121.7348;
 	fish1HeadOpenMouth[9][0] = 353.7453;
 	fish1HeadOpenMouth[9][1] = 121.7348;
 	fish1HeadOpenMouth[10][0] = 353.7453;
 	fish1HeadOpenMouth[10][1] = 121.7348;
 	fish1HeadOpenMouth[11][0] = 352.3053;
 	fish1HeadOpenMouth[11][1] = 118.6480;
 	fish1HeadOpenMouth[12][0] = 341.4235;
 	fish1HeadOpenMouth[12][1] = 100.1045;
 	fish1HeadOpenMouth[13][0] = 325.0256;
 	fish1HeadOpenMouth[13][1] = 74.8954;
 	fish1HeadOpenMouth[14][0] = 311.9729;
 	fish1HeadOpenMouth[14][1] = 54.8281;
 	fish1HeadOpenMouth[15][0] = 287.6232;
 	fish1HeadOpenMouth[15][1] = 48.6220;
 	fish1HeadOpenMouth[16][0] = 261.2355;
 	fish1HeadOpenMouth[16][1] = 48.8964;
 	fish1HeadOpenMouth[17][0] = 261.2355;
 	fish1HeadOpenMouth[17][1] = 48.8964;
 	fish1HeadOpenMouth[18][0] = 240.5871;
 	fish1HeadOpenMouth[18][1] = 69.5546;
 	fish1HeadOpenMouth[19][0] = 244.5871;
 	fish1HeadOpenMouth[19][1] = 134.5815;
 	fish1HeadOpenMouth[20][0] = 248.5871;
 	fish1HeadOpenMouth[20][1] = 199.6083;
 	fish1HeadOpenMouth[21][0] = 273.2893;
 	fish1HeadOpenMouth[21][1] = 220.5527;
 	fish1HeadOpenMouth[22][0] = 276.2531;
 	fish1HeadOpenMouth[22][1] = 220.2753;

 	 }
 };
class mouthLine{
	public:
    std::vector< std::vector< float > >& getMouthLine(void);
 	std::vector< std::vector< float > > fish1MouthLine;

 	mouthLine() :fish1MouthLine( 7, std::vector<float>(2)){
	fish1MouthLine[0][0] = 332.6379;
 	fish1MouthLine[0][1] = 135.6967;
 	fish1MouthLine[1][0] = 332.6379;
 	fish1MouthLine[1][1] = 135.6967;
 	fish1MouthLine[2][0] = 335.6984;
 	fish1MouthLine[2][1] = 132.1474;
 	fish1MouthLine[3][0] = 339.1125;
 	fish1MouthLine[3][1] = 132.0619;
 	fish1MouthLine[4][0] = 342.5266;
 	fish1MouthLine[4][1] = 131.9765;
 	fish1MouthLine[5][0] = 350.4738;
 	fish1MouthLine[5][1] = 132.5390;
 	fish1MouthLine[6][0] = 358.2404;
 	fish1MouthLine[6][1] = 137.0619;
 	}
};


//class headOpenMouth{
//
//	public:
//
// 	headOpenMouth() :{
//	fish1HeadOpenMouth[0][0] = 276.2531;
// 	fish1HeadOpenMouth[0][1] = 220.2753;
// 	fish1HeadOpenMouth[1][0] = 317.3312;
// 	fish1HeadOpenMouth[1][1] = 216.4316;
// 	fish1HeadOpenMouth[2][0] = 353.5725;
// 	fish1HeadOpenMouth[2][1] = 141.6908;
// 	fish1HeadOpenMouth[3][0] = 356.5422;
// 	fish1HeadOpenMouth[3][1] = 139.6496;
// 	fish1HeadOpenMouth[4][0] = 358.5306;
// 	fish1HeadOpenMouth[4][1] = 136.5989;
// 	fish1HeadOpenMouth[5][0] = 353.8458;
// 	fish1HeadOpenMouth[5][1] = 135.1004;
// 	fish1HeadOpenMouth[6][0] = 323.9353;
// 	fish1HeadOpenMouth[6][1] = 130.3401;
// 	fish1HeadOpenMouth[7][0] = 349.7553;
// 	fish1HeadOpenMouth[7][1] = 122.9307;
// 	fish1HeadOpenMouth[8][0] = 353.7453;
// 	fish1HeadOpenMouth[8][1] = 121.7348;
// 	fish1HeadOpenMouth[9][0] = 353.7453;
// 	fish1HeadOpenMouth[9][1] = 121.7348;
// 	fish1HeadOpenMouth[10][0] = 353.7453;
// 	fish1HeadOpenMouth[10][1] = 121.7348;
// 	fish1HeadOpenMouth[11][0] = 352.3053;
// 	fish1HeadOpenMouth[11][1] = 118.6480;
// 	fish1HeadOpenMouth[12][0] = 341.4235;
// 	fish1HeadOpenMouth[12][1] = 100.1045;
// 	fish1HeadOpenMouth[13][0] = 325.0256;
// 	fish1HeadOpenMouth[13][1] = 74.8954;
// 	fish1HeadOpenMouth[14][0] = 311.9729;
// 	fish1HeadOpenMouth[14][1] = 54.8281;
// 	fish1HeadOpenMouth[15][0] = 287.6232;
// 	fish1HeadOpenMouth[15][1] = 48.6220;
// 	fish1HeadOpenMouth[16][0] = 261.2355;
// 	fish1HeadOpenMouth[16][1] = 48.8964;
// 	fish1HeadOpenMouth[17][0] = 261.2355;
// 	fish1HeadOpenMouth[17][1] = 48.8964;
// 	fish1HeadOpenMouth[18][0] = 240.5871;
// 	fish1HeadOpenMouth[18][1] = 69.5546;
// 	fish1HeadOpenMouth[19][0] = 244.5871;
// 	fish1HeadOpenMouth[19][1] = 134.5815;
// 	fish1HeadOpenMouth[20][0] = 248.5871;
// 	fish1HeadOpenMouth[20][1] = 199.6083;
// 	fish1HeadOpenMouth[21][0] = 273.2893;
// 	fish1HeadOpenMouth[21][1] = 220.5527;
// 	fish1HeadOpenMouth[22][0] = 276.2531;
// 	fish1HeadOpenMouth[22][1] = 220.2753;
//
// 	 }
// };
//class bodyOpenMouth{
//
//	public:
// 	std::vector< std::vector< float > > fish1BodyOpenMouth;
//
// 	bodyOpenMouth() :fish1BodyOpenMouth( 31, std::vector<float>(2)){
//	fish1BodyOpenMouth[0][0] = 66.9860;
// 	fish1BodyOpenMouth[0][1] = 127.2651;
// 	fish1BodyOpenMouth[1][0] = 66.9860;
// 	fish1BodyOpenMouth[1][1] = 127.2651;
// 	fish1BodyOpenMouth[2][0] = 66.9860;
// 	fish1BodyOpenMouth[2][1] = 73.7348;
// 	fish1BodyOpenMouth[3][0] = 66.9860;
// 	fish1BodyOpenMouth[3][1] = 73.7348;
// 	fish1BodyOpenMouth[4][0] = 66.9860;
// 	fish1BodyOpenMouth[4][1] = 73.7348;
// 	fish1BodyOpenMouth[5][0] = 129.5168;
// 	fish1BodyOpenMouth[5][1] = 77.0507;
// 	fish1BodyOpenMouth[6][0] = 161.7307;
// 	fish1BodyOpenMouth[6][1] = 68.0497;
// 	fish1BodyOpenMouth[7][0] = 193.9445;
// 	fish1BodyOpenMouth[7][1] = 59.0488;
// 	fish1BodyOpenMouth[8][0] = 292.4787;
// 	fish1BodyOpenMouth[8][1] = 25.8881;
// 	fish1BodyOpenMouth[9][0] = 324.2180;
// 	fish1BodyOpenMouth[9][1] = 74.6821;
// 	fish1BodyOpenMouth[10][0] = 348.5041;
// 	fish1BodyOpenMouth[10][1] = 112.0180;
// 	fish1BodyOpenMouth[11][0] = 352.9377;
// 	fish1BodyOpenMouth[11][1] = 121.5214;
// 	fish1BodyOpenMouth[12][0] = 352.9377;
// 	fish1BodyOpenMouth[12][1] = 121.5214;
// 	fish1BodyOpenMouth[13][0] = 352.9377;
// 	fish1BodyOpenMouth[13][1] = 121.5214;
// 	fish1BodyOpenMouth[14][0] = 306.1256;
// 	fish1BodyOpenMouth[14][1] = 132.7557;
// 	fish1BodyOpenMouth[15][0] = 358.2106;
// 	fish1BodyOpenMouth[15][1] = 134.3820;
// 	fish1BodyOpenMouth[16][0] = 357.0285;
// 	fish1BodyOpenMouth[16][1] = 138.3979;
// 	fish1BodyOpenMouth[17][0] = 356.2357;
// 	fish1BodyOpenMouth[17][1] = 138.9705;
// 	fish1BodyOpenMouth[18][0] = 353.6206;
// 	fish1BodyOpenMouth[18][1] = 143.2758;
// 	fish1BodyOpenMouth[19][0] = 336.5365;
// 	fish1BodyOpenMouth[19][1] = 171.8581;
// 	fish1BodyOpenMouth[20][0] = 306.0773;
// 	fish1BodyOpenMouth[20][1] = 218.6539;
// 	fish1BodyOpenMouth[21][0] = 275.4455;
// 	fish1BodyOpenMouth[21][1] = 220.0619;
// 	fish1BodyOpenMouth[22][0] = 234.2316;
// 	fish1BodyOpenMouth[22][1] = 221.9570;
// 	fish1BodyOpenMouth[23][0] = 207.0324;
// 	fish1BodyOpenMouth[23][1] = 218.5595;
// 	fish1BodyOpenMouth[24][0] = 155.5725;
// 	fish1BodyOpenMouth[24][1] = 189.3232;
// 	fish1BodyOpenMouth[25][0] = 105.0285;
// 	fish1BodyOpenMouth[25][1] = 160.6074;
// 	fish1BodyOpenMouth[26][0] = 84.9255;
// 	fish1BodyOpenMouth[26][1] = 142.9179;
// 	fish1BodyOpenMouth[27][0] = 67.8718;
// 	fish1BodyOpenMouth[27][1] = 141.9701;
// 	fish1BodyOpenMouth[28][0] = 67.8718;
// 	fish1BodyOpenMouth[28][1] = 141.9701;
// 	fish1BodyOpenMouth[29][0] = 66.9860;
// 	fish1BodyOpenMouth[29][1] = 127.2651;
// 	fish1BodyOpenMouth[30][0] = 66.9860;
// 	fish1BodyOpenMouth[30][1] = 127.2651;
//
// 	 }
// };
