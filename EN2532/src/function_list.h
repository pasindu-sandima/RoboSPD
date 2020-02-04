//declaration of pinModes
void pinmodes();

//interrupt functions
void leftcount();//counter name ==> int countleft
void rightcount();//counter name => int countright
void rjunction();
void ljunction();



//drive fucntions
void drive_forward(int rSpeed,int lSpeed);
void drive_reverse(int rSpeed,int lSpeed);
void accelarate(int r);
void brake();
void passivebrake();
void turnR();
void turnL();
void turnlineR();
void turnlineL();
void turnR45();
void turnL45();
void turn180();
void countforward(int count);
void countreverse(int count);

//line following functions
void line_following();
void ramplinefollowing();
void junction();

//maze solving functions
void wall_followingR();
void wall_following();
void wall_followingL();
void detectjunction();
void junctiontype();



//TOF functions 
void tofSetup();
void getTOFreading(int x);
void measure();
void measuresingle();


//coin collecting
void servosetup();
void collectcoin();
void detectcolour();
void CoinRelease();

//ServoFunctions
void CoinArmUp();
void CoinArmDown();
void MagnetRelease();
void MagnetNormal();
void WaterArmDown();
void WaterArmUp();


//OLED fuctions
void testdrawRED();
void testdrawGREEN();
void testdrawBLUE();
void OLEDsetup();
void testdrawWelcome();
// void OLEDprint();

//otherfunctions
void checkserial(int a);
void watertransfer();
void task();
void uptocoincollect();
void colouredline();
void uptowall();
void MazeSolve();
void curve_line_following();
void watercollect();



