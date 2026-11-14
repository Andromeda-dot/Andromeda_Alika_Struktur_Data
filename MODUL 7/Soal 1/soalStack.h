#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct stack {
    infotype info[20];
    int top;
};

bool isEmpty(stack S);
bool isFull(stack S);
void createStack(stack &S);
void push(stack &S, infotype X);
infotype pop(stack &S);
void printInfo(stack S);
void balikStack(stack &S);

#endif
