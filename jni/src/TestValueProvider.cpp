//////////////////////////////////////////////////////
// Filename: TestValueProvider.cpp
//////////////////////////////////////////////////////

#include "TestValueProvider.h"

TestValueProvider::TestValueProvider(long double initialPosition) {
	_position = initialPosition;
}
TestValueProvider::TestValueProvider(const TestValueProvider& from) {
	_position = from._position;
}
TestValueProvider::~TestValueProvider() {

}
long double TestValueProvider::function(long double x) {
	return x*x;
}
long double TestValueProvider::gradient(long double x) {
	return 2*x;
}
long double TestValueProvider::getNextValue(long double e) {
	_position -= e * gradient(_position);
	return function(_position);
}
long double TestValueProvider::getCurrentValue() {
	return function(_position);
}
long double TestValueProvider::getCurrentPosition() {
	return _position;
}
void TestValueProvider::setPosition(long double position) {
	_position = position;
}