/* Code written by Adrien Louvrier, 28/12/2020
 * 
 * Objective : control the speed of a motor with a joystick
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * 
 * input :
 * - motor in parallel with a diode, transistor and 220 Ohms resistor connected to pin 5, 5V and grd
 * 
 * output :
 * - joystick connected to pin A0, 5V and grd (x axis used)
 */

 #define joystickPin A0
 #define motorPin 3

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int joystickValue = analogRead(joystickPin);
  
  // Mapping of the x values of the joystickValue to control the motor from 0 to 255 
  joystickValue = map(joystickValue, 507, 1023, 0, 255);
  analogWrite(motorPin, joystickValue);

  delay(15);
}
