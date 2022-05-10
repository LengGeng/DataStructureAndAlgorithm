//
// Created by Sakura on 2022/5/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_STACKCHAR_H
#define DATASTRUCTUREANDALGORITHM_STACKCHAR_H

#endif //DATASTRUCTUREANDALGORITHM_STACKCHAR_H

#include "stdbool.h"

typedef struct SCNode {
    char *data;  // 声明一个静态数组，用于堆栈
    int top;                    // 标志栈顶
    int maxSize;
} SCNode, StackChar;

/**
 * 栈的初始化
 * @param maxSize 栈最大长度
 * @return 栈指针
 */
StackChar *StackCharInit(int maxSize);

/**
 * 压栈
 * @param stack 栈指针
 * @param item 数据项
 * @param index 用于存放索引值的指针
 * @return 是否压栈成功
 */
bool StackCharPush(StackChar *stack, char item, int *index);

/**
 * 弹栈
 * @param stack 栈指针
 * @param item 用于存放数据项的指针
 * @return 是否弹栈成功
 */
bool StackCharPop(StackChar *stack, char *item);

/**
 * 打印栈数据
 * @param stack 栈指针
 */
void StackCharPrint(StackChar *stack);