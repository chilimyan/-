//
//  algo2-10.c
//  循环单链表
//
//  Created by chilim on 2018/10/20.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-10.h"

 // 将Lb合并到La的表尾，由La指示新表
void MergeList(LinkList *La,LinkList Lb){
    LinkList p = Lb->next;//Lb的头结点
    Lb->next = (*La)->next;//
    (*La)->next = p->next;
    free(p);
    *La = Lb;
}

void main210(){
    int n = 5,i;
    LinkList La,Lb;
    InitList(&La);
    for (i = 1; i <= n; i ++) {
        ListInsert(&La, i, i);
    }
    printf("La="); // 输出链表La的内容
    ListTraverse(La, print);
    InitList(&Lb);
    for (i = 1; i <= n; i ++) {
        ListInsert(&Lb, 1, i*2);
    }
    printf("Lb="); // 输出链表Lb的内容
    ListTraverse(Lb, print);
    MergeList(&La, Lb);
    printf("La+Lb="); // 输出合并后的链表的内容
    ListTraverse(La, print);
    
}

