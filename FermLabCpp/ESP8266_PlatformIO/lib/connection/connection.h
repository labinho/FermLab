#include <PubSubClient.h>

void setup_wifi(const char *wifi_ssid, const char *wifi_password); 
void mosq_callback(char *topic, byte *payload, unsigned int length);