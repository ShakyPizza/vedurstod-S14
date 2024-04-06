// WiFiConnection.cpp
#include "WiFiConnection.h"
#include <WiFi.h> // Include the ESP32 WiFi library

// Constructor implementation
WiFiConnection::WiFiConnection(const char* ssid, const char* password) {
    _ssid = ssid;
    _password = password;
}

// Method to connect to WiFi
void WiFiConnection::connect() {
    Serial.begin(115200); // Start the Serial communication
    Serial.println("Connecting to WiFi...");
    
    WiFi.begin(_ssid, _password); // Start the WiFi connection with the provided SSID and password
    
    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500); // Wait for 500 milliseconds
        Serial.print("."); // Print dots on the Serial monitor as a progress indicator
    }
    
    // Once connected:
    Serial.println("");
    Serial.println("WiFi Connected.");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // Print the IP address assigned to the ESP32
}

// Method to check if the WiFi is connected
bool WiFiConnection::isConnected() {
    return WiFi.status() == WL_CONNECTED; // Return true if connected, false otherwise
}

