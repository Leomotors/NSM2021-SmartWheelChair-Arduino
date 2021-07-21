/**
 * * Maker Nano has Built-in button and Buzzer
 * * This file will enable those feature
 * 
 * * Board Button (PIN 2) is Normally Open
 * * Board Buzzer (PIN 8)
 */

#define BOARD_BUTTON_PIN 2
#define BOARD_BUZZER_PIN 8

void MakerNanoInit()
{
    pinMode(BOARD_BUTTON_PIN, INPUT_PULLUP);
    pinMode(BOARD_BUZZER_PIN, OUTPUT);
}