#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <time.h>
#include <TZ.h>

#include "pb.h"
#include "pb_common.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "sparkplug_b.pb.h"

#include "credentials.h"

extern char *tzname[2];

org_eclipse_tahu_protobuf_Payload payload = org_eclipse_tahu_protobuf_Payload_init_zero;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

time_t setDateTime() {
  configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(100);
    now = time(nullptr);
  }
  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
  return now;
}

uint64_t getSeqNo() {
  if (payload.seq == 256) {
    payload.seq = 0;
  }
  payload.seq++;
  return payload.seq;
}

void setup() {
  delay(500);
  Serial.begin(9600);
  delay(500);
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, HIGH);
  setup_wifi();
  time_t current_time = setDateTime();

  payload.has_timestamp = true;
  payload.timestamp = current_time;

  payload.has_seq = true;
  payload.seq = 0;
}

void generate_random_payload() {

  payload.timestamp = setDateTime();
  payload.seq = getSeqNo();

  Serial.print("payload [");

  Serial.print("timestamp=");
  Serial.print(payload.timestamp);
  Serial.print(", ");
  
  Serial.print("seq=");
  Serial.print(payload.seq);
  Serial.println("]");
}

void loop() {
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  generate_random_payload();
}