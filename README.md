# Vedurstod-S14
An ESP32 based temperature, humidity and pressure logger for my home.

The plan is to have two ESP32's. One inside the house logging temperature and humidity and one outside measuring temperature, humidity and pressure.
The outside one will communicate via LoRa to the inside one. The inside one will be connected to my home wifi and transmit the measurements to a mySQL server running on a Linux computer in my garage.

Equipment:
2 x NodeMCU-32S, ESP32 WiFi+Bluetooth Development Board.
2 x RFM98W 433MHZ
2 x BME280-3.3V

![alt text](https://github.com/ShakyPizza/Vedurstod-S14/blob/main/BME280_Sensor_Wiring.png)?raw=true)
