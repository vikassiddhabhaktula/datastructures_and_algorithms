#include <iostream>

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

#define MAX 2000
int *dp = NULL;
int min(int x, int y) {
        if (x < y) return x;
        else return y;
}

int min3(int x, int y, int z) {
        return min(min(x,y), z);
}

int get_change(int m) {
	//write your code here
	// Base case
	if (m == 0) return 0;
	if (m < 0) return MAX;
	if (dp[m] != -1) return dp[m];
	dp[m] = 1 + std::min(std::min(get_change(m-1), get_change(m-3)), get_change(m-4));
	return dp[m];
}

int main() {
	int m;
	int i=0;
	std::cin >> m;

	dp = (int *)calloc(m+1, sizeof(int));
	if (dp == NULL)	return -1;
	for(i=0; i<m+1; i++) {
		dp[i] = -1;
	}
	dp[0] = 0; //	starts here
	i = m;
	get_change(m);
	std::cout << dp[i] << '\n';
	free(dp);
}
