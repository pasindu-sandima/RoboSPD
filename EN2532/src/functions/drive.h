
void drive_forward(int rSpeed,int lSpeed){
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2,LOW);
      analogWrite(Rpwm, rSpeed);
      analogWrite(Lpwm, lSpeed);
}
void drive_reverse(int rSpeed,int lSpeed){
      digitalWrite(rm1, LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1, LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm, rSpeed);
      analogWrite(Lpwm, lSpeed);
}
void accelarate(int r){
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2,LOW);
      for(int acc=100;acc<r;acc++){
            analogWrite(Rpwm, acc);
            analogWrite(Lpwm, acc);
            delay(1);

      }
}

void brake(){
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,HIGH);
      digitalWrite(Rpwm,HIGH);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,HIGH);
      digitalWrite(Lpwm,HIGH);
}
void passivebrake(){
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(Rpwm,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(Lpwm,LOW);
}
void turnL(){
      phasecount=0;
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm,390);
      analogWrite(Lpwm,400);
      while(phasecount<16){
            countright=0;
            while(countright<49){}
            phasecount++;
      }  
      brake();
      leftjunction=false;
      rightjunction=false;
      detachInterrupt(digitalPinToInterrupt(3));
}
void turnR(){
      phasecount=0;
      countleft=0;
      attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoder
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      analogWrite(Rpwm,390);
      analogWrite(Lpwm,400);
      while(phasecount<15){
            countleft=0;
            while(countleft<50){}
            phasecount++;
      }
      brake();
      leftjunction=false;
      rightjunction=false;
      detachInterrupt(digitalPinToInterrupt(2));
}
void turnlineL(){
      phasecount=0;
      countright=0;
      countleft=0;
      attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoder
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm,0);
      analogWrite(Lpwm,400);
      while(phasecount<16){
            countleft=0;
            while(countleft<100){}
            phasecount++;
      }
      brake();
      while(digitalRead(button1)){}
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      phasecount=0;
      countright=0;
      countleft=0;  
      analogWrite(Rpwm,400);
      analogWrite(Lpwm,0);
      while(phasecount<16){
            countright=0;
            while(countright<100){}
            phasecount++;
      } 
      brake();
      leftjunction=false;
      rightjunction=false;
      detachInterrupt(digitalPinToInterrupt(2));
      detachInterrupt(digitalPinToInterrupt(3));
}
void turnlineR(){
      phasecount=0;
      countleft=0;
      attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoder
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      analogWrite(Rpwm,450);
      analogWrite(Lpwm,400);
      while(phasecount<15){
            countleft=0;
            while(countleft<48){}
            phasecount++;
      }
      brake();
      leftjunction=false;
      rightjunction=false;
      detachInterrupt(digitalPinToInterrupt(2));
}
void turnR45(){
      countleft=0;
      attachInterrupt(digitalPinToInterrupt(2),leftcount,CHANGE); //encoders
      lcount = countleft+350;
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      analogWrite(Rpwm,500);
      analogWrite(Lpwm,500);
      while(lcount>countleft){
      }
      brake();
      detachInterrupt(digitalPinToInterrupt(2));

}
void turnL45(){
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoders
      rcount = countright+350;
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm,500);
      analogWrite(Lpwm,500);
      while(rcount>countright){
      }  
      brake();
      detachInterrupt(digitalPinToInterrupt(3));
}
void turn180(){
      phasecount=0;
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoder
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm,390);
      analogWrite(Lpwm,400);
      while(phasecount<34){
            countright=0;
            while(countright<49){}
            phasecount++;
      }  
      brake();
      leftjunction=false;
      rightjunction=false;
      detachInterrupt(digitalPinToInterrupt(3));
}
void countforward(int count){
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoders
      rcount = countright+count;
      condition = true;
      digitalWrite(rm1,HIGH);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,HIGH);
      digitalWrite(lm2,LOW);
      analogWrite(Rpwm,295);
      analogWrite(Lpwm,310);
      while(condition){
          if (rcount<countright) {
              condition=false;
          }  
      }
      brake();
      detachInterrupt(digitalPinToInterrupt(3));

}
void countreverse(int count){
      countright=0;
      attachInterrupt(digitalPinToInterrupt(3),rightcount,CHANGE); //encoders
      rcount = countright+count;
      condition = true;
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      analogWrite(Rpwm,rspeed);
      analogWrite(Lpwm,lspeed);
      while(condition){
          if (rcount<countright) {
              condition=false;
          }  
      }
      brake();
      detachInterrupt(digitalPinToInterrupt(3));
}