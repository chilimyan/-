//
//  NodeTest.c
//  DemoC
//
//  Created by Apple on 2018/6/7.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "NodeTest.h"

typedef struct Node{
    int data;//数据域
    struct Node *pNext;//指针域
}NODE,*PNODE;//NODE等价于struct Node， PNODE等价于struct Node *

PNODE creat_list(void);//创建链表
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);//在pHead所指向链表的第pos个节点的前面插入一个值为val节点，
bool delete_list(PNODE pHead, int pos, int *pVal);
void sort_list(PNODE pHead);

void test(void){
    PNODE pHead = NULL;
    
    pHead = creat_list();//创建一个非循环单链表，第一个内存的地址给pHead
//    traverse_list(pHead);//遍历链表
//    if (is_empty(pHead)) {
//        printf("链表为空");
//    }
//    printf("链表长度为:%d\n",length_list(pHead));
    //排序
//    sort_list(pHead);
//    traverse_list(pHead);//遍历链表
    insert_list(pHead, 3,100);
    int pVal;
    delete_list(pHead, 6, &pVal);
    traverse_list(pHead);//遍历链表
    printf("%d\n",pVal);
}

PNODE creat_list(void){
    int len = 10;
    int i;
    
    ///生成一个不存放数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("分配失败");
        exit(-1);
    }
    
    PNODE pTemp = pHead;
    pTemp->pNext = NULL;
    
    int data[10] = {1,2,3,4,5,6,7,8,9,0};
    for (i = 0; i < len; i ++) {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pHead) {
            printf("分配失败");
            exit(-1);
        }
        pNew->data = data[i];
        pTemp->pNext = pNew;
        pNew->pNext = NULL;
        pTemp = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead){
    //p指向第一个有效节点
    PNODE p = pHead->pNext;
    if (p == NULL) {
        printf("链表为空");
    }
    while (p != NULL) {
        printf("%d\n",p->data);
        p = p->pNext;
    }
}

bool is_empty(PNODE pHead){
    if (pHead->pNext == NULL) {
        return true;
    }
    return false;
}

int length_list(PNODE pHead){
    PNODE p = pHead->pNext;
    int len = 0;
    while (p != NULL) {
        len ++;
        p = p->pNext;
    }
    return len;
}

void sort_list(PNODE pHead){
    int i,j,t;
    PNODE p,q;
    for (i = 0, p = pHead->pNext; i < length_list(pHead)-1; p = p->pNext,++i) {
        for (j= i+1, q = p->pNext; j < length_list(pHead); ++j, q=q->pNext) {
            if (p->data < q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

bool insert_list(PNODE pHead, int pos, int val){
    if (pos > length_list(pHead)) {
        return false;
    }
    int i = 0;
    PNODE p = pHead;
    while (p != NULL && i < pos-1) {
        p = p->pNext;
        ++i;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (pNew == NULL) {
        printf("动态内存分配失败\n");
        exit(-1);
    }
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}

bool delete_list(PNODE pHead, int pos, int *pVal){
    if (pos > length_list(pHead)) {
        return false;
    }
    int i = 0;
    PNODE p = pHead;
    while (p->pNext != NULL && i < pos-1) {
        p = p->pNext;
        ++i;
    }
    PNODE q = p->pNext;
    *pVal = q->data;
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    return true;
}

