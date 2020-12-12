 /*
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

//           LIBRARY CONF   

#include "Arduino.h"
#include <SPI.h>
#include "Leds.h"
#include "Voltmeter.h"
#include "mcp2515.h"

struct can_frame canMsgValue;
struct can_frame canMsgState;
MCP2515 mcp2515(53);

//         END LIBRARY CONF

//             PINS

const int signalOn = A0;
const int signalHome = 5;

const int voltLeft = A9;
const int voltRight = A10;
const int voltIn = A11;
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

bool stateLeftIn = false;
bool stateLeftOut = false;
bool stateRightIn = false;
bool stateRightOut = false;
bool stateCHR = false;
bool stateHome = false;
bool stateInverter = false;

int freq = 20;      // 50 Hz = 20 m/s; 60 Hz = 16.6667 m/s
Voltmeter voltmeterLeft (voltLeft, freq);
Voltmeter voltmeterRight (voltRight, freq);
Voltmeter voltmeterIn (voltIn, freq);

//         END VARIABLES

void setup(){
  while (!Serial);
  Serial.begin(115200);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate (CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  canMsgValue.can_id = 0x036;
  canMsgValue.can_dlc = 4;
  canMsgState.can_id = 0x037;
  canMsgState.can_dlc = 7;

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
  float voltageLeft = voltmeterLeft.getVoltage();
  voltmeterRight.get();
  float voltageRight = voltmeterRight.getVoltage();
  voltmeterIn.get();
  float voltageIn = voltmeterIn.getVoltage();
  if (voltageLeft >= 255) {
    canMsgValue.data[0] = 255;
  } else {
    canMsgValue.data[0] = (byte)voltageLeft;
  }
  
  if (voltageRight >= 255) {
    canMsgValue.data[1] = 255;
  } else {
    canMsgValue.data[1] = (byte)voltageRight;
  }

  if (voltageIn >= 255) {
    canMsgValue.data[2] = 255;
  } else {
    canMsgValue.data[2] = (byte)voltageIn;
  }

  canMsgValue.data[3] = 0x00; // Reserved for Ampermeter

  canMsgState.data[0] = stateLeftIn;
  canMsgState.data[1] = stateLeftOut;
  canMsgState.data[2] = stateRightIn;
  canMsgState.data[3] = stateRightOut;
  canMsgState.data[4] = stateCHR;
  canMsgState.data[5] = stateHome;

  stateInverter = true;
  canMsgState.data[6] = stateInverter;

  mcp2515.sendMessage(&canMsgValue);
  mcp2515.sendMessage(&canMsgState);

  //delay(1200);
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
