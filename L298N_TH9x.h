 /*
 * Motor 1 = in1, in2; en1 = spdpin1
 * Motor 2 = in3, in4; en2 = spdpin2
 * Motor 3 = in5, in6; en3 = spdpin3
 * Motor 4 = in7, in8; en4 = spdpin4
 * 
 * Initial spd is set to 115
 * 
 */

#ifndef L298N_TH9x_H
#define L298N_TH9x_H

#include <IBusBM.h>
#include <Arduino.h>

class mecanumTh9x
{
  private:

  #define in1 7                      //Motor1 L298N full bridge
  #define in2 4                      //Motor1 L298N full bridge
  #define in3 8                      //Motor2 L298N full bridge
  #define in4 9                      //Motor2 L298N full bridge
  /*
  #define in5 A1                      //Motor3 L298N full bridge
  #define in6 A0                      //Motor3 L298N full bridge
  #define in7 3                       //Motor4 L298N full bridge
  #define in8 5                       //Motor4 L298N full bridge
  */
  #define spdpin1 5                   //pulse with moudulation ENA_1 and ENB_1 L298N full bridge
  #define spdpin2 6                   //pulse with moudulation ENA_2 and ENB_2 L298N full bridge
 
  public:

  volatile float Speed;
  
  inline mecanumTh9x() __attribute__((always_inline));
  inline void Stp() __attribute__((always_inline));
  inline void front() __attribute__((always_inline));
  inline void back() __attribute__((always_inline));
  inline void leftTurn() __attribute__((always_inline));
  inline void rightTurn() __attribute__((always_inline));
  /*
  inline void rightShift() __attribute__((always_inline));
  inline void leftShift() __attribute__((always_inline));
  inline void leftDiagonalFront() __attribute__((always_inline));
  inline void rightDiagonalBack() __attribute__((always_inline));
  inline void leftDiagonalBack() __attribute__((always_inline));
  inline void rightBackPivot() __attribute__((always_inline));
  inline void leftBackPivot() __attribute__((always_inline));
  */

};

  mecanumTh9x::mecanumTh9x()
  {
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    /*
    pinMode(in5,OUTPUT);
    pinMode(in6,OUTPUT);
    pinMode(in7,OUTPUT);
    pinMode(in8,OUTPUT);
    */
    pinMode(spdpin1,OUTPUT);
    pinMode(spdpin2,OUTPUT);

    this->Speed = 0;
  }
  
  
  void mecanumTh9x::Stp()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    /*
    digitalWrite(in5,LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    */
  }

  void mecanumTh9x::front()
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    /*
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    */
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::back()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    /*
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    */
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::leftTurn()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    /*
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    */
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::rightTurn()
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    /*
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    */
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }
  /*
  void mecanumTh9x::rightShift()
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::leftShift()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }
  void mecanumTh9x::leftDiagonalFront()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::rightDiagonalBack()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::leftDiagonalBack()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,LOW);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::rightBackPivot()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    digitalWrite(in7,HIGH);
    digitalWrite(in8,LOW);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }

  void mecanumTh9x::leftBackPivot()
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    digitalWrite(in7,LOW);
    digitalWrite(in8,HIGH);
    analogWrite(spdpin1,Speed);
    analogWrite(spdpin2,Speed);
  }
  */
#endif
