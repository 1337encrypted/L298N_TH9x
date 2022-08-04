#include <IBusBM.h>
#include "L298N_TH9x.h"

IBusBM ibus;                          // Create iBus Object
mecanumTh9x car;                      // Create mecanumTh9x Object

  volatile int CH0=0;                 // Leftshift - Rightshift
  volatile int spd=0;                 // Speed (Acceleration)
  volatile int CH2=0;                 // Forward - Reverse
  volatile int CH3=0;                 // leftTurn - rightTurn 
  volatile int CH5=0;                 //Switch mode
  
void setup()
{
    
    Serial.begin(115200);             // Start serial monitor for debugging
    ibus.begin(Serial);               // Attach iBus object to serial port
    car.Stp();

}

//Function to read the channel value
  int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue)
  {
    uint16_t ch = ibus.readChannel(channelInput);
    if (ch < 100) return defaultValue;
    return constrain(map(ch, 1000, 2000, minLimit, maxLimit), minLimit, maxLimit);
    //return map(ch, 1000, 2000, minLimit, maxLimit);
  }

  //Function to read the switch value
  bool readSwitch(byte channelInput, bool defaultValue)
  {
   int intDefaultValue = (defaultValue) ? 100 : 0;
   int ch = readChannel(channelInput, 0, 100, intDefaultValue);
   return (ch > 50);
  }

void loop()
{
  // Get RC channel values
  CH0 = readChannel(0, -255, 255, 0);         // Leftshift - Rightshift
  spd = readChannel(1, 0, 255, 0);           // Speed (Acceleration)
  CH2 = readChannel(2, -255, 255, 0);         // Forward - Reverse
  CH3 = readChannel(3, -255, 255, 0);         // LeftTurn - RightTurn 
  CH5 = readSwitch(5, false);                 // CH5 Switch mode

  if(CH2 > 10)
  {
    car.Speed = (float)(spd*CH2)/255;
    car.front();
  }
  else if(CH2 < -10)
  {
    car.Speed = abs((float)(spd*CH2)/255);
    //car.Speed = abs(spd);
    car.back();
  }
  /*
  else if(CH0 > 10)
  {
    car.Speed = (float)(spd*CH0)/255;
    car.rightShift();
  }
  else if(CH0 < -10)
  {
    car.Speed = abs((float)(spd*CH0)/255);
    //car.Speed = abs(spd);
    car.leftShift();
  }
  */
  if(CH3 > 10 && CH5 == 0)
  {
    car.Speed = (float)(spd*CH3)/255;
    car.rightTurn();
  }
  else if(CH3 < -10 && CH5 == 0)
  {
    car.Speed = abs((float)(spd*CH3)/255);
    //car.Speed = abs(spd);
    car.leftTurn();
  }
  /*
  if(CH3 > 0 && CH5)
  {
    car.Speed = (float)(spd*CH3)/255;
    car.rightBackPivot();
  }
  else if(CH2 < -10)
  {
    car.Speed = abs((float)(spd*CH3)/255);
    //spd = abs(spd);
    car.leftBackPivot();
  }
  */
  else
  {
    car.Stp();
  }
}
