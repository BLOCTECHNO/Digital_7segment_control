#include "segment.h"

Segment m;

const int ldr = A0;
int value = 0;
int value_mapping = 0;


void setup()
{
  m.Initial();
  pinMode(ldr,INPUT);
  Serial.begin(9600);

}

void loop()
{
  m.clear_All();
  value = analogRead(ldr);
  value_mapping = map(value,0,1023,0,99);
  for(int i=0; i<10; i++)
  {
    m.screen(value_mapping);
    Serial.println(value_mapping);
  }
}
