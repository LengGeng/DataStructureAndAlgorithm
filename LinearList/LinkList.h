//
// Created by Sakura on 2022/5/16.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINKLIST_H
#define DATASTRUCTUREANDALGORITHM_LINKLIST_H

#endif //DATASTRUCTUREANDALGORITHM_LINKLIST_H

#include "stdbool.h"

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 初始化链表
 * @param L 链表指针
 * @return 是否初始化成功
 */
bool InitLinkList(LinkList *L);

/**
 * 求链表长度
 * @param L 链表
 * @return 链表长度
 */
int LinkListLength(LinkList L);

/**
 * 判断链表是否为空
 * @param L 链表
 * @return 链表是否为空
 */
bool LinkListEmpty(LinkList L);

/**
 * 添加元素
 * @param L 链表指针
 * @param e 添加的元素
 * @param i 添加到的索引
 * @return
 */
bool LinkListPush(LinkList L, ElemType e, int *i);

/**
 * 插入元素
 * @param L 链表指针
 * @param i 插入的下标
 * @param e 插入的元素
 * @return 是否插入成功
 */
bool LinkListInsert(LinkList L, int i, ElemType e);

/**
 * 删除元素
 * @param L 链表指针
 * @param i 删除元素下标
 * @param e 保存删除元素
 * @return 是否删除成功
 */
bool LinkListDelete(LinkList L, int i, ElemType *e);

/**
 * 修改元素
 * @param L 链表指针
 * @param i 修改元素下标
 * @param e 新元素
 * @return 是否修改成功
 */
bool LinkListSet(LinkList L, int i, ElemType e);

/**
 * 获取链表中下标i的元素
 * @param L 链表
 * @param i 下标
 * @param e 获取到的元素
 * @return 是否获取成功
 */
bool LinkListGet(LinkList L, int i, ElemType *e);

/**
 * 查找元素在链表中的下标, 不存在返回-1
 * @param L 链表
 * @param e 查找的元素
 * @return
 */
int LinkListIndex(LinkList L, ElemType e);

/**
 * 打印输出链表
 * @param L 链表
 */
void LinkListPrint(LinkList L);

/**
 * 清空链表
 * @param L 链表指针
 */
void ClearLinkList(LinkList L);

/**
 * 销毁链表
 * @param L 链表指针
 */
void DestroyLinkList(LinkList *L);