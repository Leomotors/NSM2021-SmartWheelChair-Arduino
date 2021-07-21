#define BOARD_BUTTON_PIN 2
#define BOARD_BUZZER_PIN 8

void MakerNanoInit()
{
    pinMode(BOARD_BUTTON_PIN, INPUT_PULLUP);
    pinMode(BOARD_BUZZER_PIN, OUTPUT);
}