//
// Created by Sakura on 2022/5/14.
//
#include "stdio.h"
#include "stdlib.h"

#include "SqList.h"


bool InitSqList(SqList *L, int size) {
    L->items = (ElemType *) malloc(sizeof(ElemType) * size); // 分配数据存储空间
    if (!L->items) return false;        // 分配空间是否成功
    L->length = 0;                      // 空表初始长度为0
    L->size = size;                     // 表最大长度
    return true;                        // 初始化成功
}

int SqListLength(SqList L) {
    return L.length;
}

bool SqListEmpty(SqList L) {
    if (L.length == 0) {
        return true;
    } else {
        return false;
    }
}

bool SqListPush(SqList *L, ElemType e, int *i) {
    // 判断表是否满了
    if (L->length < L->size) {
        *i = L->length;
        L->items[L->length++] = e;
        return true;
    } else {
        return false;
    }
}

bool SqListInsert(SqList *L, int i, ElemType e) {
    // 判断表是否满了
    if (L->length < L->size) {
        // 判断插入位置是否合法
        if (i >= 0 && i <= L->length) {
            // 向后移动插入位置及之后的元素
            for (int j = L->length - 1; j >= i; j--) {
                L->items[j + 1] = L->items[j];
            }
            // 插入元素
            L->items[i] = e;
            // 表长+1
            L->length++;
            return true;
        }
    }
    return false;
}

bool SqListDelete(SqList *L, int i, ElemType *e) {
    // 判断表是否为空
    if (!SqListEmpty(*L)) {
        // 判断删除下标是否存在
        if (i >= 0 && i < L->length) {
            // 保存删除元素
            *e = L->items[i];
            // 向前移动删除位置之后的元素
            for (int j = i; j < L->length - 1; j++) {
                L->items[j] = L->items[j + 1];
            }
            // 表长-1
            L->length--;
            return true;
        }
    }
    return false;
}

bool SqListSet(SqList *L, int i, ElemType e) {
    // 判断表是否为空
    if (!SqListEmpty(*L)) {
        // 判断删除下标是否存在
        if (i >= 0 && i < L->length) {
            // 修改元素
            L->items[i] = e;
            return true;
        }
    }
    return false;
}

bool SqListGet(SqList L, int i, ElemType *e) {
    if (i >= 0 && i < L.length) {
        *e = L.items[i];
        return true;
    } else {
        return false;
    }
}

int SqListIndex(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.items[i] == e)return i;
    }
    return -1;
}

void SqListPrint(SqList L) {
    // 判断是否为空表
    if (SqListEmpty(L)) {
        printf("SqList([], length: %d, size: %d)\n", L.length, L.size);
    } else {
        printf("SqList([");
        for (int i = 0; i < L.length - 1; i++) {
            printf("%d, ", L.items[i]);
        }
        // 输出最后一个元素及其它信息
        printf("%d], length: %d, size: %d)\n", L.items[L.length - 1], L.length, L.size);
    }
}

void ClearSqList(SqList *L) {
    L->length = 0;
}

void DestroySqList(SqList *L) {
    if (L->items) {
        free(L->items);
        L->items = NULL;
    }
    L->length = 0;
    L->size = 0;
}

void test() {
    int index, elem;
    bool flag;
    printf("SqListTest\n");
    SqList sqList;
    printf("sqList(@%p)\n", &sqList);
    // 初始化顺序表
    InitSqList(&sqList, 5);
    // 打印空表
    SqListPrint(sqList);
    // 测试添加元素
    for (int i = 0; i < 10; i++) {
        flag = SqListPush(&sqList, i, &index);
        printf("num %d push is %s\n", i, flag ? "true" : "false");
    }
    // 打印表长
    printf("sqList length is:%d\n", SqListLength(sqList));
    // 打印表
    SqListPrint(sqList);
    // 测试删除数据
    flag = SqListDelete(&sqList, 3, &elem);
    printf("del at 3 item is %s, item is:%d\n", flag ? "true" : "false", elem);
    // 打印删除后的表
    SqListPrint(sqList);
    // 测试插入数据
    SqListInsert(&sqList, 3, 100);
    // 打印插入后的表
    SqListPrint(sqList);
    // 测试修改数据
    SqListSet(&sqList, 3, 50);
    // 打印修改后的表
    SqListPrint(sqList);
    // 测试查找数据索引下标
    int listIndex = SqListIndex(sqList, 3);
    printf("num 3 in sqList at %d\n", listIndex);
    // 测试获取数据
    flag = SqListGet(sqList, 3, &elem);
    printf("get at 3 item is %s, item is:%d\n", flag ? "true" : "false", elem);
    // 测试清空表
    ClearSqList(&sqList);
    // 打印清空后的表
    SqListPrint(sqList);
    // 销毁表
    DestroySqList(&sqList);
    // 打印销毁后的表
    printf("sqList(@%p)\n", &sqList);
    SqListPrint(sqList);
    // 销毁后操作
    flag = SqListPush(&sqList, 5, &index);
    printf("destroy push is %s\n", flag ? "true" : "false");
}

int main() {
    test();
}