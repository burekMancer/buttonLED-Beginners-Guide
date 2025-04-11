#include <Arduino.h> //Including Arduino library for basic functions

//Defining the pin nums for the button and LED
const int button = 3; 
const int LED = 2;

void setup()
{
  pinMode(button, INPUT); //the button pin is set as an imput to read its state
  pinMode(LED, OUTPUT); //the LED pin is set as an output to control the LED
}

void loop()
{
  int buttonValue = digitalRead(button); //This is to read the buttons state(HIGH or LOW)
//IF the button is pressed (HIGH), turn on the LED
  if (buttonValue != 0)
  {digitalWrite(LED, HIGH);}//Turns the LED on

  else//ELSE if the button is not pressed (LOW), turn off the LED
  {digitalWrite(LED, LOW);} //Turns the LED off
}