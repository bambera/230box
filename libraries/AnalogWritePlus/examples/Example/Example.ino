/*
 * Example for AnalogWritePlus frecuency control for PWM.
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
 * value = percentage (0~100%)
 * 
 * Developer c2mismo 2019.
 * License GNU, see at the end.
 */


#include "Arduino.h"
#include "AnalogWritePlus.h"

AnalogWritePlus plus(1, 9, 30, 317);

const int TOP = 317;
int value = 15;

void setup()
{
  plus.begin(TOP);
}

void loop()
{
  plus.write(value);
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
