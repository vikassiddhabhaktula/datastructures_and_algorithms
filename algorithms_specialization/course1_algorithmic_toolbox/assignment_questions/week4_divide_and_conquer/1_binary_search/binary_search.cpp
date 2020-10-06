#include <iostream>
#include <cassert>
#include <vector>

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

using std::vector;

int compare(const void *el1, const void *el2) {
	return ((*(int *)el1) - (*(int *)el2)  > 0);
}

#ifdef TEST
int __binary_search_gfg(const int *arr, int l, int r, int x) {
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if ((unsigned int)x > (unsigned int)arr[m]) { 
            l = m + 1; 
		}
        else {
            r = m - 1; 
		}
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1;	
}
#endif

int __binary_search(const int *a, int l, int r, int x) {
	int m = (r - l) / 2;
	m += l;
	if (x == a[m]) return (m);
	if (r <= l) return -1;
	if (x < a[m]) {
		__binary_search(a, l, m-1, x);
	}
	else {
		__binary_search(a, m+1, r, x);
	}
}

int linear_search(const int *a, int n, int x) {
	BEGIN();
	int idx=-1;
	qsort((void *)a, n, sizeof(int), compare);
	for (size_t i = 0; i < n; ++i) {
	  if (a[i] == x)  {idx = i;break;}
	}
	WORST();
	return idx;
}

int binary_search(const int *a, int n, int x) {
	//write your code here
	BEGIN();
	int i=0;
	int l = 0, r = n-1; 
	//FOREACH(i, n, PLL(a[i]));
	int idx = __binary_search(a, l, r, x);
	BEST();
	return idx;
}

#ifdef TEST
#define BOUND 30000
#define EXP 9
void run_tests() {
	int *arr;
	int num = 0;
	int i=0;
	int ls=0, bs=0;
	int key=10;
	binary_search(&key, 1, 100);
	while(1) {
		num = (rand()%BOUND);
		if (0 == num) continue;
		arr = (int *)malloc(num * sizeof(int));
		if (arr == NULL)	continue;
		FOREACH(i, num, (arr[i] = rand()%((int)pow(10,EXP))));
		//FOREACH(i, num, PLL(arr[i]));
		//key = arr[rand()%num];
		qsort(arr, num, sizeof(int), compare);
		key = arr[num-1];
		CALL(printf("num:%d key:%d\n", num, key));
		ls = __binary_search_gfg(arr, 0, num-1, key); //linear_search(arr, num, key);
		bs = binary_search(arr, num, key);
		CALL(printf("num:%d LS:%d BS:%d key:%d\n", num, ls, bs, key));
		if (ls != bs)	{FOREACH(i, num, PLL(arr[i]));}
		assert(ls == bs);
		PRINT_TIME();
		if ((unsigned int)best_time > 1) break;
		free(arr);
	}
}
#endif

int main() {
	CALL(run_tests());
	int n;
	std::cin >> n;
	int a[n];
	for (size_t i = 0; i < n; i++) {
	  std::cin >> a[i];
	}
	qsort((void *)a, n, sizeof(int), compare);
	int m;
	std::cin >> m;
	int b[m];
	for (int i = 0; i < m; ++i) {
	  std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
	  //replace with the call to binary_search when implemented
	  std::cout << binary_search(a, n, b[i]) << ' ';
	}
}
