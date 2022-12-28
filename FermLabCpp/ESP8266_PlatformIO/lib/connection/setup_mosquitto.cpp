#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void setup_mosquitto(PubSubClient mosq_client, const char *mosq_username, const char *mosq_password) {
    while (!mosq_client.connected()) {

        String mosq_client_id = "ESP8266-";
        mosq_client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", mosq_client_id.c_str());
        
        if (mosq_client.connect(mosq_client_id.c_str(), mosq_username, mosq_password)) {
            Serial.println("Local Mosquitto server connected");
        } else {
            Serial.print("Failed with state ");
            Serial.print(mosq_client.state());
            delay(2000);
        }
    }
}