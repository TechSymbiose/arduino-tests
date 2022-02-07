/* Objectif : contrôler un servomoteur à l'aide d'un joystick
 *  
 *  Date de création : 28/12/2020
 *  Auteur : Adrien Louvrier
 *  Circuit :
 *  - un joystick connecté à A0, 5V et grd
 *  - un servomoteur connecté à la pin 2, 5V et grd 
 */

 #include <Servo.h>

 #define servoPin 2
 #define joystickPin A0

 Servo servo;
int value = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(90);
  delay(2000);
}

void loop() {
  int joystickValue = analogRead(joystickPin);
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
