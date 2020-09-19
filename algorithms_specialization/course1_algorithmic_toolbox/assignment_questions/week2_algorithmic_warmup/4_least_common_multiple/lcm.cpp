#include <iostream>
#include <cassert>
//#define TEST
#ifdef TEST
	#include "../compute_time.h"
	double worst_time, best_time;
#endif

long long lcm_naive(int a, int b) {
#ifdef TEST
	time_begin();
#endif
	long long res = ((long long)a) * b;
  	for (long l = 1; l <= (long long) a * b; ++l) {
    	if (l % a == 0 && l % b == 0) {
     		res = l;
			break;
		}
	}
#ifdef TEST
	worst_time = time_taken();
#endif

  return res; 
}

int gcd_fast(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd_fast(b, a%b);
}

long long lcm_fast(int a, int b) {
#ifdef TEST
	time_begin();
#endif
	long long res = (((long long)a) * b)/gcd_fast(a, b);
#ifdef TEST
	best_time = time_taken();
#endif
	return res;
}

#ifdef TEST
void run_tests() {
	assert(lcm_fast(1, 1) == 1);
	assert(lcm_fast(6, 8) == 24);
	assert(lcm_fast(761457, 614573) == 467970912861);
	assert(lcm_fast(5, 6) == lcm_naive(5, 6));
	int a, b;
	long long naive, fast;
	int i;
	for (i=0; i<40; i++) {
		a = rand() % 2000 + 30000;
		b = rand() % 2000 + 30000;
		printf("(%d, %d) ", a, b);
		naive = lcm_naive(a, b);
		fast = lcm_fast(a, b);
		assert(fast == naive);
		printf("%lld\n", fast);
		print_time(&worst_time, &best_time);
	}
}
#endif


int main() {
#ifdef TEST
	run_tests();
#endif
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
