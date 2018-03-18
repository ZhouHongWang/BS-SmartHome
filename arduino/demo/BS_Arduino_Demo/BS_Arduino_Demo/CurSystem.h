
#ifndef _BS_CURRENT_SYSTEM_H_
#define _BS_CURRENT_SYSTEM_H_

/*
条件编译宏，在项目->属性->c/c++->预处理器->预处理器定义中定义
CUR_SYSTEM_IN	- 表示当前系统为室内的
CUR_SYSTEM_OUT	- 表示当前系统为室外的
*/
#include "SystemCfg.h"
#include "SampleSystem.h"
#include "SystemAPI.h"

#ifdef CUR_SYSTEM_IN

#include "inPinDef.h"

#include "ZigbeeDevice.h"
#include "SensorDevice.h"
#include "DHT11Device.h"
#include "TemperatureSensorDevice.h"
#include "HumiditySensorDevice.h"
#include "HeatSensorDevice.h"
#include "SimpleSensorDevice.h"
#include "LCDDevice.h"
#include "SimpleExecuterDevice.h"
#include "IRRemoteDevice.h"

#include "ZigbeeInApp.h"
#include "SensorApp.h"
#include "FireSensorApp.h"
#include "IRRemoteApp.h"

#include "SensorAppCmd.h"

/*
#include "Test1App.h"
#include "Test2App.h"
#include "Test3App.h"
*/

ZigbeeDevice zigbee;
DHT11Device dht11(PIN_DHT11_DATA);
TemperatureSensorDevice temperatureSensor(dht11, UPLOAD_INDEX_IN_TEMPERATURE);
HumiditySensorDevice humiditySensor(dht11, UPLOAD_INDEX_IN_HUMIDITY);
HeatSensorDevice heatSensor(dht11, UPLOAD_INDEX_IN_HEAT);
SimpleSensorDevice mq2(PIN_MQ2_DO, SENSOR_READ_MODE_ANALOG, UPLOAD_INDEX_HARMFUL_GAS);
LCDDevice lcd(PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
SimpleExecuterDevice alarm(PIN_ALARM_OUT, LOGIC_LEVEL_OPEN_HIGH);
SimpleSensorDevice fireSensor(PIN_FIRE_SENSOR_DO, SENSOR_READ_MODE_DIGITAL, UPLOAD_INDEX_FIRE);
IRRemoteDevice irRemote(PIN_IR_REMOTE_OUT);

ZigbeeInApp zigbeeApp(APP_ID_ZIGBEE, zigbee);
SensorApp temperatureApp(APP_ID_IN_TEMPERATURE, temperatureSensor);
SensorApp humidityApp(APP_ID_IN_HUMIDITY, humiditySensor);
SensorApp heatApp(APP_ID_IN_HEAT, heatSensor);

//Test2App test2App(0x78);
//Test3App test3App(APP_ID_TEST3);

SampleSystem curSystem(SYSTEM_ADDR_IN);

#else

#include "outPinDef.h"

#include "ZigbeeDevice.h"
#include "SimpleSensorDevice.h"
#include "DHT11Device.h"
#include "TemperatureSensorDevice.h"
#include "HumiditySensorDevice.h"
#include "HeatSensorDevice.h"
#include "GY30Device.h"
#include "PM25Device.h"

#include "ZigbeeOutApp.h"
#include "SensorApp.h"

/*
#include "Test1App.h"
#include "Test2App.h"
#include "Test3App.h"
*/

#include "SensorAppCmd.h"

ZigbeeDevice zigbee;
DHT11Device dht11(PIN_DHT11_DATA);
TemperatureSensorDevice temperatureSensor(dht11, UPLOAD_INDEX_OUT_TEMPERATURE);
HumiditySensorDevice humiditySensor(dht11, UPLOAD_INDEX_OUT_HUMIDITY);
HeatSensorDevice heatSensor(dht11, UPLOAD_INDEX_OUT_HEAT);
SimpleSensorDevice fc28(PIN_FC28_IN, SENSOR_READ_MODE_ANALOG, UPLOAD_INDEX_SOLID_HUMIDITY);
GY30Device gy30(UPLOAD_INDEX_LIGHT_INTENSITY);
PM25Device pm25(PIN_PM25_LED, PIN_PM25_VO, UPLOAD_INDEX_DUST_DENSITY);

ZigbeeOutApp zigbeeApp(APP_ID_ZIGBEE, zigbee);
SensorApp temperatureApp(APP_ID_OUT_TEMPERATURE, temperatureSensor);
SensorApp humidityApp(APP_ID_OUT_HUMIDITY, humiditySensor);
SensorApp heatApp(APP_ID_OUT_HEAT, heatSensor);
SensorApp fc28App(APP_ID_FC28, fc28);
SensorApp gy30App(APP_ID_GY30, gy30);
SensorApp pm25App(APP_ID_PM25, pm25);


/*
Test1App test1App(APP_ID_TEST1);
Test2App test2App(APP_ID_TEST2);
Test3App test3App(APP_ID_TEST3);
*/

SampleSystem curSystem(SYSTEM_ADDR_OUT);

#endif


SystemAPI API(&curSystem);

#endif
