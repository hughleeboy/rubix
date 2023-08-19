#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdint.h>

typedef uint8_t coordinate;

coordinate initCoordinateFromFrc(int face, int row, int col);

coordinate coordinate_getFace(coordinate c);
coordinate coordinate_getRow(coordinate c);
coordinate coordinate_getCol(coordinate c);

#endif