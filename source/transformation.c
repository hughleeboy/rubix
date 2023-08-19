#include <stdint.h>
#include "transformation.h"
#include "util.h"
#include "cube.h"
#include <stdio.h>
#include "coordinate.h"

void transformCube(cube *c, transformation *t){
	cube temp;
	//initCube(&temp);
	for(int face = 0; face < 6; face ++){
		for(int row = 0; row < 3; row ++){
			for(int col = 0; col < 3; col ++){
				coordinate newCoords = initCoordinateFromFrc(face,row,col);
				coordinate oldCoords = t->mapping[face][row][col];
				uint8_t oldFace = coordinate_getFace(oldCoords);
				uint8_t oldRow = coordinate_getFace(oldCoords);
				uint8_t oldCol = coordinate_getFace(oldCoords);

				// printf("%d %d %d = %d\n", oldFace, oldRow, oldCol, getColorAtCoordinates(c, oldFace, oldRow, oldCol));

				setColorAtCoordinates(&temp, newCoords, getColorAtCoordinates(c, oldCoords));
			}
		}
	}
	*c = temp;
}

coordinate getTransformationAtCoordinate(transformation *t, coordinate c){
	return t->mapping[coordinate_getFace(c)][coordinate_getRow(c)][coordinate_getCol(c)];
}

void printTransformation(transformation *t){
	for(int face = 0; face < 6; face ++){
		printf("face %d\n", face);
		for(int row = 0; row < 3; row ++){
			for(int col = 0; col < 3; col ++){
				coordinate oldCoords = t->mapping[face][row][col];
				uint8_t oldFace = coordinate_getFace(oldCoords);
				uint8_t oldRow = coordinate_getRow(oldCoords);
				uint8_t oldCol = coordinate_getCol(oldCoords);

				if(col!=0){
					printf("|");
				}

				//printf("%d%d%d %d%d%d", oldFace, oldRow, oldCol, face, row, col);
				if(oldFace==face && oldRow==row && oldCol==col){
					printf("---");
				}else{
					printf("%d%d%d", oldFace, oldRow, oldCol);
				}
			}
			printf("\n");
		}
	}
}

void initTransformationFromArray(transformation *t, uint8_t (*t_arr)[3][3][3]){
	for(int face = 0; face < 6; face ++){
		for(int row = 0; row < 3; row ++){
			for(int col = 0; col < 3; col ++){
				coordinate val = initCoordinateFromFrc(t_arr[face][row][col][0], t_arr[face][row][col][1], t_arr[face][row][col][2]);

				// uint8_t val = 0;
				// // printf("\n%d %d %d\n", t_arr[face][row][col][0], t_arr[face][row][col][1], t_arr[face][row][col][2] );
				// // printBits8(val);
				// val = setIntAtBits(val, t_arr[face][row][col][0], 0, 3);
				// // printBits8(val);
				// val = setIntAtBits(val, t_arr[face][row][col][1], 3, 2);
				// // printBits8(val);
				// val = setIntAtBits(val, t_arr[face][row][col][2], 5, 2);
				// // printBits8(val);
				t->mapping[face][row][col] = val;
			}
		}
	}
}

// void transformationGetIntValues(transformation *t, int oldFace, int oldRow, int oldCol, int* face, int* row, int* col){
// 	uint8_t newVals = t->mapping[oldFace][oldRow][oldCol];
// 	&face = makeIntFromBits(newVals, 0, 3);
// 	&row = makeIntFromBits(newVals, 3, 2);
// 	&col = makeIntFromBits(newVals, 5, 2);
// }

void initTransformationFromTransformations(transformation *n, transformation *ts, int length){
	for(int face = 0; face < 6; face ++){
		for(int row = 0; row < 3; row ++){
			for(int col = 0; col < 3; col ++){
				int forwardPropagatedFace = face;
				int forwardPropagatedRow = row;
				int forwardPropagatedCol = col;
				coordinate beforeCoord = initCoordinateFromFrc(forwardPropagatedFace, forwardPropagatedRow, forwardPropagatedCol);

				for(int i=0; i<length; i++){
					transformation t = ts[i];
					coordinate newCoord = getTransformationAtCoordinate(&t, beforeCoord);
					beforeCoord=newCoord;
				}

				// printBits8(val);
				n->mapping[face][row][col] = beforeCoord;
			}
		}
	}
}