#include "utils/maker_board_properties.h"
#include "components/LED.cpp"
#include "components/Buzzer.cpp"
#include "components/Ultrasonic.cpp"

Ultrasonic U0{A0, A1};

void setup()
{
    Serial.begin(9600);
    MakerNanoInit();
    Buzzer::init();
}

void loop()
{
    // * TEST
    // * If distance is less than 5 cm, play Giorno's Theme
    // * Limitation: Ultrasonic and Buzzer can't be at the same time.
    if (U0.getDist() < 5)
        Music::playGiorno();
}