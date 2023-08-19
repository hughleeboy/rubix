#include "util.h"
#include <stdio.h>
#include <inttypes.h>

uint8_t makeIntFromBits(uint8_t value, int start, int length){
	// printf("value: %d, start: %d, length: %d\n", value, start, length);
//	printf("result: %d\n", ((uint8_t)128) >> (6));
	// printBits(value);
	// printBits(value << start);
	// printBits((uint8_t)(value << start) >> (8-length));
	return ((uint8_t)(value << start)) >> (8-length);
}

uint8_t setIntAtBits(uint8_t value, uint8_t addition, int start, int length){
	uint8_t mask = 0b00000000;
	uint8_t digit = 0b10000000;
	for(int i=0; i<8; i++, digit >>= 1){
		if(i>=start && i<start+length){
			mask |= digit;
		}
	}

	return value & ~(((uint8_t)mask) >> start) | ((addition << (8-length)) >> start);
}


void printBits8 (uint8_t num){
	for(int i=0;i<8;++i){
		// print last bit and shift left.
		printf("%u ",num & 128 ? 1 : 0);
		num = num<<1;
	}
	printf("\n");
}

void printBits32 (uint32_t num){
	for(int i=0;i<32;++i){
		// print last bit and shift left.
		printf("%u ",num & 2147483648 ? 1 : 0);
		num = num<<1;
	}
	printf("\n");
}
