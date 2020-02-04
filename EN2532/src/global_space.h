#ifndef GLOBAL_SPACE_H
#define GLOBAL_SPACE_H

//motor_controlling
#define rm1 10
#define rm2 9
#define Rpwm 8
#define lm1 12
#define lm2 13
#define Lpwm 11
volatile int countleft=0,countright=0;
int phasecount=0;
int lspeed=410; int rspeed=384;
int rampspeed = 300;

//Buttons
#define button1 36
#define button2 38
#define button3 40

#define buzzer 48


//line following
#define S1 A8 //leftmost
#define S2 A9
#define S3 A10
#define S4 A11
#define S5 A12
#define S6 A13
#define S7 A14
#define S8 A15 //rightmost
bool anysensor=true;
bool allsensors = false;
bool coinarea = false;
bool nosensors=false;


//Junction detecting
volatile bool leftjunction=false,rightjunction=false;
bool junctionflag =  false;

//line following parameters
int n=0; int sum=0;int lineout=0; float error=0; float last_error=0; float adj=0;
bool stop=false;
int Kd=120, Kp=30,w1=1, w2=3, w3=8, w4=20, w5=4,w6=1; // w5 = error is devided by this and the substracted from rspeed
int white_range = 75,br=100;

//wall following parameters
int wposition=40;int werror=0; int wlast_error=0; int wadj=0;
int wKd=4, wKp=4;
int wrspeed=400,wlspeed=400;
bool junctionstate=false;
bool rightfollow=true;
int junctioncount=0;
bool lineid=true;
//TOF readings
int distanceR=0,distanceL=0,distanceF=0;
int TempArray[10],TempArray1[10],TempArray2[10];
int array=0;
uint8_t A[100][100];


//drive forward
int Rspeed; int Lspeed;

//right and left turns
int lcount=0;
int rcount=0;
bool condition = true;



//Tilt Sensors
int slopeup=25;int slopedown=23;
int rampup=0;
int rampdown=0;
int rampcount=0;


//Coin Collecting and Colour Detecting
#define SC0 41        //S0
#define SC1 39       //s1
#define SC2 45
#define SC3 47
#define sensorOut 43             //output pin of the colour sensor
#define coinarmservo 14        //pin number of coin arm in servo driver
#define magnetservo 15        //pin number of the magnet servo in servo driver
#define coinservoup 580 
#define coinarmrelease 450        
#define coinservodown 375
#define coinservomid 470
#define magnetservonormal 450
#define magnetservorelease 300
int red=0,green=0,blue=0;
int colour=1; 
#define blueled 30
#define redled 32
#define greenled 34

//water arm
#define waterarmservo 13
#define waterservoup 500
#define waterservodown 350
#define relaypump 27
#define relaypump1 29


//OLED function
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

int Mode=0;
unsigned long time=0;





#endif