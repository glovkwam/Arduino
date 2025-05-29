#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include "Adafruit_VL53L1X.h"

#define LED_STRIP_PIN 16  // Just one strip on GP16
#define NUM_LEDS 5        // Limit to 5 LEDs to reduce power draw

// Create single LED strip object
Adafruit_NeoPixel strip(NUM_LEDS, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_VL53L1X vl53 = Adafruit_VL53L1X(0);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize sensor
  if (!vl53.begin(0x29, &Wire)) {
    Serial.println("Failed to find VL53L1X chip");
    while(1);
  }

  // Start continuous distance measurements
  vl53.startRanging();

  // Initialize LED strip with reduced brightness
  strip.begin();
  strip.setBrightness(50);  // Reduce brightness to 50/255 to save power
  strip.show();
}

void setStripColor(uint8_t r, uint8_t g, uint8_t b) {
  for(int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}

void loop() {
  if (vl53.dataReady()) {
    int distance = vl53.distance();
    
    // Print distance for debugging
    Serial.print("Distance (mm): ");
    Serial.println(distance);

    // Map distance to LED colors
    if (distance < 200) {
      setStripColor(255, 0, 0);  // Red for close
    } 
    else if (distance < 500) {
      setStripColor(0, 255, 0);  // Green for medium
    }
    else {
      setStripColor(0, 0, 255);  // Blue for far
    }

    vl53.clearInterrupt();
  }
  delay(50);
}