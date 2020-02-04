// #include "global_space.h"
// #include "function_list.h"

void line_following(){
      n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

      if (analogRead(S1)< white_range) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)< white_range) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)< white_range) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)< white_range) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)< white_range) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)< white_range) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)< white_range) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)< white_range) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            digitalWrite(rm1, HIGH);
            digitalWrite(rm2,LOW);
            digitalWrite(lm1, HIGH);
            digitalWrite(lm2,LOW);
            error = sum/n;
            adj = Kp*error + Kd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>900){
                  Rspeed = 900;
            }
            if (Lspeed>900){
                  Lspeed = 900;
            }
            if (Rspeed<0){
                  digitalWrite(rm2,HIGH);
                  digitalWrite(rm1,LOW);
                  Rspeed = - Rspeed;
            }
            if (Lspeed<0){
                  digitalWrite(lm2,HIGH);
                  digitalWrite(lm1,LOW);
                  Lspeed = - Lspeed;
            }
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
      }
      else{
            brake();
      }
      //       if(lineout==-1){
      //             analogWrite(Lpwm, 200);
      //             analogWrite(Rpwm, 600);
      //             while((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)){}
      //             brake();
      //       }
      //       else if(lineout==1){
      //             analogWrite(Rpwm, 200);
      //             analogWrite(Lpwm, 600);
      //             while((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)){}
      //             brake();
      //       }
      //       else{
      //             brake();
      //             stop=true;
      //       }
      //       rightjunction=false;
      //       leftjunction=false;
      // }
}
void curve_line_following(){
      n=0,sum=0,Rspeed=rspeed,Lspeed=lspeed;

      if (analogRead(S1)< white_range) {
            n++;
            sum-=w4;
            lineout=-1;            
      }
      if (analogRead(S2)< white_range) {
            n++;
            sum-=w3;   
            lineout=-1;            
      }
      if (analogRead(S3)< white_range) {
            n++;
            sum-=w2;   
            lineout=-1;            
      }
      if (analogRead(S6)< white_range) {
            n++;
            lineout=1;            
            sum+=w2;            
      }
      if (analogRead(S7)< white_range) {
            n++;
            lineout=1;            
            sum+=w3;            
      }
      if (analogRead(S8)< white_range) {
            n++;
            lineout=1;            
            sum+=w4;            
      }
      if (analogRead(S4)< white_range) {
            n++;
            lineout=0;            
            sum-=w1;            
      }
      if (analogRead(S5)< white_range) {
            n++;
            lineout=0;            
            sum+=w1;            
      }
      if(n!=0){
            digitalWrite(rm1, HIGH);
            digitalWrite(rm2,LOW);
            digitalWrite(lm1, HIGH);
            digitalWrite(lm2,LOW);
            error = sum/n;
            adj = Kp*error + Kd*(error-last_error);
            last_error = error;
            if (adj>0) {      
                  Lspeed += adj/w6;
                  Rspeed -= adj/w5;
            }
            else{
                  Rspeed -= adj/w6;
                  Lspeed += adj/w5;
            }
            if (Rspeed>900){
                  Rspeed = 900;
            }
            if (Lspeed>900){
                  Lspeed = 900;
            }
            if (Rspeed<0){
                  digitalWrite(rm2,HIGH);
                  digitalWrite(rm1,LOW);
                  Rspeed = - Rspeed;
            }
            if (Lspeed<0){
                  digitalWrite(lm2,HIGH);
                  digitalWrite(lm1,LOW);
                  Lspeed = - Lspeed;
            }
            analogWrite(Rpwm, Rspeed);
            analogWrite(Lpwm, Lspeed);
      }
      else{
      }
      //       if(lineout==-1){
      //             analogWrite(Lpwm, 200);
      //             analogWrite(Rpwm, 600);
      //             while((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)){}
      //             brake();
      //       }
      //       else if(lineout==1){
      //             analogWrite(Rpwm, 200);
      //             analogWrite(Lpwm, 600);
      //             while((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)){}
      //             brake();
      //       }
      //       else{
      //             brake();
      //             stop=true;
      //       }
      //       rightjunction=false;
      //       leftjunction=false;
      // }
}

void junction(){
      // if((analogRead(S1)>white_range)&&(analogRead(S2)>white_range)&&(analogRead(S7)>white_range)&&(analogRead(S8)>white_range)&&(analogRead(S4)>white_range)&&(analogRead(S5)>white_range)){}
      if(false){}
      else{
            if(rightjunction){
                  digitalWrite(buzzer,HIGH);
                  brake();
                  delay(50);
                  digitalWrite(buzzer,LOW);
                  countforward(200);
                  turnR();
                  junctionflag = true;
            }
            else if (leftjunction){
                  digitalWrite(buzzer,HIGH);
                  brake();
                  delay(50);
                  digitalWrite(buzzer,LOW);
                  countforward(200);
                  turnL();
                  junctionflag = true;
            }
      } 
      rightjunction=false;
      leftjunction=false;  
}

void ramplinefollowing(){
      while(digitalRead(slopeup)){        //approaching to ramp
            line_following();
      }
      rspeed=rampspeed;                   //speed reduction                              
      lspeed=rampspeed;                   //climbing up and moving along the ramp
      bool ramp = digitalRead(slopeup);
      while(~ramp){            //rampspeed++ until it goes up
            line_following();
            ramp = digitalRead(slopeup);
      }
      while(~digitalRead(slopedown)){    //ramp down       
            line_following();
            passivebrake();
            delay(50);
      }

}