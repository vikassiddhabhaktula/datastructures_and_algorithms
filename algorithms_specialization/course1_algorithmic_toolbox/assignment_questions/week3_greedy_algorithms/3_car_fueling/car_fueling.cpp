#include <iostream>
#include <vector>

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

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int refills = 0;
	int st=0, l=0;
	int pv=0;
	int rem_dist = dist;
	while (rem_dist > 0) {
		if (tank >= rem_dist)	break;
		while ((tank >= stops[l] - st) && (l < stops.size())) {
			pv = stops[l];
			l++;
		}
		PLL(st);
		PLL(pv);
		if ((st == pv) && (rem_dist > tank)) return -1;
		st = pv;
		refills++;
		rem_dist = dist - st;
		PLL(rem_dist);
	}
    // write your code here
    return refills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
