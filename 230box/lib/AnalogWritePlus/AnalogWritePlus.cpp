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


#include "Arduino.h"
#include <AnalogWritePlus.h>



AnalogWritePlus::AnalogWritePlus(const byte timer, byte fanMin, byte fanMax)
{
  _timer=timer;
  _fanMin=fanMin;
  _fanMax=fanMax;
}

void AnalogWritePlus::begin(int top)
{
  
  _top=top;

  if (_timer == 1)
  {
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    TCCR1A |= (1 << COM1A1);
    TCCR1A |= (1 << COM1B1);
    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM13);
    TCCR1B |= (1 << CS10);
    ICR1 = _top;

    pinMode( 9, OUTPUT);
    pinMode( 10, OUTPUT);
  }
}

void AnalogWritePlus::write(byte pin, int value)
{
  
  _pin=pin;
	_value=value;

  if (_timer == 1)
  {
	  switch (_pin)
	  {
          case 9:
              if (_value == 0) digitalWrite(9, HIGH);
              if ((_value > 0) && (_value < 100)){
              OCR1A = map(_value,0,100,_fanMin,_fanMax);}
              if (_value == 100) digitalWrite(9, LOW);
              break;
          case 10:
              if (_value == 0) digitalWrite(10, HIGH);
              if ((_value > 0) && (_value < 100)){
              OCR1B = map(_value,0,100,_fanMin,_fanMax);}
              if (_value == 100) digitalWrite(9, LOW);
              break;
          default:
              // no other pin will work
              break;
	  }
  }
}
