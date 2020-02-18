#pragma once
/*IntStack(header)*/
#ifndef ___IntStack
#define ___IntStack



/*stack structure*/
typedef struct {
	int max;
	int ptr; /*stack pointer*/
	int* stk; /*pointer about stack's first data */
}IntStack;


/*Initialize stack*/
int Initialize(IntStack* s1,IntStack *s2, int max);


/*push data into stack */
int Push(IntStack* s1, IntStack *s2, int x);


/*pop data out stack*/
int Pop(IntStack* s1, IntStack *s2, int* x);


/*peek data in stack*/
int Peek(const IntStack* s1, IntStack *s2, int* x);


/*Clear stack*/
void Clear(IntStack * s1, IntStack *s2);


/*stack's max capacity*/
int Capacity(const IntStack* s1, IntStack *s2);


/*stack's data size*/
int Size(const IntStack* s);


/*Is empty this stack*/
int isEmpty(const IntStack* s);


/*Is full this stack*/
int isFull(const IntStack* s);


/*Search in stack*/
int Search(const IntStack* s1, IntStack *s2, int x);


/*print all data*/
void Print(const IntStack* s1, IntStack *s2);


/*stack end*/
void Terminate(IntStack* s1, IntStack *s2);

#endif // !___IntStack