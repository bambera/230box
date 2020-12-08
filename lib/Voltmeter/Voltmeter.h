#ifndef Voltmeter_H
#define Voltmeter_H

//#include "Arduino.h"

//const int

class Voltmeter {

	public:
		Voltmeter(const int sensorPin, const int freq);
		Voltmeter(const int sensorPin, const int freq, const int calibrated, const int realVoltage);

		int realVoltage;
		int calibrated;
		void get();
		int getValue();
		int getAverage();
		int getVoltage();
		bool getReady();
	private:
		int _sensor;
		int _freq;
		int _calibrated;
		int _realVoltage;
		int _voltage;
		int _maxVal;
		int _maxValue;
		int _minVal;
		int _minValue;
		int _average;
		unsigned int _tActu;
		unsigned int _tMax;
		int _i;
		int _s;
};

#endif