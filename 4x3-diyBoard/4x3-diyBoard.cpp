//Copyright 2024.08 Martin Blieninger
//Hyperdeck file
//
//Sketch for Arduino Pro Micro (Leonardo)

#include <Keyboard.h>
#include <Arduino.h>

const int taster_pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 14, 15};
const int num_taster = sizeof(taster_pins) / sizeof(taster_pins[0]);

void setup() {
  Keyboard.begin();
  bool baud = 9600;
  Serial.begin(baud);
  while (!Serial) {
    ; // wait for serial init
  }

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
  //row3,key4
  Serial.write("Key_12");
}

void funktion2() {
  //row3,key3
  Serial.write("Key_11");
}

void funktion3() {
  //row3,key2
  Serial.write("Key_10");
}

void funktion4() {
  //row3,key1
  Serial.write("Key_09");
}

void funktion5() {
  //row2,key4
  Serial.write("Key_08");
}

void funktion6() {
  //row2,key3
  Serial.write("Key_07");
}

void funktion7() {
  //row2,key2
  Serial.write("Key_06");
}

void funktion8() {
  //row2,key1
  Serial.write("Key_05");
}

void funktion9() {
  //row1,key1
  Serial.write("Key_01");
}

void funktion10() {
  //row1,key2
  Serial.write("Key_02");
}

void funktion11() {
  //row1,key3
  Serial.write("Key_03");
}

void funktion12() {
  //row1,key4
  Serial.write("Key_04");
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
