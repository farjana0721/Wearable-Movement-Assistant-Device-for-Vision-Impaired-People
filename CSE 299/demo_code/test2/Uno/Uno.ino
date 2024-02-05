#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(0,1);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  ArduinoUno.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ArduinoUno.available()>0){
    int val=ArduinoUno.parseInt();
    if (ArduinoUno.read()=='\n'){
      Serial.println(val);
    }
  }
  delay(30);

}
