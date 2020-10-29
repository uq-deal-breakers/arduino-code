const int REC=2, PLAYE=3, PLAYL=4, FT=5;
void setup(){ 
Serial.begin(9600); 
record(); delay(500); 
play_e(); delay(500); 
play_l(); delay(500);
live();
 delay(500);
}
void record(){
Serial.println("Recording for 10 seconds..."); 
digitalWrite(REC, HIGH);
delay(10000);
digitalWrite(REC, LOW);
}
void play_e(){
Serial.println("Now playing..."); 
digitalWrite(PLAYE, HIGH); 
delay(500);
digitalWrite(PLAYE, LOW);
}
void play_l(){
Serial.println("Now playing for 5 seconds..."); 
digitalWrite(PLAYL, HIGH);
delay(5000);
digitalWrite(PLAYL, LOW);
}
void live(){
Serial.println("Mic feed through for 10seconds..."); 
digitalWrite(FT, HIGH); 
delay(10000); 
digitalWrite(FT, LOW);
}
void loop(){}
