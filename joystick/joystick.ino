/* Code written by Adrien Louvrier, 27/12/2020
 * 
 * Objective : test a joystick printing values on the monitor
 * Card used : Arduino Uno
 * 
 * Electronic Circuit :
 * input :
 *  - joystick (x axis pin -> pin A0, y axis pin -> A1, switch pin -> pin 2, Vcc pin -> pin 5V, grd pin -> grd pin)
 * 
 * output : none
 */

 #define Vrx A0
 #define Vry A1

 #define switch 2

void setup() {
  pinMode(switch, INPUT);
  Serial.begin(9600);
}

void loop() {
  int VrxValue = analogRead(Vrx);
  int VryValue = analogRead(Vry);
  int switchValue = digitalRead(switch);

  Serial.print("X axis : ");
  Serial.print(VrxValue);
  Serial.print("     ");
  Serial.print("Y axis : ");
  Serial.print(VryValue);
  Serial.print("     ");
  Serial.print("Switch : ");
  Serial.print(switchValue);
  Serial.println("");
}
