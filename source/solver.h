#ifndef SOLVER_H
#define SOLVER_H

#include "cube.h"
#include "evaluator.h"
#include "transformation.h"

typedef struct solver {
    cube *c;
    evaluator e;
    transformation *ts;
    int transformation_count;
    int depth;
} solver;

typedef struct moveInformation {
    int evaluation;
    int depth;
} moveInformation;

void initSolver(solver *s, cube *c, evaluator e, transformation *ts, int transformation_count, int depth);
void solve(solver *s);
int findBestMove(solver *s);
moveInformation findBestOutcome(solver *s, cube c, int currentDepth);


#endif
