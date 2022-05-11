//
// Created by Sakura on 2022/5/9.
//

#include "stdio.h"
#include "stdbool.h"

#include "calc.h"
#include "StackChar.h"

void testChar2Float() {
    printf("'0' is: %d\n", '0');
    printf("'9' is: %d\n", '9');
    float num;
    bool flag = char2float('2', &num);
    printf("'2' to: %f\n", num);
}

void testStack() {
    bool flag;
    int index;
    char item;
    StackChar *stack = StackCharInit(24);
    printf("stack sizeof: %d\n", sizeof(*stack));
    StackCharPrint(stack);
    // 压栈测试
    for (int i = 0; i < 5; i++) {
        flag = StackCharPush(stack, (char) (i + 48), &index);
        printf("add item is %s, index is %d\n", flag ? "true" : "false", index);
    }
    // 打印栈
    StackCharPrint(stack);
    // 弹栈测试
    while (true) {
        flag = StackCharPop(stack, &item);
        if (!flag) {
            printf("栈中没有数据啦!\n");
            break;
        }
        printf("pop item is %c\n", item);
    }
    // 打印栈
    StackCharPrint(stack);
}

void testInfixToSuffix() {
    float result;
    char infix_str[] = "2*2-3+5*((6+7)/4)";
    char suffix_str[100]; // 22*3-567+4/*+
    InfixToSuffix(infix_str, suffix_str);
    printf("Infix is: %s\n", infix_str);
    printf("Suffix is: %s\n", suffix_str);
    computedSuffix(suffix_str, &result);
    printf("Suffix computed result is: %f\n", result);
}

int main() {
    printf("InfixToSuffix/simple\n");
    // testChar2Float();
    // testStack();
    testInfixToSuffix();
}


