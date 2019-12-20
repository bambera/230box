/*
 * AnalogWritePlus frecuency control for PWM.
 * 
 * device == reference the Timer/counter by Atmel 
 *   
 *   Devices UNO, NANO & MEGA.
 *   
 * pin = only from your device
 * 
 *  For UNO we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *    Pins 9 & 10.
 *  For NANO we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *    Pins 13 & 14.
 *  For MEGA we will use Timer 1 (not is possible with Servo, Toner, etc...)
 *    Pins 11, 12 & 13.
 *  For MEGA we will use Timer 3 (more advised)
 *    Pins 2, 3 & 5.
 *  For MEGA we will use Timer 4 (more advised)
 *    Pins 6, 7 & 8.
 *  For MEGA we will use Timer 5 (more advised)
 *    Pins 38, 39 & 40.
 *          
 * fanMin and fanMax for calibrate fan.
 * 
 *  Need use to begin and config frecuency
 * TOP = 400 equivalent to 19.906 MHz; From 0 to 400 PWM valors
 * TOP = 320 equivalent to 24.883 MHz; From 0 to 320 PWM valors
 * TOP = 200 equivalent to 39.813 MHz; From 0 to 200 PWM valors
 * TOP = 100 equivalent to 79.626 MHz; From 0 to 100 PWM valors
 * 
 * fanMin & fanMax for calibration use the valors 0 to TOP
 *   fanMin == Minimum value for proper engine start.
 *   fanMax ==  Maximum value we want the engine to reach.
 * 
 * calibMin & calibMax for calibration use the valors 0 to TOP
 *   calibMin == With fanMin & fanMax between the values 0 and TOP,
 *               increase this from 0 to minimum value for proper engine start,
 *               do not increase more than TOP
 *               
 *   calibMax == With fanMin & fanMax between the values 0 and TOP,
 *               decrease this from TOP to maximum value we want the engine to reach,
 *               not less than 0.
 *               
 * value = percentage (0~100%)
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */
#ifndef AnalogWritePlus2_h
#define AnalogWritePlus2_h

#include "Arduino.h"

class AnalogWritePlus2
{
	public:
			AnalogWritePlus2(const byte device, const byte pin, int fanMin, int fanMax);
      void begin(int top);
			void calibMin(int calMin);
      void calibMax(int calMax);
      void write(byte value);
			
	private:
      byte _device;
      byte _pin;
      int _fanMin;
      int _fanMax;
      int _top;
      int _calMin;
      int _calMax;
			byte _value;
			
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
