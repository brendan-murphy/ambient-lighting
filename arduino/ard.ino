#include <Adafruit_NeoPixel.h>

#define PIN 11

int xCount, yCount;
int r, g, b;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  if(Serial.available() >= 21){
    if(Serial.read() == 0xff){
      
      xCount = (int)Serial.read();
      yCount = (int)Serial.read();
      
      // Bottom Left
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      
      for (int i = 0; i < xCount / 2; i++){
        strip.setPixelColor(i, r, g, b);
      }
      for (int i = 2 * xCount + (5/3) * yCount; i < 2 * xCount + 2 * yCount; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      // Top Left
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = xCount / 2; i < xCount + yCount / 3; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      // Top Middle
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = xCount + yCount / 3; i < xCount + (2/3) * yCount; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      // Top Right
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = xCount + (2/3) * yCount; i < (3/2) * xCount + yCount; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      // Bottom Right
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = (3/2) * xCount + yCount; i < 2 * xCount + (4/3) * yCount; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      // Bottom Middle
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = 2 * xCount + (4/3) * yCount(3/2) * xCount + yCount; i < 2 * xCount + (5/3) * yCount; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      delay(5);
      strip.show();
    }
  }
}

void ClearStrip(uint8_t wait){
  for (int i = 0; i < COUNT; i++){
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
  delay(wait);
}
