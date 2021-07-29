#include <CytronMotorDriver.h>

#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"
#include "components/Joystick.cpp"
#include "components/Car.cpp"
#include "components/BTSerial.cpp"

#define CAR_ID "100000"
#define CAR_PASSWORD "123456"

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
#define EMERGENCY_BUTTON 4

void powerOff();

Ultrasonic FrontGround{A2, A3};
Ultrasonic FrontView{A4, A5};
Joystick MyJoy{A1, A0, 13, powerOff};
Car MyCar{5, 6, 9, 10};
BluetoothSerial Bluetooth{CAR_ID, CAR_PASSWORD};

void setup()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);

    pinMode(EMERGENCY_BUTTON, INPUT_PULLUP);

    Serial.begin(9600);

    Buzzer::init();

    // * Switch on Beep
    Signal::SwitchedOn();

    Bluetooth.setTracebackFunction(Signal::Alert);

    bool authenticated = false;

    while (!Bluetooth.AuthenticationLoop())
    {
        MyJoy.PowerOffCheck();
        delay(100);
    }

    // * When Authentication success, play welcome music and begin the system
    Music::playGiorno();
}

// * Main Driving Loop
void loop()
{
    if (!digitalRead(EMERGENCY_BUTTON))
    {
        // * EMERGENCY
        EmergencyMode();
    }

    String Buffer = Bluetooth.BluetoothCMDRead();
    if (Buffer == "POWER_OFF")
    {
        powerOff();
    }
    if (Buffer == "EMERGENCY")
    {
        EmergencyMode();
    }

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

void EmergencyMode()
{
    Serial.println("EMERGENCY");
    MyCar.emergencyBrake(Signal::Alert);
    while (true)
    {
        Buzzer::Play(2000, 1000);
        delay(1000);
        MyJoy.PowerOffCheck();
    }
}