#include "evaluator.h"
#include "cube.h"

int basicEvaluate(cube *c){
    int count = 0;
	for(int face=0; face<6; face++){
		for(int row=0; row<3; row++){
			for(int col=0; col<3; col++){
                if(getColorAtCoordinates(c, initCoordinateFromFrc(face, row, col)) 
                    == getColorAtCoordinates(c, initCoordinateFromFrc(face, 1, 1))){
                    count ++;
                }
            }
        }
    }
    return count;
}

int teeEvaluate(cube *c){
   int count = 0;
	for(int face=0; face<6; face++){
		for(int row=0; row<3; row++){
			for(int col=0; col<3; col++){
                if(getColorAtCoordinates(c, initCoordinateFromFrc(face, row, col)) 
                    == getColorAtCoordinates(c, initCoordinateFromFrc(face, 1, 1))){
                        if(row+col % 2 == 1){
                            //part of the cross
                            count += 31;
                        }else{
                            count ++;
                        }
                    count ++;
                }
            }
        }
    }
    return count;
}

int evaluate(evaluator e, cube *c){
    switch(e){
        case basicEvaluate_e:
            return basicEvaluate(c);
        case teeEvaluate_e:
            return teeEvaluate(c);
    }
}