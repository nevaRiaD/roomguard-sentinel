// wifiCredentials.h

#ifndef WIFI_CREDENTIALS_H
#define WIFI_CREDENTIALS_H

// credentials to log onto wifi
extern const char* ssid;
extern const char* password;

void setWiFiCredentials(const char* ssid_value, const char* password_value);

#endif // WIFI_CREDENTIALS_H