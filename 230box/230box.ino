 /*
 * 230box - Control for 230V electronic box
 * with 5 relay, 3 voltimeter, 1 amperimeter, 2 fans and CANbus and various temp sensors.
 * 3 possible input 230VAC and 3 output 230VAC
 *
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

//         //////////\\\\\\\\\\
//        //   LIBRARY CONF   \\
//       ////////////\\\\\\\\\\\\

#include "Arduino.h"
#include "AnalogWritePlus.h"
#include "OneWire.h"
#include "DallasTemperature.h"

AnalogWritePlus fan1(1, 9, 30, 317);
AnalogWritePlus fan2(1, 10, 30, 317);

const int pinOneWire = 2;

OneWire oneWire (pinOneWire);
DallasTemperature DS18B20 (&oneWire);

// Variables con las direcciones únicas del sensor DS18B20
DeviceAddress sensor1 = {0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2}; //Mark Amerillo/Verde
// Otro sensor1
DeviceAddress sensor2 = {0x28, 0xE5, 0xE0, 0xAF, 0x33, 0x14, 0x01, 0x86};

//       \\\\\\\\\\\\////////////
//        \\ END LIBRARY CONF //
//         \\\\\\\\\\//////////

//         /////////\\\\\\\\
//        //   VARIABLES   \\
//       ///////////\\\\\\\\\\

bool errorTemp = true;
float temp1 = 0;
float temp2 = 0;
int valFan1 = 0;
int valFan2 = 0;

//       \\\\\\\\\\\//////////
//        \\ END VARIABLES //
//         \\\\\\\\\////////

void setup(){
  Serial.begin(9600);
  fan1.begin(317);
  DS18B20.begin();
}

void loop(){
  if ((errorSensor(sensor1))||(errorSensor(sensor2))){
    errorTemp = true;
  }
  if (!errorTemp){
    errorTemp = false;
    temp1 = readFloat(sensor1);
    temp2 = readFloat(sensor2);
  }

  if (errorTemp){ valFan1 = 50; valFan2 = 50;}

  fan1.write(valFan1);
  fan2.write(valFan2);
}

//         /////////\\\\\\\\
//        //   FUNCTIONS   \\
//       ///////////\\\\\\\\\\

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
 */
