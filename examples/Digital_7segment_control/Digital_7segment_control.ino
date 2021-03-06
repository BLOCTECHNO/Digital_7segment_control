/*
using 2digitals 7segement to display on value this library allow you to control 2 digital 7segment
by BlocTechno <contact@bloctechno.ovh>

on this exemple you can display a number you can entrie on serial monitor

   default connection

   (74hc595n) latchPin -> 4 (arduino)
   (74hc595n) clockPin -> 3 (arduino)
   (74hc595n) dataPin  -> 2 (arduino)
   (74hc595n) segment1 -> 6 (arduino)
   (74hc595n) segment2 -> 5 (arduino)

*/

#include "segment.h"
Segment m; //Create new instance

String saisie; // variable to read value on serial monitor
int saisie_convert; // variable to convert string to int


void setup()
{
  //m.initial()  fonction allow your to define pin you using to initial in output
  //he have 2 syntax available
  //m.initial(); default connection
  //m.initial(4,3,2,6,5); use the pin of your choice

  m.Initial(4,3,2,6,5);
  Serial.begin(9600);
  while (! Serial); // serial communication
  Serial.println("ready send value 0 and 9");
}

void loop()
{
  m.clear_All(); // turn off 7segment

  if (Serial.available()) // check if serial monitor is ready
  {
    saisie = Serial.readString();
    saisie_convert = saisie.toInt(); // convert string to int
    for (int i=0; i<100; i++) //time to display value on 7segment
    {
      m.screen(saisie_convert); // function to display value
    }

  }
}
