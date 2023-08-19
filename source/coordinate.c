#include "coordinate.h"
#include "util.h"
#include <stdio.h>

coordinate initCoordinateFromFrc(int face, int row, int col){
    coordinate val = 0;
    // printf("\n%d %d %d\n", face, row, col );
    
    // printBits8(val);
    val = setIntAtBits(val, face, 0, 3);
    // printBits8(val);
    val = setIntAtBits(val, row, 3, 2);
    // printBits8(val);
    val = setIntAtBits(val, col, 5, 2);
    // printBits8(val);

    return val;
}

coordinate coordinate_getFace(coordinate c){
    return makeIntFromBits(c, 0, 3);
}
coordinate coordinate_getRow(coordinate c){
    return makeIntFromBits(c, 3, 2);
}
coordinate coordinate_getCol(coordinate c){
    return makeIntFromBits(c, 5, 2);
}