//
//  main2-5.c
//  双向链表
//
//  Created by chilim on 2018/10/21.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-5.h"

void main25(){
    DuLinkList L;
    int i,n;
    Status j;
    ElemType e;
    InitList(&L);
    for (i = 1; i<= 5; i ++) {
        ListInsert(L, i, i);// 在第i个结点之前插入i
    }
    printf("正序输出链表:");
    ListTraverse(L, print);// 正序输出
    printf("逆序输出链表:");
    ListTraverseBack(L, print);
    n = 2;
    ListDelete(L, n, &e);// 删除并释放第n个结点
    printf("删除第%d个结点，值为%d，其余结点为",n,e);
    ListTraverse(L, print);// 正序输出
    printf("链表的元素个数为%d\n",ListLength(L));
    printf("链表是否空:%d(1:是 0:否)\n",ListEmpty(L));
    ClearList(L);// 清空链表
    printf("清空后，链表是否空:%d(1:是 0:否)\n",ListEmpty(L));
    for (i = 1; i <= 5; i++) {
        ListInsert(L, i, i);// 重新插入5个结点
    }
    ListTraverse(L, print);// 正序输出
    n = 3;
    j = GetElem(L, n, &e);// 将链表的第n个元素赋值给e
    if (j) {
        printf("链表的第%d个元素值为%d\n",n,e);
    }else{
        printf("不存在第%d个元素\n",n);
    }
    n = 4;
    i = LocateElem(L, n, equal);
    if (i) {
        printf("等于%d的元素是第%d个\n",n,i);
    }else{
        printf("没有等于%d的元素\n",n);
    }
    j = PriorElem(L, n, &e);
    if (j) {
        printf("%d的前驱是%d\n",n,e);
    }else{
        printf("不存在%d的前驱\n",n);
    }
    j = NextElem(L, n, &e);
    if (j) {
        printf("%d的后继是%d\n",n,e);
    }else{
        printf("不存在%d的后继\n",n);
    }
    DestroyList(&L);
}
