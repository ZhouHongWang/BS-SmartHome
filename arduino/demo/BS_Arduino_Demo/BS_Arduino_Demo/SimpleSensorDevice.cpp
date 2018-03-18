#include "SimpleSensorDevice.h"

SimpleSensorDevice::SimpleSensorDevice(devicePin pin, unsigned char readMode, unsigned int sensorValueIndex) : SensorDevice(sensorValueIndex)
{
	this->pin = pin;
	this->readMode = readMode;
	state = DEVICE_STATE_CLOSED;
}

void SimpleSensorDevice::init()
{
	pinMode(pin, INPUT);
	state = DEVICE_STATE_READY;
}
	
float SimpleSensorDevice::getSensorValue()
{
	if(readMode == SENSOR_READ_MODE_ANALOG)
		return analogRead(pin);
	else
		return digitalRead(pin);
}