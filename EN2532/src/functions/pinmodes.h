void pinmodes(){
    //declaration of pinModes

    //motor controlling pins
    pinMode(rm1,OUTPUT);
    pinMode(rm2,OUTPUT);
    pinMode(Rpwm,OUTPUT);
    pinMode(Lpwm,OUTPUT);
    pinMode(lm1,OUTPUT);
    pinMode(lm2,OUTPUT);

    //interrupts
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    // pinMode(18,INPUT_PULLUP);
    // pinMode(19,INPUT_PULLUP);
    pinMode(18,INPUT_PULLUP);
    pinMode(19,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(18),rjunction,FALLING); //junction detectors
    attachInterrupt(digitalPinToInterrupt(19),ljunction,FALLING);    //Junction detectors
    

    //Line Sensors
    pinMode(S1,INPUT);
    pinMode(S2,INPUT);
    pinMode(S3,INPUT);
    pinMode(S4,INPUT);
    pinMode(S5,INPUT);
    pinMode(S6,INPUT);
    pinMode(S7,INPUT);
    pinMode(S8,INPUT);


    //Tilt Sensors
    pinMode(slopeup,INPUT_PULLUP);
    pinMode(slopedown,INPUT_PULLUP);

    //RGB sensor
    pinMode(SC0,OUTPUT);
    pinMode(SC1,OUTPUT);
    pinMode(SC2,OUTPUT);
    pinMode(SC3,OUTPUT);
    pinMode(sensorOut,INPUT);


    //buttons
    pinMode(button1,INPUT_PULLUP);
    pinMode(button2,INPUT_PULLUP);
    pinMode(button3,INPUT_PULLUP);
    pinMode(buzzer,OUTPUT);


    pinMode(relaypump1,OUTPUT);
    pinMode(relaypump,OUTPUT);







    



    
}