
// PROJET AVEC ESP8266 QUI REÇOIT DES COMMANDES DU GOOGLE HOME POUR PILOTER DES FIXTURES EN DMX
// CETTE VERSION EST TRÈS BASIQUE MAIS FONCTIONNE PARFAITEMENT                       
// POUR CE PROJET J'AI UTILISÉ UN WEMOS D1 MINI AVEC SN75176 SUR PIN D4, UN GOOGLE HOME (TESTÉ AUSSI SUR ANDROID)
// 7 X LAMPE DEL RGB 3CH, IFTT ET ADAFRUIT.IO

// MERCI À CLAUDE HEINTZ POUR LA LIBRAIRIE DMX ET ADAFRUIT POUR LE SERVICE MQTT

// https://github.com/adafruit/Adafruit_MQTT_Library
// https://github.com/claudeheintz/LXESP8266DMX

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h" 
#include "Adafruit_MQTT_Client.h"
#include <LXESP8266UARTDMX.h> 

#define WLAN_SSID       "NOM-DU-WIFI" // NOM DU WIFI
#define WLAN_PASS       "MOT-DE-PASSE-DU-WIFI" // MOT DE PASSE

#define AIO_SERVER      "io.adafruit.com" // ON LAISSE L'ADRESSE
#define AIO_SERVERPORT  1883 // ON LAISSE LE PORT
#define AIO_USERNAME    "USER-NAME" // NOM DU USER ADAFRUIT.IO
#define AIO_KEY         "KEY-ADAFRUIT.IO" // CLÉ ADAFRUIT.IO

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe lampe = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/lampe");

void MQTT_connect();

void setup() {
  ESP8266DMX.startOutput();
  WiFi.mode(WIFI_STA); // PAS NÉCESSAIRE ! 
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  mqtt.subscribe(&lampe);
}
uint32_t x = 0;

void loop() {
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(3000))) {

  if (subscription == &lampe) {

      if (strcmp((char *)lampe.lastread, "rouge") == 0) {
          dmxrouge();
      }
      if (strcmp((char *)lampe.lastread, "verte") == 0) {
          dmxvert();
      }
      if (strcmp((char *)lampe.lastread, "bleue") == 0) {
          dmxbleu();
      }
      if (strcmp((char *)lampe.lastread, "jaune") == 0) {
          dmxjaune();
      }
      if (strcmp((char *)lampe.lastread, "magenta") == 0) {
          dmxmagenta();
      }
      if (strcmp((char *)lampe.lastread, "cyan") == 0) {
          dmxcyan();
      }
      if (strcmp((char *)lampe.lastread, "blanche") == 0) {
          dmxblanc();
      }
      if (strcmp((char *)lampe.lastread, "noire") == 0) {
          dmxblack();
      }
      if (strcmp((char *)lampe.lastread, "chroma") == 0) {
          dmxrainbow();
      }
    if (strcmp((char *)lampe.lastread, "multicolore") == 0) {
          dmxchase();
          
      }
    }
    } /// REMET EN BOUCLE LE CHASE --- A MODIFIER
      if (strcmp((char *)lampe.lastread, "multicolore") == 0) {
          dmxchase();
  }
}

void MQTT_connect() {
  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {
    mqtt.disconnect();
    delay(3000);
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
}
 void dmxrouge() {
  ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,0);
}
void dmxvert() {
  ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,0);
}
void dmxbleu() {
  ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,255);
}
void dmxjaune() {
  ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,0);
}
void dmxcyan() {
  ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,255); 
}
void dmxmagenta() {
  ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,255);
}
void dmxblanc() {
  ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,255);
}
void dmxblack() {
  ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,0);
}
void dmxrainbow() {
  ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,255);
}
void dmxchase() {
 ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,0);
 delay(500);
 ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,0);
 delay(500);
 ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,0);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,0);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,0);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,0);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,0);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,0);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,0);
 delay(500);
 ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,255);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,255);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,255);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,255);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,255);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,255);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,255);
  ESP8266DMX.setSlot(21,255); 
 delay(500);
 ESP8266DMX.setSlot(1,0);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,0);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,0);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,0);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,0);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,0);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,0);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,255);
 delay(500);
 ESP8266DMX.setSlot(1,255);
  ESP8266DMX.setSlot(2,0);
  ESP8266DMX.setSlot(3,255);
  ESP8266DMX.setSlot(4,255);
  ESP8266DMX.setSlot(5,0);
  ESP8266DMX.setSlot(6,255);
  ESP8266DMX.setSlot(7,255);
  ESP8266DMX.setSlot(8,0);
  ESP8266DMX.setSlot(9,255);
  ESP8266DMX.setSlot(10,255);
  ESP8266DMX.setSlot(11,0);
  ESP8266DMX.setSlot(12,255);
  ESP8266DMX.setSlot(13,255);
  ESP8266DMX.setSlot(14,0);
  ESP8266DMX.setSlot(15,255);
  ESP8266DMX.setSlot(16,255);
  ESP8266DMX.setSlot(17,0);
  ESP8266DMX.setSlot(18,255);
  ESP8266DMX.setSlot(19,255);
  ESP8266DMX.setSlot(20,0);
  ESP8266DMX.setSlot(21,255);
 delay(500);
 }
