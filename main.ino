#include <CytronMotorDriver.h>

#include "utils/maker_board_properties.h"
#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"
#include "components/Joystick.cpp"

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
Ultrasonic FrontView{A4,A5};
Joystick J{A0,A1, 13};
CytronMD LeftMotor{PWM_PWM, 5, 6};
CytronMD RightMotor{PWM_PWM, 9, 10};

void setup()
{
    Serial.begin(9600);
    MakerNanoInit();
    Buzzer::init();
    pinMode(10, OUTPUT);
    digitalWrite(10, HIGH);
}

void loop()
{
    J.printInput();
}