#include <iostream>
#include <vector>
using std::vector;

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


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	CALL(time_begin());
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }
	CALL(worst_time = time_taken());
    return sum % 10;
}

long long find_period() {
	long long p2=0;
	long long p1=1;
	long long number=0;
	long long i=0;
	do {
		number = (p2+p1)%10;
		p2=p1;
		p1=number;
		i++;
	} while (!((p2 == 0) && (p1 == 1)));
	//PLL(i);
	return i;
}

long long partial_sum_fast(long long m, long long n) {
	CALL(time_begin());
	if (n <= 1)	return n;
	long long p = find_period(); //Ideally don't hardcode it.	
	long long i = m%p;
	long long j = n%p;
	long long l=0;
	long long p2=0;
	long long p1=1;
	long long sum=0;
	long long num=0;
	if ((i == 0) && (j == 0))
		return 0;

	/*	Fi	*/
	for (l=0; l<i-1; l++) {
		num = (p2+p1)%10;
		p2 = p1;
		p1 = num;
	}
	PLL(num);
	if (i<=1)	sum = 1;
	else		sum = num;
/*	I am here	*....................................*/
	/*	Rest	*/
	if (((n - m) < p) && (n/p == m/p)) {
		for (l; l<j-1; l++) {
			num = (p2+p1)%10;
			p2 = p1;
			p1 = num;
			sum = (sum + num)%10;
			PLL(sum);
		}
	}
	else {
		for (l; l<p-1; l++) {
			num = (p2+p1)%10;
			p2 = p1;
			p1 = num;
			sum = (sum + num)%10;
			//PLL(sum);
		}
		PLL(sum);
		p2=0;
		p1=1;
		if (j>0) sum += 1;
		for (l=0; l<j-1; l++) {
			num = (p2+p1)%10;
			p2 = p1;
			p1 = num;
			sum = (sum + num)%10;
			PLL(sum);
		}
	}

	CALL(best_time = time_taken());
	return sum % 10;
}

#ifdef TEST
void run_tests() {
	assert(partial_sum_fast(3,5) == 0); 
	assert(partial_sum_fast(3,6) == 8); 
	assert(partial_sum_fast(5,10) == get_fibonacci_partial_sum_naive(5,10));
	assert(partial_sum_fast(3,5) == get_fibonacci_partial_sum_naive(3,5));
	assert(partial_sum_fast(5,10) == get_fibonacci_partial_sum_naive(5,10));
	long long a,b,f,s;
	while(1) {
		a = rand() % 100;
		b = rand() % 100;
		if (a > b)	continue;
		PLL(a);
		PLL(b);
		f = partial_sum_fast(a,b);
		s = get_fibonacci_partial_sum_naive(a,b);
		PLL(f);
		PLL(s);
		PRINT_TIME();
		assert(f == s);
	}	
}
#endif

int main() {
	CALL(run_tests());
    long long from, to;
    std::cin >> from >> to;
    std::cout << partial_sum_fast(from, to) << '\n';
}
