#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

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
	#include <math.h>
    #define CALL(x)
    #define PLL(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
    #define FOREACH(i, max, array)
#endif

#define KB (1024L)

int number_of_digits(int n) {
	int numd=0;
	int i=3;
	while (i >= 0) {
		if(n/((int)pow(10, i--))) numd++;
	}
	return numd;
}

void swap(int *el1, int *el2) {
	int temp;
	temp = *el1;
	*el1 = *el2;
	*el2 = temp;
}

int min(int a, int b) {
	return ((a > b) ? b : a);
}

void stich(int *a, int n, char *str) {
	int i=0, j=0, k=3;
	int idx=0;
	int el=0;
	int numd=0;
	int mark=0;
	for(i=0; i<n; i++) {
		mark=0;
		k=3;
		while(k >= 0) {
			el = a[i]/(int)pow(10,k--);
			el %= 10;
			if (el) mark = 1;
			if (mark == 0) continue;
			str[idx++] = el + '0';
		}	
	}
	str[idx] = '\0';
}

string largest_number(int *a, int n) {
	char *str = (char *)malloc(200 * KB);
	int i=0, j=0, k=3;
	int el=0;
	int numd=0;
	int lookd=0;
	int num=0;
	int l=0;
	int u=0, v=0;
	//write your code here
	//FOREACH(i, n, PLL(a[i]));
	//FOREACH(i, n, PLL(number_of_digits(a[i])));
	//int arr[7] = {5,52,57,517,532,569,581};
	for(i=0; i<n; i++) {
		CALL(printf("========%d========\n", i));
		for(j=i+1; j<n; j++) {
			numd = number_of_digits(a[i]);
			lookd = 0;
			k = 3;
			num = 0;
			while ((lookd < numd) && (k >= 0)) {
				num = a[j]/((int)pow(10, k--));
				if (num) lookd++;
			}
			el = a[i]/((int)pow(10, numd - lookd));
			PLL(el);
			PLL(num);
			if (num > el){
				swap(&a[j], &a[i]);
			}
			else if (num == el) {
				lookd = number_of_digits(a[j]);
				u = a[i];
				v = a[j];
				int q=1;
come_here:
				if (numd > lookd) {
					u = a[i] /(int)pow(10, numd - lookd - q);
					u = u%10;
					v = a[j] /(int)pow(10, lookd - 1);
				}
				else if (lookd > numd) {
					v = a[j] /(int)pow(10, lookd - numd - q);
					v = v%10;
					u = a[i] / (int)pow(10, numd - 1);
				}
				if (v > u) {
					swap(&a[j], &a[i]);
				}
				else if (v == u) {
					q++;
					if (numd > lookd) {
						if(numd - lookd - q == 0)	continue;
					}
					else if (lookd > numd) {
						if(lookd - numd - q == 0)	continue;
					}
					goto come_here;			
				}
			}
		}
		PLL(a[i]);
		l=0;
		FOREACH(l, n, PLL(a[l]));
	}
	
	FOREACH(i, n, PLL(a[i]));
	stich(a, n, str);
	
	return str;
}

int main() {
	//int arr[7] = {5,52,57,517,532,569,581};
	//std::cout << largest_number(arr, 7);
	//return 0;
	int n;
	std::cin >> n;
	int *a = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
	  std::cin >> a[i];
	}
	std::cout << largest_number(a, n);
}
