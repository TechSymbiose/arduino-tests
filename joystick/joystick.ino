/* Objectif : tester l'utilisation d'un joystick en affichant les valeurs analogiques sur le moniteur
 *  
 *  Date de création : 27/12/2020
 *  Auteur : Adrien Louvrier
 *  Circuit :
 *  - un joystick connecté au 5V, grd, pin 2, A0 et A1
 */

 #define Vrx A0
 #define Vry A1

 #define switch 2

void setup() {
  // put your setup code here, to run once:
  pinMode(switch, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int VrxValue = analogRead(Vrx);
  int VryValue = analogRead(Vry);
  int switchValue = digitalRead(switch);

  Serial.print("Axe X : ");
  Serial.print(VrxValue);
  Serial.print("     ");
  Serial.print("Axe Y : ");
  Serial.print(VryValue);
  Serial.print("     ");
  Serial.print("Switch : ");
  Serial.print(switchValue);
  Serial.println("");
}
