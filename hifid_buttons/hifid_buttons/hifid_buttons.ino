
// put your setup code here, to run once:
#include <Adafruit_NeoPixel.h>
 
#define PIN 9 //for light control
#define NUM_LEDS 24 //Number of leds in light

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);
//Set colours
uint32_t red = strip.Color(255, 0, 0);
uint32_t pink = strip.Color(255, 0, 127); 
uint32_t blue = strip.Color(0, 0, 255);
uint32_t white = strip.Color(255, 255, 255);

//Setup button
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;
int buttonState1 = 0;// variable for reading the pushbutton status
int buttonState2 = 0;

//Sound port
const int PLAYE=4; //Port for triggerig sound effects

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  
  //Setup for light
  strip.begin();
  strip.show(); //Initialize
  strip.setBrightness(255); // set brightness (0-255)
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
  
if (buttonState1 == HIGH && buttonState2 == HIGH) {
  strip.clear();
  strip.fill(white); //Set colour
  strip.show(); 
  Serial.println("No phubbing");
  delay(1000);
}
 
if (buttonState1 == LOW && buttonState2 == LOW) {      
  Serial.println("Both phubbing!");
  strip.fill(red, 12, 12); //set colour
  strip.fill(blue, 0, 12); //set colour
  strip.show();
  digitalWrite(PLAYE, HIGH); 
  Serial.println("PLaying"); 
  delay(5000);
  digitalWrite(PLAYE, LOW);
  } 
  else if (buttonState1 == HIGH || buttonState2 == HIGH) {
    if (buttonState1 == LOW) {
      Serial.println("Button1 high!");
      strip.clear();
      strip.fill(red); //set colour
      strip.show();
      digitalWrite(PLAYE, HIGH); 
      Serial.println("PLaying"); 
      delay(5000);   
      digitalWrite(PLAYE, LOW);
      }
   if (buttonState2 == LOW) {
      Serial.println("Button2 high!");
      strip.clear();
      strip.fill(blue); //set colour
      strip.show();       
      digitalWrite(PLAYE, HIGH); 
      Serial.println("PLaying"); 
      delay(5000);
      digitalWrite(PLAYE, LOW);
      } 
  } 
  
}
