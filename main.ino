#define BLYNK_TEMPLATE_ID "TMPL4xGTbiQit"
#define BLYNK_TEMPLATE_NAME "Safe"
#define BLYNK_AUTH_TOKEN "nP88RDtkGIRUUoiSmtQe5XL4CdVLUJwJ"

#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Mr.sexobeat";
char pass[] = "gzmg0156";

BlynkTimer timer;

void setup(){
  pinMode(4, INPUT_PULLUP);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //timer.setInterval(2500L, notify);

}

int flag=0;
void notify()
{
  int isButtonPressed = digitalRead(4);
 
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Unlock Request");
     //Blynk.email("shameer50@gmail.com", "Alert", "It's Raining");
     Blynk.logEvent("unlockrequest","Unlock Request");
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
  }
}

void loop(){
  Blynk.run();
  notify();
  //timer.run();
}
