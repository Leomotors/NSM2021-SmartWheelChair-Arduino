#include <stdint.h>

class Joystick
{
    uint8_t VRx_PIN, VRy_PIN, SW_PIN;

public:
    Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW)
        : VRx_PIN(VRx), VRy_PIN(VRy), SW_PIN(SW)
    {
        pinMode(VRx_PIN, INPUT);
        pinMode(VRy_PIN, INPUT);
        pinMode(SW_PIN, INPUT);
    }

    void printInput()
    {
        int Xval = analogRead(VRx_PIN);
        int Yval = analogRead(VRy_PIN);
        int SWval = digitalRead(SW_PIN);
        Serial.println("VRx = " + (String)Xval + ", VRy = " + (String)Yval + ", SW = " + (String)SWval);
    }
};