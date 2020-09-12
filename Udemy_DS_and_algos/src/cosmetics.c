/*
 * cosmetics.c
 *
 *  Created on: Aug 4, 2020
 *      Author: vsiddhabhakt
 */

#include "cosmetics.h"

void print_header(const char *str) {
	int len = strlen(str);
	int loop = 0;
	/*
	 * Print in a particular format.
	 */
	printf("\n");
	for (loop=0; loop<2*len; loop++)
		printf("=");
	printf("\n");
	for (loop=0; loop<len/2; loop++)
			printf(" ");
	printf("%s\n", str);
	for (loop=0; loop<2*len; loop++)
			printf("=");
	printf("\n");
}
