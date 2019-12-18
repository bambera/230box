/*
 * AnalogWritePlus frecuency control for PWM optocoupled.
 * timer == Timer/counter by Atmel 
 *          For UNO we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *          Pins 9 & 10.
 *          
 * fanMin and fanMax for calibrate fan.
 * 
 * Need use to begin and config frecuency
 * TOP = 400; 19.906 MHz; PWM fron 0 to 400
 * TOP = 320; 24.883 MHz
 * TOP = 200; 39.813 MHz
 * TOP = 100; 79.626 MHz
 * 
 * fanMin & fanMax for calibration use the valors of TOP.
 * 
 * pin = only fron his timer
 * 
 * value = percentage (0~100%)
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */


#include "Arduino.h"
#include "AnalogWritePlus.h"



AnalogWritePlus::AnalogWritePlus(const byte timer, byte fanMin, byte fanMax)
{
  _timer=timer;
  _fanMin=fanMin;
  _fanMax=fanMax;
}

void AnalogWritePlus::begin(int top)
{
  
  _top=top;

  if (_timer == 1)
  {
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    TCCR1A |= (1 << COM1A1);
    TCCR1A |= (1 << COM1B1);
    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM13);
    TCCR1B |= (1 << CS10);
    ICR1 = _top;

    pinMode( 9, OUTPUT);
    pinMode( 10, OUTPUT);
  }
}

void AnalogWritePlus::write(byte pin, int value)
{
  
  _pin=pin;
	_value=value;

  if (_timer == 1)
  {
	  switch (_pin)
	  {
          case 9:
              if (_value == 0) digitalWrite(_pin, HIGH);
              if ((_value > 0) && (_value < 100)){
              OCR1A = map(_value,0,100,_fanMin,_fanMax);}
              if (_value == 100) digitalWrite(_pin, LOW);
              break;
          case 10:
              if (_value == 0) digitalWrite(_pin, HIGH);
              if ((_value > 0) && (_value < 100)){
              OCR1B = map(_value,0,100,_fanMin,_fanMax);}
              if (_value == 100) digitalWrite(_pin, LOW);
              break;
          default:
              // no other pin will work
              break;
	  }
  }
}

/*
  License:

    Copyright (C) 2019  c2mismo.

    This file is part of AnalogWritePlus.

    AnalogWritePlus is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This AnalogWritePlus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this AnalogWritePlus, see COPYING.  If not, see <https://www.gnu.org/licenses/>.

    You can download a full copy of AnalogWritePlus at <https://github.com/c2mismo>.
 */
