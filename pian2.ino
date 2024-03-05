// Define musical note frequencies
#define T_C3 130
#define T_D3 200 
#define T_E3 270
#define T_F3 340
#define T_G3 410
#define T_A3 480
#define T_B3 550
#define T_C 620
#define T_D 690
#define T_E 760
#define T_F 830
#define T_G 900
#define T_A 970
#define T_B 1040

// Define the input pins for each note
const int C = 6; //rosu
const int D = 7; //portocaliu
const int E = 8; //galben
const int F = 9; //verde
const int G = 10;//albastru
const int A = 11;//mov

// Define RGB LED pins
const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;

// Define other constants and pins
//const int LED_BLUE = A0;
const int Buzz = 5;
//const int SENSOR = 12; 
//const int POT = A5;    
const int TRIG = 12;   
const int ECHO = 13;   

long duration;
int distance;

void setup() {
  // Set up pin modes
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  //pinMode(LED_BLUE, OUTPUT);
  //pinMode(SENSOR, INPUT);
  //pinMode(POT, INPUT);
  
  // Set up note input pins
  pinMode(C, INPUT);
  digitalWrite(C, HIGH);
  pinMode(D, INPUT);
  digitalWrite(D, HIGH);
  pinMode(E, INPUT);
  digitalWrite(E, HIGH);
  pinMode(F, INPUT);
  digitalWrite(F, HIGH);
  pinMode(G, INPUT);
  digitalWrite(G, HIGH);
  pinMode(A, INPUT);
  digitalWrite(A, HIGH);

  // Set up RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() { 
 // Read potentiometer value for LED_BLUE brightness
  // int potentiometerVal = analogRead(POT);
  // int brightness = potentiometerVal / 4;
  // analogWrite(LED_BLUE, brightness);
  
  // Ultrasonic sensor distance measurement
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2; 

  // Play tones based on distance and note
  playTone(C, redPin, greenPin, bluePin);
  playTone(D, redPin, greenPin, bluePin);
  playTone(E, redPin, greenPin, bluePin);
  playTone(F, redPin, greenPin, bluePin);
  playTone(G, redPin, greenPin, bluePin);
  playTone(A, redPin, greenPin, bluePin);
  
  // Check if the sensor is triggered and adjust LED_BLUE accordingly
  // int val = digitalRead(SENSOR);
  // if(val == LOW) {
  //   analogWrite(LED_BLUE, 0);
  // } else {
  //   analogWrite(LED_BLUE, 255);
  // }
  
  noTone(Buzz);
}

// Function to play tone based on distance and note
void playTone(int notePin, int redPin, int greenPin, int bluePin) {
  while (digitalRead(notePin) == LOW) {
    // If key is pressed
    if (distance >= 10) { 

      // Set RGB LED color for the key when pressed
      if (notePin == C) {
        tone(Buzz, T_C3);
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0); // Red color for key C
      } else if (notePin == D) {
        tone(Buzz, T_D3 );
        analogWrite(redPin, 200);
        analogWrite(greenPin, 140);
        analogWrite(bluePin, 0); // Orange color for key D
      } else if (notePin == E) {
        tone(Buzz, T_E3 );
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0); // Yellow color for key E
      } else if (notePin == F) {
        tone(Buzz, T_F3 );
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0); // Green color for key F
      } else if (notePin == G) {
        tone(Buzz, T_G3 );
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255); // Blue color for key G
      } else if (notePin == A) {
        tone(Buzz, T_A3 );
        analogWrite(redPin, 128);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 128); // Purple color for key A
      }
    } else {
      // Set RGB LED color for the key when pressed and distance is less than 10
      if (notePin == C) {
        tone(Buzz, T_C );
        analogWrite(redPin, 200);
        analogWrite(greenPin, 140);
        analogWrite(bluePin, 0); // Orange color for key C
      } else if (notePin == D) {
        tone(Buzz, T_D );
        analogWrite(redPin, 255);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0); // Yellow color for key D
      } else if (notePin == E) {
        tone(Buzz, T_E );
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0); // Green color for key E
      } else if (notePin == F) {
        tone(Buzz, T_F );
        analogWrite(redPin, 0);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255); // Blue color for key F
      } else if (notePin == G) {
        tone(Buzz, T_G );
        analogWrite(redPin, 128);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 128); // Purple color for key G
      } else if (notePin == A) {
        tone(Buzz, T_A );
        analogWrite(redPin, 255);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0); // Red color for key A
      }
      //tone(Buzz, farNote);
    }
  }
}
