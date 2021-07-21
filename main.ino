#include "utils/maker_board_properties.h"
#include "components/LED.cpp"

LED A(4);

void setup()
{
    MakerNanoInit();
}

void loop()
{
    A.On();
    delay(1000);
    A.Off();
    delay(1000);
}