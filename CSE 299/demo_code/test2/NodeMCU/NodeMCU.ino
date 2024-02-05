#include <SoftwareSerial.h>
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

SoftwareSerial NodeMCU(D1,D2);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "adca6458a1da43fd9b462221a82c4d90";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Moin";
char pass[] = "102030406";

//define all the pins
int blynkPin=D0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  NodeMCU.begin(4800);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  if (digitalRead(blynkPin)==HIGH){
      NodeMCU.print("1");
      NodeMCU.println("\n");
      delay(30);
  }else{
      NodeMCU.print("0");
      NodeMCU.println("\n");
  }
      

}
