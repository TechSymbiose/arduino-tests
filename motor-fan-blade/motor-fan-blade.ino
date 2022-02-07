  /* Objectif : piloter un moteur à l'aide d'un bouton
 *  
 *  Date de création : 26/12/2020
 *  Auteur : Adrien Louvrier
 *  Circuit :
 *  - moteur // diode, transistor, réistance 220 Ohms connecté à pin 5, 5V et grd
 */

#define button 3
#define motor 5

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(button);
  if (value){
    digitalWrite(motor, HIGH);
  }
  else{
    digitalWrite(motor, LOW);
  }
}
