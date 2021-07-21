#include "utils/maker_board_properties.h"
#include "components/LED.cpp"
#include "components/Buzzer.cpp"

LED A(4);

void setup()
{
    MakerNanoInit();
    Buzzer::init();
}

void loop()
{
    A.On();
    Buzzer::Play(2000,1000);
    delay(1000);
    A.Off();
    delay(1000);
}