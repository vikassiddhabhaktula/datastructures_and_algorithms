/*
 * stack.c
 *
 *  Created on: Jul 10, 2020
 *      Author: vsiddhabhakt
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG

void create_stack(stack *s, int size) {
	s->base = malloc(size);
	if (NULL == s->base)	return;
	s->top = NULL;
	s->size = size;
}

int is_stack_empty(stack *s) {
	return (NULL == s->top);
}

int is_stack_full(stack *s) {
	return ((NULL != s->top) && (((unsigned long)s->top - (unsigned long)s->base) >= s->size));
}

int push(stack *s, void *data, int size) {
	if (is_stack_empty(s)) {
		s->top = s->base;
	}
	else {
		if (is_stack_full(s)) return -1;
		if (((unsigned long)s->top + size - (unsigned long)s->base) > s->size) return -2;
	}
	memcpy((char *)s->top, (char *)data, size);
	s->top = (char *)s->top + size;
	return 0;
}

int pop(stack *s, void *data, int size) {
	if (is_stack_empty(s)) return -1;
	if (((unsigned long)s->top - size) < (unsigned long)s->base) return -2;
	int i=0;
	char *ptr;
	s->top = (char *)s->top - size;
	memcpy((char *)data, (char *)s->top, size);
	// load the popped location with known garbage
	ptr = s->top;
	for (i=0; i<size; i++)
		*ptr++ = 0xFF;
	if (s->top == s->base)	s->top = NULL;
	return 0;
}

void print_stack(stack *s) {
#if defined(DEBUG)
	if (is_stack_empty(s))	{
		printf("STACK:\tstack empty\n");
		return;
	}
	int i=0;
	char *ptr = (char *)s->base;
	printf("STACK:\nTOP:\t%p\n", s->top);
	for (i=0; i<s->size; i+=sizeof(int)) {
		printf("%p:\t0x%x\n", ptr+i, *(unsigned int *)(char *)(ptr+i));
	}
#endif
}
