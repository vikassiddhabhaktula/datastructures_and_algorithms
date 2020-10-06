#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

#define TEST
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

void swap(int *el1, int *el2) {
	int temp;
	temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}

int partition2(int *a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[l], &a[j]);
  return j;
}

void randomized_quick_sort(int *a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(&a[l], &a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void partition3(int *a, int l, int r, int *m1, int *m2) {
	int x = a[l];
	int j = l;
	int k=0, b[r-l];
	int i=0;
	PLL(a[l]);
	FOREACH(i, r+1, PLL(a[l+i]));
	PD();
	for (int i = l + 1; i <= r; i++) {
		//CALL(printf("i:%d j:%d a[i]:%d a[j]:%d x:%d\n",
		//			i, j, a[i], a[j], x));
		if (a[i] <= x) {
		  	j++;
			//CALL(printf("i:%d j:%d a[i]:%d a[j]:%d\n",
			//			i, j, a[i], a[j]));
		  	swap(&a[i], &a[j]);
			if (a[j] == x) {
				b[k] = j;
				k++;	
			}
		}
	}
	if (a[j] == x) k--;
	*m1 = *m2 = j;
	swap(&a[l], &a[j]);
	FOREACH(i, k, PLL(b[i]));
	PD();
	FOREACH(i, r+1, PLL(a[l+i]));
	PD();
	for (i=0; i<k; i++) {
		swap(&a[b[i]], &a[j-1-i]);
		*m1 = *m1 - 1;
	}
	FOREACH(i, r+1, PLL(a[l+i]));
	PD();
}

void randomized_quick_sort_fast(int *a, int l, int r) {
	if (l >= r) {
	  return;
	}
	int m1, m2;	
	int k = l + rand() % (r - l + 1);
	swap(&a[l], &a[k]);
	partition3(a, l, r, &m1, &m2);
	
	randomized_quick_sort_fast(a, l, m1 - 1);
	randomized_quick_sort_fast(a, m2 + 1, r);
}

void wps(int *a, int l, int r) {
	BEGIN();
	randomized_quick_sort(a, l, r);
	WORST();
}

void wpf(int *a, int l, int r) {
	BEGIN();
	randomized_quick_sort_fast(a, l, r);
	BEST();
}

int array_match(int *a1, int *a2, int n) {
	int ret=1;
	int i=0;
	for(i=0; i < n; i++) {
		if (a1[i] != a2[i])	{
			PD();
			PD();
			PD();
			CALL(printf("i:%d a1[i]:%d a2[i]:%d\n", i, a1[i], a2[i]));
			PD();
			FOREACH(i, n, PLL(a1[i]));
			PD();
			FOREACH(i, n, PLL(a2[i]));
			PD();
			PD();
			PD();	
			return 0;
		}
	}
	return ret;
}

#ifdef TEST
#define BOUND 10 //100000L
#define EXP 1
void run_tests() {
	int *s = NULL;
	int *f = NULL;
	int n = 0;
	int i=0;
	{
		#define N 9
		int arr[N] = {1,2,2,2,5,8,8,10,10};
        for (int i = 0; i < N; ++i) {
            std::cout << arr[i] << ' ';
        }
		PD();
		wpf(arr, 0, N-1);
		for (int i = 0; i < N; ++i) {
	  		std::cout << arr[i] << ' ';
		}
		PD();
		//return;
	}
	while(1) {
		n = rand() % BOUND;
		if (0 == n)	continue;
		s = (int *)malloc(n * sizeof(int));
		if (NULL == s)	continue;
		f = (int *)malloc(n * sizeof(int));
		if (NULL == f) {
			free(s);
			continue;
		}
		PD();
		FOREACH(i, n, s[i] = 1 + rand()%((int)pow(10, EXP)));
		memcpy((void *)f, (void *)s, n * sizeof(int));
		wps(s, 0, n-1);
		wpf(f, 0, n-1);
		assert(array_match(s, f, n));
		PRINT_TIME();	
		free(s);
		free(f);
	}
}
#endif

int main() {
	CALL(run_tests());
	//return 0;
	int n;
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
	  std::cin >> a[i];
	}
	randomized_quick_sort_fast(a, 0, n - 1);
	for (int i = 0; i < n; ++i) {
	  std::cout << a[i] << ' ';
	}
}
