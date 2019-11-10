#ifndef ROVE_EEPROM_H
#define ROVE_EEPROM_H

#include "Energia.h"
#include "driverlib/eeprom.h"
#include <stdio.h>

#define BYTES_PER_WORD 4
#define WORDS_PER_MEMORY_BLOCK 16
#define NUM_MEMORY_BLOCKS 32

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class RoveEEPROM
{
    public:
        uint8_t read(int address);
        void write(int address, uint8_t value);
        void update(int address, uint8_t value);
};

#endif // ROVE_EEPROM_H