/*
 * Arduino Robot Car - Arduino controlled robot car
 *
 * Add some more text
 *
 * (c) 2015 Jurgen Smit. All rights reserved.
 *
 * Circuit: 
 *
 * - Adafruit Motor Shield
 * - HC-SR04 Ultrasonic Distance Sensor
 * - 2 DC Motors
 * - Mini Servo
 *
 * External References:
 *
 * - NewPing Library for Arduino (Ultrasonic Sensors): https://code.google.com/p/arduino-new-ping/
 * - Adafruit Motor Shield Library (https://github.com/adafruit/Adafruit-Motor-Shield-library)
 *
 */

#include <Wire.h>

#define I2C_ADDRESS 0x20
#define DEBUG

/*
 * Initialize everything
 */
void setup() {
    Serial.begin(115200); 

    Serial.println(F("Arduino Robot Car v0.01"));
    Serial.println(F("Initializing..."));
    
    Wire.begin(I2C_ADDRESS);      
    Wire.onReceive(receiveEvent); 
    Wire.onRequest(requestEvent); 

    delay(2000); 

    Serial.println(F("Ready"));
}

/*
 * The loop
 */
void loop() {
}

/*
 * This function is called when the master is sending data to us
 */
void receiveEvent(int howMany)
{
#ifdef DEBUG
    Serial.print(F("I2C Data Received: "));
    Serial.println(howMany);
#endif

    // Just output the received data to the serial port
    while(Wire.available()) {
        char c = Wire.read();
#ifdef DEBUG
        Serial.print(c);
#endif
    }

#ifdef DEBUG
    Serial.println();
#endif
}

/*
 * This function is called when the master is requesting data from us
 */
void requestEvent() {
#ifdef DEBUG
    Serial.print(F("I2C Data Requested"));
#endif
    Wire.write("Hello, world!", 13);
}
