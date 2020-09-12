/*
 ============================================================================
 Name        : code.c
 Author      : Vikas Siddhabhaktula
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "recursion.h"
#include "cosmetics.h"


int main(void) {
	/*
	 * 	HELLO WORLD
	 */
	print_header("HELLO WORLD");
	printf("Hello World!\n");

	/*
	 * 	GENERIC STACK
	 */
	print_header("GENERIC STACK");
	stack s = {NULL, 0, NULL};
	int a = 10, b = 20;
	printf("A:%d B:%d\n", a, b);
	create_stack(&s, 12);
	printf("push status: %d\n", push(&s, &a, sizeof(int)));
	print_stack(&s);
	printf("push status: %d\n", push(&s, &b, sizeof(int)));
	print_stack(&s);
	printf("stack_empty: %d\n", is_stack_empty(&s));
	printf("pop status: %d\n", pop(&s, &a, sizeof(int)));
	print_stack(&s);
	printf("pop status: %d\n", pop(&s, &b, sizeof(int)));
	print_stack(&s);
	printf("A:%d B:%d\n", a, b);
	/*	Strings on stack	 */
	create_stack(&s, 30);
	char *dst = (char *)malloc(20);
	char *first = "VIKAS";
	char *last = "SIDDHABHAKTULA";
	printf("push status: %d\n", push(&s, first, strlen(first) + 1));
	printf("push status: %d\n", push(&s, last, strlen(last) + 1));
	printf("pop status: %d\n", pop(&s, dst, strlen(last) + 1));
	printf("%s\n", dst);
	print_stack(&s);
	printf("pop status: %d\n", pop(&s, dst, strlen(first) + 1));
	printf("%s\n", dst);
	print_stack(&s);
	free(dst);

	/*
	 * 	RECURSION
	 */
	print_header("RECURSION");
	print_int_reverse(256); printf("\n");
	print_int_inorder(100); printf("\n");
	print_int_reverse(2); printf("\n");
	print_int_reverse(0); printf("\n");		//	Incorrect output
	print_int_reverse(-256); printf("\n");	//	Incorrect output
	print_int_reverse(2000); printf("\n");
	print_string_reverse("vikas"); printf("\n");
	print_string_reverse(""); printf("\n");
	print_string_reverse("abcdefghijklmnopqrstuvwxyz"); printf("\n");

	return 0;
}
