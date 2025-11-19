#pragma once
#include <cstdint>

// Mock SPI клас
class SPIClass {
public:
    void begin() {}
    void end() {}
    uint8_t transfer(uint8_t data) { return 0; }
    void beginTransaction() {}
    void endTransaction() {}
};

extern SPIClass SPI;