#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *dp = NULL;
int wv[4][2] = {{6, 30},
				{4, 16},
				{3, 14},
				{2, 9}};

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

#define MIN -100
#define C6(n) ((n >= 0) ? (30 + find_value(n)) : MIN)
#define C4(n) ((n >= 0) ? (16 + find_value(n)) : MIN)
#define C3(n) ((n >= 0) ? (14 + find_value(n)) : MIN)
#define C2(n) ((n >= 0) ? (9 + find_value(n)) : MIN)

int find_value(int n) {
	if (n < 0)	return MIN;
	if (dp[n] != -1)	return dp[n];
	dp[n] = max(max(C6(n-6), C4(n-4)), max(C3(n-3), C2(n-2)));
	return dp[n];	
}

int main(int argc, char **argv) {
	int tw = atoi(argv[1]);
	int i = 0;
	dp = (int *)calloc(tw+1, sizeof(int));
	for (i=2; i<tw+1; i++) {
		dp[i] = -1;
	}
	printf("%d\n", find_value(tw));
}
