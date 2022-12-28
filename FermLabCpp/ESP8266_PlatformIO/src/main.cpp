/************************************************************************************************
* Name:        Main.cpp
* Date:        26.Dec.2022
* Author:      Christopher Labisch
* Description:
* This file contains all the functionalities to serve as an IIoT edge of node or IIoT device.
************************************************************************************************/
#include <Arduino.h>
#include <time.h>
#include <TZ.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
// not yet in use
// #include <pb.h>
// #include <pb_common.h>
// #include <pb_encode.h>
// #include <pb_decode.h>
// #include <sparkplug_b.pb.h>
#include "credentials.h"
#include "connection.h"
#include "publishBirths.h"

// TODO: Sparkplug B Device Specifications
// const char namespace = "SpBv1.0";
// const char groupID = "BR1L";
// const char edgeNodeId = "Edge Node ID";
// const char deviceId = "device ID";

// Example topics
const char *topic_1 = "esp8266/welcome";
const char *topic_2 = "esp8266/input1";
const char *topic_3 = "esp8266/input2";
const char *topic_4 = "esp8266/output1";

WiFiClient espClient;
PubSubClient mosq_client(espClient);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, HIGH);

  // WiFi and Mosquitto setup
  Serial.begin(9600);
  setup_wifi(wifi_ssid, wifi_password);
  mosq_client.setServer(mosq_server, mosq_port);
  mosq_client.setCallback(mosq_callback);
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

  // TODO: publish Birth Certificates
  publishBirthCertificates();

  // example code
  mosq_client.publish(topic_1, "hello ESP8266 Mosquitto");
  // TODO: incoming JSON strings that excced a certain size are not displayed anymore.
  // Find out whether Serial.println() or mosq_callback() has a buffer overflow.
  mosq_client.subscribe(topic_2);
  mosq_client.subscribe(topic_3);
}

void loop() {
  // example code
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  mosq_client.publish(topic_4, "output1");
  mosq_client.loop();
}