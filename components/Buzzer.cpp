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

#define NOTE_C5 523
#define NOTE_C5S 554
#define NOTE_D5 587
#define NOTE_D5S 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_F5S 740
#define NOTE_G5 784
#define NOTE_G5S 831
#define NOTE_A5 880
#define NOTE_A5S 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_C6S 1109
#define NOTE_D6 1175
#define NOTE_D6S 1245

namespace Music
{
    void playGiorno()
    {
        auto p = [](uint32_t f, uint32_t d, uint32_t e)
        {
            tone(BOARD_BUZZER_PIN, f, d);
            delay(d + e);
        };
        /*
            * FS D... D E F E D CS D E FS B B CS+ D+ G FS F D+ AS B
        */
        p(NOTE_F5, 650, 0);
        p(NOTE_D5, 900, 0);
        p(NOTE_D5, 150, 0);
        p(NOTE_E5, 150, 0);
        p(NOTE_F5, 300, 0);
        p(NOTE_E5, 300, 0);
        p(NOTE_D5, 350, 0);
        p(NOTE_C5S, 350, 0);
        p(NOTE_D5, 350, 0);
        p(NOTE_E5, 250, 0);
        p(NOTE_F5S, 650, 0);
        p(NOTE_B5, 650, 0);
        p(NOTE_B5, 150, 0);
        p(NOTE_C6S, 200, 0);
        p(NOTE_D6, 300, 0);
        p(NOTE_G5, 300, 0);
        p(NOTE_F5S, 250, 0);
        p(NOTE_F5, 300, 0);
        p(NOTE_D6, 350, 0);
        p(NOTE_A5S, 350, 0);
        p(NOTE_B5, 250, 0);
    }
}