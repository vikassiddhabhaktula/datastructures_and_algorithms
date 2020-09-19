#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>

//#define TEST
#ifdef TEST
	#include "../compute_time.h"
	double worst_time, best_time;
#endif

int get_fibonacci_last_digit_naive(int n) {
#ifdef TEST
	time_begin();
#endif
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%1000000000;
    }
#ifdef TEST
	time_end();
	worst_time = time_taken();
#endif
    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
#ifdef TEST
	time_begin();
#endif
	if (n <= 1)	return n;
	unsigned int number = 0;
	unsigned int prev_2 = 0;
	unsigned int prev_1 = 1;
	int i;
	for (i = 0; i < n - 1; ++i) {
		number = (prev_2%10) + (prev_1%10);
		prev_2 = prev_1;
		prev_1 = number;
	}
#ifdef TEST
	time_end();
	best_time = time_taken();
#endif
	return (number % 10);
}

#ifdef TEST
void run_tests() {
	assert(get_fibonacci_last_digit_fast(0) == 0);
	assert(get_fibonacci_last_digit_fast(1) == 1);
	assert(get_fibonacci_last_digit_fast(10) == get_fibonacci_last_digit_naive(10));
	assert(get_fibonacci_last_digit_fast(3) == get_fibonacci_last_digit_naive(3));
	assert(get_fibonacci_last_digit_fast(331) == 9);
	assert(get_fibonacci_last_digit_fast(327305) == 5);
	while(1) {
		int number = rand() % 1000000;
		std::cout << number << '\n';
		assert(get_fibonacci_last_digit_fast(number) == get_fibonacci_last_digit_naive(number));
		printf("OK %lf %lf\n", worst_time, best_time);
	}
}
#endif

int main() {
    int n;
#ifdef TEST
	run_tests();
#endif
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
