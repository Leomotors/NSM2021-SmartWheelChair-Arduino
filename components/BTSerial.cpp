#include <stdint.h>

class BluetoothSerial
{
    String Device_ID;
    String Device_Password;
    void (*authTraceback)();

public:
    BluetoothSerial(String Device_ID, String Device_Password)
        : Device_ID(Device_ID), Device_Password(Device_Password) {}

    void setTracebackFunction(void func())
    {
        authTraceback = func;
    }

    bool AuthenticationLoop()
    {
        if (Serial.available())
        {
            String Buffer = getSerialString();
            if (Buffer == "ID_QUERY")
            {
                Serial.println("DEVICEID=" + Device_ID);
                return false;
            }

            if (Buffer == Device_Password)
            {
                Serial.println("AUTH=SUCCESS");
                return true;
            }
            else
            {
                Serial.println("AUTH=FAILED");
                authTraceback();
            }
        }
        Serial.flush();
        return false;
    }

    /**
     * @brief Get String from Bluetooth Serial
     * 
     * @return String - Message from Serial
     */
    String getSerialString()
    {
        String Buffer = "";
        int tBuffer = Serial.read();

        while (tBuffer != '\n')
        {
            Buffer += (char)tBuffer;
            tBuffer = Serial.read();
        }
        return Buffer;
    }
};