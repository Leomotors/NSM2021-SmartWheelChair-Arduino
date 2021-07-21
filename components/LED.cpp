#include <stdint.h>

class LED
{
    uint8_t LED_PIN;

public:
    LED(uint8_t PIN) : LED_PIN(PIN)
    {
        pinMode(LED_PIN, OUTPUT);
    }
    void On()
    {
        digitalWrite(LED_PIN, HIGH);
    }
    void Off()
    {
        digitalWrite(LED_PIN, LOW);
    }
};