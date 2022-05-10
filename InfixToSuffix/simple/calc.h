//
// Created by Sakura on 2022/5/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_CALC_H
#define DATASTRUCTUREANDALGORITHM_CALC_H

#endif //DATASTRUCTUREANDALGORITHM_CALC_H

#include "stdbool.h"

/**
 * 将 0-9 的字符转换成对应数字
 * @param c 数字字符
 * @param num 存放结果的指针
 * @return 是否转换成功
 */
bool char2float(char c, float *num);

/**
 * 中缀表达式转后缀表达式
 * @param infix_str 中缀表达式字符串的指针
 * @param suffix_str 存放后缀表达式字符串的指针
 */
void InfixToSuffix(char *infix_str, char *suffix_str);

/**
 * 计算后缀表达式的结果
 * @param suffix_str 后缀表达式字符串的指针
 * @param result 存放结果指针
 */
void computedSuffix(char *suffix_str, float *result);