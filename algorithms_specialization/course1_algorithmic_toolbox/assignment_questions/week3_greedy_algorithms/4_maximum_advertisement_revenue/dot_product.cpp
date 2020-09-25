#include <algorithm>
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
#else
	#include <stdio.h>
    #include <stdlib.h>
    #define CALL(x)
    #define PLL(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
#endif


using std::vector;

int compare(const void *el1, const void *el2) {
	return ((*(int *)el2) - (*(int *)el1)) > 0;
}

long long max_dot_product(int *a, int *b, int size) {
	// write your code here
	long long result = 0;
	qsort(a, size, sizeof(int), compare);
	qsort(b, size, sizeof(int), compare);
	for (size_t i = 0; i < size; i++) {
	  result += ((long long) a[i]) * b[i];
	}
	return result;
}

int main() {
  size_t n;
  std::cin >> n;
  int a[n], b[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b, n) << std::endl;
}
