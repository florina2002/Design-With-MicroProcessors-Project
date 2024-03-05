# Design-With-MicroProcessors-Project
This project involves creating a simple piano using an Arduino Uno, a breadboard, six buttons (acting as piano keys), an ultrasonic sensor, an RGB LED, and a buzzer. The piano plays different musical notes based on the buttons pressed and adjusts the color of the RGB LED based on the distance measured by the ultrasonic sensor. 


PROJECT DOCUMENTATION
PIANO WITH RGB LED
Design with microprocessors
(DMP)
Student: Nechita Florina-Elena
Group: 30434
Email: nechitaflorina2002@gmail.com
Date: January 2024
Teacher: Radu Dănescu
Teaching Assistant: Ana Rednic

1. Introduction
This project involves creating a simple piano using an Arduino
Uno, a breadboard, six buttons (acting as piano keys), an
ultrasonic sensor, an RGB LED, and a buzzer. The piano plays
different musical notes based on the buttons pressed and
adjusts the color of the RGB LED based on the distance
measured by the ultrasonic sensor. It offers both auditory and
visual feedback, providing an interactive and engaging musical
experience.
![WhatsApp Image 2024-01-12 at 19 38 09 (1)](https://github.com/florina2002/Design-With-MicroProcessors-Project/assets/78110103/c818527b-fcc3-4dc3-b957-ae2b06994963)
![WhatsApp Image 2024-01-12 at 19 38 09](https://github.com/florina2002/Design-With-MicroProcessors-Project/assets/78110103/6fa45e46-361a-4cb1-9de3-e7657a84a510)

3. Components Used
● Arduino Uno
● Breadboard
● Six buttons (C, D, E, F, G, A)
● Ultrasonic sensor (HC-SR04)
● RGB LED
● Buzzer
● Jumper wires
4. Setup and Connections
● Connect buttons to pins 6 to 11 on the Arduino Uno.
● Connect the ultrasonic sensor's trigger pin (TRIG) to pin
12 and the echo pin (ECHO) to pin 13.
● Connect the RGB LED's red, green, and blue pins to pins
2, 3, and 4, respectively.
● Connect the buzzer to pin 5.
● Ensure proper power and ground connections for all
components.

5. Circuit Diagram
![diagram](https://github.com/florina2002/Design-With-MicroProcessors-Project/assets/78110103/da5ad31d-a7e0-44e0-a41f-81bbed8e12ea)
6. Code Explanation
● The code defines musical note frequencies and assigns
pins for buttons, RGB LED, and the ultrasonic sensor.
● The `playTone` function plays a note on the buzzer and
sets the RGB LED color based on the pressed button and
distance measured.
● In the `loop` function, the ultrasonic sensor measures the
distance, and the `playTone` function is called for each
button. The RGB LED color changes depending on the
pressed button and distance.
● The buzzer produces sound based on the musical notes.
● The `noTone` function turns off the buzzer.
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
const int C = 6; //roșu
const int D = 7; //portocaliu
const int E = 8; //galben
3
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
4
pinMode(A, INPUT);
digitalWrite(A, HIGH);
// Set up RGB LED pins
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}
void loop() {
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
noTone(Buzz);
}
// Function to play tone based on distance and note
void playTone(int notePin, int redPin, int greenPin, int
bluePin) {
while (digitalRead(notePin) == LOW) {
// If key is pressed
if (distance >= 10) {
5
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
// Set RGB LED color for the key when pressed and
distance is less than 10
6
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
}
}
}
7
7. Operation
● Pressing a button activates the corresponding musical
note and changes the RGB LED color.
● The ultrasonic sensor measures the distance, affecting the
RGB LED color when a button is pressed.
● The buzzer produces the musical note associated with the
pressed button.
8. Applications
● Educational tool for learning basic electronics and
programming.
● Interactive and entertaining musical experience for users
of all ages.
9. Challenges and Improvements
● Ensure proper button connections to prevent button
bouncing issues.
● Implement debounce mechanisms for more reliable button
presses.
● Experiment with different RGB LED color patterns based
on musical notes.
8
10. Conclusion
The Arduino Uno Piano with LED Lights provides an engaging
and interactive way to learn about electronics and
programming. It combines both visual and auditory elements,
making it a versatile and enjoyable project for beginners and
enthusiasts alike. Further enhancements can be made to
expand the functionality and visual effects.
9
