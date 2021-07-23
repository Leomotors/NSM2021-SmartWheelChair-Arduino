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

}