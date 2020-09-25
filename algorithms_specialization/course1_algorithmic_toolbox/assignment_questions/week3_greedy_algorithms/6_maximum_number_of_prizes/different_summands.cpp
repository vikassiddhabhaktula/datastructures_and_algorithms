#include <iostream>
#include <vector>

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
#else
    #include <stdio.h>
    #include <stdlib.h>
    #define CALL(x)
    #define PLL(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
    #define FOREACH(i, max, array)
#endif


using std::vector;
#define KB (1024L)
#define MB (1024L * 1024L)

int optimal_summands(int n, int *summands) {
	int total=0;
	int i=0;
	if (n == 0)	return 0;
	while (n > 0) {
		if (i >= (n-i)) {
			total++;
			summands[i] = n;
			break;
		}
		total++;
		summands[i] = i;
		n -= i;
		i++;
	}
	//write your code here
	return total;
}

int main() {
	int n;
	std::cin >> n;
	int *summands = (int *)malloc(50 * KB * sizeof(int));
	if (summands == NULL) {
		std::cout << "Not enough mem"  << '\n';
		return -1;
	}
	int total_summands = optimal_summands(n, summands);
	std::cout << (total_summands ? (total_summands - 1) : 0) << '\n';
	for (size_t i = 1; i < total_summands; ++i) {
	  std::cout << summands[i] << ' ';
	}
}
