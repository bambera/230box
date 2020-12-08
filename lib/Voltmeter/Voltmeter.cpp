#include "Arduino.h"
#include "Voltmeter.h"

Voltmeter::Voltmeter(const int sensorPin, const int freq)
{
  _calibrated = 757;
  _realVoltage = 224;
  _sensor = sensorPin;
  _freq = freq;
}

Voltmeter::Voltmeter(const int sensorPin, const int freq, const int calibrated, const int realVoltage)

{
  _calibrated = calibrated;
  _realVoltage = realVoltage;
  _sensor = sensorPin;
  _freq = freq +1;
}

void Voltmeter::get()
{
  _maxValue = 0;
  _minValue = 0;
  _maxVal = 0;
  _minVal = 1024;
  _tMax = millis() + _freq;

  for (_tActu = millis(); _tMax > _tActu; _tActu = millis()){
    _s = analogRead(_sensor);
    if (_s > _maxVal)_maxVal = _s;
    if (_s < _minVal) _minVal = _s;
  }
  _average = (_maxVal - _minVal) / 2 + _minVal;
}

int Voltmeter::getValue()
{
  return _maxVal;
}

int Voltmeter::getAverage()
{
  return _average;
}

int Voltmeter::getVoltage()
{
  _voltage = map (_maxVal, _average, _calibrated, 0, _realVoltage);
  return _voltage;
}

bool Voltmeter::getReady()
{
  getVoltage();
  if (_voltage > 190 && _voltage < 240){
    return true;
  } else {
    return false;
  }
}