#include <SPI.h>
#include <RF24.h>

#define pinCE     9         // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN    10         // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define button 4
#define led 2

#define tunnel1 "PIPE1"     // On définit un premier "nom de tunnel" (5 caractères), pour pouvoir envoyer des données à l'autre NRF24
#define tunnel2 "PIPE2"     // On définit un second "nom de tunnel" (5 caractères), pour pouvoir recevoir des données de l'autre NRF24

RF24 radio(pinCE, pinCSN);  // Instanciation du NRF24L01

const byte adresses[][6] = {tunnel1, tunnel2};    // Tableau des adresses de tunnel, au format "byte array"

int localButtonState = 0;
int otherButtonState = 0;
int ledState = 1;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  radio.begin();                           // Initialisation du module NRF24
  radio.openWritingPipe(adresses[0]);      // Ouverture du "tunnel1" en ÉCRITURE
  radio.openReadingPipe(1, adresses[1]);   // Ouverture du "tunnel2" en LECTURE
  radio.setPALevel(RF24_PA_MIN);           // Sélection d'un niveau "MINIMAL" pour communiquer (pas besoin d'une forte puissance, pour nos essais)

  delay(2000);              // puis démarrage du programme
}

void loop() {
  // ******** ENVOI ********
  if (digitalRead(button) && !localButtonState) {
    localButtonState = 1;
  }
  if (!digitalRead(button) && localButtonState) {
    localButtonState = 0;
  }
  radio.write(&localButtonState, sizeof(localButtonState));
  radio.stopListening();                                                  // On commence par arrêter le mode écoute, pour pouvoir émettre les données
  delay(5);                                                               // avec une petite pause, avant de passer à la suite

  // ******** RÉCEPTION ********
  radio.startListening();                                                 // On commence par arrêter le mode envoi, pour pouvoir réceptionner des données
  if(radio.available()) {                                                 // On regarde si une donnée a été reçue
    while (radio.available()) {                                           // Si une donné est en attente de lecture, on va la lire
      radio.read(&otherButtonState, sizeof(otherButtonState));
    }
    delay(20);                                                             // avec une petite pause, avant de reboucler
  }
  if (otherButtonState) {
    changeLedState();
    otherButtonState = 0;
    }
  delay(5);
}

void changeLedState() {
  if (!ledState){
    digitalWrite(led, HIGH);
    ledState = 1;
  }
  else{
    digitalWrite(led, LOW);
    ledState = 0;
  }
}
