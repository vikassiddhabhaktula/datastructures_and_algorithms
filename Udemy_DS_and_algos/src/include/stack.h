/*
 * stack.h
 *
 *  Created on: Jul 10, 2020
 *      Author: vsiddhabhakt
 */

#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack_t {
	void *base;
	int size;
	void *top;
}stack;

void create_stack(stack *s, int size);
int is_stack_empty(stack *s);
int is_stack_full(stack *s);
int push(stack *s, void *data, int size);
int pop(stack *s, void *data, int size);
// Debug functions
void print_stack(stack *s);

#endif /* INCLUDE_STACK_H_ */
