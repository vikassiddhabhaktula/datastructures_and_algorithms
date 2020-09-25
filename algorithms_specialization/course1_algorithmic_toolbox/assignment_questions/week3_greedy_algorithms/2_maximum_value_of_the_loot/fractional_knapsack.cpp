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
    #define PLLD(x) printf("%s %d %lf\n", __func__, __LINE__, (double)x)
#else
        //#include <stdio.h>
	#include <stdlib.h>
    #define CALL(x)
    #define PLL(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
    #define PLLD(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
#endif

using std::vector;

int compare(const void *el1, const void *el2) {
	return ((*(double *)el2) - (*(double *)el1)) > 0;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  	double value = 0.0;
	int size = weights.size();
	int l=0;
	double results[size][2];
	for (l=0; l<size; l++) {
		results[l][0] = (double)values[l] / weights[l];
		results[l][1] = weights[l];
		PLLD(results[l][0]);
	}

	qsort(results, size, 2*sizeof(double), compare);
	for (l=0; l<size; l++) {
		PLLD(results[l][1]);
	}
	l=0;
	while ((capacity > 0) && (l < size)){
		if (capacity > (int)results[l][1]) {
			value += results[l][0] * results[l][1];
			capacity -= results[l][1];
			PLL(capacity);
		}
		else {
			PLL(capacity);
			value += results[l][0] * (double)capacity;
			capacity = 0;
		}
		l++;
	}

  	// write your code here

	PLLD(value);
	return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
