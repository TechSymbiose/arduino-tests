/* Code written by Arien Louvrier
 * 
 * Objective : print the digicode input on the serial monitor
 * Card used : Arduino Mega 2560
 * 
 * Electronic Circuit :
 * 
 * input :
 * - digicode (lines connected to pins 39, 37, 35, 33, columns connected to pins 29, 27, 25, 23)
 * 
 * output : none
 */

#define line0Pin 39
#define line1Pin 37
#define line2Pin 35
#define line3Pin 33

#define column0Pin 29
#define column1Pin 27
#define column2Pin 25
#define column3Pin 23

void setup() {
  // Setup the lines in output mode
  pinMode(line0Pin, OUTPUT);
  pinMode(line1Pin, OUTPUT);
  pinMode(line2Pin, OUTPUT);
  pinMode(line3Pin, OUTPUT);

  // Setup the columns in input mode with pull-up
  pinMode(column0Pin, INPUT_PULLUP);
  pinMode(column1Pin, INPUT_PULLUP);
  pinMode(column2Pin, INPUT_PULLUP);
  pinMode(column3Pin, INPUT_PULLUP);  

  Serial.begin(9600);
}

void loop() {
  int column0PinState = HIGH;
  int column1PinState = HIGH;
  int column2PinState = HIGH;
  int column3PinState = HIGH;

  // On met la ligne 0 à 0V et les autres au 5V
  digitalWrite(line0Pin, LOW);
  digitalWrite(line1Pin, HIGH);
  digitalWrite(line2Pin, HIGH);
  digitalWrite(line3Pin, HIGH);

  // On recupère l'état des colonnes
  column0PinState = digitalRead(column0Pin);
  column1PinState = digitalRead(column1Pin);
  column2PinState = digitalRead(column2Pin);
  column3PinState = digitalRead(column3Pin);

  // Si on a la colonne 0 à LOW, c'est que le bouton 1 est pressé
  if(column0PinState == LOW) {
    Serial.println("1");
  }

  // Si on a la colonne 1 à LOW, c'est que le bouton 2 est pressé
  if(column1PinState == LOW) {
    Serial.println("2");    
  }

    // Si on a la colonne 2 à LOW, c'est que le bouton 3 est pressé
  if(column2PinState == LOW) {
    Serial.println("3");    
  }

    // Si on a la colonne 3 à LOW, c'est que le bouton A est pressé
  if(column3PinState == LOW) {
    Serial.println("A");   
  }

  // On met la ligne 1 à 0V et les autres au 5V
  digitalWrite(line0Pin, HIGH);
  digitalWrite(line1Pin, LOW);
  digitalWrite(line2Pin, HIGH);
  digitalWrite(line3Pin, HIGH);

  // On recupère l'état des colonnes
  column0PinState = digitalRead(column0Pin);
  column1PinState = digitalRead(column1Pin);
  column2PinState = digitalRead(column2Pin);
  column3PinState = digitalRead(column3Pin);

  // Si on a la colonne 0 à LOW, c'est que le bouton 4 est pressé
  if(column0PinState == LOW) {
    Serial.println("4");
  }

  // Si on a la colonne 1 à LOW, c'est que le bouton 5 est pressé
  if(column1PinState == LOW) {
    Serial.println("5");    
  }

    // Si on a la colonne 2 à LOW, c'est que le bouton 6 est pressé
  if(column2PinState == LOW) {
    Serial.println("6");    
  }

    // Si on a la colonne 3 à LOW, c'est que le bouton B est pressé
  if(column3PinState == LOW) {
    Serial.println("B");    
  }

  // On met la ligne 2 à 0V et les autres au 5V
  digitalWrite(line0Pin, HIGH);
  digitalWrite(line1Pin, HIGH);
  digitalWrite(line2Pin, LOW);
  digitalWrite(line3Pin, HIGH);

  // On recupère l'état des colonnes
  column0PinState = digitalRead(column0Pin);
  column1PinState = digitalRead(column1Pin);
  column2PinState = digitalRead(column2Pin);
  column3PinState = digitalRead(column3Pin);

  // Si on a la colonne 0 à LOW, c'est que le bouton 7 est pressé
  if(column0PinState == LOW) {
    Serial.println("7");
  }

  // Si on a la colonne 1 à LOW, c'est que le bouton 8 est pressé
  if(column1PinState == LOW) {
    Serial.println("8");    
  }

    // Si on a la colonne 2 à LOW, c'est que le bouton 9 est pressé
  if(column2PinState == LOW) {
    Serial.println("9");    
  }

    // Si on a la colonne 3 à LOW, c'est que le bouton C est pressé
  if(column3PinState == LOW) {
    Serial.println("C");   
  }  

  // On met la ligne 3 à 0V et les autres au 5V
  digitalWrite(line0Pin, HIGH);
  digitalWrite(line1Pin, HIGH);
  digitalWrite(line2Pin, HIGH);
  digitalWrite(line3Pin, LOW);

  // On recupère l'état des colonnes
  column0PinState = digitalRead(column0Pin);
  column1PinState = digitalRead(column1Pin);
  column2PinState = digitalRead(column2Pin);
  column3PinState = digitalRead(column3Pin);

  // Si on a la colonne 0 à LOW, c'est que le bouton * est pressé
  if(column0PinState == LOW) {
    Serial.println("*");
  }

  // Si on a la colonne 1 à LOW, c'est que le bouton 0 est pressé
  if(column1PinState == LOW) {
    Serial.println("0");   
  }

    // Si on a la colonne 2 à LOW, c'est que le bouton # est pressé
  if(column2PinState == LOW) {
    Serial.println("#");    
  }

    // Si on a la colonne 3 à LOW, c'est que le bouton D est pressé
  if(column3PinState == LOW) {
    Serial.println("D");   
  }
}