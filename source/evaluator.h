#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "cube.h"

typedef enum evaluator {basicEvaluate_e, teeEvaluate_e} evaluator;

int evaluate(evaluator e, cube *c);

#endif