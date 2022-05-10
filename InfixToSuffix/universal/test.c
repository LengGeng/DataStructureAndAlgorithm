//
// Created by Sakura on 2022/5/10.
//
#include "stdio.h"

#include "calc.h"
#include "Stack.h"

void testCreateItem() {
    int intData = 120;
    char charData = 'A';
    char *strData = "ABC";
    // int
    void *viData = createItem(&intData, INT);
    printf("intData(%p) is:%d\n", &viData, intData);
    printf("viData(%p) is:%d\n", viData, *(int *) viData);
    // char
    void *vcData = createItem(&charData, CHAR);
    printf("charData(%p) is:%c\n", &charData, charData);
    printf("vcData(%p) is:%c\n", vcData, *(char *) vcData);
    // str
    void *vsData = createItem(strData, STRING);
    printf("strData(%p) is:%s\n", &strData, strData);
    printf("vsData(%p) is:%s\n", vsData, (char *) vsData);
}

void testStack() {
    int index;
    // INT
    printf("info:Test Int Stack\n");
    Stack *intStack = StackInit(INT, 64);
    printf("info:init intStack(%p)\n", intStack);
    StackPrint(intStack);
    for (int i = 0; i < 10; i++) {
        StackPush(intStack, &i, &index);
    }
    StackPrint(intStack);
    // FLOAT
    printf("Test FLOAT Stack\n");
    Stack *floatStack = StackInit(FLOAT, 64);
    printf("info:init floatStack(%p)\n", floatStack);
    StackPrint(floatStack);
    for (int i = 0; i < 10; i++) {
        float num = (float) i;
        StackPush(floatStack, &num, &index);
    }
    StackPrint(floatStack);
    // CHAR
    printf("Test CHAR Stack\n");
    Stack *charStack = StackInit(CHAR, 64);
    printf("info:init charStack(%p)\n", charStack);
    StackPrint(charStack);
    // 压栈测试
    for (int i = 0; i < 10; i++) {
        char token = (char) (i + 48);
        StackPush(charStack, &token, &index);
    }
    StackPrint(charStack);
    // STRING
    printf("Test STRING Stack\n");
    Stack *strStack = StackInit(STRING, 64);
    printf("info:init strStack(%p)\n", strStack);
    StackPrint(strStack);
    // 压栈测试
    char string[11];
    for (int i = 0; i < 10; i++) {
        string[i] = (char) (i + 48);
        string[i + 1] = '\0';
        StackPush(strStack, string, &index);
    }
    StackPrint(strStack);
    // 弹栈测试
    while (StackPop(strStack, string)) {
        printf("info:test stack pop str is:%s\n", string);
    }
    StackPrint(strStack);
}

void testInfixToSuffix() {
    float result;
    char infix_str[] = "2.2544*22+55*(60+7)";
    char suffix_str[100]; // 2 2 *5 6 7 +*+
    InfixToSuffix(infix_str, suffix_str);
    printf("Infix is: %s\n", infix_str);
    printf("Suffix is: %s\n", suffix_str);
    computedSuffix(suffix_str, &result);
    printf("Suffix computed result is: %f\n", result);
}

int main() {
    printf("InfixToSuffix/universal\n");
    // testCreateItem();
    // testStack();
    testInfixToSuffix();
}
