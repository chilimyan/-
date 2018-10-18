//
//  main2-1.c
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-1.h"

// 数据元素判定函数(平方关系)，LocateElem()调用的函数
Status sq(ElemType c1, ElemType c2){
    if (c1 == c2*c2) {
        return TRUE;
    }else{
        return FALSE;
    }
}

//ListTraverse()调用的另一函数(元素值加倍)
void dbl(ElemType *c){
    *c *= 2;
}

void main21(){
    struct SqList L;
    ElemType e,e0;
    Status i;
    int j,k;
    InitList(&L);
    printf("初始化L后:L.elem=%p L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    for (j = 1; j <= 5; j++) {
        i = ListInsert(&L, 1, j);
    }
    printf("在L的表头依次插入1~5后:*L.elem=");
    for (j = 1; j <= 5; j++) {
        printf("%d\n",*(L.elem + j - 1));
    }
    printf("L.elem=%p L.length=%d L.listsize=%d ",L.elem,L.length,L.listsize);
    i = ListEmpty(&L);
    printf("L是否空:i=%d(1:是 0:否)\n",i);
    ClearList(&L);
    printf("清空L后:L.elem=%p L.length=%d L.listsize=%d ",L.elem,L.length,L.listsize);
    i = ListEmpty(&L);
    printf("L是否空:i=%d(1:是 0:否)\n",i);
    for (j = 1; j <= 10; j ++) {
        ListInsert(&L, j, j);
    }
    printf("在L的表尾依次插入1~10后:*L.elem=");
    for (j = 1; j <= 10; j++) {
        printf("%d",*(L.elem + j - 1));
    }
    printf("L.elem=%p L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    ListInsert(&L,1, 0);
    printf("在L的表头插入0后:*L.elem=");
    for (j = 1; j <= ListLength(&L); j ++) {
        printf("%d",*(L.elem + j - 1));
    }
    printf("L.elem=%p(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n",L.elem,L.length, L.listsize);
    GetElem(&L, 5, &e);
    printf("第5个元素的值为%d\n",e);
    for (j = 10; j <= 11; j ++) {
        k = LocateElem(&L, j, equal);
        // k不为0，表明有符合条件的元素，且其位序为k
        if (k) {
            printf("第%d个元素的值为%d\n",k,j);
        }else{
            printf("没有值为%d的元素\n",j);
        }
    }
    for (j = 3; j <= 4; j ++) {
        k = LocateElem(&L, j, sq);
        // k不为0，表明有符合条件的元素，且其位序为k
        if (k) {
            printf("第%d个元素的值为%d的平方\n",k,j);
        }else{
            printf("没有值为%d的平方的元素\n",j);
        }
    }
    // 测试头两个数据
    for (j = 1; j <= 2; j ++) {
        // 把第j个数据赋给e0
        GetElem(&L, j, &e0);
        // 求e0的前驱
        i = PriorElem(&L, e0, &e);
        if (i == INFEASIBLE) {
            printf("元素%d无前驱\n",e0);
        }else{
            printf("元素%d的前驱为%d\n",e0,e);
        }
    }
    // 测试最后两个数据
    for (j = ListLength(&L) - 1; j <= ListLength(&L); j++) {
        // 把第j个数据赋给e0
        GetElem(&L, j, &e0);
        // 求e0的后继
        i = NextElem(&L, e0, &e);
        if(i==INFEASIBLE){
            printf("元素%d无后继\n",e0);
        }else {
            printf("元素%d的后继为%d\n",e0,e);
        }
    }
    // k为表长
    k = ListLength(&L);
    for (j = k + 1; j >= k; j --) {
        // 删除第j个数据
        i = ListDelete(&L, j, &e);
        if (i == ERROR) {
            printf("删除第%d个元素失败\n",j);
        }else{
            printf("删除第%d个元素成功，其值为%d\n",j,e);
        }
    }
    printf("依次输出L的元素:");
    // 依次对元素调用print1()，输出元素的值
    ListTraverse(&L, print1);
    printf("L的元素值加倍后:");
    // 依次对元素调用dbl()，元素值乘2
    ListTraverse(&L, dbl);
    ListTraverse(&L, print1);
    DestoryList(&L);
    printf("销毁L后:L.elem=%p L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
}
