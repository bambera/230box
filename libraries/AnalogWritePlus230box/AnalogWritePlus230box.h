/*
 * AnalogWritePlus230box frecuency control for PWM,
 * based at AnalogWritePlus
 * AnalogWritePlus230box plus();
 * 
 * 
 * 
 * State testing, developer c2mismo 2019.
 * License GNU, see at the end.
 */
#ifndef AnalogWritePlus230box_h
#define AnalogWritePlus230box_h

#include "Arduino.h"

class AnalogWritePlus230box
{
	public:
			AnalogWritePlus230box;
      void begin(int top);
      void write(int value);

	private:
      int _top;
			int _value;
};

#endif

/*
  License:

    Copyright (C) 2019  c2mismo.

    This file is part of AnalogWritePlus230box.

    AnalogWritePlus230box is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This AnalogWritePlus230box is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this AnalogWritePlus230box, see COPYING.  If not, see <https://www.gnu.org/licenses/>.

    You can download a full copy of AnalogWritePlus230box at <https://github.com/c2mismo>.
 */
