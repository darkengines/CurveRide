//////////////////////////////////////////////////////
// Filename: TestValueProvider.h
// Class name: TestValueProvider
//////////////////////////////////////////////////////

#ifndef _TEST_VALUE_PROVIDER_H_
#define _TEST_VALUE_PROVIDER_H_

#include <math.h>

#include "ValueProvider.h"

class TestValueProvider: public ValueProvider {
protected:
	long double gradient(long double);
	long double function(long double);
public:
	TestValueProvider(long double initialPosition);
	TestValueProvider(const TestValueProvider&);
	~TestValueProvider();
	void setPosition(long double);
	long double getNextValue(long double);
	long double getCurrentValue();
	long double getCurrentPosition();
private:
	long double _position;
};

#endif