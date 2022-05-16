//
// Created by Sakura on 2022/5/14.
//

#ifndef DATASTRUCTUREANDALGORITHM_SQLIST_H
#define DATASTRUCTUREANDALGORITHM_SQLIST_H

#endif //DATASTRUCTUREANDALGORITHM_SQLIST_H

#include "stdbool.h"

typedef int ElemType;

typedef struct {
    ElemType *items;    // 数据数组
    int length;         // 表长度
    int size;           // 表大小, 即最大长度
} SqList;

/**
 * 初始化顺序表
 * @param L 顺序表指针
 * @return 是否初始化成功
 */
bool InitSqList(SqList *L, int size);

/**
 * 求顺序表长度
 * @param L 顺序表
 * @return 顺序表长度
 */
int SqListLength(SqList L);

/**
 * 判断顺序表是否为空
 * @param L 顺序表
 * @return 顺序表是否为空
 */
bool SqListEmpty(SqList L);

/**
 * 添加元素
 * @param L 顺序表指针
 * @param e 添加的元素
 * @param i 添加到的索引
 * @return
 */
bool SqListPush(SqList *L, ElemType e, int *i);

/**
 * 插入元素
 * @param L 顺序表指针
 * @param i 插入的下标
 * @param e 插入的元素
 * @return 是否插入成功
 */
bool SqListInsert(SqList *L, int i, ElemType e);

/**
 * 删除元素
 * @param L 顺序表指针
 * @param i 删除元素下标
 * @param e 保存删除元素
 * @return 是否删除成功
 */
bool SqListDelete(SqList *L, int i, ElemType *e);

/**
 * 修改元素
 * @param L 顺序表指针
 * @param i 修改元素下标
 * @param e 新元素
 * @return 是否修改成功
 */
bool SqListSet(SqList *L, int i, ElemType e);

/**
 * 获取顺序表中下标i的元素
 * @param L 顺序表
 * @param i 下标
 * @param e 获取到的元素
 * @return 是否获取成功
 */
bool SqListGet(SqList L, int i, ElemType *e);

/**
 * 查找元素在顺序表中的下标, 不存在返回-1
 * @param L 顺序表
 * @param e 查找的元素
 * @return
 */
int SqListIndex(SqList L, ElemType e);

/**
 * 打印输出顺序表
 * @param L 顺序表
 */
void SqListPrint(SqList L);

/**
 * 清空顺序表
 * @param L 顺序表指针
 */
void ClearSqList(SqList *L);

/**
 * 销毁顺序表
 * @param L 顺序表指针
 */
void DestroySqList(SqList *L);