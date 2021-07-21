#include <stdint.h>

#define BOARD_BUZZER_PIN 8

namespace Buzzer
{
    uint8_t PIN = BOARD_BUZZER_PIN;
    
    void init()
    {
        pinMode(PIN, OUTPUT);
    }
    void Play(uint32_t frequency, uint32_t duration)
    {
        tone(PIN, frequency, duration);
    }
    void Stop()
    {
        noTone(PIN);
    }
}