#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>
#include "global_space.h"
#include "function_list.h"

#include "functions\drive.h"
#include "functions\interrupts.h"
#include "functions\line_following.h"
#include "functions\mazesolve.h"
#include "functions\pinmodes.h"
#include "functions\tofSetup.h"
#include "functions\coincollecting.h"
#include "functions\OLED.h"
#include "functions\others.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial.println("Started");
  Serial3.println("Started");
  Wire.begin();
  TCCR1B &= ~(1<<CS11);//to set 7.5kHz f to pin 11
  TCCR1A |= (1<<WGM11); // resolution to 10 bits of pins 10,11
  TCCR4B &= ~(1<<CS41);//to set 7.5kHz f to pin 8
  TCCR4A |= (1<<WGM41); // resolution to 10 bits of pins 6,7,8
  // pinmodes();
  servosetup();
  OLEDsetup();
  // tofSetup();
  Serial.println("Done Setup");
  Serial3.println("Done Setup");
  testdrawWelcome();
  delay(3000);
  Serial.println(" Setup");
  pwm.setPWM(coinarmservo, 0, coinservoup);
  pwm.setPWM(magnetservo, 0, magnetservonormal);
  pwm.setPWM(waterarmservo,0,waterservoup);
  Serial.println("Initial Setup");

  delay(2000);
  Serial.println("loop Setup");

  while(true){
    MagnetNormal();
    delay(500);
    MagnetRelease();
    delay(500);
  }
}

void loop() {
  display.print(F("IDLE")); 
  Mode=0;
  while(digitalRead(button2)){
    if(digitalRead(button1)){}
    else{
        digitalWrite(buzzer,HIGH);
        delay(50);
        digitalWrite(buzzer,LOW);
        delay(150);
        Mode+=1;
        if(Mode>15){
          Mode=0;
        }
    }
    if(digitalRead(button3)){
    }
    else{
        digitalWrite(buzzer,HIGH);
        delay(50);
        digitalWrite(buzzer,LOW);
        delay(150);
        Mode-=1;
        if(Mode<0){
          Mode=15;
        }

    }
    if(Mode==0){
        display.clearDisplay();
        display.setTextSize(4);             // Normal 1:1 pixel scale
        display.setTextColor(WHITE);        // Draw white text
        display.setCursor(20,20);             // Start at top-left corner
        display.print(F("IDLE")); 
        display.display();
    }
    else  if(Mode==1){
        display.clearDisplay();
        display.setTextSize(2);             // Normal 1:1 pixel scale
        display.setTextColor(WHITE);        // Draw white text
        display.setCursor(20,20);             // Start at top-left corner
        display.print(F("Drive Forward")); 
        display.display();
    }
    else  if(Mode==2){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Coin Collecting")); 
      display.display();

    }
    else  if(Mode==3){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Colour Detection")); 
      display.display();

    }
    else  if(Mode==4){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Slope Detection")); 
      display.display();
    }
    else  if(Mode==5){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Coin Releasing")); 
      display.display();
    }
    else  if(Mode==6){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Water Arm Down")); 
      display.display();
    }
    else  if(Mode==7){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Water Arm up")); 
      display.display();
    }
    else  if(Mode==8){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("line following")); 
      display.display();
    }
    else  if(Mode==9){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Turns")); 
      display.display();
    }
    else  if(Mode==10){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Water Transfer")); 
      display.display();
    }
    else  if(Mode==11){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("WallFollowingR")); 
      display.display();
    }
    else  if(Mode==12){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("WallFollowingL")); 
      display.display();
    }
    else  if(Mode==13){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Maze Solve")); 
      display.display();
    }
    else  if(Mode==14){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(0,0);             // Start at top-left corner
      display.print(F("Up to coin collecting")); 
      display.display();
    }
    else  if(Mode==15){
      display.clearDisplay();
      display.setTextSize(2);             // Normal 1:1 pixel scale
      display.setTextColor(WHITE);        // Draw white text
      display.setCursor(20,20);             // Start at top-left corner
      display.print(F("Water Collect")); 
      display.display();
    }

  }

  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(150);

  while(digitalRead(button3)){
    if(Mode==0){
      break;
    }
    else  if(Mode==7){                      //Coin Collect
      WaterArmUp();
          
      break;
    }
    else  if(Mode==9){                      //Coin Release
      turnR();
      while(digitalRead(button1)){}
      delay(500);
      turnL();
      while(digitalRead(button1)){}
      delay(500);
      turn180();

      break;

    }
    else  if(Mode==3){                      //Drive Forward
      detectcolour();
      break;

    }
    else if(Mode==4){                       //Colour Detection
      Kp=30;
      Kd=60;
      rspeed=240;
      lspeed=255;
      while(true){
        rampup = digitalRead(slopeup);
        rampdown = digitalRead(slopedown);
        if((rampup)&&(rampdown)){
          display.clearDisplay();
          display.setTextSize(2);             // Normal 1:1 pixel scale
          display.setTextColor(WHITE);        // Draw white text
          display.setCursor(20,20);             // Start at top-left corner
          display.print(F("flat")); 
          display.display();


        }
        else{
          if(rampdown){}
          else{
            display.clearDisplay();
            display.setTextSize(2);             // Normal 1:1 pixel scale
            display.setTextColor(WHITE);        // Draw white text
            display.setCursor(20,20);             // Start at top-left corner
            display.print(F("rampdown")); 
            display.display();
          }
          if(rampup){}
          else{
          display.clearDisplay();
          display.setTextSize(2);             // Normal 1:1 pixel scale
          display.setTextColor(WHITE);        // Draw white text
          display.setCursor(20,20);             // Start at top-left corner
          display.print(F("ramp up")); 
          display.display();
        }
        }
        
      }
      break;

    }
    else if(Mode==5){                       //Coin Arm Down
      CoinArmDown();
      drive_forward(512,540);
      delay(210);
      brake();
      delay(200);
      CoinArmUp();
      MagnetNormal();
      break;
      


    }
    else if(Mode==6){                       //Coin Arm Up
      WaterArmDown();
      break;
    }
    else if(Mode==1){                       //Turn 180
      drive_forward(500,540);
      while(true){
        measure();
        if(distanceF<100){
          brake();
          break;
        }
      }
      // MazeSolve();
      // delay(200);
      // watercollect();
      break;
    }
    else if(Mode==8){                       //line_following
      rightjunction=false;
      leftjunction=false;
      while(digitalRead(button3)){
        line_following();
      }
      brake();
      break;
    }
    else if(Mode==2){
      CoinArmDown();
      drive_forward(400,440);
      delay(1000);
      brake();
      CoinArmUp();
      MagnetRelease();
      // watercollect();
      // Kp=90;
      // Kd=200;
      // rspeed=290;
      // lspeed=325;
      // while(true){
      //   line_following();
      // }
      break;
      // time = millis();      
      // measure();
      // time=millis()-time;
      // Serial.print(time);
      // Serial.print(",  ");
      // Serial.print(distanceR);
      // Serial.print(",  ");
      // Serial.print(distanceF);
      // Serial.print(",  ");
      // Serial.print(distanceL);
      // Serial.println(",  ");
      // delay(100);
    }
    else if(Mode==10){                      //Magnet Release
      
      WaterArmDown();
      delay(100);
      digitalWrite(relaypump1,HIGH);
      digitalWrite(relaypump,HIGH);
      while(digitalRead(button1)){}
      delay(100);
      digitalWrite(relaypump1,LOW);
      digitalWrite(relaypump,LOW);
      delay(1000);
      WaterArmUp();
      delay(100);
      break;
      // time = millis();      
      // measure();
      // time=millis()-time;
      // Serial.print(time);
      // Serial.print(",  ");
      // Serial.print(distanceR);
      // Serial.print(",  ");
      // Serial.print(distanceF);
      // Serial.print(",  ");
      // Serial.print(distanceL);
      // Serial.println(",  ");
      // delay(50);
    }
    else if(Mode==11){                      //Wall Following Right
      while(true){
        wall_followingR();
        if(distanceF<150){
          break;
        }
        if(digitalRead(button3)){}
        else{
          break;
        }
      }
      brake();
      break;
    }
    else if(Mode==12){                      //Wall Following Left
      while(true){
        wall_followingL();
        if(distanceF<150){
          break;
        }
        if(digitalRead(button3)){}
        else{
          break;
        }
      }
      brake();
      break;
    }
    else if(Mode==13){                      //Maze Solve
      while(true){
        if(lineid){
          wall_following();
        }
        else{
          break;
        }
      }
      brake();
      while(true){
        line_following();
        measure();
        if(distanceF<100){
          brake();
          break;
        }
      }
      break;
    }
    else if(Mode==14){                      //Upto COin collecting
      digitalWrite(buzzer,HIGH);
      while ((analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range)){
        drive_forward(400,400);
      }
      digitalWrite(buzzer,LOW);
      countforward(200);
      leftjunction = false;
      rightjunction = false;
  
      while(true){     //Line following upto the coin collecting area
        line_following();
        junction();
        if(junctionflag){
          break;
        }
        delay(10);
      }
      rspeed=lspeed=300;
      while(true){
        line_following();
        coinarea = (((analogRead(S1)<white_range)||(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)||(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)||(analogRead(S5)>white_range)));
        if(coinarea){
          break;
        }
      }
      brake();
      digitalWrite(buzzer,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
      CoinArmDown();
      while(true){
        line_following();
        allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);
        if(allsensors){
          break;
        }
      }
      countforward(200);
      while(true){
        line_following();
        allsensors= (analogRead(S1)<white_range)&&(analogRead(S2)<white_range)&&(analogRead(S3)<white_range)&&(analogRead(S4)<white_range)&&(analogRead(S5)<white_range)&&(analogRead(S6)<white_range)&&(analogRead(S7)<white_range)&&(analogRead(S8)<white_range);
        if(allsensors){
          break;
        }
      }
      countforward(200);
      time = millis();
      while(true){
        line_following();
        if(millis()>time+600){
          break;
        }
      }
      brake();
      CoinArmUp();
      MagnetRelease();
      drive_forward(600,600);
      delay(100);
      brake();
      break;
    }
    else if(Mode==15){                      //coin releasing move
      Kp=90;
      Kd=250;
      rspeed=290;
      lspeed=325;
      while(true){
        line_following();
      }
      break;
    }  
    else{
      break;
    }
  }

  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  delay(150);

}








////////// comments in setup
// turnL();
  // delay(500);
  // turnR();
  // delay(500);


  // Sensor1.startContinuous(ContInterval);




  // countforward(300);
  // delay(200);
  // CoinArmDown();
  // delay(200);
  // countreverse(300);
  // delay(200);
  // CoinArmUp();
  // delay(200);
  // MagnetRelease();
  // delay(200);
  // for (uint16_t pulselen = coinservoup; pulselen > coinservomid; pulselen--) {
  // pwm.setPWM(coinarmservo, 0, pulselen);
  // } 
  // delay(500);
  // for (uint16_t pulselen = coinservomid; pulselen < coinservoup; pulselen++) {
  // pwm.setPWM(coinarmservo, 0, pulselen);
  // delay(5);
  // }
  // delay(50);
  // MagnetNormal();
  // delay(200);
  // detectcolour();
  // CoinArmRelease();
  // delay(200);
  // drive_forward(600,600);
  // delay(100);
  // brake();
  // CoinArmUp();
  // delay(200);
  // brake();



  // WaterArmDown();
  // delay(100);
  // digitalWrite(relaypump1,HIGH);
  // digitalWrite(relaypump,HIGH);
  // delay(2000);
  // digitalWrite(relaypump1,LOW);
  // digitalWrite(relaypump,LOW);

  


  // drive_forward(600,600);
  // delay(250);
  // brake();
  
  // while(true){
  //   line_following();
  // }
  // brake();
  // turnL();

  // while((true)){
  //   wall_following();
  //   if(distanceF<85){
  //     break;
  //   }
  //  // delay(50);
  // }
  // brake();
  // turnL();
  // countforward(150);
  // while((true)){
  // wall_following();
  // if(distanceF<100){
  //   break;
  // }
  //  // delay(50);
  // }
  // brake();

  // while(true){
  //   wall_following();
  //   if((distanceL>200)|(distanceR>200)){
  //     if(distanceR>200){
  //       drive_forward(200,200);
  //       delay(1600);
  //       brake();
  //       delay(5);
  //       turnR();
  //       drive_forward(200,200);
  //       delay(300);
  //     }
  //     else{
  //       drive_forward(200,200);
  //       delay(1600);
  //       brake();
  //       delay(5);
  //       turnL();
  //       drive_forward(200,200);
  //       delay(400);
  //   }

  //   }
  // }



  // turnL();

  // digitalWrite(buzzer,HIGH);


  // while(true){
  //   wall_followingR();
  //   detectjunction();
  //   if(junctionstate){
  //     digitalWrite(buzzer,HIGH);
  //     break;
  //     brake();
  //   }
  // }
  // brake();
  // delay(500);
  // digitalWrite(buzzer,LOW);
  // drive_forward(300,300);
  // while(distanceF>110){
  //   measure();
  // }
  // brake();
  // turnR();
  // digitalWrite(buzzer,HIGH);

  // while(true){
  //   wall_followingL();
  //   if(distanceR<100){
  //     break;
  //   }
  // }
  // digitalWrite(buzzer,LOW);
  // brake();
  // while(true){
  //   wall_followingL();
  //   detectjunction();
  //   if(junctionstate){
  //     digitalWrite(buzzer,HIGH);
  //     break;
  //     brake();
  //   }
  // }
  // digitalWrite(buzzer,LOW);
  // brake();


  
  // turnR();
  // digitalWrite(buzzer,HIGH);
  // while((distanceR>150)){
  //     wall_followingL();
  
  // }
  // digitalWrite(buzzer,LOW);
  // wlast_error=0;

  // if(distanceR<200){
  //   while(true){
  //       wall_followingR();
  //       detectjunction();
  //       if(junctionstate){
  //           break;
  //       }
        
  //   }
  //   wlast_error=0;

  //   }
  //   else if(distanceL<200){
  //       while(true){
  //          wall_followingL(); 
  //           detectjunction();
  //          if(junctionstate){
  //               break;
  //           }
            
  //       }
  //       wlast_error=0;

  //   }
  //   brake();



  //comments in loop


    // coinarea = (((analogRead(S1)<white_range)|(analogRead(S2)<white_range))&&((analogRead(S7)<white_range)|(analogRead(S8)<white_range))&&((analogRead(S4)>white_range)|(analogRead(S5)>white_range)));
  // if(coinarea){
  //   Serial.println("1");
  // }
  // else{
  //   Serial.println('0');
  // }
  // while(digitalRead(button1)){}
  // delay(500);
  // countforward(700);
  // brake();
  // delay(500);
  // turnR();
  // delay(500);
  // // wall_followingL();

  // while(digitalRead(button1)){}
  // delay(500);
  // countforward(700);
  // brake();  
  // delay(500);
  // turnL();
  // delay(500);
  // wall_followingL();

  // measure();
  // detectjunction();
  // if(junctionstate){
  //   Serial.println("1");
  // }
  // else{
  //   Serial.println('0');
  // }


  // wall_followingL();
  // if(distanceF<150){
  //   brake();
  //   while(digitalRead(button1)){}
  //   delay(500);
  // }
  





  // wall_following();
  // time = millis();
  // measure();
  // time=millis()-time;
  // Serial.print(time);
  // Serial.print(",  ");
  // Serial.print(distanceR);
  // Serial.print(",  ");
  // Serial.print(distanceF);
  // Serial.print(",  ");
  // Serial.print(distanceL);
  // Serial.println(",  ");
  // delay(50);

  
  // if (~digitalRead(button1)){
  //   turnR();
  // }
  // if()

  // while(Serial3.available()>0){
  //   Kd = Serial3.parseInt();
  //   Serial3.print("Kd = ");
  //   Serial3.println(Kd);
  // }
  // Mode= 0;
  // while(digitalRead(button2)){
  //   if(~digitalRead(button1)){
  //     Mode+=1;
    
  //     if(Mode==0){
  //       display.clearDisplay();
  //       display.setCursor(20,20);             // Start at top-left corner
  //       display.print(F("Select a Mode")); 
  //     }
  //     else if(Mode==1){
  //       display.clearDisplay();
  //       display.setCursor(20,20);             // Start at top-left corner
  //       display.print(F("Line Following")); 
  //     }
  //     else if(Mode==2){
  //       display.clearDisplay();
  //       display.setCursor(20,20);             // Start at top-left corner
  //       display.print(F("Wall Following")); 
  //     }
  //     else{
  //       Mode=0;
  //       display.clearDisplay();
  //       display.setCursor(20,20);             // Start at top-left corner
  //       display.print(F("Select a Mode")); 
  //     }
  //     delay(50);
  //   }
  // }
  // if(Mode==1){
  //     display.clearDisplay();
  //     display.setCursor(20,20);             // Start at top-left corner
  //     display.print(F("Select a Mode")); 
  // }



