#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#define TIME
#ifdef TIME
	#include <time.h>
	double worst_time, best_time;
#endif

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.


long long fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

#ifdef TIME
long long fibonacci_naive_time(int n) {
	clock_t begin = clock(), end;
	long long number;
	number = fibonacci_naive(n);
	end = clock();
	worst_time = (double)(end - begin)/CLOCKS_PER_SEC;
	return number;
}
#else
int fibonacci_naive_time(int n) {
	return fibonacci_naive(n);
}
#endif

long long fibonacci_fast(int n) {
#ifdef TIME
	clock_t begin = clock(), end;
#endif
    // write your code here
	if (n <= 1) return n;
	int i, number=0;
	int prev_2 = 0, prev_1 = 1;
	for(i=2; i<=n; i++) {	
		number = ((long long)prev_2) + prev_1;
		prev_2 = prev_1;
		prev_1 = number;
	}
#ifdef TIME
	end = clock();
	best_time = (double)(end - begin)/CLOCKS_PER_SEC;
#endif
	//std::cout << "number " << number << '\n';
    return number;
}

void test_solution() {
	int n;
    assert(fibonacci_fast(0) == 0);
    assert(fibonacci_fast(1) == 1);
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
	for (n = 0; n < 20; ++n) {
		int number = rand() % 50;
		std::cout << "number: " << number << '\n';
		long long best = fibonacci_fast(number);
		long long worst = fibonacci_naive_time(number);
		assert(best == worst);
#ifdef TIME
		printf("OK %lld %lf %lf\n", best, worst_time, best_time);
#endif
	}
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
#ifdef TEST
    test_solution();
#endif
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
