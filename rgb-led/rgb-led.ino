/* Code written by Adrien Louvrier, 27/12/2020
 * 
 * Objective : control a RGB led with 3 potentiometers
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * input :
 * - 3 potentiometers connected o pins A0, A3 and A5, 5V pin and grd pin
 * 
 * output :
 * - led rg potentiometer connected to pins 3, 5, 6 and grd
 */

 #define pot1Pin A0
 #define pot2Pin A2
 #define pot3Pin A4

 #define redColorPin 3
 #define greenColorPin 5
 #define blueColorPin 6

int pot1Value = 0;
int pot2Value = 0;
int pot3Value = 0;

void setup() {
  pinMode(redColorPin, OUTPUT);
  pinMode(greenColorPin, OUTPUT);
  pinMode(blueColorPin, OUTPUT);
}

void loop() {
  pot1Value = analogRead(pot1Pin);
  pot2Value = analogRead(pot2Pin);
  pot3Value = analogRead(pot3Pin);

  pot1Value = map(pot1Value, 1, 1024, 1, 255);
  pot2Value = map(pot2Value, 1, 1024, 1, 255);
  pot3Value = map(pot3Value, 1, 1024, 1, 255);

  analogWrite(redColorPin, pot1Value);
  analogWrite(greenColorPin, pot2Value);
  analogWrite(blueColorPin, pot3Value);
}
