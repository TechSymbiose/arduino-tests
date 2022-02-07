/* Objectif : allumer une led avec une tilt ball
 * Date de création : 03/01/2021
 * Auteur : Adrien Louvrier
 * Circuit : 
 * - une tilt ball connectée à 8 et grd
 * - une led avec résistance 330 Ohms connectée à pin 2 et grd
 */

#define tiltPin 8
#define ledPin 2

int ledValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int tiltValue = digitalRead(tiltPin);
  Serial.println(tiltValue);
  if (tiltValue){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
