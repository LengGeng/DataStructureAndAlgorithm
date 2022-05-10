//
// Created by Sakura on 2022/5/9.
//

#ifndef DATASTRUCTUREANDALGORITHM_STACK_H
#define DATASTRUCTUREANDALGORITHM_STACK_H

#endif //DATASTRUCTUREANDALGORITHM_STACK_H

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

enum StackType {
    SHORT, INT, LONG, FLOAT, DOUBLE, CHAR, STRING
};

static char *StackTypeName[] = {"SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "CHAR", "STRING"};
static int StackTypeSize[] = {
        sizeof(short),
        sizeof(int),
        sizeof(long),
        sizeof(float),
        sizeof(double),
        sizeof(char),
        sizeof(char *)
};

typedef struct {
    int top;
    int maxSize;
    enum StackType type;
    void **data;
} Stack;

/**
 * 栈的初始化
 * @param stack 栈指针
 * @param type 栈中存放的数据类型
 * @param maxSize 栈最大长度
 */
Stack *StackInit(enum StackType type, int maxSize);

/**
 * 创建数据的拷贝
 * @param data 数据指针
 * @param type 数据类型
 * @return 新数据指针
 */
void *createItem(void *data, enum StackType type);

/**
 * 打印数据
 * @param item 数据指针
 * @param type 数据类型
 */
void PrintItem(void *item, enum StackType type);

/**
 * 压栈
 * @param stack 栈指针
 * @param item 数据项指针
 * @param index 用于存放索引值的指针
 * @return 是否压栈成功
 */
bool StackPush(Stack *stack, void *item, int *index);

/**
 * 弹栈
 * @param stack 栈指针
 * @param item 存放数据项的指针
 * @return 是否弹栈成功
 */
bool StackPop(Stack *stack, void *item);

/**
 * 打印栈数据
 * @param stack 栈指针
 */
void StackPrint(Stack *stack);
