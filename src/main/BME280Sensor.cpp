//BME280Sensor.cpp
#include "BME280Sensor.h"

BME280Sensor::BME280Sensor() {}

// Initialize the BME280 sensor
bool BME280Sensor::begin(uint8_t address) {
    return bme.begin(address);
}

// Read temperature in Celsius
float BME280Sensor::readTemperature() {
    return bme.readTemperature();
}

// Read humidity percentage
float BME280Sensor::readHumidity() {
    return bme.readHumidity();
}

// Read pressure in Pa
float BME280Sensor::readPressure() {
    return bme.readPressure();
}
