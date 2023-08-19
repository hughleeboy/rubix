#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

uint8_t makeIntFromBits(uint8_t value, int start, int length);
uint8_t setIntAtBits(uint8_t value, uint8_t addition, int start, int length);
void printBits8(uint8_t value);
void printBits32 (uint32_t num);
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#endif
