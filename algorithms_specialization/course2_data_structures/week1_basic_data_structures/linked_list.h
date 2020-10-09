#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll {
	void *data;
	struct ll *next;
	struct ll *prev;
}ll_t;

int is_list_empty(struct ll *head);
int push_front(struct ll *head, struct ll *tail, void *el, int size);
int push_back(ll_t *head, ll_t *tail, void *el, int size);
int pop_front(struct ll *head, struct ll *tail, void *el, int size);
int pop_back(ll_t *head, ll_t *tail, void *el, int size);


#endif
