/*
 * QueenBee for c-base / hive at 34c4
 */

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 6

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];
int posval = LOW;
int v = 100;
int vstep = 10;
int hue = 45;
long last_interval = 0;
long curr = 0;
long timespan = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

// the loop function runs over and over again forever
void loop() {
  curr = millis();
  timespan = curr - last_interval;
  if (timespan > 1000) {
    posval = !posval;
    last_interval = curr;
  }
  
  digitalWrite(2, posval);
  digitalWrite(3, posval);   // turn the LED on (HIGH is the voltage level)

  
  
  FastLED.showColor(CHSV(hue, 150, v)); 
  
  FastLED.show();
  
  delay(5);

  v = v + vstep;

  if (v > 220) {
    vstep = -1;
  }
  if (v < 120) {
    vstep = 1;
  }
  
}
