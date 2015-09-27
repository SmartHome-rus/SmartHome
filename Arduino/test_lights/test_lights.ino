#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

class device   // includes lights and outlets
{
 public:
 int deviceStatus; //1 or 0 - contains current device status
 int deviceCodeOn; //8 digit unique code like 13456653 for switching device ON
 int deviceCodeOff; //8 digit unique code like 13456653 for switching device OFF
 
 
 int action(int code) //executes action based on device status (last digit in code)
   {
     switch (code) { //switch case will act based on status 0,1,2
    case 0:    // switch outlet off
      switchOFF();
      break;
    case 1:    // switch outlet on
      switchON();
      break;
    case 2:    // your hand is a few inches from the sensor
      switchON(); //for lamps only. will work as on/off.
      break;
     }
   }
 
 void switchON() //sends switch on code to device
   {
     mySwitch.send(deviceCodeOn, 24);
  } 
 
 void switchOFF() //sends switch off code to device
   {
     mySwitch.send(deviceCodeOff, 24);
   }
}; 

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);

  // Optional set pulse length.
  mySwitch.setPulseLength(180);
  
  // Optional set protocol (default is 1, will work for most outlets)
  // 
  //mySwitch.setProtocol(3);
  
  // Optional set number of transmission repetitions.
  //mySwitch.setRepeatTransmit(15);
  
}

void loop()
{
  if (Serial.available())
  {
      String n = Serial.read();
      codeSplit(n);
      delay(1000);
  }
}

void codeSplit(String n)
{
  
    mySwitch.send(13456653, 24);
  
  //for (int i = 0; i < n; i++)
  //{
  //  mySwitch.send(13456653, 24);
  //  delay(1000);
  //  mySwitch.send(13456653, 24);
  //  delay(1000);
 //}
}
