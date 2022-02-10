/* Code written by Adrien Louvrier, 15/01/2022
 *
 * Objective : turn on and off a led using registers instead of pinMode and digitalWrite functions
 * Card used : Arduin Uno
 * 
 * Electronic Circuit :
 * 
 * input : none
 * 
 * output : 
 * - led with 330 Ohms resistor connected to pin 13
 */

#define PIN_0 B00000001
#define PIN_1 B00000010
#define PIN_2 B00000100
#define PIN_3 B00001000
#define PIN_4 B00010000
#define PIN_5 B00100000
#define PIN_6 B01000000
#define PIN_7 B10000000

#define PIN_8 B11000001
#define PIN_9 B11000010
#define PIN_10 B11000100
#define PIN_11 B11001000
#define PIN_12 B11010000
#define PIN_13 B11100000

#define INPUT_MODE 0
#define OUTPUT_MODE 1

volatile uint8_t *REGISTER_0 = &DDRC;
volatile uint8_t *REGISTER_1 = &DDRC;
volatile uint8_t *REGISTER_2 = &DDRC;
volatile uint8_t *REGISTER_3 = &DDRC;
volatile uint8_t *REGISTER_4 = &DDRC;
volatile uint8_t *REGISTER_5 = &DDRC;
volatile uint8_t *REGISTER_6 = &DDRC;
volatile uint8_t *REGISTER_7 = &DDRC;

volatile uint8_t *REGISTER_8 = &DDRB;
volatile uint8_t *REGISTER_9 = &DDRB;
volatile uint8_t *REGISTER_10 = &DDRB;
volatile uint8_t *REGISTER_11 = &DDRB;
volatile uint8_t *REGISTER_12 = &DDRB;
volatile uint8_t *REGISTER_13 = &DDRB;

volatile uint8_t *PORT_0 = &PORTC;
volatile uint8_t *PORT_1 = &PORTC;
volatile uint8_t *PORT_2 = &DDRC;
volatile uint8_t *PORT_3 = &PORTC;
volatile uint8_t *PORT_4 = &PORTC;
volatile uint8_t *PORT_5 = &PORTC;
volatile uint8_t *PORT_6 = &PORTC;
volatile uint8_t *PORT_7 = &PORTC;

volatile uint8_t *PORT_8 = &PORTB;
volatile uint8_t *PORT_9 = &PORTB;
volatile uint8_t *PORT_10 = &PORTB;
volatile uint8_t *PORT_11 = &PORTB;
volatile uint8_t *PORT_12 = &PORTB;
volatile uint8_t *PORT_13 = &PORTB;

#define ledPin PIN_13
volatile uint8_t *ledRegister = REGISTER_13;
volatile uint8_t *ledPort = PORT_13;

void setPin(volatile uint8_t *reg, int pin, int mode);
void writePin(volatile uint8_t *port, int pin, int state);


void setup() {
  setPin(ledRegister, ledPin, OUTPUT_MODE);
}

void loop() {
  writePin(ledPort, ledPin, LOW);
  delay(500);
  writePin(ledPort, ledPin, HIGH);
  delay(500);
}

void setPin(volatile uint8_t *reg, int pin, int mode) {
  if (mode == INPUT_MODE) {
    (*reg) = (*reg) & (pin ^ B11111111);
  }
  else {
    (*reg) = (*reg) | pin;
  }
}

void writePin(volatile uint8_t *port, int pin, int state) {
  if (state == LOW) {
    (*port) = (*port) & (pin ^ B11111111);
  }
  else {
    (*port) = (*port) | pin;
  }
}
