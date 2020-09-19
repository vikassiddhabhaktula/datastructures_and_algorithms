#ifndef INCLUDE_COMPUTE_TIME_H_
#define INCLUDE_COMPUTE_TIME_H_

#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void time_begin();
void time_end();
double time_taken();
void print_time(double *t1, double *t2);

#endif
