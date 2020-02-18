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
int Initialize(IntStack* s, int max);


/*push data into stack */
int Push(IntStack* s, int x);


/*pop data out stack*/
int Pop(IntStack* s, int* x);


/*peek data in stack*/
int Peek(const IntStack* s, int* x);


/*Clear stack*/
void Clear(IntStack *s);


/*stack's max capacity*/
int Capacity(const IntStack* s);


/*stack's data size*/
int Size(const IntStack* s);


/*Is empty this stack*/
int isEmpty(const IntStack* s);


/*Is full this stack*/
int isFull(const IntStack* s);


/*Search in stack*/
int Search(const IntStack* s, int x);


/*print all data*/
void Print(const IntStack* s);


/*stack end*/
void Terminate(IntStack* s);

#endif // !___IntStack