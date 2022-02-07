/* Objectif : contrôler une led rgb
 *  
 *  Date de création : 27/12/2020
 *  Auteur : Adrien Louvrier
 *  Circuit :
 *  - led rgb connectées aux pins 3, 5, 6 et grd
 *  -3 potentiomètre connectées aux pins A0, A3 et A5, 5V et grd 
 *
 */

 #define pot1 A0
 #define pot2 A2
 #define pot3 A4

 #define r 3
 #define g 5
 #define b 6

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  int pot1Value = analogRead(pot1);
  int pot2Value = analogRead(pot2);
  int pot3Value = analogRead(pot3);

  pot1Value = map(pot1Value, 1, 1024, 1, 255);
  pot2Value = map(pot2Value, 1, 1024, 1, 255);
  pot3Value = map(pot3Value, 1, 1024, 1, 255);

  analogWrite(r, pot1Value);
  analogWrite(g, pot2Value);
  analogWrite(b, pot3Value);
}
