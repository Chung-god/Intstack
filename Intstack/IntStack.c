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


int main(void) {
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("fail to make stack.");
		return 1;
	}
	printf("Capacity is %d\n", Capacity(&s));

	while (1) {
		int menu, x;
		printf("Now data number : %d / %d\n",Size(&s),Capacity(&s));
		printf("1.Push 2.Pop 3.Peek 4.Print 5.Search 6.Clear 0.End :  ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1: 
			printf("Data is : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a Eroor : fail to push");
			break;
		case 2:

			if (Pop(&s, &x) == -1)
				puts("\a Error : fail to pop");
			else
				printf("Pop data is %d\n",x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("\a Error : fail to Peek");
			else
				printf("Peek data is %d\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("Data is : ");
			scanf_s("%d", &x);
			if (Search(&s, x) == -1)
				puts("\a Error : fail to search");
			else
				printf("Search data is array[%d]\n",Search(&s,x));
			break;
		case 6:
			printf("Clear");
			Clear(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}







