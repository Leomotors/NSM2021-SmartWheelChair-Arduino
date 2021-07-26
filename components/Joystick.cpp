#include <stdint.h>

#define INACCURACY_RANGE 10

class Joystick
{
    uint8_t VRx_PIN, VRy_PIN, SW_PIN;
    int Xval, Yval, SWval;

public:
    Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW)
        : VRx_PIN(VRx), VRy_PIN(VRy), SW_PIN(SW)
    {
        pinMode(VRx_PIN, INPUT);
        pinMode(VRy_PIN, INPUT);
        pinMode(SW_PIN, INPUT);
    }

    // * Get Data from Joystick and save to class private variable
    void eval()
    {
        Xval = analogRead(VRx_PIN);
        Xval = map(Xval, 0, 1023, -255, 255);
        Xval = (abs(Xval) > INACCURACY_RANGE) ? Xval : 0;
        Yval = analogRead(VRy_PIN);
        Yval = map(Yval, 0, 1023, -255, 255);
        Yval = (abs(Yval) > INACCURACY_RANGE) ? Yval : 0;
        SWval = digitalRead(SW_PIN);
    }

    MyPair getData()
    {
        return MyPair{Xval, Yval};
    }
};