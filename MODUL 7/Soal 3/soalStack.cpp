#include <iostream>
#include "soalStack.h"
using namespace std;

void createStack(stack &S) {
    S.top = -1;
}

bool isEmpty(stack S) {
    return S.top == -1;
}

bool isFull(stack S) {
    return S.top == 19;
}

void push(stack &S, infotype X) {
    if (S.top < 19) {
        S.top = S.top + 1;
        S.info[S.top] = X;
    }
}

infotype pop(stack &S) {
    infotype x = -1;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong." << endl;
    }
    return x;
}

void printInfo(stack S) {
    if (S.top >= 0) {
        for (int i = S.top; i >= 0; i--) {
            if (i == S.top) {
                cout << "[TOP] " << S.info[i] << endl;
            } else {
                cout << "      " << S.info[i] << endl;
            }
        }
    } else {
        cout << "Stack kosong." << endl;
    }
}

void pushAscending(stack &S, infotype X) {
    stack tempStack;
    createStack(tempStack);

    while (!isEmpty(S) && S.info[S.top] > X) {
        push(tempStack, pop(S));
    }

    push(S, X);

    while (!isEmpty(tempStack)) {
        push(S, pop(tempStack));
    }
}

void balikStack(stack &S) {
    stack tempStack;
    createStack(tempStack);

    while (S.top >= 0) {
        infotype X;
        X = pop(S);
        push(tempStack, X);
    }

    S = tempStack;
}

void getInputStream(stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        infotype X = c - '0';
        push(S, X);
    }
}