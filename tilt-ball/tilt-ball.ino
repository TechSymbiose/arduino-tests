/* Code written by Adrien Louvrier, 03/01/2021
 *
 * Objective : turn on a led with a tilt ball
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * 
 * input :
 * - tilt ball connected to pin 8 and grd pin
 * 
 * output
 * - led with 330 Ohms resistor in serial connected to pin 2 and grd pin
 */

#define tiltPin 8
#define ledPin 2

byte ledValue = 0;

void setup() {
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  tiltValue = digitalRead(tiltPin);

  if (tiltValue){ // If the ball is tilted, turn on the led
    digitalWrite(ledPin, HIGH);
  }
  else { // If the ball isn't tilted, turn off the led
    digitalWrite(ledPin, LOW);
  }
}
