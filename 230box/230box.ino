 /*
 * 230box - Control for 230V electronic box
 * with 5 relay, 3 voltimeter, 1 amperimeter, 2 fans and CANbus and various temp sensors.
 * 3 possible input 230VAC and 3 output 230VAC
 *
 *
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */

//         //////////\\\\\\\\\\
//        //   LIBRARY CONF   \\
//       ////////////\\\\\\\\\\\\

// #include "Arduino.h"

//       \\\\\\\\\\\\////////////
//        \\ END LIBRARY CONF //
//         \\\\\\\\\\//////////

//         /////////\\\\\\\\
//        //     PINS      \\
//       ///////////\\\\\\\\\\

static const int signalOn = A0;
static const int signalHome = 4;

static const int signalAmper = A8;
static const int signalLeft = A9;
static const int signalRight = A10;
static const int signalIn = A11;

static const int ledLeftIn = 40;
static const int ledLeftOut = 41;
static const int ledRightIn = 42;
static const int ledRightOut = 43;
static const int ledInverted = 46;
static const int ledCHR = 47;
static const int ledHome = 48;
static const int ledAutomatic = 49;
static const int leds[9] = {ledLeftIn, ledLeftOut, ledRightIn, ledRightOut, ledInverted, ledCHR, ledHome, ledAutomatic};

static const int releRightIn = A1;
static const int releLeftIn = A2;
static const int releRightOut = A3;
static const int releLeftOut = A4;
static const int releHome = A5;
static const int releCHR = A6;


//       \\\\\\\\\\\//////////
//        \\    END PINS   //
//         \\\\\\\\\////////

//         /////////\\\\\\\\
//        //   VARIABLES   \\
//       ///////////\\\\\\\\\\

//       \\\\\\\\\\\//////////
//        \\ END VARIABLES //
//         \\\\\\\\\////////

void setup(){
  Serial.begin(9600);

  pinMode(signalOn, INPUT);
  pinMode(signalHome, INPUT);

  pinMode(signalAmper, INPUT);

  pinMode(releRightIn, OUTPUT);
  pinMode(releLeftIn, OUTPUT);
  pinMode(releRightOut, OUTPUT);
  pinMode(releLeftOut, OUTPUT);
  pinMode(releHome, OUTPUT);
  pinMode(releCHR, OUTPUT);

  pinMode(ledLeftIn, OUTPUT);
  pinMode(ledLeftOut, OUTPUT);
  pinMode(ledRightIn, OUTPUT);
  pinMode(ledRightOut, OUTPUT);
  pinMode(ledInverted, OUTPUT);
  pinMode(ledCHR, OUTPUT);
  pinMode(ledHome, OUTPUT);
  pinMode(ledAutomatic, OUTPUT);
  blink();
}

void loop(){
}

//         /////////\\\\\\\\
//        //   FUNCTIONS   \\
//       ///////////\\\\\\\\\\

void blink() {
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], HIGH);
    delay(200);
  }
  delay(1500);
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], LOW);
  }
  delay(1000);
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
  delay(1500);
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], LOW);
  }
  delay(1000);
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
  delay(3000);
  for (byte i = 0; i < 9; i++)
  {
    digitalWrite(leds[i], LOW);
  }
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
