 // SMC prototype by Aurelie, Jerome, Sajjad and Sindre

#include <Adafruit_NeoPixel.h>
 
#define PIN 9 //for light control
#define NUM_LEDS 24 //Number of leds in light

const int PLAYE=4; //Port for triggerig sound effects
 
int sensor1 = 2;               // Input for sensor 1
int sensor2 = 3;               // Input for sensor 2  

int val1 = LOW;
int val2 = LOW; // variable for reading the pin status

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);

//Set colours
uint32_t red = strip.Color(255, 0, 0); 
uint32_t blue = strip.Color(0, 0, 255);
uint32_t white = strip.Color(255, 255, 255);

void setup() {
  //Setup sensors
  pinMode(sensor1, INPUT);     // declare sensors as input
  pinMode(sensor2, INPUT);
  
  //Setup for light
  strip.begin();
  strip.show(); //Initialize
  strip.setBrightness(64); // set brightness (0-255)
  Serial.begin(9600);
}

void loop() {
  val1 = digitalRead(sensor1);
  val2 = digitalRead(sensor2);
  
  if (val1 == HIGH) {
    Serial.println("Sensor1 detected!");
    strip.clear();
    strip.fill(red); //set colour
    strip.show(); 
    delay(1000);
    digitalWrite(PLAYE, HIGH); 
    Serial.println("PLaying"); 
    digitalWrite(PLAYE, LOW);
    delay(4000);
    digitalWrite(val1, LOW);    
  } 
  if (val2 == HIGH) 
 {
    Serial.println("Sensor2 detected!");
    strip.clear();
    strip.fill(blue); //set colour
    strip.show(); 
    delay(1000);
    digitalWrite(PLAYE, HIGH); 
    Serial.println("PLaying"); 
    digitalWrite(PLAYE, LOW);
    digitalWrite(val2, LOW);
    delay(4000);
  } else {
  Serial.println("No motion detected");
    strip.fill(white); //Set colour
//    strip.fill(white, 12, 12); //set colour
//    strip.fill(white, 0, 12); //set colour
    strip.show();
    delay(1000); 
  }  
}
