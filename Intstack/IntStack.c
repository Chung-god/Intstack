/*IntStack (Source)*/
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max) {
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;/*fail to make array*/
		return -1;
	}
	s->max = max;
	return 0;
}

int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)/*stack is full*/
		return -1;
	s->stk[s->ptr++] = x; 
	return 0;
}

int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0) /*stack is empty*/
		return -1;
	*x = s->stk[--s->ptr];
	return 0;
}

int Peek(const IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];/*ptr point doesn't change*/
	return 0;
}

void Clear(IntStack* s) {
	s->ptr = 0;
}

int Capacity(const IntStack* s) {
	return s->max;
}

int Size(const IntStack* s) {
	return s->ptr;
}

int isEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

int isFull(const IntStack* s) {
	return s->ptr >= s->max;
}

int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--)/*top -> bottom linear search*/
		if (s->stk[i] == x)
			return i;
	return -1;
}

void Print(const IntStack* s) {
	int i = 0;
	for (i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);/*bottom -> top*/
	putchar('\n');
}

void Terminate(IntStack* s) {
	if (s->stk != NULL) free(s->stk);
	s->max = s->ptr = 0;
}

