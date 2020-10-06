#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int find_value(int **wv, int n, int w) {
	int i=0;
	int j=0;
	int val = 0;
	int a[w+1][n+1];
	int b[n];
	for (i=0; i<n; i++)
		b[i] = 0;

	for (j=0; j<w+1; j++) {
		for (i=0; i<n+1; i++) {
			a[j][i] = 0;
		}
	}

	for (i=1; i<n+1; i++) {
		for (j=1; j<w+1; j++) {
			a[j][i] = a[j][i-1];
			if (wv[i-1][0] <= j) {
				val = a[j - wv[i-1][0]][i-1] + wv[i-1][1];
				a[j][i] = max(val, a[j][i]);
			}
		}	
	}

	for (j=0; j<w+1; j++) {
		for (i=0; i<n+1; i++) {
			printf("%5d ", a[j][i]);
		}
		printf("\n");
	}

	// backtrack
	int prev;
	int wt;
	int mx;
	int tw = w;
	for (i=n; i>0; i--) {
		prev = a[tw][i-1];
		wt = wv[i-1][0];
		mx = max(a[tw - wt][i-1] + wv[i-1][1], prev);
		if (prev != mx) {	
			b[i-1] = 1;
			tw -= wt;
		}
	}

	for (i=0; i<n; i++)
		printf("%d ", b[i]);
	printf("\n");

	return a[w][n];
}

int main(int argc, char **argv) {
	int w = atoi(argv[1]);
	int i = 0;
	int n;
	scanf("%d", &n);
	int **wv = (int **)calloc(n, sizeof(int *));
	for (i=0; i<n; i++)
		wv[i] = (int *)calloc(2, sizeof(int));
	for (i=0; i<n; i++) {
		scanf("%d %d", &wv[i][0], &wv[i][1]);
	}
	printf("%d\n", find_value(wv, n, w));
}
