#include <CytronMotorDriver.h>

#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"
#include "components/Joystick.cpp"
#include "components/Car.cpp"

#define CAR_ID "100000"
#define CAR_PASSWORD "123456"

#include "utils/Pair.hpp"

#include <SoftwareSerial.h>

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

void powerOff();

SoftwareSerial BTSerial(0, 1);

Ultrasonic FrontGround{A2, A3};
Ultrasonic FrontView{A4, A5};
Joystick MyJoy{A1, A0, 13, powerOff};
Car MyCar{5, 6, 9, 10};

void setup()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.begin(9600);
    BTSerial.begin(9600);

    Buzzer::init();

    // * Switch on Beep
    Signal::SwitchedOn();

    // TODO Implement authentication process
    delay(1200);

    bool authenticated = false;

    while (!authenticated)
    {
        if (BTSerial.available())
        {
            String Buffer = "";
            int tBuffer = BTSerial.read();

            while (tBuffer != '\n')
            {
                Buffer += (char)tBuffer;
                tBuffer = BTSerial.read();
            }

            if (Buffer == CAR_PASSWORD)
            {
                authenticated = true;
                break;
            }
            BTSerial.println(Buffer);
            BTSerial.flush();
            Signal::Alert();
        }
        MyJoy.PowerOffCheck();
    }

    // * When Authentication success, play welcome music and begin the system
    Music::playGiorno();
}

// * Main Driving Loop
void loop()
{
    MyPair JoyData = MyJoy.getData(true);
    MyJoy.PowerOffCheck();

    if (MyJoy.isForward() && (FrontGround.getDist() > 5 || FrontView.getDist() <= 10))
    {
        MyCar.emergencyBrake(Signal::Alert);
    }
    else
        MyCar.setSpeed(JoyData);
}

void powerOff()
{
    if (!MyJoy.isNeutral())
    {
        MyCar.emergencyBrake(Signal::Alert);
    }

    while (true)
        digitalWrite(RELAY_PIN, LOW);
}