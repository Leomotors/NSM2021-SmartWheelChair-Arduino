#include <stdint.h>

#include <CytronMotorDriver.h>

#include "../utils/Pair.hpp"

#define MY_MODE PWM_PWM

class Car
{
    CytronMD *Left;
    CytronMD *Right;

public:
    Car(uint8_t M1A, uint8_t M1B, uint8_t M2A, uint8_t M2B)
        : Left(new CytronMD{MY_MODE, M2A, M2B}), Right(new CytronMD{MY_MODE, M1A, M1B}) {}

    void setSpeed(MyPair speed)
    {
        Left->setSpeed(speed.first + speed.second / 2);
        Right->setSpeed(speed.first - speed.second / 2);
    }
};