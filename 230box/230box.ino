 /*
 * 230box - Control for 230V electronic box
 * with 5 relay, 3 voltimeter, 1 amperimeter, 2 fans and CANbus and various temp sensors.
 * 3 possible input 230VAC and 3 output 230VAC
 *
 * We have decided not to use a PID controller.
 * 1. Because we can't keep maintaining a specific temperature.
 * 2. Excessive changes in temperature are not expected.
 * 3. It remains to experiment and determine the thermal response of the components.
 *
 * The temperature controller is configured as follows:
 * 1. We will treat the data as integers from the beginning, because the map function with decimals has a not very clear answer.
 * 2. The chaining is not done until it reaches 45ºC (4500).
 * 3. The engine starts at 4% ±.
 * 3. 100% or maximum engine power is at 70 ° C (7000).
 * 4. The engine will not stop until it reaches 40ºC, with a timely hysteresis.
 *
 * With the AnaloWritePlus230box we ensure that the engine runs at 25kHz (317).
 *
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

//         //////////\\\\\\\\\\
//        //   LIBRARY CONF   \\
//       ////////////\\\\\\\\\\\\

#include "Arduino.h"
#include "AnalogWritePlus230box.h"
#include "OneWire.h"
#include "DallasTemperature.h"

AnalogWritePlus230box fan;

const int pinOneWire = 2;

OneWire oneWire (pinOneWire);
DallasTemperature DS18B20 (&oneWire);

// Variables con las direcciones únicas del sensor DS18B20
DeviceAddress sensor1 = {0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2}; //Mark Amerillo/Verde
// Otro sensor
DeviceAddress sensor2 = {0x28, 0xE5, 0xE0, 0xAF, 0x33, 0x14, 0x01, 0x86};

//       \\\\\\\\\\\\////////////
//        \\ END LIBRARY CONF //
//         \\\\\\\\\\//////////

//         /////////\\\\\\\\
//        //   VARIABLES   \\
//       ///////////\\\\\\\\\\

bool errorTemp = true;
int temp=0, temp1=0, temp2=0;
int minSetTemp = 4500, maxSetTemp = 7000, offSetTemp = 4000;
bool onFan = false;
int valfan=0;

//       \\\\\\\\\\\//////////
//        \\ END VARIABLES //
//         \\\\\\\\\////////

void setup(){
  Serial.begin(9600);
  fan.begin(317);
  DS18B20.begin();
}

void loop(){

  fan.write(valFan()); // write on pins 9 & 10 simultaneously.

  Serial.print(" Sens1=");Serial.print(temp1);
  Serial.print(" Sens2=");Serial.print(temp2);
  Serial.print(" Temp=");Serial.print(temp);
  Serial.print(" State=");Serial.print(onFan);
  Serial.print(" Fan=");Serial.println(valFan());

//  for (;;);
}

//         /////////\\\\\\\\
//        //   FUNCTIONS   \\
//       ///////////\\\\\\\\\\

int valFan ()
{
  if (errorSensor(sensor1) || errorSensor(sensor2)){
    valfan = 50;
    errorTemp = true;
    Serial.print(" ERROR");}
  else errorTemp = false;

  if (!errorTemp){
    temp1 = readInt(sensor1);
    temp2 = readInt(sensor2);
    temp = max(temp1, temp2);

    if (temp >= minSetTemp) onFan = true;
    if (temp < offSetTemp) onFan = false, valfan = 0;
    if (temp > maxSetTemp) temp = maxSetTemp;
    if (onFan)valfan = map(temp, offSetTemp, maxSetTemp, 30, 317);
  }
  return valfan;
}

bool errorSensor (int sensor){
  DS18B20.requestTemperatures();
  float tmp = DS18B20.getTempC(sensor);
  if (tmp == -127.00) return true; else return false;
}

float readFloat (int sensor){
  DS18B20.requestTemperatures();
  float tmp = DS18B20.getTempC(sensor);
  return tmp;
}

int readInt (int sensor){
  DS18B20.requestTemperatures();
  int tmp = DS18B20.getTempC(sensor)*100;
  return tmp;
}

float result (int tmpInt){
  float tempResult = tmpInt;
  tempResult = tempResult/100;
  return tempResult;
}

//       \\\\\\\\\\\//////////
//        \\ END FUNCTIONS //
//         \\\\\\\\\////////

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


  EXCLUDED CODE:
    The code described below and contained in the 230box Source Code,
    is not part of the Program covered by the GPL and is expressly excluded
    from its terms.  You are solely responsible for obtaining from
    the copyright holder a license for such code and complying with
    the applicable license terms.
    THIS SOFTWARE THAT IS DESCRIBED BELOW IS A SOFTWARE CREATED BY
    THIRD PARTIES, THIS EQUIPMENT IS NOT CONTRIBUTED OR MODIFIED
    IN ANY LINE, THEREFORE WE WILL NOT BE LIABLE FOR ANY CLAIM,
    BE FOR DAMAGES OR OTHER LIABILITY.

  DallasTemperature library
---------------------------------------------------------------------------
  lines   files
  885     libraries/DallasTemperature/DallasTemperature.cpp

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.


  OneWire library v2.3
---------------------------------------------------------------------------
  lines   files
  580     libraries/OneWire/OneWire.cpp
  Copyright (C) 2000 Dallas Semiconductor Corporation, All Rights Reserved.

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL DALLAS SEMICONDUCTOR BE LIABLE FOR ANY CLAIM, DAMAGES
  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  Except as contained in this notice, the name of Dallas Semiconductor
  shall not be used except as stated in the Dallas Semiconductor
  Branding Policy.
 */
