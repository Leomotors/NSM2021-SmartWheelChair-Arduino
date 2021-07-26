#include <stdint.h>

#define INACCURACY_RANGE 10

#define HOLD_TO_POWER_OFF_DURATION 4000

class Joystick
{
    uint8_t VRx_PIN, VRy_PIN, SW_PIN;
    int Xval, Yval;
    MyPair dataPair{0, 0};
    void (*powerOffFunc)();
    int powerOffTimer{0};

public:
    Joystick(uint8_t VRx, uint8_t VRy, uint8_t SW, void powerOffFunc())
        : VRx_PIN(VRx), VRy_PIN(VRy), SW_PIN(SW), powerOffFunc(powerOffFunc)
    {
        pinMode(VRx_PIN, INPUT);
        pinMode(VRy_PIN, INPUT);
        pinMode(SW_PIN, INPUT_PULLUP);
    }

    void PowerOffCheck()
    {
        if (!digitalRead(SW_PIN))
        {
            powerOffTimer++;
            if (powerOffTimer > HOLD_TO_POWER_OFF_DURATION)
                powerOffFunc();
        }
        else
        {
            powerOffTimer = 0;
        }
    }

    MyPair getData(bool generateNewData = false)
    {
        if (generateNewData)
            calcJoystickPositionAndSaveToClassAttribute();
        return MyPair{Xval, Yval};
    }

    bool isNeutral()
    {
        MyPair data = getData();
        return data.first == 0 && data.second == 0;
    }

    bool isForward()
    {
        return getData().first > 0;
    }

private:
    // * Get Data from Joystick and save to class private variable
    void calcJoystickPositionAndSaveToClassAttribute()
    {
        Xval = analogRead(VRx_PIN);
        Xval = map(Xval, 0, 1023, -255, 255);
        Xval = (abs(Xval) > INACCURACY_RANGE) ? Xval : 0;
        Yval = analogRead(VRy_PIN);
        Yval = map(Yval, 0, 1023, -255, 255);
        Yval = (abs(Yval) > INACCURACY_RANGE) ? Yval : 0;
        dataPair.first = Xval;
        dataPair.second = Yval;
    }
};