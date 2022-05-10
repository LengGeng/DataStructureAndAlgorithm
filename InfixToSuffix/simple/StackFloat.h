//
// Created by Sakura on 2022/5/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_STACKFLOAT_H
#define DATASTRUCTUREANDALGORITHM_STACKFLOAT_H

#endif //DATASTRUCTUREANDALGORITHM_STACKFLOAT_H

#include "stdbool.h"

typedef struct SFNode {
    float *data;  // 声明一个静态数组，用于堆栈
    int top;                    // 标志栈顶
    int maxSize;
} SFNode, StackFloat;

/**
 * 栈的初始化
 * @param maxSize 栈最大长度
 * @return 栈指针
 */
StackFloat *StackFloatInit(int maxSize);

/**
 * 压栈
 * @param stack 栈指针
 * @param item 数据项
 * @param index 用于存放索引值的指针
 * @return 是否压栈成功
 */
bool StackFloatPush(StackFloat *stack, float item, int *index);

/**
 * 弹栈
 * @param stack 栈指针
 * @param item 用于存放数据项的指针
 * @return 是否弹栈成功
 */
bool StackFloatPop(StackFloat *stack, float *item);

/**
 * 打印栈数据
 * @param stack 栈指针
 */
void StackFloatPrint(StackFloat *stack);