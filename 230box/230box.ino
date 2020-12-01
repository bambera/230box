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

#include "Arduino.h"

//       \\\\\\\\\\\\////////////
//        \\ END LIBRARY CONF //
//         \\\\\\\\\\//////////

//         /////////\\\\\\\\
//        //   VARIABLES   \\
//       ///////////\\\\\\\\\\

int ledLeftIn = 40;
int ledLeftOut = 41;
int ledRightIn = 42;
int ledRightOut = 43;
int ledInverted = 46;
int ledCHR = 47;
int ledHome = 48;
int ledAutomatic = 49;

//       \\\\\\\\\\\//////////
//        \\ END VARIABLES //
//         \\\\\\\\\////////

void setup(){
  pinMode(ledLeftIn, OUTPUT);
  pinMode(ledLeftOut, OUTPUT);
  pinMode(ledRightIn, OUTPUT);
  pinMode(ledRightOut, OUTPUT);
  pinMode(ledInverted, OUTPUT);
  pinMode(ledCHR, OUTPUT);
  pinMode(ledHome, OUTPUT);
  pinMode(ledAutomatic, OUTPUT);
  pinMode(ledTest, OUTPUT);
  blink();
}

void loop(){
  
}

//         /////////\\\\\\\\
//        //   FUNCTIONS   \\
//       ///////////\\\\\\\\\\


void blink() {
  digitalWrite(ledLeftIn, HIGH);
  digitalWrite(ledLeftOut, HIGH);
  digitalWrite(ledRightIn, HIGH);
  digitalWrite(ledRightOut, HIGH);
  digitalWrite(ledInverted, HIGH);
  digitalWrite(ledCHR, HIGH);
  digitalWrite(ledHome, HIGH);
  digitalWrite(ledAutomatic, HIGH);
  delay(1500);
  digitalWrite(ledLeftIn, LOW);
  digitalWrite(ledLeftOut, LOW);
  digitalWrite(ledRightIn, LOW);
  digitalWrite(ledRightOut, LOW);
  digitalWrite(ledInverted, LOW);
  digitalWrite(ledCHR, LOW);
  digitalWrite(ledHome, LOW);
  digitalWrite(ledAutomatic, LOW);
  delay(1000);

  digitalWrite(ledLeftIn, HIGH);
  digitalWrite(ledLeftOut, HIGH);
  digitalWrite(ledRightIn, HIGH);
  digitalWrite(ledRightOut, HIGH);
  digitalWrite(ledInverted, HIGH);
  digitalWrite(ledCHR, HIGH);
  digitalWrite(ledHome, HIGH);
  digitalWrite(ledAutomatic, HIGH);
  delay(1500);
  digitalWrite(ledLeftIn, LOW);
  digitalWrite(ledLeftOut, LOW);
  digitalWrite(ledRightIn, LOW);
  digitalWrite(ledRightOut, LOW);
  digitalWrite(ledInverted, LOW);
  digitalWrite(ledCHR, LOW);
  digitalWrite(ledHome, LOW);
  digitalWrite(ledAutomatic, LOW);
  delay(1000);

  digitalWrite(ledLeftIn, HIGH);
  digitalWrite(ledLeftOut, HIGH);
  digitalWrite(ledRightIn, HIGH);
  digitalWrite(ledRightOut, HIGH);
  digitalWrite(ledInverted, HIGH);
  digitalWrite(ledCHR, HIGH);
  digitalWrite(ledHome, HIGH);
  digitalWrite(ledAutomatic, HIGH);
  delay(3000);

  digitalWrite(ledLeftIn, LOW);
  digitalWrite(ledLeftOut, LOW);
  digitalWrite(ledRightIn, LOW);
  digitalWrite(ledRightOut, LOW);
  digitalWrite(ledInverted, LOW);
  digitalWrite(ledCHR, LOW);
  digitalWrite(ledHome, LOW);
  digitalWrite(ledAutomatic, LOW);
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
