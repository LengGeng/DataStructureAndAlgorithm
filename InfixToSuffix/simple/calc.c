//
// Created by Sakura on 2022/5/8.
//

#include "stdio.h"
#include "ctype.h"

#include "calc.h"
#include "StackChar.h"
#include "StackFloat.h"

bool char2float(char c, float *num) {
    if (c < 48 || c > 57) {
        return false;
    } else {
        *num = (float) c - 48;
        return true;
    }
}

void InfixToSuffix(char *infix_str, char *suffix_str) {
    if (infix_str == NULL) return;
    StackChar *stack = StackCharInit(12);
    char token;
    // 遍历 infix_str 字符串
    int i;
    int infix_index = 0;
    int suffix_index = 0;
    while (infix_str[infix_index] != '\0') {
        // 跳过空格
        if (infix_str[infix_index] == ' ') {
            infix_index++;
            continue;
        }
        // 数字的情况
        if (isdigit(infix_str[infix_index])) {
            // 数字直接添加
            suffix_str[suffix_index++] = infix_str[infix_index];
            // 左括号的情况
        } else if (infix_str[infix_index] == '(') {
            StackCharPush(stack, infix_str[infix_index], &i);
            // 右括号的情况
        } else if (infix_str[infix_index] == ')') {
            while (true) {
                i = StackCharPop(stack, &token);
                if (!i || token == '(') {
                    break;
                }
                suffix_str[suffix_index++] = token;
            }
            // + - 符号的情况
        } else if (infix_str[infix_index] == '+' || infix_str[infix_index] == '-') {
            while (true) {
                i = StackCharPop(stack, &token);
                if (i && (token == '*' || token == '/')) {
                    suffix_str[suffix_index++] = token;
                } else {
                    break;
                }
            }
            // 如果弹出了值就再压回去
            if (i) {
                StackCharPush(stack, token, &i);
            }
            StackCharPush(stack, infix_str[infix_index], &i);
            // * / 符号的情况
        } else if (infix_str[infix_index] == '*' || infix_str[infix_index] == '/') {
            StackCharPush(stack, infix_str[infix_index], &i);
            // 非法字符
        } else {
            printf("Infix String is Error\n");
            return;
        }
        infix_index++;
    }
    // 弹出栈内剩余
    while (true) {
        i = StackCharPop(stack, &token);
        if (!i) {
            break;
        }
        suffix_str[suffix_index++] = token;
    }
    suffix_str[suffix_index] = '\0';
}

void computedSuffix(char *suffix_str, float *result) {
    StackFloat *stack = StackFloatInit(20);
    float num, a, b;
    int i, suffix_index = 0;
    while (suffix_str[suffix_index] != '\0') {
        // 跳过空格
        if (suffix_str[suffix_index] == ' ') {
            suffix_index++;
            continue;
        }
        // 数字添加到栈
        if (isdigit(suffix_str[suffix_index])) {
            // 转换Float
            char2float(suffix_str[suffix_index], &num);
            // 将值添加到栈
            StackFloatPush(stack, num, &i);
            // +-*/ 弹栈计算
        } else if (suffix_str[suffix_index] == '+' || suffix_str[suffix_index] == '-' ||
                   suffix_str[suffix_index] == '*' || suffix_str[suffix_index] == '/') {
            // 取栈顶两个值
            StackFloatPop(stack, &a);
            StackFloatPop(stack, &b);
            // 计算
            switch (suffix_str[suffix_index]) {
                case '+':
                    *result = a + b;
                    break;
                case '-':
                    *result = a - b;
                    break;
                case '*':
                    *result = a * b;
                    break;
                case '/':
                    *result = a / b;
                    break;
            }
            // 将结果再入栈
            StackFloatPush(stack, *result, &i);
            // 忽略括号
        } else if (suffix_str[suffix_index] == '(' || suffix_str[suffix_index] == ')') {
            // 非法字符
        } else {
            printf("非法字符!");
            return;
        }
        suffix_index++;
    }
    StackFloatPop(stack, result);
}
