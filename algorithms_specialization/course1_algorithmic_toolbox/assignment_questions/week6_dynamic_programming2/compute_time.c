#include "compute_time.h"

clock_t start, end;

void time_begin() {
	start = clock();
}

void time_end() {
	end = clock();
}

double time_taken() {
	time_end();
	return (double)(end - start)/CLOCKS_PER_SEC;
}

void print_time(double *time1, double *time2) {
	printf("OK %lf %lf\n", *time1, *time2);
}
