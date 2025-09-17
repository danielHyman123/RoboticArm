#include <ESP32Servo.h>

Servo servoBase;
Servo servoArm;   // second servo

int sBasePin = 18;   // PWM pin for base servo
int sArmPin  = 19;   // PWM pin for arm servo (pick another PWM-capable pin)

int angleBase = 0;
int angleArm  = 0;

int xyzPins[] = {25, 33, 32};   // x, y, z pins

void setup() {
  // Attach both servos
  servoBase.attach(sBasePin, 500, 2400);
  servoArm.attach(sArmPin, 500, 2400);

  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);  // z axis is a button
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);

  // Map joystick Y to two different servo angles
  angleBase = map(yVal, 0, 4095, 0, 180);   // normal direction
  angleArm  = map(xVal, 0, 4095, 180, 0);   // opposite direction (optional)

  // Write angles to servos
  servoBase.write(angleBase);
  servoArm.write(angleArm);

  // Debugging
  Serial.printf("X,Y,Z: %d,\t%d,\t%d\tBase: %d\tArm: %d\n",
                xVal, yVal, zVal, angleBase, angleArm);

  delay(20);
}
