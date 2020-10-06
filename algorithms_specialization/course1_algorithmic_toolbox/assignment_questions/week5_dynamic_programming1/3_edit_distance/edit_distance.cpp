#include <iostream>
#include <string>

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

using std::string;
#define DUMMY 1000

unsigned int **dp = NULL;
int min(int x, int y) {
        if (x < y) return x;
        else return y;
}

int min3(int x, int y, int z) {
        return min(min(x,y), z);
}

void print_dp(int m, int n) {
	for(int i=0; i<m+1; i++) {
		for (int j=0; j<n+1; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int fill_mat(const char *str1, const char *str2) {
	int i=1, j=1;
	int l1 = strlen(str1), l2 = strlen(str2);
	for (i=1; i<l2+1; i++) {
		for (j=1; j<l1+1; j++) {
			
		}
	}
}

int ed(const char *str1, const char *str2) {
	//write your code here
	int cols = strlen(str1);
	int rows = strlen(str2); 
	PD();
	CALL(printf("%s %s\n", str1, str2));
	if (dp[rows][cols] != DUMMY) return dp[rows][cols];
	char tm_str1[cols];
	char tm_str2[rows]; 	
	memcpy(tm_str1, str1, cols); tm_str1[cols-1] = '\0';
	memcpy(tm_str2, str2, rows); tm_str2[rows-1] = '\0';
	if (str2[rows-1] == str1[cols-1]) {
		dp[rows][cols] = min3(ed(tm_str1, tm_str2), 1+ed(tm_str1, str2), 1+ed(str1, tm_str2));
	}
	else {
		dp[rows][cols] = 1 + min3(ed(tm_str1, tm_str2), ed(tm_str1, str2), ed(str1, tm_str2));
	}
	return dp[rows][cols];
}

int main() {
	char *str1 = (char *)malloc(110 * sizeof(char));
	if (str1 == NULL) return -1;
	char *str2 = (char *)malloc(110 * sizeof(char));
	if (str2 == NULL) {
		free(str1);
		return -2;
	}
	std::cin >> str1 >> str2;
	int cols, rows;
	int i=0, j=0;
	cols = strlen(str1);
	rows = strlen(str2);
	dp = (unsigned int **)calloc((rows+1), sizeof(int *));
	if (dp == NULL) {
		free(str1);
		free(str2);
		return -3;
	}
	for(i=0; i<rows+1; i++) {
		dp[i] = (unsigned int *)calloc((cols+1), sizeof(int));
		if (dp[i] == NULL)	{
			PLL(i);
			PD();
			return -4;
		}
		else { PLL(dp[i]);}
	}
	CALL(print_dp(rows, cols));

	//	Set dp start values
	for (i=0; i<cols+1; i++) {
		dp[0][i] = i;
	}
	for (i=0; i<rows+1; i++) {
		dp[i][0] = i;
	}

	for (i=1; i<rows+1; i++) {
		for (j=1; j<cols+1; j++) {
			PLL(dp[i][j]);
			dp[i][j] = DUMMY;
		}
	}
	CALL(print_dp(rows, cols));
	std::cout << ed(str1, str2) << std::endl;
	CALL(print_dp(rows, cols));
	return 0;
}
