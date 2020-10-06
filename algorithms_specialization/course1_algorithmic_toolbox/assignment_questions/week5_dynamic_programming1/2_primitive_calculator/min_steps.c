#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y) {
	if (x < y) return x;
	else return y;
}

int min3(int x, int y, int z) {
	return min(min(x,y), z);
}

int *dp;

int steps(int n) {
	if (dp[n] != -1) return dp[n];
	if (n % 6 == 0) {
		dp[n] = 1 + min3(steps(n/3), steps(n/2), steps(n-1));
	}
	else if (n % 3 == 0) {
		dp[n] = 1 + min(steps(n/3), steps(n-1));
	}
	else if (n % 2 == 0) {
		dp[n] = 1 + min(steps(n-1), steps(n/2));
	}
	else {
		dp[n] = 1 + steps(n-1);
	}
	return dp[n];
}

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	dp = (int *)malloc((n+1) * sizeof(int));
	if (dp == NULL)	return -1;
	for(int i=0; i<n+1; i++)	{
		dp[i] = -1;
	}
	dp[1] = 0; // we start at 1.
	steps(n);
	for(int i=0; i<n+1; i++)	{
		;//printf("DP[%d]: %d\n", i, dp[i]);
	}
	printf("n:%d %d\n", n, dp[n]);
	return 0;
}
