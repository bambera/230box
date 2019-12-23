/*
 * AnalogWritePlus frecuency control for PWM.
 * AnalogWritePlus plus(device, pin, valMin, valMax);
 * 
 * device == reference the Timer/counter by Atmel 
 *   Devices 1 == UNO or NANO & 2 == MEGA.
 *   
 * pin = only from your device
 *  For UNO & NANO we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *    Pins 9 & 10.
 *  For MEGA we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *    Pins 11, 12 & 13.
 *  For MEGA we will use Timer 3 (more advised)
 *    Pins 2, 3 & 5.
 *  For MEGA we will use Timer 4 (more advised)
 *    Pins 6, 7 & 8.
 *  For MEGA we will use Timer 5 (more advised)
 *    Pins 44, 45 & 46.
 *          
 * valMin and valMax for calibrate motor.
 * 
 *  Need use to begin and config frecuency
 * TOP = 400 equivalent to 19.906 MHz; From 0 to 400 PWM valors
 * TOP = 317 equivalent to 25.057 MHz; From 0 to 317 PWM valors
 * TOP = 200 equivalent to 39.813 MHz; From 0 to 200 PWM valors
 * TOP = 100 equivalent to 79.626 MHz; From 0 to 100 PWM valors
 * 
 * valMin & valMax for calibration use the valors 0 to TOP
 *   valMin == Minimum value for proper engine start.
 *   valMax == Maximum value we want the engine to reach.
 * 
 * calibMin & calibMax for calibration use the valors 0 to TOP
 *   calibMin == With valMin & valMax between the values 0 and TOP,
 *               increase this from 0 to minimum value for proper engine start,
 *               do not increase more than TOP
 *               
 *   calibMax == With valMin & valMax between the values 0 and TOP,
 *               decrease this from TOP to maximum value we want the engine to reach,
 *               not less than 0.
 *               
 * value = percentage (0~100%)
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */


#include "Arduino.h"
#include "AnalogWritePlus.h"



AnalogWritePlus::AnalogWritePlus(const byte dev, const byte pin, int valMin, int valMax)
{
  _dev=dev;
  _pin=pin;
  _valMin=valMin;
  _valMax=valMax;
}

void AnalogWritePlus::begin(int top)
{
  _top=top;

  if (_dev == 1)
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
  }
  /*
  if (_dev == 2)
  {
    if (_pin == 11 || _pin == 12 || _pin == 13)
    {
      TCCR1A = 0;
      TCCR1B = 0;
      TCNT1 = 0;
      TCCR1A |= (1 << COM1A1);
      TCCR1A |= (1 << COM1B1);
      TCCR1A |= (1 << COM1C1);
      TCCR1A |= (1 << WGM11);
      TCCR1B |= (1 << WGM13);
      TCCR1B |= (1 << CS10);
      ICR1 = _top;
    }
    if (_pin == 2 || _pin == 3 || _pin == 5)
    {
      TCCR3A = 0;
      TCCR3B = 0;
      TCNT3 = 0;
      TCCR3A |= (1 << COM3A1);
      TCCR3A |= (1 << COM3B1);
      TCCR3A |= (1 << COM3C1);
      TCCR3A |= (1 << WGM31);
      TCCR3B |= (1 << WGM33);
      TCCR3B |= (1 << CS30);
      ICR3 = _top;
    }
    if (_pin == 6 || _pin == 7 || _pin == 8)
    {
      TCCR4A = 0;
      TCCR4B = 0;
      TCNT4 = 0;
      TCCR4A |= (1 << COM4A1);
      TCCR4A |= (1 << COM4B1);
      TCCR4A |= (1 << COM4C1);
      TCCR4A |= (1 << WGM41);
      TCCR4B |= (1 << WGM43);
      TCCR4B |= (1 << CS40);
      ICR4 = _top;
    }
    if (_pin == 44 || _pin == 45 || _pin == 46)
    {
      TCCR5A = 0;
      TCCR5B = 0;
      TCNT5 = 0;
      TCCR5A |= (1 << COM5A1);
      TCCR5A |= (1 << COM5B1);
      TCCR5A |= (1 << COM5C1);
      TCCR5A |= (1 << WGM51);
      TCCR5B |= (1 << WGM53);
      TCCR5B |= (1 << CS50);
      ICR5 = _top;
    }
  }
  */
  pinMode(_pin, OUTPUT);
}

void AnalogWritePlus::calibMin(int calMin)
{
  _calMin=calMin;

  if (_dev == 1)
  {
    if (_pin ==  9) OCR1A=_calMin;
    if (_pin == 10) OCR1B=_calMin;
  }
  /*
  if (_dev == 2 )
  {
    if (_pin == 11) OCR1A=_calMin;
    if (_pin == 12) OCR1B=_calMin;
    if (_pin == 13) OCR1C=_calMin;
    if (_pin ==  5) OCR3A=_calMin;
    if (_pin ==  2) OCR3B=_calMin;
    if (_pin ==  3) OCR3C=_calMin;
    if (_pin ==  6) OCR4A=_calMin;
    if (_pin ==  7) OCR4B=_calMin;
    if (_pin ==  8) OCR4C=_calMin;
    if (_pin == 46) OCR5A=_calMin;
    if (_pin == 45) OCR5B=_calMin;
    if (_pin == 44) OCR5C=_calMin;
  }
  */
}

void AnalogWritePlus::calibMax(int calMax)
{
  _calMax=calMax;
  
  if (_dev == 1)
  {
    if (_pin ==  9) OCR1A=_calMin;
    if (_pin == 10) OCR1B=_calMin;
  }
  /*
  if (_dev == 2)
  {
    if (_pin == 11) OCR1A=_calMin;
    if (_pin == 12) OCR1B=_calMin;
    if (_pin == 13) OCR1C=_calMin;
    if (_pin ==  5) OCR3A=_calMin;
    if (_pin ==  2) OCR3B=_calMin;
    if (_pin ==  3) OCR3C=_calMin;
    if (_pin ==  6) OCR4A=_calMin;
    if (_pin ==  7) OCR4B=_calMin;
    if (_pin ==  8) OCR4C=_calMin;
    if (_pin == 46) OCR5A=_calMin;
    if (_pin == 45) OCR5B=_calMin;
    if (_pin == 44) OCR5C=_calMin;
  }
  */
}

void AnalogWritePlus::write(byte value)
{
	_value=value;


  if (_dev == 1)
  {
    if (_pin == 9)
    {
      if (_value < 1) OCR1A=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR1A=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 10)
    {
      if (_value < 1) OCR1B=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR1B=map(_value,1,100,_valMin,_valMax);
    }
  }
  /*
  if (_dev == 2)
  {
    if (_pin == 11)
    {
      if (_value < 1) OCR1A=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR1A=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 12)
    {
      if (_value < 1) OCR1B=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR1B=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 13)
    {
      if (_value < 1) OCR1C=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR1C=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  5)
    {
      if (_value < 1) OCR3A=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR3A=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  2)
    {
      if (_value < 1) OCR3B=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR3B=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  3)
    {
      if (_value < 1) OCR3C=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR3C=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  6)
    {
      if (_value < 1) OCR4A=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR4A=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  7)
    {
      if (_value < 1) OCR4B=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR4B=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin ==  8)
    {
      if (_value < 1) OCR4C=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR4C=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 46)
    {
      if (_value < 1) OCR5A=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR5A=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 45)
    {
      if (_value < 1) OCR5B=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR5B=map(_value,1,100,_valMin,_valMax);
    }
    if (_pin == 44)
    {
      if (_value < 1) OCR5C=0;                        // We ensure 0 as off.
      if (_value >= 1) OCR5C=map(_value,1,100,_valMin,_valMax);
    }
  }
  */
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
