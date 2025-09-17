#include <dummy.h>

#include <ESP32Servo.h>

Servo servoBase;

int sBasePin = 18; //PwM capable pin
int angleBase = 0;

int xyzPins[] = {25, 33, 32};   //x,y,z pins


void setup() {
  // put your setup code here, to run once:
  servoBase.attach(sBasePin, 500, 2400); 

  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  //z axis is a button.

}

void loop() {
  // put your main code here, to run repeatedly:


  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  angleBase = map(yVal, 0, 4095, 0, 180);
  servoBase.write(angleBase);
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);
  // delay(1000);
}
