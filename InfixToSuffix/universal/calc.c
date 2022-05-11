//
// Created by Sakura on 2022/5/10.
//

#include "calc.h"
#include "ctype.h"
#include "stdlib.h"

#include "Stack.h"


void InfixToSuffix(const char *infix_str, char *suffix_str) {
    if (infix_str == NULL || suffix_str == NULL) return;
    Stack *stack = StackInit(CHAR, 16);
    char c;
    bool flag;
    int infix_index = 0, suffix_index = 0, stack_index;
    char token = infix_str[infix_index];
    // 遍历 infix_str 字符串
    while (token != '\0') {
        // 跳过空格
        if (token == ' ') {
            token = infix_str[++infix_index];
            continue;
        }
        // 读取数字
        if (isdigit(token)) {
            // 添加 `.` 判断支持小数
            while (isdigit(token) || token == '.') {
                // 当前字符添加到末尾
                suffix_str[suffix_index++] = token;
                // 后移
                token = infix_str[++infix_index];
            }
            // 数字后添加一个空格用于与其它数字分割
            suffix_str[suffix_index++] = ' ';
            // 回移
            infix_index--;
            // +-*/()
        } else {
            if (token == '(') {
                StackPush(stack, &token, &stack_index);
                // 右括号的情况
            } else if (token == ')') {
                while (true) {
                    // TODO 栈空未见到(应该是式子错误
                    flag = StackPop(stack, &c);
                    if (!flag || c == '(') {
                        break;
                    }
                    suffix_str[suffix_index++] = c;
                }
                // + - 符号的情况
            } else if (token == '+' || token == '-') {
                // 反复弹出栈顶操作符添加到后缀末尾, 直到栈顶的操作符优先级低于它。
                while (true) {
                    flag = StackPop(stack, &c);
                    // 只有 `(` 的优先级比 `+-` 低, 即不为 `（` 就一直添加到后缀末尾
                    if (flag && c != '(') {
                        suffix_str[suffix_index++] = c;
                    } else {
                        break;
                    }
                }
                // 如果弹出了值就再压回去
                if (flag) {
                    StackPush(stack, &c, &stack_index);
                }
                StackPush(stack, &token, &stack_index);
                // * / 符号的情况
            } else if (token == '*' || token == '/') {
                // 反复弹出栈顶操作符添加到后缀末尾, 直到栈顶的操作符优先级低于它。
                while (true) {
                    flag = StackPop(stack, &c);
                    // 只有 `*/` 的优先级大于等于 `*/`, 即只有 `*/` 时才会添加到后缀末尾
                    if (flag && (c == '*' || c == '/')) {
                        suffix_str[suffix_index++] = c;
                    } else {
                        break;
                    }
                }
                // 如果弹出了值就再压回去
                if (flag) {
                    StackPush(stack, &c, &stack_index);
                }
                StackPush(stack, &token, &stack_index);
                // 非法字符
            } else {
                printf("Infix String is Error\n");
                return;
            }
        }
        token = infix_str[++infix_index];
    }

    // 弹出栈内剩余
    while (true) {
        flag = StackPop(stack, &c);
        // 空栈跳出循环
        if (!flag) {
            break;
        }
        suffix_str[suffix_index++] = c;
    }
    suffix_str[suffix_index] = '\0';
}


void computedSuffix(const char *suffix_str, float *result) {
    Stack *stack = StackInit(FLOAT, 64);
    float y, a, b;
    char num_chars[16];
    int suffix_index = 0, stack_index, num_index;
    char token = suffix_str[suffix_index];
    while (token != '\0') {
        // 跳过空格
        if (token == ' ') {
            token = suffix_str[++suffix_index];
            continue;
        }
        // 读取一个数字
        if (isdigit(token)) {
            num_index = 0;
            // 添加 `.` 判断支持小数
            while (isdigit(token) || token == '.') {
                num_chars[num_index] = token;
                token = suffix_str[++suffix_index];
                num_index++;
            }
            // 字符串尾缀
            num_chars[num_index] = '\0';
            // 回移
            suffix_index--;
            float num = (float) atof(num_chars); // NOLINT(cert-err34-c)
            // 数字直接添加到栈中
            StackPush(stack, &num, &stack_index);
            // +-*/ 弹栈计算
        } else {
            if (token == '+' || token == '-' ||
                token == '*' || token == '/') {
                // 弹出栈顶两个数据
                StackPop(stack, &a);
                StackPop(stack, &b);
                // 计算
                switch (token) { // NOLINT(hicpp-multiway-paths-covered)
                    case '+':
                        y = a + b;
                        break;
                    case '-':
                        y = a - b;
                        break;
                    case '*':
                        y = a * b;
                        break;
                    case '/':
                        y = a / b;
                        break;
                }
                // 将结果再入栈
                StackPush(stack, &y, &stack_index);
                // 忽略括号
            } else if (token == '(' || token == ')') {
                // 非法字符
            } else {
                printf("非法字符!");
                return;
            }
        }
        token = suffix_str[++suffix_index];
    }
    // 将结果放入指定地址
    StackPop(stack, result);
}
