#ifndef CUBE_H
#define CUBE_H

#include <stdint.h>
#include "coordinate.h"

// typedef enum color { white, blue, yellow, green, orange, red } color;
// // 0 - white
// // 1 - blue
// // 2 - yellow
// // 3 - green
// // 4 - orange
// // 5 - red

typedef uint8_t color;

#define WHITE (color) 0
#define BLUE (color) 1
#define YELLOW (color) 2
#define GREEN (color) 3
#define ORANGE (color) 4
#define RED (color) 5

typedef struct cube {
	uint32_t faces[6];
} cube;

int getColorAtCoordinates(cube *c, coordinate co);
void setColorAtCoordinates(cube *c, coordinate co, uint8_t val);
void initCube(cube *c);
void cubeFromString(cube *c, char str[54]);
void printCube(cube *c);

#endif
