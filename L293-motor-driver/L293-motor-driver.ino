/* Code written by Adrien Louvrier
 * 
 * Objective : motor control with a L293D motor driver
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * 
 * input :
 * - potentiometer (X axis pin -> pin A0, Vcc pin -> 5V pin, grd pin -> grd pin)
 * 
 * output :
 * - L293 motor driver (IN1 pin -> pin 9, IN2 pin -> pin 10, Vcc pin -> 5V pin, grd pin -> grd pin) with DC motor connected to A+ and A-
 */

#define potXPin A0
#define speedPin 11
#define IN1 9
#define IN2 10

int potValue = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop() {
  potValue = analogRead(potXPin);

  analogWrite(speedPin, potValue / 4);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
