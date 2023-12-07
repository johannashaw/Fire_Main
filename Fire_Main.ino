#include "FastLED.h"

#define NUM_LEDS  60     // Enter the total number of LEDs on the strip
#define PIN       7      // The pin connected to DATA line to control the LEDs

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);    // Set power limit of LED strip to 5V, 1500mA
  FastLED.clear();                                    // Initialize all LEDs to "OFF"
}

void loop() {
  static int FlameHeight = 50;    // inverse logic; large num => small flame
  static int Sparks=100;          // likelihood out of 255 that a spark generates for each strip
  static int DelayDuration=10;    // delay in ms
  static int gridWidth = 5;

  // Fire(FlameHeight, Sparks, DelayDuration);
  FireGrid(FlameHeight, Sparks, DelayDuration, gridWidth);
}
