/*
 * 230box - Control for 230V electronic box
 * with 5 relay, 3 voltimeter, 1 amperimeter, 2 fans and CANbus and various temp sensors.
 * 3 possible input 230VAC and 3 output 230VAC
 *
 * State testing, developer c2mismo.
 * Licency GNU.
 */


#include "Arduino.h"
#include "AnalogWritePlus.h"

AnalogWritePlus plus(1, 100, 20);

void setup()
{
  plus.begin(230);
}

void loop()
{
  plus.write(9, 15);
}
