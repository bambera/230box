/*
 * Created and checked the functions for DS18B20
 * 
 * We created and checked 4 functions to use with DS18B20.
 * 
 * Function errorSensor check if the sensor has an error.
 * 
 * Function readFloat returns the temperature readings.
 * 
 * Fuction readInt returns the temperature readings how integer,
 * to avoid possible mistakes when working with float numbers.
 * 
 * Function result returns the result of operations as a float number.
 * 
 * 
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
*/

////////////\\\\\\\
//  LIBRARY CONF  \\
////////////\\\\\\\\\


#include <OneWire.h>
#include <DallasTemperature.h>

const int pinOneWire = 2;

OneWire oneWire (pinOneWire);
DallasTemperature DS18B20 (&oneWire);
 
// Variables con las direcciones únicas del sensor DS18B20
DeviceAddress sensor1 = {0x28, 0xAA, 0xE0, 0x2A, 0x1B, 0x13, 0x02, 0xB2}; //Mark Amerillo/Verde
// Otro sensor1
DeviceAddress sensorExtern = {0x28, 0xE5, 0xE0, 0xAF, 0x33, 0x14, 0x01, 0x86};

///////////////////////
// END LIBRARY CONF //
/////////////////////


void setup() {
  Serial.begin(9600);
  DS18B20.begin();
}


void loop() {


  if (!errorSensor(sensor1)){
    float result1 = readFloat(sensor1);
    Serial.print("readFloat: ");
    Serial.print(result1);
    Serial.println(" ºC");
    delay(200);

    int result2 = readInt(sensor1);
    Serial.print("readInt: ");
    Serial.print(result2);
    Serial.println(" ºC");
    delay(200);

    float result3 = result(result2);
    Serial.print("convert: ");
    Serial.print(result3);
    Serial.println(" ºC");
    delay(200);
  }

  if (error(sensor1)) Serial.print("error de lectura en sensor1");

  while(1);
}

///////\\\\\\\\
//  FUCTION   \\
///////\\\\\\\\\\

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

///////////////////
// END  FUCTION //
/////////////////

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
