/*
 * AnalogWritePlus230box frecuency control for PWM.
 * based at AnalogWritePlus
 * AnalogWritePlus230box plus();
 * 
 * 
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */


#include "Arduino.h"
#include "AnalogWritePlus230box.h"




AnalogWritePlus230box::AnalogWritePlus230box(int top)
{
	_top=top;
}

void AnalogWritePlus230box::begin()
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
  pinMode(10, OUTPUT);
}

void AnalogWritePlus230box::write(int value)
{
	_value=value;
// Pin09
  if (_value < 1) OCR1A=0;
  if (_value >= 1 && _value <= _top) OCR1A=_value;
  if (_value > _top) OCR1A=_top;
// Pin10
  if (_value < 1) OCR1B=0;
  if (_value >= 1 && _value <= _top) OCR1B=_value;
  if (_value > _top) OCR1B=_top;
}

/*
  License:

    Copyright (C) 2019  c2mismo.

    This file is part of 230box.

    230box is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This 230box is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this 230box, see COPYING.  If not, see <https://www.gnu.org/licenses/>.

    You can download a full copy of 230box at <https://github.com/c2mismo>.
 */
