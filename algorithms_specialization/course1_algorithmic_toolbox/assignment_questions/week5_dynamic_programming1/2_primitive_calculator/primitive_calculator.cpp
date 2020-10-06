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

int *dp = NULL;
int *bt = NULL;
#define COM(x) ((dp[x] == -1) ? steps(x) : dp[x])

int steps(int n) {
	if (dp[n] != -1) return dp[n];
	if (n % 6 == 0) {
		dp[n] = 1 + min3(COM(n/3), COM(n/2), COM(n-1));
	}
	else if (n % 3 == 0) {
		dp[n] = 1 + min(COM(n/3), COM(n-1));
	}
	else if (n % 2 == 0) {
		dp[n] = 1 + min(COM(n-1), COM(n/2));
	}
	else {
		dp[n] = 1 + COM(n-1);
	}
	return dp[n];
}

void backtrack(int n) {
	static int i=dp[n]-1;
	if (n == 1) {
		return;
	}
	int m;
	bt[i--] = n;
	if (n % 6 == 0) {
		m = min3(dp[n-1], dp[n/2], dp[n/3]);
		if (m == dp[n/3])
			backtrack(n/3);
		else if (m == dp[n/2])
			backtrack(n/2);
		else 
			backtrack(n-1);
	}
	else if (n % 3 == 0) {
		m = min(dp[n-1], dp[n/3]);
		if (m == dp[n/3])
			backtrack(n/3);
		else
			backtrack(n-1);
	}
	else if (n % 2 == 0) {
		m = min(dp[n-1], dp[n/2]);
		if (m == dp[n/2])
			backtrack(n/2);
		else
			backtrack(n-1);
	}
	else {
		backtrack(n-1);
	}
}

int main(int argc, char **argv) {
	int n;
	int i=0;
	scanf("%d", &n);
	dp = (int *)malloc((n+1) * sizeof(int));
	if (dp == NULL)	return -1;
	for(i=0; i<n+1; i++)	{
		dp[i] = -1;
	}
	dp[1] = 0; // we start at 1.
//	printf("Yo\n");
	steps(n);
	printf("%d\n", dp[n]);
	bt = (int *)calloc(dp[n], sizeof(int));
	if (bt == NULL)	return -1;
//	printf("YoYo\n");
	backtrack(n);
	printf("1 ");
	for(i=0; i<dp[n]; i++)
		printf("%d ", bt[i]);
	printf("\n");
	return 0;
}
