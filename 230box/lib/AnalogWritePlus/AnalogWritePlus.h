/*
 * AnalogWritePlus frecuency control for PWM optocoupled.
 * timer == Timer/counter by Atmel 
 *          For UNO I advise Timer 1 (not is possible with Servo, Toner, etc...)
 * fanMin and fanMax for calibrate fan.
 * 
 * Need use to begin and config frecuency
 * TOP = 320; 24.883 MHz; PWM 0~320
 * TOP = 400; 19.906 MHz
 * TOP = 200; 39.813 MHz
 * TOP = 100; 79.626 MHz
 * 
 * Use with write as percentage (0~100%)
 * pin = only fron his timer
 * value = percentage
 * 
 * Created by c2mismo 19/07/19
 * Released into the public domain.
 */

#ifndef AnalogWritePlus_h
#define AnalogWritePlus_h

#include "Arduino.h"

class AnalogWritePlus
{
	public:
			AnalogWritePlus(const byte timer, byte fanMin, byte fanMax);
			void write(byte pin, int value);
      void begin(int top);
			
	private:
      byte _timer;
      byte _fanMin;
      byte _fanMax;
      int _top;
      byte _pin;
			int _value;
			
};

#endif
