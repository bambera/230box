#include "Arduino.h"
#include "Voltmeter.h"

Voltmeter::Voltmeter(const int sensorPin, const int freq, const int waves)
{
  _calibrated = 757;
  _realVoltage = 224;
  _sensor = sensorPin;
  _freq = freq;
  _waves = waves;
}

Voltmeter::Voltmeter(const int sensorPin, const int freq, const int waves, const int calibrated, const int realVoltage)

{
  _calibrated = calibrated;
  _realVoltage = realVoltage;
  _sensor = sensorPin;
  _freq = freq;  // + 5
  _waves = waves;
}

void Voltmeter::get()
{
  _maxVal = 0;
  _minVal = 1024;
  _maxValue = 0;
  _minValue = 0;
  _tMax = millis() + _freq;
  for (_i = 0; _waves > _i; _i++){
    for (_tActu = millis(); _tMax > _tActu; _tActu = millis())
    {
      _s = analogRead(_sensor);
      if (_s > _maxVal) _maxVal = _s;
      if (_s < _minVal) _minVal = _s;
    }
    _maxValue = _maxValue + _maxVal;
    _minValue = _minValue + _minVal;
  }
  _maxValue = _maxValue / _waves;
  _minValue = _minValue / _waves;
  _average = (_maxValue - _minValue) / 2 + _minValue;
}

int Voltmeter::getValue()
{
  get();
  return _maxValue;
}

int Voltmeter::getAverage()
{
  get();
  return _average;
}

int Voltmeter::getVoltage()
{
  get();
  _voltage = map (_maxValue, _average, _calibrated, 0, _realVoltage);
  return _voltage;
}

//bool Voltmeter::getReady()