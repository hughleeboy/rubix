#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <stdint.h>
#include "util.h"
#include "cube.h"
#include "coordinate.h"

typedef struct transformation {
	coordinate mapping [6][3][3]; //mapping[new coords] = old coordinates
} transformation;

void printTransformation(transformation *t);
void transformCube(cube *c, transformation *t);
void printTransformation(transformation *t);
void initTransformationFromArray(transformation *t, uint8_t (*t_arr)[3][3][3]);
void initTransformationFromTransformations(transformation *n, transformation *ts, int length);

#endif
