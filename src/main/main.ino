#include "WiFiConnection.h"
#include "BME280Sensor.h"
#include "secrets.h"
#include <esp_task_wdt.h>
#include <LoRa.h>

#define LED_BUILTIN 2

// WiFi credentials
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

// LoRa configuration parameters
const long frequency = 433E6;  // LoRa Frequency in Hz (adjust based on your region)
//**const int csPin = 18;          // LoRa radio chip select pin
//**const int resetPin = 14;       // LoRa radio reset pin
//**const int irqPin = 26;         // LoRa radio IRQ pin

// Create sensor and WiFi objects
WiFiConnection wifi(ssid, password);
BME280Sensor bmeSensor;

void setup() {

  // Initialize the ESP32 Watchdog Timer for a 30-second timeout
  esp_task_wdt_init(30, true); // Enable panic so ESP32 restarts
  esp_task_wdt_add(NULL); // Add the current task to WDT

  Serial.println("Initializing Watchdog...");

  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for the serial connection to initialize

  // Initialize WiFi
  if (!wifi.isConnected()) {
    wifi.connect();
  }

esp_task_wdt_reset(); // Reset the WDT after successful initialization

  // Initialize BME280 Sensor
  if (!bmeSensor.begin()) {
    Serial.println("Could not find a valid BME280 sensor!");
    while (1)
      ;
  }

esp_task_wdt_reset(); // Reset the WDT after successful initialization

  // Initialize LoRa
  if (!LoRa.begin(frequency)) {
    Serial.println("Starting LoRa failed!");
    while (1)
      ;
  }

esp_task_wdt_reset(); // Reset the WDT after successful initialization

  Serial.println("Initialization completed.");
}
void loop() {
  // Ensure WiFi is connected
  if (!wifi.isConnected()) {
    Serial.println("WiFi disconnected. Attempting to reconnect...");
    wifi.connect();
  }

  // Read from BME280 sensor
  float temperature = bmeSensor.readTemperature();
  float humidity = bmeSensor.readHumidity();
  float pressure = bmeSensor.readPressure();

  // Prepare data packet
  String dataPacket = "Temp: " + String(temperature) + "C, Hum: " + String(humidity) + "%, Press: " + String(pressure / 100.0) + "hPa";

  // Send data packet over LoRa
  LoRa.beginPacket();
  LoRa.print(dataPacket);
  LoRa.endPacket();

  Serial.println(dataPacket);

  delay(10000);  // ms delay between readings and transmissions

  esp_task_wdt_reset(); // Regularly reset the WDT within loop()

  // Simulate work by delaying for a bit
  delay(1000); // Note: Consider using non-blocking delays in real applications

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  Serial.println("LED ON");
  delay(200);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  delay(200);                      // wait for a second
  Serial.println("LED OFF :)");
}