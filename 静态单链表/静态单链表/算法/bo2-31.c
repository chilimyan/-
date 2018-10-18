//
//  bo2-31.c
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-31.h"


//一个数组只生成一个静态链表

//一个备用链表，表头为L的第一个单元L[0]，“0”表示空指针
void InitList(SLinkList L){
    int i;
    L[MAX_SIZE-1].cur = 0;
    for (i = 0; i < MAX_SIZE - 2; i ++) {
        L[i].cur = i + 1;
    }
    L[MAX_SIZE-2].cur = 0;
}

//将L重置为空表
void ClearList(SLinkList L){
    int i,j = 0,k;
    i = L[MAX_SIZE - 1].cur;// 链表第一个结点的位置
    L[MAX_SIZE - 1].cur = 0;// 链表空
    k = L[0].cur;// 备用链表第一个结点的位置
    L[0].cur = i;
    while (i) {// 没到链表尾
        j = i;
        i = L[i].cur;// 指向下一个元素
    }
    L[j].cur = k;// 备用链表的第一个结点接到链表的尾部
}

// 若L是空表，返回TRUE;否则返回FALSE
Status ListEmpty(SLinkList L){
    ///判断最后一个元素的下标是否为0
    if (L[MAX_SIZE - 1].cur == 0) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 返回L中数据元素个数
int ListLength(SLinkList L){
    int j = 0,i = L[MAX_SIZE - 1].cur;// i指向第一个元素
    while (i) {// 没到静态链表尾
        i = L[i].cur;// 指向下一个元素
        j ++;
    }
    return j;
}

// 用e返回L中第i个元素的值
Status GetElem(SLinkList L,int i,ElemType *e){
    int l,k = MAX_SIZE-1;// k指向表头序号
    if (i < 1|| i>ListLength(L)) {
        return ERROR;
    }
    for (l = 1; l <= i; l++) {
        k = L[k].cur;// 移动到第i个元素处
    }
    *e = L[k].data;
    return OK;
}

// 在静态单链线性表L中查找第1个值为e的元素。若找到，则返回它在L中的
// 位序;否则返回0。(与其它LocateElem()的定义不同)
int LocateElem(SLinkList L,ElemType e){
    int i = L[MAX_SIZE - 1].cur;// i指示表中第一个结点
    while (i && L[i].data != e) {// 在表中顺链查找(e不能是字符串)
        i = L[i].cur;
    }
    return i;
}


//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱;
Status PriorElem(SLinkList L,ElemType cur_e,ElemType *pre_e){
    int j,i = L[MAX_SIZE - 1].cur;// i指示链表第一个结点的位置
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

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继;
Status NextElem(SLinkList L,ElemType cur_e,ElemType *next_e){
    int j,i = LocateElem(L, cur_e);// 在L中查找第一个值为cur_e的元素的位置
    if (i) {
        j = L[i].cur;// cur_e的后继的位置
        if (j) {
            *next_e = L[j].data;//cur_e有后继
            return OK;
        }
    }
    return ERROR;
}

 // 在L中第i个元素之前插入新的数据元素e
Status ListInsert(SLinkList L,int i,ElemType e){
    int l,j,k = MAX_SIZE - 1;// k指向表头
    if (i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }
    j = Malloc(L);// 申请新单元
    if (j) {
        L[j].data = e;// 赋值给新单元
        for (l = 1; l < i; l++) {//找到第i-1个元素的位置k
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;//让j的下一个元素指向i
        L[k].cur = j;//第i-1个元素的下一个元素指向j
        return OK;
    }
    return ERROR;
}

// 删除在L中第i个数据元素e，并返回其值
Status ListDelete(SLinkList L,int i,ElemType *e){
    int j,k = MAX_SIZE - 1;// k指向表头
    if (i < 1 || i > ListLength(L)) {
        return ERROR;
    }
    for (j = 1; j < i; j ++) {// 移动i-1个元素
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    *e = L[j].data;
    Free(L, j);
    return OK;
}

//依次对L的每个数据元素调用函数vi()
void ListTraverse(SLinkList L,void(*vi)(ElemType)){
    int i = L[MAX_SIZE - 1].cur;// 指向第一个元素
    while (i) {
        vi(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}



