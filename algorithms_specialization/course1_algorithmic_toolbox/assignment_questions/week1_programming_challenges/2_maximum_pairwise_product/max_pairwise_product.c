#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define TEST
//#define TIME

#ifdef TIME
	double worst_time;
	double best_time;
#endif

long long max_pairwise_product(const int *numbers, int size) {
#ifdef TIME
	clock_t begin = clock(), end;
#endif
    long long max_product = 0;
    long long product = 0;
    int n = size;

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            product = ((long long)numbers[first]) * numbers[second];
			if (product > max_product) max_product = product;
        }
    }
#ifdef TIME
	end = clock();
	worst_time = (double)(end - begin)/CLOCKS_PER_SEC;
#endif
    return max_product;
}

long long max_pairwise_product_fast(const int *numbers, int size) {
#ifdef TIME
	clock_t begin = clock(), end;
#endif
	int index1 = -1, index2 = -1;
	int max = 0;
	int el=0;
	int n = size;
	for (el = 0; el < n; ++el) {
		if (numbers[el] > max) {
			max = numbers[el];
			index1 = el;
		}
	}
	max = 0;
	for (el = 0; el < n; ++el) {
		if ((el != index1) && (numbers[el] > max)) {
			max = numbers[el];
			index2 = el;
		}
	}
#ifdef TIME
	end = clock();
	best_time = (double)(end - begin)/CLOCKS_PER_SEC;
#endif

	return ((long long)numbers[index1] * numbers[index2]);
}

#ifdef TEST_2
void printer(const int *numbers, int n) {
	printf("%d\n", n);
	for(int i=0; i<n; ++i) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
#else
void printer(const int *numbers, int n) {}
#endif

int main(int argc, char **argv) {
    int n;
    int *numbers;
#ifdef TEST
	while(1) {
		long long correct, result;
		n = rand() % 90000;
		numbers = malloc(n * sizeof(int));
		if (NULL == numbers) {
			printf("Not enough memory: %ld bytes\n", n * sizeof(int));
			break;
		}
		for (int i=0; i<n; ++i) {
			numbers[i] = rand() % 10000;
		}
		printer(numbers, n);
		correct = max_pairwise_product(numbers, n);
		result = max_pairwise_product_fast(numbers, n);
		if (correct == result) {
			printf("OK");
			#ifdef TIME
				printf(" %lf %lf", worst_time, best_time);
			#endif
			printf("\n");
		}
		else {
			printf("NOT OKAY: %lld %lld\n", correct, result);
			free(numbers);
			break;
		}
		free(numbers);
	}
#endif
    scanf("%d", &n);
	numbers = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    printf("%lld\n", max_pairwise_product_fast(numbers, n));
    return 0;
}
