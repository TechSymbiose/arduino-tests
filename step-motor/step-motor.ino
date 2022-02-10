/* Code written by Adrien Louvrier, 29/12/2020
 *
 * Objective : control a step motor with a joystick
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * 
 * input :
 * - a joystick connected to pin A0, 5V and grd
 * 
 * output :
 * - a step motor connected to a driver connected to pins 6, 6, 10 and 11, 5V and grd pins
 * 
 * 
 */

#include <Stepper.h>

 #define joystickPin A0

 int stepNumber = 48*64;
 int joystickValue = 0;
 Stepper motor(stepNumber, 9, 11, 10, 6);

void setup() {
  motor.setSpeed(9);
}

void loop() {
  joystickValue = analogRead(joystickPin);
  
  if (joystickValue < 300) { // 
    motor.step(-100);
    delay(15);
  } else if (joystickValue > 700) {
    motor.step(100);
    delay(15);
  }

}
