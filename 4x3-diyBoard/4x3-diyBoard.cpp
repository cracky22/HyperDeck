// Copyright 2024.08 Martin Blieninger
// Hyperdeck control sketch for Arduino Pro Micro (Leonardo)
// Maps button presses to specific key commands sent via serial

#include <Keyboard.h>
#include <Arduino.h>

// Pin configuration for buttons
const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 14, 15};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Function prototypes for better organization
void handleKeyPress(int keyIndex);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  // Initialize keyboard emulation
  Keyboard.begin();
  
  // Configure button pins with internal pull-up resistors
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

/*
  Button Layout
  -------------
  |09|10|11|12|  <- Key numbers
  |08|07|06|05|
  |04|03|02|01|
  -------------
*/

// Key press handler functions
void key01() { Serial.println("Key_01"); } // Row 1, Key 1
void key02() { Serial.println("Key_02"); } // Row 1, Key 2
void key03() { Serial.println("Key_03"); } // Row 1, Key 3
void key04() { Serial.println("Key_04"); } // Row 1, Key 4
void key05() { Serial.println("Key_05"); } // Row 2, Key 1
void key06() { Serial.println("Key_06"); } // Row 2, Key 2
void key07() { Serial.println("Key_07"); } // Row 2, Key 3
void key08() { Serial.println("Key_08"); } // Row 2, Key 4
void key09() { Serial.println("Key_09"); } // Row 3, Key 1
void key10() { Serial.println("Key_10"); } // Row 3, Key 2
void key11() { Serial.println("Key_11"); } // Row 3, Key 3
void key12() { Serial.println("Key_12"); } // Row 3, Key 4

// Array of function pointers for key handlers
void (*keyHandlers[])() = {
  key12, key11, key10, key09,  // Row 3
  key08, key07, key06, key05,  // Row 2
  key01, key02, key03, key04   // Row 1
};

void loop() {
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      // Execute the corresponding key handler
      keyHandlers[i]();
      
      // Debounce: wait for button release
      delay(200);
      while (digitalRead(buttonPins[i]) == LOW) {
        ; // Wait until button is released
      }
    }
  }
}