#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
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

int compare(const void *el1, const void *el2) {
	return ((*(int *)el1) - (*(int *)el2) > 0);
}

int get_majority_element(int *a, int n) {
	//write your code here
	if (n == 1) return a[0];
	int num = -1;
	int tot = 0;
	int i=0;
	for (i=0; i<n-1; i++) {
		if (a[i] == a[i+1]) {
			tot++;
			if (tot >= n/2) {
				num = a[i];
				break;
			}
		}
		else {
			tot = 0;
		}
	}
	return num;
}

int main() {
	int n;
	std::cin >> n;
	int a[n];
	for (size_t i = 0; i < n; ++i) {
	  std::cin >> a[i];
	}
	  qsort((void *)a, n, sizeof(int), compare);
	std::cout << (get_majority_element(a, n) != -1) << '\n';
}
