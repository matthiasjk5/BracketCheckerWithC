#include <stdio.h>
#include <stdbool.h>
#include "charStack.h"

typedef struct {
    int top;          // Top of stack
    char ST[MAXSTACK]; // Array containing stack data
} Stack;

static Stack S;  // Variable S has source-file scope 

// Initialize an empty stack
void initStack(void) {
    S.top = -1;
}

// Check if the stack is empty, returns true if the stack is empty.
bool isEmpty(void) {
    return (S.top == -1);
}

// Push a character 'ch' on the stack.
void push(char ch) {
    if (S.top == MAXSTACK - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } else {
        ++S.top;            // Update top index
        S.ST[S.top] = ch;  // Put 'num' on the stack
    }
} 

// Pop a character off the stack, returning the character obtained.
// If ROGUEVALUE is returned this indicates an error (empty stack).
char pop(void) {
    if (isEmpty()) {
        return ROGUEVALUE; // Special value indicates error
    } else {
        char result = S.ST[S.top];  // Get item
        --S.top;           // Update top index
        return result;     // Return item
    }
} 

