#include <SoftwareSerial.h>
SoftwareSerial Genotronex(10, 11);
int flame = 3;
int door = 4;
int infrared=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(flame,INPUT);
  pinMode(door,INPUT);
  digitalWrite(door,HIGH);
  pinMode(infrared,INPUT);
  Genotronex.begin(38400);
 // Genotronex.println("Bluetooth ON");
}

void loop() {
  // put your main code here, to run repeatedly:
  String f = "off";
  String d = "off";
  String i = "off";

  if(digitalRead(flame)==LOW){
    f = "on";
  }else{
    f = "off";
  }

  if(digitalRead(door)==LOW){
    d = "on";
  }else{
    d = "off";
  }
 
  if(digitalRead(infrared)==LOW){
    i = "on";
  }else{
    i = "off";
  }
  Genotronex.println(f+","+d+","+i);
}

