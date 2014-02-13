//////////////////////////////////////////////////////
// Filename: ValueProvider.h
// Class name: ValueProvider
//////////////////////////////////////////////////////

#ifndef _VALUE_PROVIDER_H_
#define _VALUE_PROVIDER_H_

#include <math.h>

class ValueProvider {
public:
	virtual void setPosition(long double) = 0;
	virtual long double getNextValue(long double) = 0;
	virtual long double getCurrentValue() = 0;
	virtual long double getCurrentPosition() = 0;
};

#endif