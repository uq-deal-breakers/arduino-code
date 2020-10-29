 //Install the NeoPixel library 
 #include <Adafruit_NeoPixel.h>
 
// Define what pin the neopixel is attached to and how many pins 
// XC4385 has 24 pixels, XC4380 only has 8

#define PIN 9
#define NUMPIXELS 24
// Create the object
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
pixels.begin(); //start the object 
}
void loop() 
{
for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) 
{
  for (int i = 0; i < pixels.numPixels(); i++) 
{ // For each pixel in strip...
int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue))); 
}
pixels.show(); // Update strip with new contents
delay(10); // Pause for a moment }
}
}
