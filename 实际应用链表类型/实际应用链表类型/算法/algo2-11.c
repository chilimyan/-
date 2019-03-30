//
//  algo2-11.c
//  实际应用链表类型
//
//  Created by chilim on 2018/10/22.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-11.h"

// 在带头结点的单链线性表L的第i个元素之前插入元素e
Status ListInsert_L(PLinkList *L,int i,ElemType e){
    Link h,s;
    if (!LocatePos(*L,i-1,&h)) {
        return ERROR;
    }
    MakeNode(&s, e);// 结点分配失败则退出
    InsFirst(L, h, s);// 对于从第i个结点开始的链表，第i-1个结点是它的头结点
    return OK;
}

// 已知单链线性表La和Lb的元素按值非递减排列。归并La和Lb得到新的单链
// 线性表Lc，Lc的元素也按值非递减排列。
void MergeList_L(PLinkList *La,PLinkList *Lb,PLinkList *Lc,int (*compare)(ElemType,ElemType)){
    Link ha,hb,pa,pb,q;
    ElemType a,b;
    InitList(Lc);// 存储空间分配失败则退出
    ha = GetHead(*La);// ha和hb分别指向La和Lb的头结点
    hb = GetHead(*Lb);
    pa = NextPos(ha);// pa和pb分别指向La和Lb的首元结点
    pb = NextPos(hb);
    while (pa && pb) {// La和Lb均非空
        a = GetCurElem(pa);// a和b为两表中当前比较元素(第1个元素)
        b = GetCurElem(pb);
        if (compare(a,b) <= 0) {
            DelFirst(La, ha, &q);// 移去La的首元结点并以q返回
            q->next = NULL;// 将q的next域赋值NULL，以便调用Append()
            Append(Lc, q);// 将q结点接在Lc的尾部
            pa = NextPos(ha);
        }else{
            DelFirst(Lb, hb, &q);// 移去Lb的首元结点并以q返回
            q->next = NULL;// 将q的next域赋值NULL，以便调用Append()
            Append(Lc, q);// 将q结点接在Lc的尾部
            pb = NextPos(hb);// pb指向Lb新的首元结点
        }
    }
    if (pa) {
        Append(Lc, pa);// 链接La中剩余结点
    }else{
        Append(Lc, pb);// 链接Lb中剩余结点
    }
    free(ha);// 销毁La和Lb
    (*La)->head = (*La)->tail = NULL;
    (*La)->len = 0;
    free(hb);
    (*Lb)->head = (*Lb)->tail = NULL;
    (*Lb)->len = 0;
}

int diff(ElemType c1,ElemType c2){
    return c1-c2;
}

void main211(){
    PLinkList La,Lb,Lc;
    int j;
    InitList(&La);
    for (j = 1; j <= 5; j++) {
        ListInsert_L(&La, j, j);// 顺序插入 1、2、3、4、5
    }
    printf("La=");
    ListTraverse(La, print);
    InitList(&Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert_L(&Lb, j, 2*j);// 顺序插入 2、4、6、8、10
    }
    printf("Lb=");
    ListTraverse(Lb, print);
    MergeList_L(&La, &Lb, &Lc, diff);// 归并La和Lb，产生Lc
    printf("Lc=");
    ListTraverse(Lc, print);
    DestroyList(&Lc);
    
}


