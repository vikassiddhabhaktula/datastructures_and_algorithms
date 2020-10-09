#include "linked_list.h"

int is_list_empty(struct ll *head) {
	return (head == NULL);
}

int push_front(struct ll *head, struct ll *tail, void *el, int size) {
	struct ll *node = (struct ll *)calloc(1, sizeof(struct ll));
	if (NULL == node)	return -1;
	node->data = malloc(size);
	if (NULL == node->data)	return -2;
	memcpy(node->data, el, size);
	if (head == NULL)	{
		head = tail = node;
		node->prev = NULL;
		node->next = NULL;
	}		
	else {
		node->prev = NULL;
		node->next = head;
		head->prev = node;
		head = node;
	}
	return 0;
}

int push_back(ll_t *head, ll_t *tail, void *el, int size) {
    struct ll *node = (struct ll *)calloc(1, sizeof(struct ll));
    if (NULL == node)   return -1;
    node->data = malloc(size);
    if (NULL == node->data) return -2;
    memcpy(node->data, el, size);
	if (head == NULL) {
		head = tail = node;
        node->prev = NULL;
        node->next = NULL;
	}
	else {
		node->prev = tail;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	return 0;
}

int pop_front(struct ll *head, struct ll *tail, void *el, int size) {
	if (is_list_empty(head)) return -1;
	memcpy(el, head->data, size);
	free(head->data);
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		head = head->next;
		free(head->prev);
		head->prev = NULL;	
	}
	return 0;
}

int pop_back(ll_t *head, ll_t *tail, void *el, int size) {
	if (is_list_empty(head)) return -1;
    memcpy(el, tail->data, size);
    free(tail->data);
    if (head == tail) {
        free(head);
        head = tail = NULL;
    }
	else {
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
	return 0;
}


