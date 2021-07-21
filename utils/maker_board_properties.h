/**
 * * Maker Nano has Built-in button and Buzzer
 * * This file will enable those feature
 * 
 * * Board Button (PIN 2) is Normally Open
 * * Board Buzzer (PIN 8) will be defined in other file
 */

#define BOARD_BUTTON_PIN 2

void MakerNanoInit()
{
    pinMode(BOARD_BUTTON_PIN, INPUT_PULLUP);
}