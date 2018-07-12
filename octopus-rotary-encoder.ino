/*
 * octopus-rotary-encoder.ino - Example how to interface rotary encoder on fablab's Octopus IoT board
 *
 * Copyright (C) 2018 Wolfgang Klenk <wolfgang.klenk@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <Encoder.h> 

#define ENCODER_PIN_A 14
#define ENCODER_PIN_B 12
#define ENCODER_PIN_BUTTON 2

Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);

long oldPosition  = -1;

// The setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    // Wait for serial port to connect. Needed for native USB
    delay(100);
  }
  Serial.println(F("Basic Encoder Test:"));  
  
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Push button functionality
  pinMode(ENCODER_PIN_BUTTON, INPUT);
}

// The loop function runs over and over again forever
void loop() {

  if(digitalRead(ENCODER_PIN_BUTTON) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    encoder.write(0); // Reset to zero
  }
  
  long newPosition = encoder.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
}
