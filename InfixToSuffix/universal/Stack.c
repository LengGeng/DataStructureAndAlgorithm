//
// Created by Sakura on 2022/5/9.
//

#include "stdlib.h"

#include "Stack.h"

Stack *StackInit(enum StackType type, int maxSize) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    stack->type = type;
    stack->maxSize = maxSize;
    stack->data = (void **) malloc(maxSize * sizeof(char *));
    return stack;
}

void *createItem(void *data, enum StackType type) {
    // 计算元素的大小
    int typeSize;
    if (type == STRING) {
        // 需要多一个存储尾缀
        typeSize = (int) strlen((char *) data) + 1;
    } else {
        typeSize = StackTypeSize[type];
    }
    // printf("typeSize:%d\n", typeSize);
    // 创建一个同样大小的内存存储数据
    void *item = malloc(typeSize);
    // 字符串尾缀
    if (type == STRING) {
        char *s = item;
        s[typeSize - 1] = '\0';
    }
    // 数据拷贝
    memcpy(item, data, typeSize);
    return item;
}

void PrintItem(void *item, enum StackType type) {
    switch (type) {
        case SHORT:
            printf("%d", *(short *) item);
            break;
        case INT: {
            printf("%d", *(int *) item);
        }
            break;
        case LONG:
            printf("%d", *(long *) item);
            break;
        case FLOAT:
            printf("%f", *(float *) item);
            break;
        case DOUBLE:
            printf("%f", *(double *) item);
            break;
        case CHAR:
            printf("'%c'", *(char *) item);
            break;
        case STRING:
            printf("\"%s\"", (char *) item);
            break;
        default:
            break;
    }
}

bool StackPush(Stack *stack, void *item, int *index) {
    // 栈满
    if (stack->top == stack->maxSize - 1) {
        printf("堆栈满了");
        return false;
    } else {
        stack->data[++stack->top] = createItem(item, stack->type);
        *index = stack->top;
        return true;
    }
}

bool StackPop(Stack *stack, void *item) {
    // 栈空
    if (stack->top == -1) {
        return false;
    } else {
        // 将数据复制到给定的地址
        void *data = stack->data[stack->top--];
        if (stack->type == STRING) {
            memcpy(item, data, strlen(data) + 1);
            // printf("info:StackPop str_item is: %s\n", (char *) item);
        } else {
            memcpy(item, data, StackTypeSize[stack->type]);
            // printf("info:StackPop item is: ");
            // PrintItem(data, stack->type);
            // printf("\n");
        }
        return true;
    }
}

void StackPrint(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack([], MAXSIZE=%d, type=%s)\n", stack->maxSize, StackTypeName[stack->type]);
    } else {
        printf("Stack([");
        for (int i = 0; i < stack->top; i++) {
            PrintItem(stack->data[i], stack->type);
            printf(", ");
//            printf("%c, ", stack->data[i]);
        }
        PrintItem(stack->data[stack->top], stack->type);
        printf("], MAXSIZE=%d, type=%s)\n", stack->maxSize, StackTypeName[stack->type]);
    }
}