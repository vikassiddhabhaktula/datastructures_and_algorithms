/*
 * recursion.h
 *
 *  Created on: Jul 12, 2020
 *      Author: vsiddhabhakt
 */

#ifndef INCLUDE_RECURSION_H_
#define INCLUDE_RECURSION_H_

#include <stdio.h>

void print_int_reverse(int num);
void print_string_reverse(char *str);
void print_generic_reverse(void *data, int (*cond)(void *), void (*printer)(void *));

#endif /* INCLUDE_RECURSION_H_ */
