//
//  bo2-32.c
//  静态单链表
//
//  Created by chilim on 2018/10/19.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-32.h"

// 将一维数组L中各分量链成一个备用链表，L[0].cur为头指针。“0”表示空指针。
void InitSpace(SLinkList L){
    int i;
    for (i = 0; i < MAX_SIZE-1; i ++) {
        L[i].cur = i + 1;
    }
    L[MAX_SIZE -1].cur = 0;
}

// 构造一个空链表，返回值为空表在数组中的位序
int InitList(SLinkList L){
    int i;
    i = Malloc(L);// 调用Malloc()，简化程序
    L[i].cur = 0;// 空链表的表头指针为空(0)
    return i;
}

// 初始条件:L中表头位序为n的静态链表已存在。操作结果:将此表重置为空表
void ClearList(SLinkList L,int n){
    int j=0,k,i = L[n].cur;// 链表第一个结点的位置
    L[n].cur = 0;// 链表空
    k = L[0].cur;// 备用链表第一个结点的位置
    L[0].cur = i;// 把链表的结点连到备用链表的表头
    while (i) {
        j=i;
        i = L[i].cur;// 指向下一个元素
    }
    L[j].cur = k;// 备用链表的第一个结点接到链表的尾部
}

// 判断L中表头位序为n的链表是否空，若是空表返回TRUE;否则返回FALSE
Status ListEmpty(SLinkList L,int n){
    if (L[n].cur == 0) {// 空表
        return TRUE;
    }else{
        return FALSE;
    }
}

// 返回L中表头位序为n的链表的数据元素个数
int ListLength(SLinkList L,int n){
    int j = 0,i = L[n].cur;// i指向第一个元素
    while (i) {
        i = L[i].cur;
        j ++;
    }
    return j;
}
 // 用e返回L中表头位序为n的链表的第i个元素的值
Status GetElem(SLinkList L,int n, int i,ElemType *e){
    int l,k = n;
    if (i < 1 || i > ListLength(L, n)) {
        return ERROR;
    }
    for (l = 1; l <= i; l++) {
        k = L[k].cur;
    }
    *e = L[k].data;
    return OK;
}

// 在L中表头位序为n的静态单链表中查找第1个值为e的元素。
// 若找到，则返回它在L中的位序;否则返回0。
int LocateElem(SLinkList L,int n,ElemType e){
    int i = L[n].cur;// i指示表中第一个结点
    while (i && L[i].data != e) {
        i = L[i].cur;
    }
    return i;
}

//若cur_e是此单链表的数据元素，且不是第一个，
//则用pre_e返回它的前驱;否则操作失败，pre_e无定义
Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType *pre_e){
    int j,i = L[n].cur;
    do {
        j = i;
        i = L[i].cur;
    } while (i && cur_e != L[i].data);
    if (i) {
        *pre_e = L[j].data;
        return OK;
    }
    return ERROR;
}

//若cur_e是此单链表的数据元素，且不是最后一个
//则用next_e返回它的后继;否则操作失败，next_e无定义
Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType *next_e){
    int i;
    i = LocateElem(L, n, cur_e);
    if (i) {
        i = L[i].cur;// cur_e的后继的位置
        if (i) {
            *next_e = L[i].data;
            return OK;// cur_e元素有后继
        }
    }
    return ERROR;
}

// 在L中表头位序为n的链表的第i个元素之前插入新的数据元素e
Status ListInsert(SLinkList L,int n,int i,ElemType e){
    int l,j,k = n;// k指向表头
    if (i < 1 || i > ListLength(L, n) + 1) {
        return ERROR;
    }
    j = Malloc(L);
    if (j) {
        L[j].data = e;
        for (l = 1; j < i; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}
// 删除在L中表头位序为n的链表的第i个数据元素e，并返回其值
Status ListDelete(SLinkList L, int n,int i,ElemType *e){
    int j,k = n;
    if (i < 1 || i > ListLength(L, n)) {
        return ERROR;
    }
    for (j = 1; j < i; j++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    *e = L[j].data;
    Free(L, j);
    return OK;
}

// 依次对L中表头位序为n的链表的每个数据元素调用函数vi()
void ListTraverse(SLinkList L,int n,void(*vi)(ElemType)){
    int i = L[n].cur;// 指向第一个元素
    while (i) {
        vi(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}

