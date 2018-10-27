/*
using 7segement to display on value this library allow you to control 1 digital to 4 digital 7segment
by BlocTechno <contact@bloctechno.ovh>

on this exemple you can display a number you can entrie on serial monitor

   defautl pin waring

      latchPin -> 4
      clockPin -> 3
      dataPin  -> 2
      segment1 -> 6
      segment2 -> 5

*/

#include "segment.h"
Segment m; //Create new instance

String saisie; // variable to read value on serial monitor
int saisie_convert; // variable to convert string to int


void setup()
{
  //m.initial is fonction to allow your to define pin you using et initial in output
  //he have 2 syntax available
  //m.initial(); using defautl pin waring
  //m.initial(4,3,2,6,5); using your pin your have choice
  m.nSegment();
  m.initial(4,3,2,6,5);
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
