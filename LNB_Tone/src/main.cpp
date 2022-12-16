#include <avr/io.h>

int main() {
  DDRB |= (1<<PB1); //PB1 (pin 6) as clock output
  DDRB |= (1<<PB2); //PB2 (pin 7) as LED output

  TCCR0A |= (1 << COM0A0); //toggle OC0A (pin 6)
  TCCR0A |= (1 << WGM01); //CTC mode
  TCCR0B |= (1 << CS00); // no prescaler

  // This value determines the output frequency
  // fOCnx = fclk / (2 * N * (1+OCRnx))
  OCR0A = 181; //21.978khz

  while(1) {

  }
}