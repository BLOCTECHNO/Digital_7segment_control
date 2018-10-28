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

   to be able to display the time on the 7 segment you will need a module rtc and ca librarie
after it will be necessary to assign to the variable hour, the time which was given to you by the module
rtc does the same thing for minute

*/

#include "segment.h"
Segment m; //Create new instance

String saisie; // variable to read value on serial monitor
int saisie_convert; // variable to convert string to int

int hour = 12;
int minute = 54;

void setup()
{
  //m.initial()  fonction allow your to define pin you using to initial in output
  //he have 2 syntax available
  //m.initial(); default connection
  //m.initial(4,3,2,6,5); use the pin of your choice

  m.Initial(4,3,2,6,5);
  Serial.begin(9600);
}

void loop()
{
  m.clear_All(); // turn off 7segment

  //this condition is for Hour
  for (int i=0; i<100; i++)
    {
      m.screen(hour); // print 12 H
    }

  //this condition is for minute
  for (int i=0; i<100; i++)
    {
      m.screen(minutes);
      m.screenPoint(2); // this fonction allow you to turn on segment point
    }
}
