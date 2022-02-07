/* Objectif : piloter un moteur à l'aide d'un L293D
 * Carte utilisée : Arduino Uno
 * Date de création : 04/02/2021
 * Auteur : Adrien Louvrier
 * Circuit :
 * - un L293D connecté à 5V, grd et aux pins 9, 10 et 11
 * - un potentiomètre connecté à A0, 5V et grd
 * - un moteur connecté au L293D
 */

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int mesure = analogRead(A0);
  analogWrite(11, mesure / 4);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
