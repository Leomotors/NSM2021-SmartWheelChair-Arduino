// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Original Algorithm by Arbi Abdul Jabbaar
// Original Algorithm tested on 17 September 2019
// Original Algorithm Source: https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
// ---------------------------------------------------------------- //

#include <stdint.h>

#define ULTRASONIC_TIME_LIMIT 5000

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
        duration = pulseIn(echoPin, HIGH, ULTRASONIC_TIME_LIMIT);
        duration = duration ? duration : ULTRASONIC_TIME_LIMIT;
        // Calculating the distance
        distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
        // Displays the distance on the Serial Monitor
        //Serial.println(distance);
        return distance;
    }
};
