/* Objectif : contrôler un moteur pas à pas avec un joystick
 *  Date de création : 29/12/2020
 *  Auteur : Adrien Louvrier
 *  Circuit : 
 *  -un moteur pas à pas connecté à un driver connecté aux pins 6, 9, 10, 11, 5V et grd
 *  -un joystick connecté à la pin A0, 5V et grd
 */

#include <Stepper.h>

 #define joystickPin A0
 int nombrePas = 48*64;
 Stepper motor(nombrePas, 9, 11, 10, 6);

void setup() {
  motor.setSpeed(9);
  Serial.begin(9600);
}

void loop() {
  int joystickValue = analogRead(joystickPin);
  
  if (joystickValue < 300) {
    motor.step(-100);
    delay(15);
  } else if (joystickValue > 700) {
    motor.step(100);
    delay(15);
  }

  Serial.println(joystickValue);
}
