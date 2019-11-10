#include "RoveEEPROM.h"

uint8_t RoveEEPROM::read(int address)
{
  uint32_t byteAddr = address - (address % BYTES_PER_WORD);
  uint32_t wordVal = 0;

  ROM_EEPROMRead(&wordVal, byteAddr, 4);
  wordVal = wordVal >> (8*(address % BYTES_PER_WORD));

  return (uint8_t) wordVal;
}

void RoveEEPROM::write(int address, uint8_t value)
{
  uint32_t byteAddr = address - (address % BYTES_PER_WORD);

  uint32_t wordVal = 0;
  ROM_EEPROMRead(&wordVal, byteAddr, 4);
  wordVal &= ~(0xFF << (8*(address % BYTES_PER_WORD)));
  wordVal |= value << (8*(address % BYTES_PER_WORD));

  ROM_EEPROMProgram(&wordVal, byteAddr, 4);
}

void RoveEEPROM::update(int address, uint8_t value)
{
    uint8_t old_value = read(address);
  
    if(value != old_value)
      write(address, value);
}
