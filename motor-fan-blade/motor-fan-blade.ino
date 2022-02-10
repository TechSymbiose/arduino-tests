/* Code written by Adrien Louvrier, 26/12/2020
 * 
 * Objective : control a DC motor with a button
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * 
 * input :
 * - A button connected to 5V and pin 3 with a 10kOhms resistor in parallel connected to 5V and grd
 * 
 * output :
 * - DC motor in parallel with a diode, transistor and 220 Ohms resistor connected to pin 5, 5V and grd
 */

#define buttonPin 3
#define motorPin 5

byte buttonValue = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  if (buttonValue){
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }
}
