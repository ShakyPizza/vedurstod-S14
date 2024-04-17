#include "WiFiConnection.h"
#include "BME280Sensor.h"
#include "secrets.h"
#include <esp_task_wdt.h>

#define LED_BUILTIN 2


bool isBME280Available = false;
unsigned long ID = 0;

// WiFi credentials
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

// Create sensor and WiFi objects
WiFiConnection wifi(ssid, password);
BME280Sensor bmeSensor;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Ensure LED pin is set to output mode
  Serial.begin(115200);
  while (!Serial); // Wait for the serial connection to initialize
  
  Serial.println("Starting setup...");
  wifi.connect();
  // Initialize WiFi
  if (!wifi.isConnected()) {
    wifi.connect();
    if (wifi.isConnected()) {
      Serial.println("Connected to WiFi:");
    } else {
      Serial.println("Failed to connect to WiFi.");
    }
  }

  // Initialize BME280
  Serial.println("Initializing BME280...");
  if (!bmeSensor.begin()) {
    Serial.println("BME280 initialization failed!");
    isBME280Available = false;
  } else {
    Serial.println("BME280 initialized successfully.");
    isBME280Available = true;
  }

  Serial.println("Setup completed.");
}

void loop() {
  //Serial.println("Entering loop...");

  // Ensure WiFi is connected
  if (!wifi.isConnected()) {
    Serial.println("WiFi disconnected. Attempting to reconnect...");
    wifi.connect();
  }

  if (isBME280Available) {
    float temperature = bmeSensor.readTemperature();
    float humidity = bmeSensor.readHumidity();
    float pressure = bmeSensor.readPressure();

    Serial.print(ID);
    Serial.print(", ");
    Serial.print("Hitastig: ");
    Serial.print(temperature);
    Serial.print(" C");
    Serial.print(" --- ");

    Serial.print("Rakastig: ");
    Serial.print(humidity);
    Serial.print(" %");
    Serial.print(" --- ");

    Serial.print("Loftþrýstingur: ");
    Serial.print(pressure / 100.0);
    Serial.println(" hPa");
    ID++;
  } else {
    Serial.println("Skipping BME280 readings; Device not initialized.");
  }

  
  delay(5000); // Slow down the loop to make serial output readable
}