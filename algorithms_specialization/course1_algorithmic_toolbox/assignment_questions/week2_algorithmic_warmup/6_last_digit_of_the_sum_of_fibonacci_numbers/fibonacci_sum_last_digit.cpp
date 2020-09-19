#include <iostream>

//#define TEST
#ifdef TEST
    #include <cassert>
    #include "../compute_time.h"
    double worst_time, best_time;
    #define CALL(x) (x)
	#define PRINT_TIME() CALL(print_time(&worst_time, &best_time))
#else
    #define CALL(x)
#endif


int fibonacci_sum_naive(long long n) {
	CALL(time_begin());
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
	CALL(worst_time = time_taken());
    return sum % 10;
}

long long find_period() {
	long long period = 0;
	long long i = 0;
	int pv_2 = 0;
	int pv_1 = 1;
	int num;
	while(1){
		num = (pv_1 + pv_2) % 10;
		pv_2 = pv_1;
		pv_1 = num;
		if ((pv_2 == 0) && (pv_1 == 1)) {
			period = i+1;
			break;
		}
		i++;
	}
	return period;
}

int fib_fast(long long n) {
	CALL(time_begin());
	n = n % find_period();
	if (n <= 1) return n;
	int prev_2 = 0;
	int prev_1 = 1;
	long long i;
	int num;
	int sum = 1;
	for (i = 0; i < n - 1; ++i) {
		num = (prev_2 + prev_1)%10;
		prev_2 = prev_1;
		prev_1 = num;
		sum = (sum + num)%10;		
	}
	CALL(best_time = time_taken());
	return sum;
}

#ifdef TEST
void run_tests() {
	assert(fib_fast(3) == 4);
	assert(fib_fast(100) == 5);
	assert(fib_fast(10) == fibonacci_sum_naive(10));
	PRINT_TIME();
	long long n;
	int i;
	int naive = -1, best;
	while(1) {
		n = rand() % (long long)pow(10,14);
		printf("%lld \n", n);
		best = fib_fast(n);
		//naive = fibonacci_sum_naive(n);
		printf("%d %d\n", naive, best);
		PRINT_TIME();
		if (naive < 0)	continue;
		assert(naive == best);
		PRINT_TIME();
	}
	CALL(printf("DONE\n"));
}
#endif

int main() {
	CALL(std::cout << period << '\n');
	CALL(run_tests());
    long long n = 0;
    std::cin >> n;
    std::cout << fib_fast(n) << '\n';
}
