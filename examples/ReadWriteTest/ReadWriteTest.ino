#include "RoveEEPROM.h"



String command;
RoveEEPROM EEPROM;

void setup() 
{
  Serial.begin(115200);

  while (!Serial);  //wait for serial to start, so we can display info on serial monitor

  Serial.println("Writing to EEPROM and then reading");
  EEPROM.write(0, 15);
  EEPROM.write(1, 16);
  EEPROM.write(2, 17);
  EEPROM.write(3, 18);

  delay(100);
}

void loop() 
{
    while (Serial.available()) 
        {
        char c = Serial.read();  
        command += c; 
        delay(5);  
        }

    if (command.length() >0) 
        {
        if (command == "read")
            {
            Serial.println("Read: ");
            Serial.println(EEPROM.read(0));
            Serial.println(EEPROM.read(1));
            Serial.println(EEPROM.read(2));
            Serial.println(EEPROM.read(3));

            }
        command = "";
        }
    }