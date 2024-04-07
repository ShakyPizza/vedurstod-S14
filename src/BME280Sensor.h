//BME280Sensor.h

#ifndef BME280Sensor_h
#define BME280Sensor_h

#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Sensor {
public:
    BME280Sensor();
    bool begin(uint8_t address = BME280_ADDRESS_ALTERNATE);
    float readTemperature();
    float readHumidity();
    float readPressure();
private:
    Adafruit_BME280 bme; // Use Adafruit's BME280 library to interface with the sensor
};

#endif
