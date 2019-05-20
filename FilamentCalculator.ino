  //Loadcell lib
#include "HX711.h"

//LCD lib
#include <LiquidCrystal.h>  //lcd lib

//Timer lib
#include "timer.h"

//Other Tabs
#include "FilamentCalculator_A_Variables.h"
#include "FilamentCalculator_B_MenuVariables.h"
#include "FilamentCalculator_C_MenuWalkthrough.h"
#include "FilamentCalculator_D_RotaryEncoderScroll.h"
#include "FilamentCalculator_E_RotaryEncoderClick.h"
#include "FilamentCalculator_F_Timer.h"

int xa = 1;

void setup() 
{
  
  //Rotary Encoder input
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (0, OUTPUT);

  //Set up the LCD's pins, number of columns and rows:
  lcd.begin(16, 2); 

  //Screen toggle output
  pinMode(PinBacklight, OUTPUT);

  /*
   * Approximate correct calibration scale : -824028.25
   * Parameters used for testing
   * Transparent spool epmty: 230g.
   * Transparent spool pla black 750g full: 990g.
   */

  //Calibration Factor
  scale.set_scale(CalibrationFactor);

  //Reset the scale to 0
  scale.tare();

    //turn on screen
    digitalWrite(PinBacklight, HIGH);

  //for looping through longer string
  timer.every(500, FilamentCalculator_Timer);

  //timeout function. Set timeout duration in MenuVariables
  timeout.every(1000, FilamentCalculator_Timeout);

  //startup sound
  tone(9, 300);
  delay(100);
  tone(9, 400);
  delay(100);
  tone(9, 500);
  delay(100);
  tone(9, 600);
  delay(100);
  tone(9, 700);
  delay(200);
  noTone(9);
  }

void loop() 
{
  if(TimerStart){timeout.tick();}
  //Read rotary encoder input
  PinA = digitalRead(A0);
  PinB = digitalRead(A1);
  PinC = digitalRead(A2);

  //Scroll Actions
  FilamentCalculator_RotaryEncoderScroll();

  //Click Actions
  FilamentCalculator_RotaryEncoderClick();
  
  //Screen Output
  FilamentCalculator_MenuWalkthrough();
}
