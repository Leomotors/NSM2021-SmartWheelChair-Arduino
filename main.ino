#include <CytronMotorDriver.h>

#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"
#include "components/Joystick.cpp"
#include "components/Car.cpp"

/**
 * * COMPONENTS ARE
 * * - 2 Ultrasonic (Use 2 Digital Pin Each)
 * * - Bluetooth Module (RX TX Pin)
 * * - Analog Joystick (2 Analog In PIN, 1 Digital In)
 * * - Relay (1 Digital Out)
 * * - Push Button (1 Digital In)
 * * - Motor Driver (4 Digital PWM)
 */

Ultrasonic FrontGround{A2, A3};
Ultrasonic FrontView{A4, A5};
Joystick J{A1, A0, 13};
Car C{5,6,9,10};

void setup()
{
    Serial.begin(9600);
    Buzzer::init();
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
    Signal::SwitchedOn();
}

void loop()
{

}