#include <CytronMotorDriver.h>

#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"
#include "components/Joystick.cpp"
#include "components/Car.cpp"

#include "utils/Pair.hpp"

/**
 * * COMPONENTS ARE
 * * - 2 Ultrasonic (Use 2 Digital Pin Each)
 * * - Bluetooth Module (RX TX Pin)
 * * - Analog Joystick (2 Analog In PIN, 1 Digital In)
 * * - Relay (1 Digital Out)
 * * - Push Button (1 Digital In)
 * * - Motor Driver (4 Digital PWM)
 */

#define RELAY_PIN 2

Ultrasonic FrontGround{A2, A3};
Ultrasonic FrontView{A4, A5};
Joystick CtrlJoy{A1, A0, 13};
Car MyCar{5, 6, 9, 10};

void setup()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.begin(9600);
    Buzzer::init();
    Signal::SwitchedOn();
}

// * Main Driving Loop
void loop()
{
    MyPair JoyData = CtrlJoy.getData();
    MyCar.setSpeed(JoyData);
}