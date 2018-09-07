//
//  algo2-6.c
//  CDemo
//
//  Created by chilim on 2018/9/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-6.h"

// 逆位序(插在表头)输入n个元素的值，建立带表头结构的单链线性表L,头插法
void CreateList1(LinkList *L, int n){
    int i;
    LinkList p;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;//建立一个带头结点的单链表
    printf("请输入%d个数据\n",n);
    for (i = n; i >0; --i) {
        p = (LinkList)malloc(sizeof(LNode));//生成新结点
        scanf("%d",&p->data);//输入元素值
        p->next = (*L)->next;//插入到表头
        (*L)->next = p;
    }
}

// 正位序(插在表尾)输入n个元素的值，建立带表头结构的单链线性表L,尾插法
void CreateList2(LinkList *L, int n){
    int i;
    LinkList p = NULL,q;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    q = *L;
    printf("请输入%d个数据\n",n);
    for (i = 1; i <= n; i ++) {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
}

void MergeList3(LinkList La, LinkList *Lb, LinkList *Lc){
    // 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
    LinkList pa = La->next, pb = (*Lb)->next, pc;
    *Lc = pc = La;//用La的头结点作为Lc的头结点
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        pc->next = pa ? pa : pb;//插入剩余段
        free(*Lb);//释放Lb的头结点
        *Lb = NULL;
    }
}

void main28(){
    int n = 5;
    LinkList La,Lb,Lc;
    printf("按非递减顺序,");
    CreateList2(&La, n);
    printf("La = ");//输出链表La的内容
    ListTraverse1(La, print);
    printf("按非递增顺序,");
    CreateList1(&Lb, n);
    printf("Lb = ");
    ListTraverse1(Lb, print);
    MergeList3(La, &Lb, &Lc);
    printf("Lc=");//输出Lc的内容
    ListTraverse1(Lc, print);
}
