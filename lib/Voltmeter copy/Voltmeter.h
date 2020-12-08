#ifndef Voltmeter_H
#define Voltmeter_H

//#include "Arduino.h"

//const int

class Voltmeter {

	public:
		Voltmeter(const int sensorPin, const int freq, const int waves);
		Voltmeter(const int sensorPin, const int freq, const int waves, const int calibrated, const int realVoltage);

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
		int _waves;
		int _calibrated;
		int _realVoltage;
		int _voltage;
		int _maxVal;
		int _maxValue;
		int _minVal;
		int _minValue;
		int _average;
		int _tActu;
		int _tMax;
		int _i;
		int _s;
};

#endif