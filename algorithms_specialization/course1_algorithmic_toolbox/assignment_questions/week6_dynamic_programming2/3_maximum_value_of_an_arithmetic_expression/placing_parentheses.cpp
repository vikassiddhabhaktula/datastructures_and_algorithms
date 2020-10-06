#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

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
        #define PD() CALL(printf("================\n"))
#else
    #include <stdio.h>
    #include <stdlib.h>
        #include <string.h>
    #include <math.h>
    #define CALL(x)
    #define PLL(x)
    #define FOREACH(i, max, array)
        #define BEGIN()
        #define END()
        #define TT()
        #define WORST()
        #define BEST()
        #define PD()
#endif

#define MIN (1LL << 60)
#define MAX (-MIN)

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
	  	return a + b;
	} else if (op == '-') {
	  	return a - b;
	} else {
	  	assert(0);
	}
}

void minmax(const char *s, int i, int j,
				 long long **m, long long **M) {
	long long min = MIN;
	long long max = MAX;
	int k=0;
	long long a,b,c,d;
	for (k=i; k<j; k++) {
		a = eval(m[i][k], m[k+1][j], s[(k*2) + 1]);
		b = eval(m[i][k], M[k+1][j], s[(k*2) + 1]);
		c = eval(M[i][k], m[k+1][j], s[(k*2) + 1]);
		d = eval(M[i][k], M[k+1][j], s[(k*2) + 1]);
		min = std::min(min, std::min(std::min(a,b), std::min(c,d)));
		max = std::max(max, std::max(std::min(a,b), std::max(c,d)));
	}
	m[i][j] = min;
	M[i][j] = max;
}

long long get_maximum_value(const char *s) {
	//write your code here
	int len = strlen(s);
	if (len == 0)	return 0;
	int r = (len/2) + 1;
	int i=0,sp,j;
	long long val = 0;
	//	Create the matrices.
	long long **m = (long long **)calloc(r, sizeof(long long *));
	for (i=0; i<r; i++) m[i] = (long long *)calloc(r, sizeof(long long));
	long long **M = (long long **)calloc(r, sizeof(long long *));
	for (i=0; i<r; i++) M[i] = (long long *)calloc(r, sizeof(long long));
	//	Initialize the diagonal
	for (i=0; i<r; i++) m[i][i] = M[i][i] = s[i*2] - '0';
	//	Find the rest
	for (sp=0; sp<r; sp++) {
		for (i=0; i<r-sp; i++) {
			j = i + sp;
			if (i == j)	continue;
			minmax(s, i, j, m, M);
		}
	}
	val = M[0][r-1];
	free(m);
	free(M);
	//	return the result
	return val;
}

int main() {
	char s[40];
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
