#define XSHUT_pin1 31           //Right Sensor
#define XSHUT_pin2 33           //Left Sensor
#define XSHUT_pin3 35           //Front Sensor    


#define Sensor1_newAddress 42
#define Sensor2_newAddress 43
#define Sensor3_newAddress 44

#define SignalRateLimit 0.8          //Higher the limit , higher the accuracy
#define MeasurementBudget 60000      //Higher the time , higher the accuracy
#define Timeout 200
#define ContInterval 40 //inter-measurement period in milliseconds determining how often the sensor takes a measurement.


VL53L0X Sensor1;      //Right Sensor
VL53L0X Sensor2;      //Left Sensor
VL53L0X Sensor3;      //Front Sensor



void tofSetup(){ /*WARNING*/
  //Shutdown pins of VL53L0X ACTIVE-LOW-ONLY NO TOLERANT TO 5V will fry them
  pinMode(XSHUT_pin1, OUTPUT);
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(XSHUT_pin3, OUTPUT);

  pinMode(XSHUT_pin3,INPUT);
  delay(10);
  Sensor3.setAddress(Sensor3_newAddress);
  
  pinMode(XSHUT_pin2,INPUT);
  delay(10);
  Sensor2.setAddress(Sensor2_newAddress);
  
  pinMode(XSHUT_pin1, INPUT);
  delay(10);
  Sensor1.setAddress(Sensor1_newAddress);
 
  if(Sensor1.init()){
    Serial.println("Sensor 1 : Configured");
  }
  else
  {
    Serial.println("Sensor 1 : Configuration Failed");
  }
  if(Sensor2.init()){
    Serial.println("Sensor 2 : Configured");
  }
  else
  {
    Serial.println("Sensor 2 : Configuration Failed");
  }
    if(Sensor3.init()){
    Serial.println("Sensor 3 : Configured");
  }
  else
  {
    Serial.println("Sensor 3 : Configuration Failed");
  }
  
  Sensor1.setSignalRateLimit(0.8);
  Sensor2.setSignalRateLimit(0.9);
  Sensor3.setSignalRateLimit(0.9);

  Sensor1.setMeasurementTimingBudget(MeasurementBudget);
  Sensor2.setMeasurementTimingBudget(MeasurementBudget);
  Sensor3.setMeasurementTimingBudget(MeasurementBudget);

  Sensor1.setTimeout(Timeout);
  Sensor2.setTimeout(Timeout);
  Sensor3.setTimeout(Timeout);

 Sensor1.startContinuous();
 Sensor2.startContinuous();
 Sensor3.startContinuous();
}

void getTOFReading(){
  Serial.print(Sensor1.readRangeSingleMillimeters());
  Serial.print(",  ");
  Serial.print(Sensor2.readRangeSingleMillimeters());
  Serial.print(",  ");
  Serial.print(Sensor3.readRangeSingleMillimeters());
  Serial.println(",  ");
  delay(50);
}

void measure(){
  distanceR = Sensor1.readRangeContinuousMillimeters()-80;
  distanceL = Sensor2.readRangeContinuousMillimeters()-17;
  distanceF = Sensor3.readRangeContinuousMillimeters()-20;

}

void measuresingle(){
  distanceR = Sensor1.readRangeSingleMillimeters();
  distanceL = Sensor2.readRangeSingleMillimeters();
  distanceF = Sensor3.readRangeSingleMillimeters();
}



