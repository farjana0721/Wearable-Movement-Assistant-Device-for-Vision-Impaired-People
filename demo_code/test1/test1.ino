/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "adca6458a1da43fd9b462221a82c4d90";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Moin";
char pass[] = "102030406";

//define all the pins
int blynkPin=16;

int trigPin1=4;
int echoPin1=5;
int vibration1=13;

int trigPin2=12;
int echoPin2=14;
int vibration2=15;

/*int trigPin3=10;
int echoPin3=3;
int vibration3=9;*/

int trigPin4=2;
int echoPin4=0;
int vibration4=1;


void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(vibration1, OUTPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(vibration2, OUTPUT);
  
  /*pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(vibration3, OUTPUT);*/
  
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(vibration4, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  if (digitalRead(blynkPin)==HIGH){
      Serial.println("wala");
     
  long duration1, distance1;
  digitalWrite(vibration1, LOW);
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   if (distance1 >= 30 || distance1 <= 0){
    Serial.println("Out of range");
    digitalWrite(vibration1, LOW);
  }
  else {
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
    digitalWrite(vibration1, HIGH);
  }
  delay(100);
  
  
  long duration2, distance2;
  digitalWrite(vibration2, LOW);
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;

   if (distance2 >= 30 || distance2 <= 0){
    Serial.println("Out of range");
    digitalWrite(vibration2, LOW);
  }
  else {
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
    digitalWrite(vibration2, HIGH);
  }
  delay(100);

  
  /*long duration3, distance3;
  digitalWrite(vibration3, LOW);
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= (duration3/2) / 29.1;

   if (distance3 >= 30 || distance3 <= 0){
    Serial.println("Out of range");
    digitalWrite(vibration3, LOW);
  }
  else {
    Serial.print("Sensor3  ");
    Serial.print(distance3);
    Serial.println("cm");
    digitalWrite(vibration3, HIGH);
  }
  delay(100);*/


  long duration4, distance4;
  digitalWrite(vibration4, LOW);
  digitalWrite(trigPin4, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4= (duration4/2) / 29.1;

   if (distance4 >= 30 || distance4 <= 0){
    Serial.println("Out of range");
    digitalWrite(vibration4, LOW);
  }
  else {
    Serial.print("Sensor4  ");
    Serial.print(distance4);
    Serial.print("cm");
    digitalWrite(vibration4, HIGH);
  }
  delay(100);

  }

}
