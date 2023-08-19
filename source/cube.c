#include <stdio.h>
#include "cube.h"
#include "util.h"
#include "coordinate.h"

int getColorAtCoordinates(cube *c, coordinate co){
	uint8_t face = coordinate_getFace(co);
	uint8_t row = coordinate_getRow(co);
	uint8_t col = coordinate_getCol(co);
	// printf("%d, %d, %d\n", face, row, col);

	int offset = 9*row + 3*col;
	
	int raw = c->faces[face];
	int num = (raw & (((uint32_t)0b11100000000000000000000000000000) >> offset)) >> (29-offset);

	return num;
}

void setColorAtCoordinates(cube *c, coordinate co, uint8_t val){
	uint8_t face = coordinate_getFace(co);
	uint8_t row = coordinate_getRow(co);
	uint8_t col = coordinate_getCol(co);
	uint8_t offset = 9*row + 3*col;
	
	uint32_t raw = c->faces[face];
	// uint32_t raw = 0;
	// printf("face before setting face:%d row:%d col:%d, offset:%d, val:%d\n", face, row, col, offset, val);
	// printBits32(raw);
	// printBits32(((uint32_t)0b11100000000000000000000000000000) >> offset);
	// printBits32((((uint32_t) val << 29) >> offset));

	uint32_t num = raw & ~(((uint32_t)0b11100000000000000000000000000000) >> offset) | (((uint32_t) val << 29) >> offset);
	// printBits32(num);
	// printf("%u\n", num);

	c->faces[face] = num;
}

void initCube(cube *c){
	c->faces[0] = (uint32_t) 0b000000000000000000000000000 << 5;
	c->faces[1] = (uint32_t) 0b001001001001001001001001001 << 5;
	c->faces[2] = (uint32_t) 0b010010010010010010010010010 << 5;
	c->faces[3] = (uint32_t) 0b011011011011011011011011011 << 5;
	c->faces[4] = (uint32_t) 0b100100100100100100100100100 << 5;
	c->faces[5] = (uint32_t) 0b101101101101101101101101101 << 5;
}

void cubeFromString(cube *c, char str[54]){
	for(int face=0; face<6; face++){
		for(int row=0; row<3; row++){
			for(int col=0; col<3; col++){
				int lookupOffset = face*9+row*3+col;
				char ch = str[lookupOffset];
				color clr;
				switch(ch){
					case 'w': clr = WHITE; break;
					case 'b': clr = BLUE; break;
					case 'y': clr = YELLOW; break;
					case 'g': clr = GREEN; break;
					case 'o': clr = ORANGE; break;
					case 'r': clr = RED; break;
				}
				setColorAtCoordinates(c, initCoordinateFromFrc(face, row, col), clr);
			}
		}
	}
}

void printCube(cube *c){
	for(int face=0; face<6; face++){
		for(int row=0; row<3; row++){
			for(int col=0; col<3; col++){
				printf("%d", getColorAtCoordinates(c, initCoordinateFromFrc(face, row, col)));
			}
			printf("\n");
		}
		printf("\n");
	}
}
