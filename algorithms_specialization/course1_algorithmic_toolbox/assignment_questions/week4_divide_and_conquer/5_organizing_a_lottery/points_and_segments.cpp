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
    #define FOREACH(i, max, x) \
            do { \
                for (i=0; i < max; ++i) { \
                    (x); \
                } \
            } while(0);
    #define BEGIN() (time_begin())
    #define END() (time_end())
    #define TT() (time_taken())
    #define WORST() (worst_time = TT())
    #define BEST() (best_time = TT())
    #define PD() CALL(printf("================\n"))
#else
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #define CALL(x)
    #define PLL(x)
    #define FOREACH(i, max, array)
    #define BEGIN()
    #define END()
    #define TT()
    #define WORST()
    #define BEST()
    #define PD()
#endif


using std::vector;

int **dp = NULL;

int compare(const void *el1, const void *el2) {
	int **d1 = (int **)el1;
	int **d2 = (int **)el2;
	return (*d1[0] - *d2[0]);
}

int compare2(const void *el1, const void *el2) {
	int **d1 = (int **)el1;
	int **d2 = (int **)el2;
	return (*d1[1] - *d2[1]);
}

#define ST 1
#define EN 0

void fast_count_segments(int **segments, int s, int e, int **points, int sp, int ep) {
	// base case
	int i=0;
	if (e == s) {
		for (i=sp; i<=ep; i++) {
			if ((segments[s][ST] <= points[i][0]) && (points[i][0] <= segments[s][EN])) {
				dp[i][1]++;
			}
		}
		return;
	}
	if (ep == sp) {
		for (i=s; i<=e; i++) {
			if ((segments[i][ST] <= points[sp][0]) && (points[sp][0] <= segments[i][EN])) {
				dp[sp][1]++;
			}
		}
		return;
	}
	int mp = sp + ((ep - sp) / 2);
	int m = s + ((e - s) / 2);
	if (points[mp][0] > segments[m][EN]) {
		fast_count_segments(segments, m+1, e, points, mp, ep);
		fast_count_segments(segments, s, m, points, sp, mp-1);
	}
	else {
		fast_count_segments(segments, s, m, points, sp, mp);
		fast_count_segments(segments, m+1, e, points, mp+1, ep);
	}
#if 0
	if (points[mp][0] > segments[m][1]) {
		fast_count_segments(segments, m+1, e, points, mp, ep);
		fast_count_segments(segments, s, m, points, sp, mp-1);
	}
	else {
		fast_count_segments(segments, s, m, points, sp, mp);
		fast_count_segments(segments, m+1, e, points, mp+1, ep);
	}
#endif
	return;
}

int * naive_count_segments(int **segments, int num_segs, int **points, int num_points) {
	int *cnt = (int *)calloc(num_points, sizeof(int));
	for (int i = 0; i < num_points; i++) {
	  for (int j = 0; j < num_segs; j++) {
	    cnt[i] += segments[j][0] <= points[i][0] && points[i][0] <= segments[j][1];
	  }
	}
	return cnt;
}

#define N 50000
#define M 50000
#define EXP 8
#define INT 10000000
int main() {
	int n, m;
	int i=0;
#ifndef TEST
	std::cin >> n >> m;
#else
	n = 6;//N;
	m = 7;//M;
	int arr[12] = {0,2,1,3,2,4,3,5,4,6,5,7};
	int p[7] = {1, 1,1,2,2,3,4};
#endif
	int **segments = (int **)calloc((n*2) + m, sizeof(int *));
	if (segments == NULL)	return -1;
	for (int i = 0; i < (n*2) + m; i++) {
		segments[i] = (int *)calloc(2, sizeof(int));
		if (segments[i] == NULL)	return -2;
	}

	PD();
	for (int i = 0; i < n*2; i++) {
#ifndef TEST
		std::cin >> segments[i][0];
#else
		segments[i][0] = arr[i];//(rand() % (long long)pow(10, EXP));
#endif
		segments[i++][1] = -1;
#ifndef TEST
		std::cin >> segments[i][0];
#else
		segments[i][0] =  arr[i]; //segments[i-1][0] + (rand() % INT);
#endif
		segments[i][1] = 1;
	}
	FOREACH(i, (n*2) + m, printf("segs: %d,%d\n", segments[i][0], segments[i][1]));

	PD();
	int **points = (int **)calloc(m, sizeof(int *));
	if (points == NULL)	return -3;
	for (int i = 0; i < m; i++) {
		points[i] = (int *)calloc(2, sizeof(int));
		if (points[i] == NULL)	return -4;
	}
	PD();
	for (int i = 0; i < m; i++) {
#ifndef TEST
	    std::cin >> points[i][0];
#else
		points[i][0] = p[i];//rand() % (long long)pow(10, EXP);
#endif
		segments[(n*2) + i][0] = points[i][0];
		segments[(n*2) + i][1] = 0;
		points[i][1] = i;
	}
	PD();

	// sort the segs
	qsort((void *)segments, (n*2) + m, 2*sizeof(int), compare);
	FOREACH(i, (n*2) + m, printf("segs: %d,%d\n", segments[i][0], segments[i][1]));
	// sort the points
	qsort((void *)points, m, 2*sizeof(int), compare);
	FOREACH(i, m, printf("points: %d,%d\n", points[i][0], points[i][1]));

	//use fast_count_segments
	dp = (int **)calloc(m, sizeof(int *));
	if (dp == NULL)	return -4;
	for (int i = 0; i < m; i++) {
		dp[i] = (int *)calloc(3, sizeof(int));
		if (dp[i] == NULL)	return -5;
	}
	for (int i = 0; i < m; i++) {
		dp[i][0] = points[i][1];
	}

	//for(int i=0; i<m; i++) {
	i=0;
	for (int j=0; j<(n*2) + m; j++) {
		if (segments[j][1] == 0)	{
			while ((i < m-1) && (points[i+1][0] == points[i][0])) {
				CALL(printf("A %d %d: %d %d\n", j, i, points[i+1][0], points[i][0]));
				dp[i+1][1] = dp[i][1];
				dp[i+1][2] = dp[i][2];
				i++;
				j++;
			}
			if (i >= m-1)	break;
			dp[i+1][1] = dp[i][1];
			i++;
		}
		else if ((segments[j][0] == points[i][0]) && (segments[j][1] == 1)) {
			dp[i][2]++;
			CALL(printf("B %d %d:\n", j, i));
		}
		dp[i][1] += segments[j][1];
		CALL(printf("C %d %d: %d %d\n", j, i, points[i][0], dp[i][1]));
	}
#if 0
	for (i=0; i<m-1; i++) {
		if (dp[i][0] == dp[i+1][0]) {
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2];
		}
	}
#endif
	//}

#if 0
	int *cnt = naive_count_segments(segments, n, points, m);
	for (int i = 0; i < m; i++) {
	  std::cout << cnt[i] << ' ';
	}
#endif
	PD();
#if 0
	fast_count_segments(segments, 0, n-1, points, 0, m-1);
#endif
	qsort((void *)dp, m, 2*sizeof(int), compare);
	for (int i = 0; i < m; i++) {
		std::cout << (-dp[i][1]) + dp[i][2] << ' ';
	}
	return 0;
}
