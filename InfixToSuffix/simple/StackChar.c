//
// Created by Sakura on 2022/5/8.
//
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "StackChar.h"

StackChar *StackCharInit(int maxSize) {
    StackChar *stack = (StackChar *) malloc(sizeof(StackChar));
    stack->top = -1;
    stack->maxSize = maxSize;
    stack->data = (char *) malloc(maxSize * sizeof(char));
    return stack;
}

bool StackCharPush(StackChar *stack, char item, int *index) {
    // 栈满
    if (stack->top == stack->maxSize - 1) {
        printf("堆栈满了");
        return false;
    } else {
        stack->data[++stack->top] = item;
        *index = stack->top;
        return true;
    }
}

bool StackCharPop(StackChar *stack, char *item) {
    // 栈空
    if (stack->top == -1) {
        return false;
    } else {
        *item = stack->data[stack->top--];
        return true;
    }
}

void StackCharPrint(StackChar *stack) {
    if (stack->top == -1) {
        printf("StackChar([], MAXSIZE=%d)\n", stack->maxSize);
    } else {
        printf("StackChar([");
        for (int i = 0; i < stack->top; i++) {
            printf("%c, ", stack->data[i]);
        }
        printf("%c], MAXSIZE=%d)\n", stack->data[stack->top], stack->maxSize);
    }
}