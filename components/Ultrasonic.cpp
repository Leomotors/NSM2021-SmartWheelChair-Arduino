// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

// * https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6

#include <stdint.h>

class Ultrasonic
{
    long duration;
    int distance;
    uint8_t echoPin;
    uint8_t trigPin;

public:
    Ultrasonic(uint8_t echo_pin, uint8_t trigger_pin) : echoPin(echo_pin), trigPin(trigger_pin)
    {
        pinMode(echoPin, INPUT);
        pinMode(trigPin, OUTPUT);
    }
    int getDist()
    {
        // Clears the trigPin condition
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPin, HIGH);
        // Calculating the distance
        distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
        // Displays the distance on the Serial Monitor
        return distance;
    }
};
