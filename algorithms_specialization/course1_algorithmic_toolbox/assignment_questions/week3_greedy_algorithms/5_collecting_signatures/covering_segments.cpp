#include <algorithm>
#include <iostream>
#include <climits>
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

int compare(const void *el1, const void *el2) {
	return ((*(int *)el1) - (*(int *)el2)) > 0;
}

int optimal_points(int segments[][2], int n, int *points) {
	//write your code here
	int i=0;
	int curr=0;
	int total = 0;
	FOREACH(i, n, printf("(%d, %d)\n", segments[i][0], segments[i][1]));
	qsort(segments, n, 2*sizeof(int), compare);
	FOREACH(i, n, printf("(%d, %d)\n", segments[i][0], segments[i][1]));
	i=0;
	if (n == 1)	{
		points[total] = segments[0][1];
		return ++total;
	}
	while (i < n) {
		curr = segments[i][1];
		PLL(curr);
		if (i == n-1) {
			if (!(segments[i][0] > points[total - 1]))
				break;
			i++;
		}
		while (i < n-1) {
			if (curr < segments[i+1][0]) {
				PLL(i);
				i++;
				break;
			}
			else if (curr >= segments[i+1][0] &&
					 curr <= segments[i+1][1]) {
				PLL(i);
				i++;
			}
			else {
				PLL(i);
				curr = segments[i+1][1];
				i++;	
			}
		}
		points[total] = curr; 
		total++;
	}
	
	PLL(total);
	return total;
}

int main() {
	int n;
	std::cin >> n;
	int segments[n][2];
	for (size_t i = 0; i < n; ++i) {
	  std::cin >> segments[i][0] >> segments[i][1];
	}

	int points[n];
	int total_points = optimal_points(segments, n, points);
	std::cout << total_points << "\n";
	for (size_t i = 0; i < total_points; ++i) {
	  std::cout << points[i] << " ";
	}
}
