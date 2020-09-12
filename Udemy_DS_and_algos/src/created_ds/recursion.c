/*
 * recursion.c
 *
 *  Created on: Jul 12, 2020
 *      Author: vsiddhabhakt
 */

#include "recursion.h"

void print_int_reverse(int num) {
	if (num != 0) {
		printf("%d", num%10);
		print_int_reverse(num/10);
	}
}

void print_int_inorder(int num) {
	if (num != 0) {
		print_int_inorder(num/10);
		printf("%d", num%10);
	}
}

void print_string_reverse(char *str) {
	if (*str != '\0') {
		print_string_reverse(str + 1);
		printf("%c", *str);
	}
}

/*
 * Incomplete: To be developed. Interesting.
 */
void print_generic_reverse(void *data, int (*cond)(void *), void (*printer)(void *)){
	if (cond(data)) {
		printer(data);
	}
}
