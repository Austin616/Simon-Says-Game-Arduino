#include <LiquidCrystal.h>

// Define the LCD pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Define button and LED pins
const int redButtonPin = A3;
const int redLedPin = 4;

const int blueButtonPin = A1;
const int blueLedPin = 5;

const int greenButtonPin = A0;
const int greenLedPin = 3;

const int yellowButtonPin = A2;
const int yellowLedPin = 2;

const int buzzerButtonPin = A4;  // Buzzer button on A4
const int buzzerPin = 1;          // Connect the buzzer to digital pin 1

void setup() {
  // Set up button pins as INPUT_PULLUP
  pinMode(redButtonPin, INPUT_PULLUP);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(yellowButtonPin, INPUT_PULLUP);
  pinMode(buzzerButtonPin, INPUT_PULLUP);

  // Set up LED pins as OUTPUT
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);

  // Set up buzzer pin as OUTPUT
  pinMode(buzzerPin, OUTPUT);

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Press Buttons");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Arrays to store button and LED states
  int buttonPins[] = {redButtonPin, blueButtonPin, greenButtonPin, yellowButtonPin};
  int ledPins[] = {redLedPin, blueLedPin, greenLedPin, yellowLedPin};

  int onCount = 0; // Count of pins that are turned on

  // Check and control the state of each LED
  for (int i = 0; i < 4; ++i) {
    if (digitalRead(buttonPins[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);  // Turn on the LED
      onCount++;
    } else {
      digitalWrite(ledPins[i], LOW);  // Turn off the LED
    }
  }

  // Control the buzzer based on the button states
  if (digitalRead(buzzerButtonPin) == LOW) {
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer when the A4 button is pressed
    delay(1000);  // Keep the buzzer on for 1 second
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer when the A4 button is released
    delay(50);  // Add a small delay for stability
  }

  // Display the count of pins that are turned on
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(onCount);
  lcd.print(" pin");
  if (onCount != 1) {
    lcd.print("s");
  }
  lcd.print(" on");

  delay(100); // Add a small delay for stability
}
