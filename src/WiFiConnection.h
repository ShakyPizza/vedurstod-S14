#ifndef WiFiConnection_h
#define WiFiConnection_h

#include "Arduino.h"

class WiFiConnection {
public:
    WiFiConnection(const char* ssid, const char* password); // Constructor with WiFi credentials.
    void connect(); // Method to initiate the WiFi connection.
    bool isConnected(); // Method to check if the WiFi is connected.
private:
    const char* _ssid; // WiFi network SSID.
    const char* _password; // WiFi network password.
};

#endif


