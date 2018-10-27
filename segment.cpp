#include <Arduino.h>
#include "segment.h"

/*-------------------------------------------------------------------------------------------------*/
// this funciton allow you to turn off all 7segment digital
void Segment::clear_All()
{
  leds = 0; // turn off all 7segments
  updateShiftRegister(); // update shift to apply
  delay(2);
}

/*-------------------------------------------------------------------------------------------------*/

/* function that allows you to tell which pin you use to configure the 74hc595n
to control both segment you need to give the latch, data, clock pin and tracking
segment1 and segment2
by default the pin is configured as
default connection

  (74hc595n) latchPin -> 4 (arduino)
  (74hc595n) clockPin -> 3 (arduino)
  (74hc595n) dataPin  -> 2 (arduino)
  (74hc595n) segment1 -> 6 (arduino)
  (74hc595n) segment2 -> 5 (arduino)

but you can change it with the function m.initial () in the main program
after we use it to configure on OUTPUT
*/
void Segment::Initial(int latchPin_, int dataPin_, int clockPin_, int segment1_, int segment2_)
{
  latchPin = latchPin_;
  clockPin = dataPin_;
  dataPin = clockPin_;
  segment1 = segment1_;
  segment2 = segment2_;

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(segment1, OUTPUT);
  pinMode(segment2, OUTPUT);
}

/*-------------------------------------------------------------------------------------------------*/
//this function retrieves the unit of the two-digit numbers

int Segment::unite (int val)
{
  return val / 10;
}

//this function makes it possible to recover the ten of the numbers issued at two digits
int Segment::dizaine (int val)
{
  return val % 10;
}

/*-------------------------------------------------------------------------------------------------*/

/* function that makes it possible to send to the shift register the bits that will make
 it possible to display the numbers on the segments */
void Segment::zero_f()
{
  leds = zero;
  updateShiftRegister();
  leds = 0;
}

void Segment::one_f()
{
  leds = one;
  updateShiftRegister();
  leds = 0;
}
void Segment::two_f()
{
  leds = two;
  updateShiftRegister();
  leds = 0;
}

void Segment::tree_f()
{
  leds = tree;
  updateShiftRegister();
  leds = 0;
}

void Segment::four_f()
{
  leds = four;
  updateShiftRegister();
  leds = 0 ;
}

void Segment::five_f()
{
  leds = five;
  updateShiftRegister();
  leds = 0;
}

void Segment::six_f()
{
  leds = six;
  updateShiftRegister();
  leds = 0;
}

void Segment::seven_f()
{
  leds = seven;
  updateShiftRegister();
  leds = 0;
}

void Segment::eight_f()
{
  leds = eight;
  updateShiftRegister();
  leds = 0;
}

void Segment::nine_f()
{
  leds = nine;
  updateShiftRegister();
  leds = 0;
}

void Segment::point_f()
{
  leds = point;
  updateShiftRegister();
  leds = 0;
}

/*-------------------------------------------------------------------------------------------------*/
//function that allows to choose the segments must be turned on or off to be able to
//display the numbers correctly

void Segment::segment_1_run()
{
  digitalWrite(segment1, HIGH);
  digitalWrite(segment2, LOW);
}

void Segment::segment_2_run()
{
  digitalWrite(segment1, LOW);
  digitalWrite(segment2, HIGH);
}

/*-------------------------------------------------------------------------------------------------*/
//function that uses the value we send it as a parameter, it calls the function unite and dizaine to know how to place the values on both segments
void Segment::screen(int saisie_convert)
{
  segment_1_run();
  if (unite(saisie_convert) == 0)
  {
    zero_f();
  }
  else if (unite(saisie_convert) == 1)
  {
    one_f();
  }
  else if (unite(saisie_convert) == 2)
  {
    two_f();
  }
  else if (unite(saisie_convert) == 3)
  {
    tree_f();
  }
  else if (unite(saisie_convert) == 4)
  {
    four_f();
  }
  else if (unite(saisie_convert) == 5)
  {
    five_f();
  }
  else if (unite(saisie_convert) == 6)
  {
    six_f();
  }
  else if (unite(saisie_convert) == 7)
  {
    seven_f();
  }
  else if (unite(saisie_convert) == 8)
  {
    eight_f();
  }
  else if (unite(saisie_convert) == 9)
  {
    nine_f();
  }

  delay(7);



  segment_2_run();
  if (dizaine(saisie_convert) == 0)
  {
    zero_f();
  }
  else if (dizaine(saisie_convert) == 1)
  {
    one_f();
  }
  else if (dizaine(saisie_convert) == 2)
  {
    two_f();
  }
  else if (dizaine(saisie_convert) == 3)
  {
    tree_f();
  }
  else if (dizaine(saisie_convert) == 4)
  {
    four_f();
  }
  else if (dizaine(saisie_convert) == 5)
  {
    five_f();
  }
  else if (dizaine(saisie_convert) == 6)
  {
    six_f();
  }
  else if (dizaine(saisie_convert) == 7)
  {
    seven_f();
  }
  else if (dizaine(saisie_convert) == 8)
  {
    eight_f();
  }
  else if (dizaine(saisie_convert) == 9)
  {
    nine_f();
  }
  delay(7);
}

/*-------------------------------------------------------------------------------------------------*/
//functon allow to apply value on digital segment
void Segment::updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
