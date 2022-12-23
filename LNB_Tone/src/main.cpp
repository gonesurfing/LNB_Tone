#include <avr/io.h>

int main() {
  DDRB |= (1<<PB0); //PB0 (pin 5) as clock output
  DDRB |= (1<<PB4); //PB4 (pin 3) as LED output

  TCCR0A |= (1 << COM0A0); //toggle OC0A (pin 6)
  TCCR0A |= (1 << WGM01); //CTC mode
  TCCR0B |= (1 << CS00); // no prescaler

  // This value determines the output frequency
  // fOCnx = fclk / (2 * N * (1+OCRnx))
  // 1,000,000 = (2 * 1 * (1 + OCR0A))
  OCR0A = 22; //21.74khz
  PORTB |= (1<<PB4);

  while(1) {

  }
}