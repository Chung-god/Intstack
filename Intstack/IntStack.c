/*IntStack (Source)*/
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack* s1, IntStack *s2, int max) {
	s1->ptr = 0;
	s2->ptr = max;
	if ((s1->stk = calloc(max, sizeof(int))) == NULL) {
		s1->max = 0;/*fail to make array*/
		return -1;
	}
	s2->stk = s1->stk +max;
	s1->max = max/2;
	s2->max = max/2;
	return 0;
}

int Push(IntStack* s1,IntStack* s2, int x) {
	int choice;
	do {
		printf("Choose stack 1 or 2 : ");
		scanf_s("%d", &choice);
	} while (choice != 1 && choice != 2);
	
	if (choice == 1) {
		if (s1->ptr >= s1->max)/*stack is full*/
			return -1;
		s1->stk[s1->ptr++] = x;
		return 0;
	}
	else {
		if (s2->ptr <= s2->max)/*stack is full*/
			return -1;
		s2->stk[s2->ptr--] = x;
		return 0;
	}
	
}


int Pop(IntStack* s1,IntStack* s2, int* x) {
	int choice;
	do {
		printf("Choose stack 1 or 2 : ");
		scanf_s("%d", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 1) {
		if (s1->ptr <= 0) /*stack is empty*/
			return -1;
		*x = s1->stk[--s1->ptr];
		return 0;
	}
	else {
		if (s2->ptr >= ((s2->max) *2)) /*stack is empty*/
			return -1;
		*x = s2->stk[++s2->ptr];
		return 0;
	}
	
}



int Peek(const IntStack* s1,const IntStack* s2, int* x) {
	int choice;
	do {
		printf("Choose stack 1 or 2 : ");
		scanf_s("%d", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 1) {
		if (s1->ptr <= 0)
			return -1;
		*x = s1->stk[s1->ptr - 1];/*ptr point doesn't change*/
		return 0;
	}
	else {
		if (s2->ptr >= ((s2->max)*2))
			return -1;
		*x = s2->stk[s2->ptr + 1];/*ptr point doesn't change*/
		return 0;
	}
}

void Clear(IntStack* s1,IntStack* s2) {

	int choice;
	do {
		printf("Choose stack 1 or 2 : ");
		scanf_s("%d", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 1) {
		s1->ptr = 0;
	}
	else {
		s2->ptr = (s2->max) * 2;
	}

}

int Capacity1(const IntStack* s1) {
	return s1->max;
}
int Capacity2(const IntStack* s2) {
	return (s2->max) * 2;
}

int Size1(const IntStack* s) {
		return s->ptr;
}
int Size2(const IntStack* s) {
	return s->ptr;
}

int isEmpty1(const IntStack* s) {
	return s->ptr <= 0;
}

int isEmpty2(const IntStack* s) {
	return s->ptr >= (s->max)*2;
}

int isFull1(const IntStack* s) {
	return s->ptr >= s->max;
}
int isFull2(const IntStack* s) {
	return s->ptr <= s->max;
}

int Search(const IntStack* s1,const IntStack* s2, int x) {
	int choice;
	do {
		printf("Choose stack 1 or 2 : ");
		scanf_s("%d", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 1) {
		int i;
		for (i = s1->ptr - 1; i >= 0; i--)/*top -> bottom linear search*/
			if (s1->stk[i] == x)
				return i;
	}
	else {
		int j;
		for (j = s2->ptr + 1; j <= ((s2->max)*2); j++)/*top -> bottom linear search*/
			if (s2->stk[j] == x)
				return j;
	}
	
	return -1;
}

void Print(const IntStack* s1,const IntStack * s2) {
	int i = 0;
	printf("s1 :");
	for (i = 0; i < s1->ptr; i++)
		printf("%d ", s1->stk[i]);/*bottom -> top*/
	putchar('\n');
	int j;
	printf("s2 : ");
	for (j = (s2->max) * 2; j > s2->ptr; j--)
		printf("%d ", s2->stk[j]);
	putchar('\n');
}

void Terminate(IntStack* s1, IntStack* s2) {
	if (s1->stk != NULL) free(s1->stk);
	s1->max = s1->ptr = 0;
	s2->max = s2->ptr = 0;
}

int main(void) {
	IntStack s1;
	IntStack s2;

	if (Initialize(&s1, &s2, 64) == -1) {
		puts("fail to make stack.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("Now data number First : %d / %d\n",Size1(&s1),Capacity1(&s1));
		printf("Now data number Second : %d / %d\n", Size2(&s2), Capacity2(&s2));
		printf("1.Push 2.Pop 3.Peek 4.Print 5.Search 6.Clear 0.End :  ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1: 
			printf("Data is : ");
			scanf_s("%d", &x);
			if (Push(&s1,&s2, x) == -1)
				puts("\a Eroor : fail to push");
			break;
		case 2:

			if (Pop(&s1,&s2, &x) == -1)
				puts("\a Error : fail to pop");
			else
				printf("Pop data is %d\n",x);
			break;
		case 3:
			if (Peek(&s1, &s2, &x) == -1)
				puts("\a Error : fail to Peek");
			else
				printf("Peek data is %d\n", x);
			break;
		case 4:
			Print(&s1, &s2);
			break;
		case 5:
			printf("Data is : ");
			scanf_s("%d", &x);
			int result= Search(&s1, &s2, x);
			if ( result == -1)
				puts("\a Error : fail to search");
			else
				printf("Search data is array[%d]\n",result);
			break;
		case 6:
			printf("Clear");
			Clear(&s1, &s2);
			break;
		}
	}
	Terminate(&s1, &s2);
	return 0;
}







