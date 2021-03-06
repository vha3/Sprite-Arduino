#include <SpriteRadio.h>

/*
  This example code will configure the CC1101 radio core in the CC430 to
  transmit a PRN sequence once per second. The output signal will be MSK
  modulated at 64 kbps on a 437.24 MHz carrier.
*/

static unsigned char prn0[64] = {
  0b00000000, 0b01110110, 0b10101101, 0b01010110, 0b00010111, 0b01111010, 0b00111000, 0b10001011,
  0b10010011, 0b10110001, 0b00110001, 0b00100110, 0b00101010, 0b11110111, 0b01010011, 0b01101011,
  0b01011110, 0b11111111, 0b00000110, 0b01000111, 0b01000010, 0b01010010, 0b11101011, 0b11000100,
  0b00001101, 0b00100110, 0b01010011, 0b01001001, 0b11101110, 0b00001110, 0b11101101, 0b11110010,
  0b00000111, 0b10010010, 0b01110100, 0b00010010, 0b10111101, 0b00011000, 0b10001010, 0b00101011,
  0b10101011, 0b10001100, 0b10111110, 0b00001110, 0b00000111, 0b11011101, 0b11101000, 0b00011110,
  0b10011000, 0b01010101, 0b10111000, 0b01101000, 0b01001111, 0b11011111, 0b00111001, 0b01100011,
  0b11001011, 0b10111010, 0b01011111, 0b00100100, 0b11011010, 0b10000000, 0b01010000, 0b10111110
};

SpriteRadio m_radio = SpriteRadio(prn0, prn0);

void setup() {
  pinMode(5, OUTPUT);
  m_radio.txInit();
};


void loop() {
  
  //Blink LED, wait a second
  digitalWrite(5, HIGH);
  m_radio.rawTransmit(prn0,64);
  m_radio.rawTransmit(prn0,64);
  m_radio.rawTransmit(prn0,64);
  m_radio.rawTransmit(prn0,64);
  m_radio.rawTransmit(prn0,64);
  delay(300);
  digitalWrite(5, LOW);
  delay(700);
};
