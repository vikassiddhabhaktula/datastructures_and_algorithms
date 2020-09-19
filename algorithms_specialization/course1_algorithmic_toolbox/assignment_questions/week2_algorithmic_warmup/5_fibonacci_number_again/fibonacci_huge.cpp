#include <iostream>

//#define TEST
#ifdef TEST
	#include <cassert>
	#include "../compute_time.h"
	double worst_time, best_time;
	#define CALL(x) (x)
#else
	#define CALL(x) 
#endif

long long get_fibonacci_huge_naive(long long n, long long m) {
	CALL(time_begin());
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
	CALL(worst_time = time_taken());
	//CALL(printf("%s: (%lld, %lld) A:%lld\n", __func__, n, m, current%m));

    return current % m;
}

long long fib_fast(long long n, long long m) {
	CALL(time_begin());
	if (n <= 1)	return n;

	long long prev_2 = 0;
	long long prev_1 = 1;
	long long number; 
	long long i=0;
	long long period = 0;
	//CALL(printf("%lld %lld ", prev_2, prev_1));
	for (i = 0; i < n - 1; ++i) {
		number = (prev_2 + prev_1) % m;
		prev_2 = prev_1;
		prev_1 = number;
		//CALL(printf("%lld ", number));
		if ((prev_2 == 0) && (prev_1 == 1)) {
			period = i+1;
			break;
		}
	}
	if (period) {
		prev_2 = 0;
		prev_1 = 1;
		number = n % period;
		long long n_mod_p = number;
		for (i = 0; i < n_mod_p - 1; ++i) {
			number = (prev_2 + prev_1) % m;
			prev_2 = prev_1;
			prev_1 = number;
		}
	}
	CALL(best_time = time_taken());
	//CALL(printf("%s: (%lld, %lld) A:%lld P:%lld\n", __func__, n, m, number, period));
	return number;
}

#ifdef TEST
void run_tests() {
	//assert(fib_fast(1083, 96) == get_fibonacci_huge_naive(1083, 96));
	assert(fib_fast(3, 2) == get_fibonacci_huge_naive(3, 2));
	assert(fib_fast(6, 2) == get_fibonacci_huge_naive(6, 2));
	assert(fib_fast(16, 3) == get_fibonacci_huge_naive(16, 3));
	assert(fib_fast(16, 4) == get_fibonacci_huge_naive(16, 4));
	assert(fib_fast(239, 1000) == 161);
	assert(fib_fast(2816213588, 239) == 151);
	int i;
	long long n, m;
	for (i = 0; i < 40; ++i) {
		n = rand() % 60 + ((long long)pow(10,2));
		m = rand() % 300 + ((long long)pow(10,1));
		CALL(printf("(%lld, %lld)\n", n, m));
		assert(fib_fast(n, m) == get_fibonacci_huge_naive(n, m));
		CALL(print_time(&worst_time, &best_time));
	}
}
#endif

int main() {
	CALL(run_tests());
	CALL(printf("DONE\n"));
    long long n, m;
    std::cin >> n >> m;
    std::cout << fib_fast(n, m) << '\n';
}
