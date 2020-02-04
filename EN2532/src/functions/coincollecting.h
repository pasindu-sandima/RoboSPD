Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void servosetup(){
    pwm.begin();
    pwm.setPWMFreq(60);
}

void collectcoin(){
    CoinArmDown();
    drive_forward(288,310);
    delay(700);
    allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
    while(allsensors){
    allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
    }
    delay(500);
    brake();
    Kp=45;
    Kd=60;
    while(true){
    line_following();
    allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
    if(allsensors){
        brake();
        break;
    }
    }
    delay(100);
    CoinArmUp();
    MagnetRelease();
    // drive_forward(600,600);
    // delay(100);
    // brake();
    // delay(100);

}
void CoinRelease(){
    CoinArmDown();
    drive_forward(500,500);
    delay(200);
    brake();
    CoinArmUp();
    MagnetNormal();
    
}

void detectcolour(){
    //Sets the frequency to 20%.... Set both to high for 100%
    digitalWrite(SC0,HIGH);
    digitalWrite(SC1,LOW);
    red=0;
    green=0;
    blue=0;
    
    for (int detect=0;detect<5;detect++){
        //detecting red 
        digitalWrite(SC2,LOW);
        digitalWrite(SC3,LOW);
        // delay(100);
        red = pulseIn(sensorOut, LOW);   
        delay(100);
        //detecting green 
        digitalWrite(SC2,HIGH);
        digitalWrite(SC3,HIGH);
        // delay(100);
        green = pulseIn(sensorOut, LOW); 
        delay(100);
        //detecting blue
        digitalWrite(SC2,LOW);
        digitalWrite(SC3,HIGH);
        // delay(100);
        blue = pulseIn(sensorOut, LOW);
        delay(100);
    }

    // Serial.print(red);
    // Serial.print("  ,  ");
    // Serial.print(blue);
    // Serial.print("   ,  ");
    // Serial.print(green);
    // Serial.println(" ");

    if(((red+green+blue)>240)||((red+green+blue)<100)){
        digitalWrite(greenled,HIGH);
        testdrawGREEN();
        colour=1;
    }
    else if(red<50){
        digitalWrite(redled,HIGH);
        testdrawRED();
        colour=2;
    }
    else if(blue<50){
        digitalWrite(blueled,HIGH); 
        testdrawBLUE();
        colour=3; 
    }
}

void CoinArmDown(){
    for (uint16_t pulselen = coinservoup; pulselen > coinservodown; pulselen--) {
    pwm.setPWM(coinarmservo, 0, pulselen);
    delay(5);
    } 
}

void CoinArmUp(){
    for (uint16_t pulselen = coinservodown; pulselen < coinservoup; pulselen++) {
    pwm.setPWM(coinarmservo, 0, pulselen);
    delay(1);
    }
}
void MagnetRelease(){
    for (uint16_t pulselen = magnetservonormal; pulselen > magnetservorelease; pulselen--){
        pwm.setPWM(magnetservo, 0, pulselen);
        delay(5);
    }
}
void MagnetNormal(){
    for (uint16_t pulselen = magnetservorelease; pulselen < magnetservonormal; pulselen++){
        pwm.setPWM(magnetservo, 0, pulselen);
        delay(5);
    }
}
void WaterArmDown(){
    for (uint16_t pulselen = waterservoup; pulselen > waterservodown; pulselen--) {
    pwm.setPWM(waterarmservo, 0, pulselen);
    delay(5);
    } 
}
void WaterArmUp(){
    for (uint16_t pulselen = waterservodown; pulselen < waterservoup; pulselen++) {
    pwm.setPWM(waterarmservo, 0, pulselen);
    delay(5);
    }
}