 /*
 * 230box - Control for 230V electronic box
 * with 5 relay, 3 voltimeter, 1 amperimeter, 2 fans and CANbus and various temp sensors.
 * 3 possible input 230VAC and 3 output 230VAC
 *
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */


#include "Arduino.h"
#include "AnalogWritePlus.h"

AnalogWritePlus plus(1, 9, 30, 317);

void setup()
{
  plus.begin(317);
}

void loop()
{
  plus.write(15);
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
