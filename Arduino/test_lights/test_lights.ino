/*
  Example for different sending methods
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

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
  Serial.println("Hello Pi");
  if (Serial.available())
  {
     flash(Serial.read() - '0');
  }
  delay(1000);
}

void flash(int n)
{
  for (int i = 0; i < n; i++)
  {
    mySwitch.send(13456653, 24);
    delay(1000);
    mySwitch.send(13456653, 24);
    delay(1000);    
  }
}
