void checkserial(int a){
    if(Serial3.available()){
        a = Serial3.parseInt();
    }
}
void watertransfer(){
    WaterArmDown();
    delay(100);
    digitalWrite(relaypump1,HIGH);
    digitalWrite(relaypump,HIGH);
    delay(500);
    digitalWrite(relaypump1,LOW);
    digitalWrite(relaypump,LOW);
    delay(1000);
    WaterArmUp();
    delay(100);
}

void uptocoincollect(){
    digitalWrite(buzzer,HIGH);
    while ((analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range)){
    drive_forward(400,400);
    }
    digitalWrite(buzzer,LOW);
    countforward(200);
    leftjunction = false;
    rightjunction = false;
    rspeed=450;
    lspeed=480;
    while(true){
        line_following();
        junction();
        if(junctionflag){
            brake();
            break;
        }
    }
    delay(100);

    Kp=30;
    Kd=60;
    rspeed=295;
    lspeed=310;
    while(true){
    line_following();
    // coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));
    allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
    if(allsensors){
        brake();
        break;
    } 
    }
    delay(500);
}

void colouredline(){
    if(colour==1){                  //Green
      drive_forward(200,210);
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
      rcount=countright;
      while(countright<rcount+1000){}
      detachInterrupt(digitalPinToInterrupt(3));
      brake();
      delay(500);
      CoinArmDown();
      drive_forward(510,510);
      delay(220);
      brake();
      delay(50);
      CoinArmUp();
      MagnetNormal();


      while(true){
          line_following();
          allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
          coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));        
          if(coinarea||allsensors){
          brake();
          break;
          }
      }
      drive_forward(295,310);
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
      rcount=countright;
      while(countright<rcount+350){}
      detachInterrupt(digitalPinToInterrupt(3));
      brake();  
    }
    else if(colour==2){             //Red
        drive_reverse(290,310);
        delay(1000);
        while(true){
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            if(allsensors){
            brake();
            break;
            }
        }
        delay(200);
        drive_forward(295,310);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+350){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(200);
        turnR45();
        rspeed = 190; lspeed= 205;
        Kp=30;
        Kd=60;
        while(true){
            line_following();
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));        
            if(coinarea||allsensors){
            brake();
            break;
            }
        }
        drive_forward(200,210);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+600){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(500);
        drive_forward(150,0);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+200){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(500);
        drive_forward(200,210);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+500){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(500);
        CoinArmDown();
        drive_forward(500,500);
        delay(210);
        brake();
        delay(50);
        CoinArmUp();
        MagnetNormal();
        drive_reverse(200,210);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+1000){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        while(true){
            line_following();
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));        
            if(coinarea||allsensors){
            brake();
            break;
            }
        }
        drive_forward(295,310);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+450){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(200);
        turnR45();       
    }
    else if(colour==3){             //Blue
        drive_reverse(290,310);
        delay(1000);
        while(true){
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            if(allsensors){
            brake();
            break;
            }
        }
        delay(200);
        drive_forward(295,310);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+350){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(200);
        turnL45();
        rspeed = 200; lspeed= 215;
        Kp=30;
        Kd=60;
        while(true){
            line_following();
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));        
            if(coinarea||allsensors){
            brake();
            break;
            }
        }
        delay(500);
        drive_forward(0,160);
        countleft=0;
        attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoders
        lcount=countleft;
        while(countleft<lcount+250){}
        detachInterrupt(digitalPinToInterrupt(2));
        brake();
        delay(500);
        drive_forward(200,210);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+900){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(500);
        CoinArmDown();
        drive_forward(500,500);
        delay(210);
        brake();
        delay(50);
        CoinArmUp();
        MagnetNormal();
        drive_reverse(200,210);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+1000){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        while(true){
            line_following();
            allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);        
            coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));        
            if(coinarea||allsensors){
            brake();
            break;
            }
        }
        drive_forward(295,310);
        countright=0;
        attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
        rcount=countright;
        while(countright<rcount+350){}
        detachInterrupt(digitalPinToInterrupt(3));
        brake();
        delay(200);
        turnL45();        
    }
    brake();

}

void watercollect(){
    Kp=45;
    Kd=60;
    rspeed=390;
    lspeed=420;
    while(true){
        line_following();
        junction();
        if(n==0){
            brake();
            break;
        }
    }
    delay(1000);
    countreverse(300);
    watertransfer();
    turn180();
    brake();
    delay(500);
    countreverse(500);
    delay(500);
    leftjunction = false;
    rightjunction = false;
    junctionflag=false;
    while(true){
        line_following();
        junction();
        if(junctionflag){
            brake();
            break;
        }
    }
    leftjunction = false;
    rightjunction = false;
    junctionflag=false;
    while(true){
        line_following();
        if(rightjunction){
            digitalWrite(buzzer,HIGH);
            brake();
            delay(50);
            digitalWrite(buzzer,LOW);
            countforward(200);
            turnR();
            junctionflag = true;
            brake();
            delay(100);
            break;
        }
    }
    while(true){
        line_following();
        if(n==8){
            brake();
            break;
        }
    }
    countforward(300);
    brake();
}



void task(){
    uptocoincollect();
    collectcoin();
    detectcolour();
    colouredline();
    brake();
    delay(200);
    uptowall();
    delay(200);
    MazeSolve();
    delay(200);
    watercollect();
    brake();
    turn180();
    turn180();
    brake();



}

void uptowall(){
    rampcount=0;
    Kp=45;
    Kd=60;
    rspeed=295;
    lspeed=310;
    leftjunction = false;
    rightjunction = false;
    junctionflag=false;
    while(true){
        line_following();
        junction();
        if(junctionflag){
            brake();
            break;
        }
    }
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    leftjunction = false;
    rightjunction = false;
    junctionflag=false;
    while(true){
        line_following();
        junction();
        if(junctionflag){
            brake();
            break;
        }
    }
    Kp=60;
    Kd=120;
    rspeed=200;
    lspeed=215;
    while(true){
        line_following();
        if(digitalRead(slopeup)){}
        else{
            rampcount++;
        }
        if(rampcount>60){
            // brake();
            digitalWrite(buzzer,HIGH);
            break;
            
        }
    }
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(20,20);             // Start at top-left corner
    display.print(F("Ramp Up")); 
    display.display();
    delay(100);
    digitalWrite(buzzer,LOW);
    // while(digitalRead(button1)){}
    rampcount=0;
    rspeed=384;
    lspeed=400;

    while(true){
        line_following();
        if(digitalRead(slopeup)){
            rampcount++;
        }
        if(rampcount>60){
            // brake();
            digitalWrite(buzzer,HIGH);
            break;
        } 
    }
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(20,20);             // Start at top-left corner
    display.print(F("Ramp Up-11")); 
    display.display();
    delay(100);
    digitalWrite(buzzer,LOW);
    // while(digitalRead(button1)){}
    rampcount=0;
    while(true){
        line_following();
        if(digitalRead(slopedown)){}
        else{
            rampcount++;
        }
        if(rampcount>5){
            // brake();
            digitalWrite(buzzer,HIGH);
            break;
        }
    }
    display.clearDisplay();
    display.setTextSize(2);             // Normal 1:1 pixel scale
    display.setTextColor(WHITE);        // Draw white text
    display.setCursor(20,20);             // Start at top-left corner
    display.print(F("slope down")); 
    display.display();
    delay(200);
    digitalWrite(buzzer,LOW);
    // while(digitalRead(button1)){}
    Kp=45;
    Kd=60;
    rampcount=0;
    rspeed=200;
    lspeed=215;
    leftjunction = false;
    rightjunction = false;
    junctionflag=false;
    while(true){
        line_following();
        junction();
        if(junctionflag){
            brake();
            break;
        }
    }
    while(true){
        line_following();
        if(n==0){
            brake();
            break;
        }
    }
    digitalWrite(buzzer,HIGH);
    delay(300);
    digitalWrite(buzzer,LOW);
}