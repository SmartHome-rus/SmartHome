#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

class device   // includes lights and outlets
{
 public:
 int deviceMode; //send or recieve. Send = 1; Recieve = 2
 int deviceType; //type of the device. Lamp = 1; Power Outlet = 2; Sensor = 3
 int deviceRoom; //# of room where device is located
 int deviceNumber; //2-digit code that contains device number (how many outlets/lamps you have)
 int deviceSendCommand; //what should we send to device 0 - off; 1 - on; 2 - on/off for lamp
 int deviceStatus; //1 or 0 - contains current device status
 unsigned long deviceCodeOn = 13456653; //8 digit unique code like 13456653 for switching device ON
 unsigned long deviceCodeOff = 13456653; //8 digit unique code like 13456653 for switching device OFF
 
 
 void codeRead() //reading 6 digit code from Raspberry and translating it into variables
{
  int n = 0; //will use this variable to read from Raspberry
  int tempDeviceNumber_1; //two integers to read the 2-digit code of device number. Will be afterwards translated in 1 int
  int tempDeviceNumber_2;
  for (int y=0; y<6; y++) //runing loop until we read every number in recieving code
    {
      n = Serial.read(); //reding from serial port
      Serial.write(n); //for debugging 
      switch (y) { //will be assigning current n to different variables based on the position in the code: 1 - device_type, 2 - device room, etc.
    case 0:    // reading deviceMode
      deviceMode = n;
      break;
    case 1:    // reading deviceType
      deviceType = n;
      break;
    case 2:    // reading device Room
      deviceRoom = n; 
      break;
    case 3:    // reading deviceNumber first digit. We will calculate it afterwards
      tempDeviceNumber_1 = n;
      break;
    case 4:    // reading deviceNumber second digit
      tempDeviceNumber_2 = n;
      break;
    case 5:    // reading deviceSendCommand
      deviceSendCommand = n;
      break;
     }
     delay(500);
    }
   deviceNumber = tempDeviceNumber_1*10 + tempDeviceNumber_2;
   switchON(); 
}
 void action(int code) //executes action based on device status (last digit in code)
   {
     switch (code) { //checking deviceSendStatus variable to send right command to device
    case 0:    // switch outlet off
      switchOFF();
      break;
    case 1:    // switch outlet on
      switchON();
      break;
    case 2:    
      switchON(); //for lamps only. will work as on/off.
      break;
     }
   }
private: 
 void switchON() //sends switch on code to device
   {
     mySwitch.send(deviceCodeOn, 24);
  } 
 
 void switchOFF() //sends switch off code to device
   {
     mySwitch.send(deviceCodeOff, 24);
   }
}; 

device lamp; //creating object Lamp from class device
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
  if (Serial.available()) //checking if serail port is avaliable
  {
   lamp.codeRead(); //reading the code from Python and splitting to variables
   lamp.action(lamp.deviceSendCommand); //acting based on the code
  }
}


