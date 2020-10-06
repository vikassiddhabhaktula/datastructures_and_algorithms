#ifndef INCLUDE_COMPUTE_TIME_H_
#define INCLUDE_COMPUTE_TIME_H_

#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void time_begin();
void time_end();
double time_taken();
void print_time(double *t1, double *t2);

#ifndef TEST
//#define TEST
#ifdef TEST
    #include <cassert>
    #include "../compute_time.h"
    double worst_time, best_time;
    #define CALL(x) (x)
    #define PRINT_TIME() CALL(print_time(&worst_time, &best_time))
    #define PLL(x) printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
    #define FOREACH(i, max, x) \
            do { \
                for (i=0; i < max; ++i) { \
                    (x); \
                } \
            } while(0);
        #define BEGIN() (time_begin())
        #define END() (time_end())
        #define TT() (time_taken())
        #define WORST() (worst_time = TT())
        #define BEST() (best_time = TT())
#else
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #define CALL(x)
    #define PLL(x)
    #define FOREACH(i, max, array)
        #define BEGIN()
        #define END()
        #define TT()
        #define WORST()
        #define BEST()
#endif
#endif
#endif
