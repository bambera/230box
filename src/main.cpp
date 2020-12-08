 /*
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

//           LIBRARY CONF   

#include "Arduino.h"
#include "Leds.h"
#include "Voltmeter.h"

//         END LIBRARY CONF

//             PINS

const int signalOn = A0;
const int signalHome = 5;

const int amperemeter = A8;

const int ledLeftIn = 40;
const int ledLeftOut = 41;
const int ledRightIn = 42;
const int ledRightOut = 43;
const int ledInverter = 44;
const int ledCHR = 45;
const int ledHome = 46;
const int ledAutomatic = 47;

Leds leds (ledLeftIn, ledLeftOut, ledRightIn, ledRightOut, ledInverter, ledCHR, ledHome, ledAutomatic);

const int releRightIn = A1;
const int releLeftIn = A2;
const int releRightOut = A3;
const int releLeftOut = A4;
const int releHome = A5;
const int releCHR = A7;
const int reles[7] = {releRightIn, releLeftIn, releRightOut, releLeftOut, releHome, releCHR};

//            END PINS

//           VARIABLES
//           Voltimetros

const int voltLeft = A9;
const int voltRight = A10;
const int voltIn = A11;

int freq = 20;      // 50 Hz = 20 m/s; 60 Hz = 16.6667 m/s

int calibratedLeft = 740;
int realVoltageLeft = 220;
Voltmeter voltmeterLeft (voltLeft, freq, calibratedLeft, realVoltageLeft);

int calibratedRight = 739;
int realVoltageRight = 223;
Voltmeter voltmeterRight (voltRight, freq, calibratedRight, realVoltageRight);

int calibratedIn = 740;
int realVoltageIn = 220;
Voltmeter voltmeterIn (voltIn, freq, calibratedIn, realVoltageIn);

//         END VARIABLES

void setup(){
  Serial.begin(9600);

  pinMode(signalOn, INPUT);
  pinMode(signalHome, INPUT_PULLUP);

  pinMode(amperemeter, INPUT);

  pinMode(releRightIn, OUTPUT);
  pinMode(releLeftIn, OUTPUT);
  pinMode(releRightOut, OUTPUT);
  pinMode(releLeftOut, OUTPUT);
  pinMode(releHome, OUTPUT);
  pinMode(releCHR, OUTPUT);

  //leds.blinkOn();
}

void loop(){

  digitalWrite(ledAutomatic, HIGH);

  voltmeterLeft.get();
  voltmeterRight.get();
  voltmeterIn.get();
  int val = voltmeterRight.getValue();
  int vol = voltmeterRight.getVoltage();

  Serial.print(" Value    : ");
  Serial.println(val);
  Serial.print(" Voltage  : ");
  Serial.println(vol);
  if (voltmeterIn.getReady())
  {
    Serial.print("            Encendido");
    digitalWrite(ledRightIn, HIGH);
  } else {
    Serial.print("            Apagado");
    digitalWrite(ledInverter, LOW);
  }

  digitalWrite(releRightIn, HIGH);

  Serial.println();Serial.println("************************************************");
  Serial.println();Serial.println("************************************************");Serial.println();

  delay(1000);
}

//           FUNCTIONS
//         END FUNCTIONS

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
