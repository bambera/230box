/*
 * AnalogWritePlus frecuency control for PWM optocoupled.
 * timer == Timer/counter by Atmel 
 *          For UNO I advise Timer 1 (not is possible with Servo, Toner, etc...)
 * fanMin and fanMax for calibrate fan.
 * 
 * Need use to begin and config frecuency
 * TOP = 320; 24.883 MHz; PWM 0~320
 * TOP = 400; 19.906 MHz
 * TOP = 200; 39.813 MHz
 * TOP = 100; 79.626 MHz
 * 
 * Use with write as percentage (0~100%)
 * pin = only fron his timer
 * value = percentage
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

#ifndef AnalogWritePlus_h
#define AnalogWritePlus_h

#include "Arduino.h"

class AnalogWritePlus
{
	public:
			AnalogWritePlus(const byte timer, byte fanMin, byte fanMax);
			void write(byte pin, int value);
      void begin(int top);
			
	private:
      byte _timer;
      byte _fanMin;
      byte _fanMax;
      int _top;
      byte _pin;
			int _value;
			
};

#endif

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
