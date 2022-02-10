/* Code written by Adien Louvrier and based on this page : https://passionelectronique.fr/tutorial-nrf24l01/
 * 
 * Objective : control a distant led using RF communication by pressing a button
 * Card used : Arduino Nano
 * 
 * Electronic Circuit :
 * 
 * input :
 * - A button connected to 5V and pin 4 with a 10kOhms resistor in parallel connected to 5V and grd
 * 
 * output :
 * - led with 330 Ohms resistor connected to pin 2 and grd
 */

#include <SPI.h>
#include <RF24.h>

#define pinCE     9         // We associate the "CE" pin of the NRF24L01 to the digital output D7 of the Arduino
#define pinCSN    10         // We associate the "CSN" pin of the NRF24L01 to the digital output D8 of the Arduino
#define button 4
#define led 2

#define tunnel1 "PIPE2"     // We define the first name of pipe (5 characters) to be able to send data to the other NRF24
#define tunnel2 "PIPE1"     //We define the second name of pipe (5 characters) to be able to send data to the other NRF24
/* ----- Note that the inversion between PIPE1 and PIPE2 for the two electric circuit (each pipe conveys the information only in one direction */

RF24 radio(pinCE, pinCSN);  // instantiation of the NRF24L01

const byte adresses[][6] = {tunnel1, tunnel2};    // Table of tunnel addresses, in "byte array" format

int localButtonState = 0; // state of the local button from this circuit
int otherButtonState = 0; // state of the distant button from the circuit
byte ledState = 0; // state of the led (1 if on, 0 if off)

void changeLedState();

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  radio.begin();                           // initialisation of the NRF24 module
  radio.openWritingPipe(adresses[0]);      // Opening of the "pipe1" in WRITING
  radio.openReadingPipe(1, adresses[1]);   // Opening of the "pipe2" en READING
  radio.setPALevel(RF24_PA_MIN);           // Selection of a "MINIMUM" level to communicate (no need for high power, for our use)

  delay(2000);              // then start the program
}

void loop() {
  // ******** SENDING ********
  if (digitalRead(button) && !localButtonState) {
    localButtonState = 1;
  }
  if (!digitalRead(button) && localButtonState) {
    localButtonState = 0;
  }
  radio.write(&localButtonState, sizeof(localButtonState));
  radio.stopListening();                                                  // We start by stopping the listening mode, so we can transmit the data
  delay(5);                                                               // with a short break, before moving on

  // ******** RECEIVING ********
  radio.startListening();                                                 // We start by stopping the sending mode, to be able to receive data
  if(radio.available()) {                                                 // See if any data has been received
    while (radio.available()) {                                           // If a data is waiting to be read, we will read it
      radio.read(&otherButtonState, sizeof(otherButtonState));
    }
    delay(20);                                                             // with a short break, before doing it again
  }
  
  if (otherButtonState) {
    changeLedState();
    otherButtonState = 0;
  }
  delay(5);
}

void changeLedState() {
  if (!ledState) { // if the led is off, turn it on
    digitalWrite(led, HIGH);
    ledState = 1;
  } else { // if the led is on, turn it off
    digitalWrite(led, LOW);
    ledState = 0;
  }
}
