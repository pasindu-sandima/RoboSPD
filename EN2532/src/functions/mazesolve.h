void wall_followingR(){
    werror = distanceR-70;
    wadj = wKp*werror + wKd*(werror-wlast_error);
    wlast_error = werror;
    Rspeed = wrspeed;
    Lspeed = wlspeed;
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2,LOW);
    // Lspeed+=wadj;
    // Rspeed-=wadj/2;
    if (wadj>0) {      
            Lspeed += wadj;
            Rspeed -= wadj/2;
    }
    else{
            Rspeed -= wadj;
            Lspeed += wadj/2;
    }
    if (Rspeed>600){
            Rspeed = 600;
    }
    if (Lspeed>600){
            Lspeed = 600;
    }
    if (Rspeed<200){
            Rspeed =200;
    }
    if (Lspeed<200){
            Lspeed = 200;
    }
    analogWrite(Rpwm, Rspeed);
    analogWrite(Lpwm, Lspeed);
    // if ((distanceF>100)&&(distanceF<300)){
    // Rspeed *= (distanceF-100)/10;                //check the accuracy of the reading ====> distanceF
    // Lspeed *= (distanceF-100)/10;                //to slow down the robot when its closer to a wall and to go faster when its not
    // }
    // drive_forward(Rspeed,Lspeed);
    measure();
}
void wall_followingL(){
    werror = distanceL-70;
    wadj = wKp*werror + wKd*(werror-wlast_error);
    wlast_error = werror;
    Rspeed = wrspeed;
    Lspeed = wlspeed;
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2,LOW);
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2,LOW);
    // Lspeed+=wadj;
    // Rspeed-=wadj/2;
    if (wadj>0) {      
            Rspeed += wadj;
            Lspeed -= wadj/2;
    }
    else{
            Lspeed -= wadj;
            Rspeed += wadj/2;
    }
    if (Rspeed>600){
            Rspeed = 600;
    }
    if (Lspeed>600){
            Lspeed = 600;
    }
    if (Rspeed<200){
            Rspeed =200;
    }
    if (Lspeed<200){
            Lspeed = 200;
    }
    analogWrite(Rpwm, Rspeed);
    analogWrite(Lpwm, Lspeed);
    // if ((distanceF>100)&&(distanceF<300)){
    // Rspeed *= (distanceF-100)/10;                //check the accuracy of the reading ====> distanceF
    // Lspeed *= (distanceF-100)/10;                //to slow down the robot when its closer to a wall and to go faster when its not
    // }
    // drive_forward(Rspeed,Lspeed);
    measure();
}

void detectjunction(){
    if ((distanceF<110)||(distanceL>170)||(distanceR>170)){
        junctionstate=true;
    }
    else{
        junctionstate = false;
    }

}

void junctiontype(){
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    if((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S3)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)&&(analogRead(S6)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)){
        if(distanceF<400){
            drive_forward(290,300);
            while(distanceF>75){
                measure();
            }
            brake();
            delay(500);
            if(distanceR>200){
                turnR();
                delay(200);
                digitalWrite(buzzer,HIGH);
                time = millis();
                while(true){
                    wall_followingL();
                    if(distanceR<100){
                        break;
                    }
                    if(distanceF<240){
                        break;
                    }
                }
                brake();
                rightfollow = false;
                digitalWrite(buzzer,LOW);
            }
            else if(distanceL>200){
                turnL();
                delay(200);
                digitalWrite(buzzer,HIGH);
                while(true){
                    wall_followingR();
                    if(distanceL<200){
                        break;
                    }
                    if(distanceF<240){
                        break;
                    }
                }
                brake();
                rightfollow=true;
                digitalWrite(buzzer,LOW);
            }
            else{
                measure();
                if(distanceR<distanceL){
                    digitalWrite(buzzer,HIGH);
                    delay(300);
                    digitalWrite(buzzer,LOW);
                    turnL();
                    delay(200);
                    countreverse(150);
                    delay(200);
                    turnL();
                    delay(200);
                }
                else{
                    digitalWrite(buzzer,HIGH);
                    delay(300);
                    digitalWrite(buzzer,LOW);
                    turnR();
                    delay(200);
                    countreverse(50);
                    delay(200);
                    turnR();
                    delay(200);
                }

            }
        }
        else{
            countforward(200);
            measure();
            if(distanceR>170){
                countforward(800);
                brake();
                delay(500);
                turnR();
                delay(300);
                countforward(400);
                brake();
                delay(200);
            }
            else{
                digitalWrite(buzzer,HIGH);
                while(true){
                    wall_followingR();
                    if(distanceL<200){
                        break;
                    }
                }
                digitalWrite(buzzer,LOW);
                rightfollow=true;
                brake();
                delay(200);
                
            }
        }
    }
    else{
        lineid=false;
    }
}

void wall_following(){
    if(rightfollow){
        while(true){
            wall_followingR();
            detectjunction();
           if(junctionstate){
               break;
            }
            
        }
        wlast_error=0;

    }
    else{
        while(true){
           wall_followingL(); 
            detectjunction();
           if(junctionstate){
                break;
            }
            
        }
        wlast_error=0;

    }
    brake();
    junctiontype();
}

void MazeSolve(){
    while(true){
        if(lineid){
          wall_following();
        }
        else{
          break;
        }
      }
      brake();
}