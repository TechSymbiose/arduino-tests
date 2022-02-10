/* Code written by Adrien Louvrier, 28/12/2020
 * 
 * Objective : control a servomotor using a joystick
 * Card used : Arduino Uno
 * 
 * Electronic Circuit : control a servomotor using a joystick.
 * 
 * intput :
 * - a joystick connected to pin A0, 5V and grd
 * 
 * output :
 * - a servomotor connected to pin 2, 5V and grd
 */

 #include <Servo.h>

 #define servoPin 2
 #define joystickPin A0

int joystickValue = 0;

Servo servo;
int value = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(90);
  delay(2000);
}

void loop() {
  joystickValue = analogRead(joystickPin);
  Serial.println(joystickValue);
  
  if (joystickValue < 100 && value < 180){
    value += 10;
    servo.write(value);
    delay(15);
  }
  if (joystickValue > 1000 && value > 0){
    value -= 10;
    servo.write(value);
    delay(15);
  }
}
