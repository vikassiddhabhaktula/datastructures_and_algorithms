#include <iostream>
#include <stdlib.h>
#include <math.h>

//#define TEST
#ifdef TEST
    #include <cassert>
    #include "../compute_time.h"
    double worst_time, best_time;
    #define CALL(x) (x)
    #define PRINT_TIME() CALL(print_time(&worst_time, &best_time))
    #define PLL(x) printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
#else
        //#include <stdio.h>
    #define CALL(x)
    #define PLL(x) //printf("%s %d %lld\n", __func__, __LINE__, (long long)x)
#endif

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long find_period() {
	long long i=0;
	long long p2=0, p1=1, fi=0, num=0, p2_sq=0, p1_sq=1;
	do {
		fi = p2 + p1;
		p2 = p1;
		p1 = fi;
		num = ((long long)pow(fi,2))%10;
		p2_sq = p1_sq;
		p1_sq = num;
		//PLL(num);
		i++;
	} while (!((p2_sq == 0) && (p1_sq == 1)));
	//PLL(i);
	return i;
}

int fib_fast(long long n) {
	long long i = (n % find_period());
	if (i<=1)	return i;
	long long p2=0, p1=1, fi=0, num=0;
	long long l=0;
	int sum = 1;
	for (l=0; l<i-1; ++l) {
		fi = p2 + p1;
		p2 = p1;
		p1 = fi;
		num = ((long long)pow(fi,2))%10;
		//PLL(num);
		sum += num;
		sum %= 10;
		//PLL(sum);
	}
	return sum%10;	
}

#ifdef TEST
void run_tests() {
	assert(fib_fast(10) == fibonacci_sum_squares_naive(10));
	assert(fib_fast(20) == fibonacci_sum_squares_naive(20));
	assert(fib_fast(30) == fibonacci_sum_squares_naive(30));
	assert(fib_fast(40) == fibonacci_sum_squares_naive(40));
	long long n;
	while(1) {
		n = rand() % 60 + 5;
		PLL(n);
		PLL(fib_fast(n));
		PLL(fibonacci_sum_squares_naive(n));
		assert(fib_fast(n) == fibonacci_sum_squares_naive(n));
	}
}
#endif

int main() {
	CALL(run_tests());
    long long n = 0;
    std::cin >> n;
    std::cout << fib_fast(n);
}
