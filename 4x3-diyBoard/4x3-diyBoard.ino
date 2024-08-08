//Copyright 2024.02 Martin Blieninger
//origional file

#include <Keyboard.h>
#include <Arduino.h>

const int taster_pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 14, 15};
const int num_taster = sizeof(taster_pins) / sizeof(taster_pins[0]);

void setup() {
  Keyboard.begin();

  for (int i = 0; i < num_taster; i++) {
    pinMode(taster_pins[i], INPUT_PULLUP);
  }
}

/*
  Board Belegung
  -------------
  |09|10|11|12|
  |08|07|06|05|
  |04|03|02|01|
  -------------
*/

void funktion1() {
  
}

void funktion2() {
  // Energiesparmodus
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('m');
  delay(80);
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(150);
  Keyboard.releaseAll();
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void funktion3() {
  // Grafiktreiber neu laden
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('b');
  delay(100);
  Keyboard.releaseAll();
}

void funktion4() {
  // Splitscreen
  Keyboard.press(KEY_LEFT_GUI);
  delay(20);
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(50);
  Keyboard.releaseAll();
  delay(900);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void funktion5() {
  // Snipping Tool
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
}

void funktion6() {
  // Screenshot
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_PRINT_SCREEN);
  delay(100);
  Keyboard.releaseAll();
}

void funktion7() {
  // Taskmanager
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_ESC);
  delay(100);
  Keyboard.releaseAll();
}

void funktion8() {
  // Windows Zwischenablage
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('v');
  delay(80);
  Keyboard.releaseAll();
}

void funktion9() {
  // Windows Sperren
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}

void funktion10() {
  // Windows Tab
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.releaseAll();
}

void funktion11() {
  // Alt Tab
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.release(KEY_TAB);
  delay(400);
  Keyboard.releaseAll();
}

void funktion12() {
  // Windows Desktop
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  delay(80);
  Keyboard.releaseAll();
}

void loop() {
  for (int i = 0; i < num_taster; i++) {
    if (digitalRead(taster_pins[i]) == LOW) {
      switch (i) {
        case 0:
          funktion1();
          break;
        case 1:
          funktion2();
          break;
        case 2:
          funktion3();
          break;

        case 3:
          funktion4();
          break;
      
        case 4:
          funktion5();
          break;

        case 5:
          funktion6();
          break;

        case 6:
          funktion7();
          break;

        case 7:
          funktion8();
          break;

        case 8:
          funktion9();
          break;

        case 9:
          funktion10();
          break;

        case 10:
          funktion11();
          break;

        case 11:
          funktion12();
          break;
          

        default:
          break;
      }

      //debug
      /*Serial.print("Taster ");
      Serial.print(taster_pins[i]);
      Serial.println(" wurde gedrückt.");*/
      delay(200);
      while (digitalRead(taster_pins[i]) == LOW) {}
    }
  }
}
