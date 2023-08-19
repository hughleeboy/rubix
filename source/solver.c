#include "solver.h"
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void initSolver(solver *s, cube *c, evaluator e, transformation *ts, int transformation_count, int depth){
    s->c = c;
    s->e = e;
    s->ts = ts;
    s->transformation_count = transformation_count;
    s->depth = depth;
}

int moveIsBetterThan(moveInformation m1, moveInformation m2){
    if(m1.evaluation > m2.evaluation || (m1.evaluation==m2.evaluation && m1.depth < m2.depth)){
        return 1;
    } else {
        return 0;
    }
}

void solve(solver *s){
    while(1){
        int bestTransformation = findBestMove(s);
        transformCube(s->c, s->ts+bestTransformation);
    }
}

int findBestMove(solver *s){
    moveInformation currentEvaluation;
    currentEvaluation.evaluation = evaluate(s->e, s->c);
    currentEvaluation.depth = 0;

    int *evaluations = malloc(sizeof(int) * s->transformation_count);
    int bestTransformation=0;
    moveInformation bestEvaluation;
    bestEvaluation.evaluation=0;
    for(int ti=0; ti<s->transformation_count; ti++){
        cube innerCube = *(s->c);
        transformCube(&innerCube, s->ts+ti);
        moveInformation innerOutcome = findBestOutcome(s, innerCube, 1);

        evaluations[ti] = innerOutcome.evaluation;
        if(moveIsBetterThan(innerOutcome, bestEvaluation)){
            bestTransformation = ti;
            bestEvaluation = innerOutcome;
        }
    }

    printf("Current Evaluation: %d\n", evaluate(s->e, s->c));
    printf("Best Transformation: %d\t\t Best Evaluation: %d\n", bestTransformation, bestEvaluation.evaluation);
    for(int ti=0; ti<s->transformation_count; ti++){
        printf("%d,", evaluations[ti]);
    }
    printf(currentEvaluation.evaluation >= bestEvaluation.evaluation ? "\nWarning: Current evaluation is better than future evaluations\n\n" : "\n\n");

    return bestTransformation;
}



moveInformation findBestOutcome(solver *s, cube c, int currentDepth){
    moveInformation moveInfo;
    moveInfo.evaluation = evaluate(s->e, &c);
    moveInfo.depth = currentDepth;

    if(currentDepth == s->depth){
        return moveInfo;
    }

    for(int ti=0; ti<s->transformation_count; ti++){
        cube innerCube = c;
        transformCube(&innerCube, s->ts+ti);
        moveInformation innerMoveInfo = findBestOutcome(s, innerCube, currentDepth+1);
        if(moveIsBetterThan(innerMoveInfo, moveInfo)){
            moveInfo = innerMoveInfo;
        }
    }

    return moveInfo;
}

