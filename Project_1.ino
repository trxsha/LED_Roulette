#include <avr/io.h> // contains uint8_t and register definitions
#include <avr/delay.h> // contains the delay function
#include "USART.h"


void sweepLight(int startBit, int stopBit) {
  DDRD = 0xFC;
  int duration = 50;

  boolean pressed = (PINB & 0b00100000);

  if (!pressed) {

    for (int light = startBit; light <= stopBit; light++) {
      PORTD = 1 << light;
      _delay_ms(duration);
      if (PINB & 0b00100000) {
        _delay_ms(1000);
        break;
      }
      //levels();
      pop();
    }
    for (int light = stopBit; light >= startBit; light--) {
      PORTD = 1 << light;
      _delay_ms(duration);
      if (PINB & 0b00100000) {
        _delay_ms(1000);
        break;
      }
      //levels();
      pop();
    }
  }
}


void levels() {
  boolean pressed1 = (PINB & 0b00010000);

  if (pressed1) {
    _delay_ms(25);
  }
  else {
    _delay_ms(100);
  }
}

void pop() {
  int r = rand() % 6;

  boolean pressed1 = (PINB & 0b00010000);

  if (pressed1) {
    //printString("HI");
    if (r == 0) {
      PORTD = 0x00;
      PORTD = 0b10000000;
      _delay_ms(500);
    }
    if (r == 1) {
      PORTD = 0x00;
      PORTD = 0b01000000;
      _delay_ms(500);
    }
    else if (r == 2) {
      PORTD = 0x00;
      PORTD = 0b00100000;
      _delay_ms(500);
    }
    else if (r == 3) {
      PORTD = 0x00;
      PORTD = 0b00010000;
      _delay_ms(500);
    }
    else if (r == 4) {
      PORTD = 0x00;
      PORTD = 0b00001000;
      _delay_ms(500);
    }
    else if (r == 5) {
      PORTD = 0x00;
      PORTD = 0b00000100;
      _delay_ms(500);
    }
    else {
      PORTD = 0x00;
      PORTD = 0b00000010;
      _delay_ms(500);
    }

  }
}

void roulette(int startBit, int stopBit) {
  init();
  while (true) {
    // call the sweepLight repeatedly
    sweepLight(startBit, stopBit);
  }
  return 0;
}

int main() {
  roulette(1, 7);
}
