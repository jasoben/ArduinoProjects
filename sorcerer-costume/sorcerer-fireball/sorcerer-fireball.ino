#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 13
int x;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(8);
  strip.show(); // Initialize all pixels to 'off'
  x = 0;
  strip.setBrightness(255);
}

void loop() {
  uint16_t i, j, k, l, pulseLength;
  pulseLength = 9;
  
  while (x < 1)
  {
    for (j = 0; j < 255; j = j + 10)
    {
      for (i = 0; i < 50; i++)
      {
        strip.setPixelColor(i, 0, 0, 0);
        for (k = 1; k < pulseLength; k = k + 2)
        {
          strip.setPixelColor(i, j, (j * .1), 0);
          strip.setPixelColor(i + k, j, (j * .66) * random(100) / 100, 0);
          strip.setPixelColor(random(50), j, 0, 0);
          strip.setPixelColor(random(50), j * .05, j * .05, j * .05);
          for (l = 50; l < 60; l++)
          {
            strip.setPixelColor(l, min(j * 2, 255), j * .1, 0);
            strip.setPixelColor(random(10) + 50, min(j * 2, 255), 0, 0);
            strip.setPixelColor(random(10) + 50, j * .05, j * .05, j * .05);
          }
        }
        strip.show();
        delay(15);
      }  
    }
    strip.setBrightness(0);
    strip.show();
    x++;
  }
}

void fireCycle(uint8_t wait) {
  uint16_t i, j;

//  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
//    for(i=0; i< strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
//    }
//    strip.show();
//    delay(wait);
//  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  WheelPos = 255 - WheelPos;
//  if(WheelPos < 85) {
//    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  }
//  if(WheelPos < 170) {
//    WheelPos -= 85;
//    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//  WheelPos -= 170;
//  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//}
