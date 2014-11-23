#include <Adafruit_NeoPixel.h>

#define PIN 11
#define COUNT 60

int r, g, b;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  if(Serial.available() >= 7){
    if(Serial.read() == 0xff){
      
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = 0; i < 17; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      r = (int)Serial.read(); 
      g = (int)Serial.read(); 
      b = (int)Serial.read(); 
      for (int i = 17; i < 51; i++){
        strip.setPixelColor(i, r, g, b);
      }
      
      delay(5);
      strip.show();
    }
  }
}

void Random(uint8_t wait){
   for (int i = 0; i < COUNT; i++){
    strip.setPixelColor(i, random(0,255), random(0,255), random(0,255));
  }
  strip.show();
  delay(wait);
}

void ClearStrip(uint8_t wait){
  for (int i = 0; i < COUNT; i++){
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
  delay(wait);
}
