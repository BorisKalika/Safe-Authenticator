#define BLYNK_TEMPLATE_ID "<yourID>"
#define BLYNK_TEMPLATE_NAME "<yourName>"
#define BLYNK_AUTH_TOKEN "<yourToken>"

#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "<yourWifiName>";
char pass[] = "<yourWifiPass>";

BlynkTimer timer;

void setup(){
  pinMode(4, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);


}
void notify()
{
   Serial.println("Unlock Request send to device");
   Blynk.logEvent("unlockrequest","");
 }

void loop(){
  Blynk.run();
  if(digitalRead(2) == HIGH){ //Lock
    delay(4000);
    digitalRead(2) == LOW;
    Serial.println("Unlock Door");
  }

  int isButtonPressed = digitalRead(4); //Notification
  if (isButtonPressed == 0) {
    notify();
   }
}
