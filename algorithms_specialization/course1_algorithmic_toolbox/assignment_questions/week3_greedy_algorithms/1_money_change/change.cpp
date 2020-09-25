#include <iostream>

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

int correct(int m) {
	int coins = 0;
	int tens=0, fives=0, ones=0;
	tens = m / 10;
	fives = (m % 10) / 5;
	ones = (m % 10)	% 5;
	coins = tens + fives + ones;
	return coins;
}

int get_change(int m) {
  	//write your code here
	int coins = 0;
	int change[3] = {10, 5, 1};
	int i=0;
	while (m != 0){
		coins += m/change[i];
		m = m%change[i++];
	}
  	return coins;
}

#ifdef TEST
void run_tests() {
	assert(get_change(10) == correct(10));
	int i;
	while(1) {
		i = rand() % 1001;
		PLL(i);
		assert(get_change(i) == correct(i));
	}
}
#endif

int main() {
	CALL(run_tests());
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
