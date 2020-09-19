#include <iostream>
#include <cassert>

//#define TEST
#ifdef TEST
	#include "../compute_time.h"
	double worst_time, best_time;
#endif

int gcd_naive(int a, int b) {
#ifdef TEST
	time_begin();
#endif
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
#ifdef TEST
	worst_time = time_taken();
#endif
  return current_gcd;
}

int __gcd_fast(int a, int b) {
	if (b == 0) return a;
	return __gcd_fast(b, a%b);
}

int gcd_fast(int a, int b) {
#ifdef TEST
	time_begin();
#endif
	int res = __gcd_fast(a, b);
#ifdef TEST
	best_time = time_taken();
#endif
	return res;
}

#ifdef TEST
void run_tests() {
	assert(gcd_fast(18,35) == 1);
	assert(gcd_fast(28851538,1183019) == 17657);
	assert(gcd_fast(5,10) == 5);
	assert(gcd_fast(0,36) == 36);
	assert(gcd_fast(5,2) == 1);
	assert(gcd_fast(0,10) == 10);
	assert(gcd_fast(6,10) == 2);
	while(1) {
		int a = rand() % (20000) + 1000000000;
		int b = rand() % (20000) + 1000000000;
		std::cout << "(" << a << "," << b << ")" << '\n';
		assert(gcd_fast(a,b) == gcd_naive(a,b));
		printf("OK %lf %lf\n", worst_time, best_time);
	}
}
#endif

int main() {
  int a, b;
#ifdef TEST
	run_tests();
#endif
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
