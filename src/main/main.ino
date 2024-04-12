#include "WiFiConnection.h"
#include "BME280Sensor.h"
#include "secrets.h"
#include <esp_task_wdt.h>
#include <LoRa.h>

#define LED_BUILTIN 2

// Global flag to track status for BME280 and LoRa
bool isBME280Available = false;
bool isLoRaAvailable = false;

// WiFi credentials
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

// LoRa configuration parameters
const long frequency = 433E6;  // LoRa Frequency in Hz (adjust based on your region)
const int csPin = 18;          // LoRa radio chip select pin
const int resetPin = 14;       // LoRa radio reset pin
const int irqPin = 26;         // LoRa radio IRQ pin

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
  //if (!wifi.isConnected()) {
    //Serial.println("Connecting to WiFi...");
    //wifi.connect();
    //if (wifi.isConnected()) {
      //Serial.println("Connected to WiFi.");
    //} else {
      //Serial.println("Failed to connect to WiFi.");
    //}
  //}

  // Initialize BME280
  Serial.println("Initializing BME280...");
  if (!bmeSensor.begin()) {
    Serial.println("BME280 initialization failed!");
    isBME280Available = false;
  } else {
    Serial.println("BME280 initialized successfully.");
    isBME280Available = true;
  }

  // Initialize LoRa
  //Serial.println("Initializing LoRa...");
  //if (!LoRa.begin(frequency)) {
    //Serial.println("LoRa initialization failed!");
    //isLoRaAvailable = false;
  //} else {
    //Serial.println("LoRa initialized successfully.");
    //isLoRaAvailable = true;
  //}

  Serial.println("Setup completed.");
}

void loop() {
  Serial.println("Entering loop...");

  // Ensure WiFi is connected
  if (!wifi.isConnected()) {
    Serial.println("WiFi disconnected. Attempting to reconnect...");
    wifi.connect();
  } else {
    Serial.println("WiFi is still connected.");
  }

  if (isBME280Available) {
    float temperature = bmeSensor.readTemperature();
    float humidity = bmeSensor.readHumidity();
    float pressure = bmeSensor.readPressure();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(pressure / 100.0);
    Serial.println(" hPa");
  } else {
    Serial.println("Skipping BME280 readings; Device not initialized.");
  }

  if (isLoRaAvailable) {
    Serial.println("Sending data via LoRa...");
    LoRa.beginPacket();
    LoRa.print("Hello LoRa");
    LoRa.endPacket();
    Serial.println("Data sent.");
  } else {
    Serial.println("Skipping LoRa; Device not initialized.");
  }

  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on
  delay(200);                        // Wait for 200 ms
  digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off
  delay(200);                        // Wait for 200 ms

  Serial.println("Exiting loop.");
  delay(1000); // Slow down the loop to make serial output readable
}
