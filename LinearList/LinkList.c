//
// Created by Sakura on 2022/5/16.
//

#include "stdio.h"
#include "stdlib.h"

#include "LinkList.h"

void test();

bool InitLinkList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(LNode));  // 分配存储空间
    if (!*L) return false;                  // 判断分配是否成功
    (*L)->next = NULL;                      // 空表
    return true;
}

int LinkListLength(LinkList L) {
    int length = 0;
    LinkList p = L;
    while (p->next) {
        p = p->next;
        length++;
    }
    return length;
}

bool LinkListEmpty(LinkList L) {
    if (L->next) {
        return false;
    } else {
        return true;
    }
}

bool LinkListPush(LinkList L, ElemType e, int *i) {
    int l = 0;
    LinkList p = L;
    // 将链表移动到最后一个
    while (p->next) {
        l++;
        p = p->next;
    }
    // 新建元素
    LinkList n = NULL;
    // 初始化元素
    if (InitLinkList(&n)) {
        // 设置值
        n->data = e;
        // 添加元素
        p->next = n;
        // 返回添加索引
        *i = l;
        return true;
    } else {
        return false;
    }
}

bool LinkListInsert(LinkList L, int i, ElemType e) {
    // 判断插入位置是否合法
    if (i < 0)return false;
    LinkList p = L;
    for (int j = 0; j < i; j++) {
        // 判断是否还有下一元素
        if (!p)return false;
        p = p->next;
    }
    // 新建元素
    LinkList n = NULL;
    // 初始化元素
    if (InitLinkList(&n)) {
        // 设置值
        n->data = e;
        // 先将 n->next 指向 p->next
        n->next = p->next;
        // 再将 p->next 指向 n
        p->next = n;
        return true;
    } else {
        return false;
    }
}

bool LinkListDelete(LinkList L, int i, ElemType *e) {
    // 判断删除位置是否合法
    if (i < 0)return false;
    LinkList p = L;
    for (int j = 0; j < i; j++) {
        // 判断是否还有下一元素
        if (!p)return false;
        p = p->next;
    }
    // 删除的元素
    LinkList n = p->next;
    // 返回元素数据
    *e = n->data;
    // 从链表中删除
    p->next = n->next;
    // 删除元素
    free(n);
    return true;
}

bool LinkListSet(LinkList L, int i, ElemType e) {
    // 判断删除位置是否合法
    if (i < 0)return false;
    LinkList p = L->next;
    for (int j = 0; j < i; j++) {
        // 判断是否还有下一元素
        if (!p)return false;
        p = p->next;
    }
    // 修改值
    p->data = e;
    return true;
}

bool LinkListGet(LinkList L, int i, ElemType *e) {
    // 判断删除位置是否合法
    if (i < 0)return false;
    LinkList p = L->next;
    for (int j = 0; j < i; j++) {
        // 判断是否还有下一元素
        if (!p)return false;
        p = p->next;
    }
    // 返回值
    *e = p->data;
    return true;
}

int LinkListIndex(LinkList L, ElemType e) {
    int i = 0;
    LinkList p = L->next;
    while (p) {
        if (p->data == e) {
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}

void LinkListPrint(LinkList L) {
    // 判断空表
    if (LinkListEmpty(L)) {
        printf("LinkList()\n");
    } else {
        LinkList p = L->next;
        printf("LinkList([");
        // 遍历链表
        while (p) {
            // 判断是否还有下一元素
            if (p->next) {
                printf("%d, ", p->data);
            } else {
                printf("%d])\n", p->data);
            }
            // 后移
            p = p->next;
        }
    }
}

void ClearLinkList(LinkList L) {
    LinkList t, p = L->next;
    // 清空元素
    while (p) {
        // 保存当前元素
        t = p;
        // 向下移动
        p = p->next;
        // 删除当前元素
        free(t);
    }
    // 将表置为空表
    L->next = NULL;
}

void DestroyLinkList(LinkList *L) {
    LinkList t, p = *L;
    // 清空元素
    while (p) {
        // 保存当前元素
        t = p;
        // 向下移动
        p = p->next;
        // 删除当前元素
        free(t);
    }
    // 将表指向 NULL
    *L = NULL;
}

void test() {
    int index;
    bool flag;
    int data;
    printf("init before LinkListTest\n");
    LinkList L = NULL;
    printf("init after LinkList(@%p)\n", L);
    // 初始化表
    InitLinkList(&L);
    printf("LinkList(@%p)\n", L);
    // 判断空表
    printf("LinkListEmpty is: %s\n", LinkListEmpty(L) ? "true" : "false");
    // 表长度
    printf("LinkListLength is: %d\n", LinkListLength(L));
    // 打印表
    LinkListPrint(L);
    // 测试添加数据
    for (int i = 0; i < 10; i++) {
        flag = LinkListPush(L, i, &index);
        printf("LinkListPush is %s, index at %d\n", flag ? "true" : "false", index);
    }
    printf("LinkListEmpty is: %s\n", LinkListEmpty(L) ? "true" : "false");
    printf("LinkListLength is: %d\n", LinkListLength(L));
    LinkListPrint(L);
    // 测试插入数据
    flag = LinkListInsert(L, 4, 100);
    printf("LinkListInsert 100 at 4 is %s\n", flag ? "true" : "false");
    printf("LinkListEmpty is: %s\n", LinkListEmpty(L) ? "true" : "false");
    printf("LinkListLength is: %d\n", LinkListLength(L));
    LinkListPrint(L);
    // 测试删除元素
    flag = LinkListDelete(L, 5, &data);
    printf("LinkListDelete at 5 is %s, data is %d\n", flag ? "true" : "false", data);
    LinkListPrint(L);
    // 测试获取元素
    flag = LinkListGet(L, 3, &data);
    printf("LinkListGet at 3 is %s, data is %d\n", flag ? "true" : "false", data);
    // 测试修改元素
    flag = LinkListSet(L, 6, 1000);
    printf("LinkListSet at 4 to 1000 is %s\n", flag ? "true" : "false", data);
    LinkListPrint(L);
    // 测试查找索引
    printf("LinkListIndex 1000 at %d\n", LinkListIndex(L, 1000));
    LinkListPrint(L);
    // 测试清空表
    ClearLinkList(L);
    LinkListPrint(L);
    // 测试销毁表
    DestroyLinkList(&L);
    printf("LinkList(@%p)\n", L);
}

int main() {
    test();
}



