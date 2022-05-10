//
// Created by Sakura on 2022/5/8.
//
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "StackFloat.h"

StackFloat *StackFloatInit(int maxSize) {
    StackFloat *stack = (StackFloat *) malloc(sizeof(StackFloat));
    stack->top = -1;
    stack->maxSize = maxSize;
    stack->data = (float *) malloc(maxSize * sizeof(float));
    return stack;
}

bool StackFloatPush(StackFloat *stack, float item, int *index) {
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

bool StackFloatPop(StackFloat *stack, float *item) {
    // 栈空
    if (stack->top == -1) {
        return false;
    } else {
        *item = stack->data[stack->top--];
        return true;
    }
}

void StackFloatPrint(StackFloat *stack) {
    if (stack->top == -1) {
        printf("StackChar([], MAXSIZE=%d)\n", stack->maxSize);
    } else {
        printf("StackChar([");
        for (int i = 0; i < stack->top; i++) {
            printf("%f, ", stack->data[i]);
        }
        printf("%f], MAXSIZE=%d)\n", stack->data[stack->top], stack->maxSize);
    }
}