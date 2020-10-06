#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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


int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int find_value(int **wv, int n, int w) {
	int i=0;
	int j=0;
	int val = 0;
	int **a = (int **)calloc(w+1, sizeof(int *));
	for(i=0; i<w+1; i++) {
		a[i] = (int *)calloc(n+1, sizeof(int));
	}
PD();
	for (i=1; i<n+1; i++) {
		for (j=1; j<w+1; j++) {
			a[j][i] = a[j][i-1];
			if (wv[i-1][0] <= j) {
				val = a[j - wv[i-1][0]][i-1] + wv[i-1][1];
				a[j][i] = max(val, a[j][i]);
			}
		}	
	}
PD();
#if 0
	for (j=0; j<w+1; j++) {
		for (i=0; i<n+1; i++) {
			printf("%5d ", a[j][i]);
		}
		printf("\n");
	}

	// backtrack
	int prev;
	int wt;
	int mx;
	int tw = w;
	for (i=n; i>0; i--) {
		prev = a[tw][i-1];
		wt = wv[i-1][0];
		mx = max(a[tw - wt][i-1] + wv[i-1][1], prev);
		if (prev != mx) {	
			b[i-1] = 1;
			tw -= wt;
		}
	}

	for (i=0; i<n; i++)
		printf("%d ", b[i]);
	printf("\n");
#endif
	val = a[w][n];
	for (i=0; i<w+1; i++) {
		free(a[i]);
	}
	free(a);
	return val;
}

#define W 10000
#define N 7
#define EXP 3
int main(int argc, char **argv) {
	int w;
	int i = 0;
	int n;
#ifndef TEST
	scanf("%d", &w);
	scanf("%d", &n);
#else
	w = W;
	n = N;
#endif
PD();
	int **wv = (int **)calloc(n, sizeof(int *));
	for (i=0; i<n; i++)
		wv[i] = (int *)calloc(2, sizeof(int));
	for (i=0; i<n; i++) {
#ifndef TEST
		scanf("%d", &wv[i][0]);
#else
		wv[i][0] = rand() % (int)pow(10, EXP);	
#endif
		wv[i][1] = wv[i][0];
	}
PD();
	printf("%d\n", find_value(wv, n, w));
}
