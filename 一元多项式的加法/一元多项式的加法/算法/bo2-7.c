//
//  bo2-7.c
//  一元多项式的加法
//
//  Created by chilim on 2018/10/22.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "bo2-7.h"

// 按有序判定函数compare()的约定，将值为e的结点插入或合并到升序链表L的适当位置
void OrderInsertMerge(PLinkList *L,ElemType e,int(*compare)(term,term)){
    Position q,s;
    if (LocateElem1(*L, e, &q, compare)) {
        q->data.coef += e.coef;// 改变当前结点系数的值
        if (!q->data.coef) {// 系数为0
            // 删除多项式L中当前结点
            s = PriorPos(*L, q);// s为当前结点的前驱
            if (!s) {//q无前驱
                s = (*L)->head;
            }
            DelFirst(L, s, &q);
            FreeNode(&q);
        }
    }else{// 生成该指数项并插入链表
        MakeNode(&s, e);// 生成结点
        InsFirst(L, q, s);
    }
}

///指数值的比较
int cmp(term a,term b){
    if (a.expn == b.expn) {
        return 0;
    }else{
        return (a.expn - b.expn)/abs(a.expn - b.expn);
    }
}

// 输入m项的系数和指数，建立表示一元多项式的有序链表P
void CreatePolyn(PLinkList *L, int m){
    Position q,s;
    term e;
    int i;
    InitList(L);
    printf("请依次输入%d个系数，指数:\n",m);
    for (i = 1; i <= m; ++ i) {
        // 依次输入m个非零项(可按任意顺序)
        scanf("%f,%d",&e.coef,&e.expn);
        if (!LocateElem1(*L, e, &q, cmp)) {
            MakeNode(&s, e);// 生成结点并插入链表
            InsFirst(L, q, s);
        }
    }
}

// 打印输出一元多项式P
void PrintPolyn(PLinkList *L){
    Link q;
    q = (*L)->head->next;// q指向第1个结点
    printf(" 系数 指数\n");
    while (q) {
        printf("%f  %d\n",q->data.coef,q->data.expn);
        q = q->next;
    }
}

// 多项式加法:Pa=Pa+Pb，并销毁一元多项式Pb
void AddPolyn(PLinkList *pa,PLinkList *pb){
    Position ha,hb,qa,qb;
    term a,b;
    ha = GetHead(*pa);// ha和hb分别指向Pa和Pb的头结点
    hb = GetHead(*pb);
    qa = NextPos(ha);
    qb = NextPos(hb);// qa和qb分别指向Pa和Pb中当前结点(现为第1个结点)
    while (!ListEmpty(*pa)&&!ListEmpty(*pb)&&qa) {// Pa和Pb均非空且ha没指向尾结点(qa!=0)
        a = GetCurElem(qa);
        b = GetCurElem(qb);// a和b为两表中当前比较元素
        switch (cmp(a, b)) {
            case -1:
                ha = qa;// 多项式Pa中当前结点的指数值小
                qa = NextPos(ha);
                break;
            case 0:
                qa->data.coef += qb->data.coef;// 两者的指数值相等，修改Pa当前结点的系数值
                if (qa->data.coef == 0) {
                    DelFirst(pa, ha, &qa);
                    FreeNode(&qa);
                }else{
                    ha = qa;
                }
                DelFirst(pb, hb, &qb);
                FreeNode(&qb);
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            case 1:
                DelFirst(pb, hb, &qb);// 多项式Pb中当前结点的指数值小
                InsFirst(pa, ha, qb);
                ha = ha->next;
                qb = NextPos(hb);
                break;
            default:
                break;
        }
    }
    if (!ListEmpty(*pb)) {
        (*pb)->tail = hb;
        Append(pa, qb);// 链接Pb中剩余结点
    }
    DestroyPolyn(pb);
}
// 另一种多项式加法的算法:Pa=Pa+Pb，并销毁一元多项式Pb
void AddPolyn1(PLinkList *pa,PLinkList *pb){
    Position qb;
    term b;
    qb = GetHead(*pb);// qb指向Pb的头结点
    qb = qb ->next;// qb指向Pb的第1个结点
    while (qb) {
        b = GetCurElem(qb);
        OrderInsertMerge(pa, b, cmp);
        qb = qb ->next;
    }
    DestroyPolyn(pb);
}

// 一元多项式Pa系数取反
void Opposite(PLinkList pa){
    Position p;
    p = pa->head;
    while (p->next) {
        p = p->next;
        p->data.coef *= -1;
    }
}
// 多项式减法:Pa=Pa-Pb，并销毁一元多项式Pb
void SubtractPolyn(PLinkList *pa,PLinkList *pb){
    Opposite(*pb);
    AddPolyn(pa, pb);
}
// 多项式乘法:Pa=Pa×Pb，并销毁一元多项式Pb
void MultiplyPolyn(PLinkList *pa,PLinkList *pb){
    PLinkList pc;
    Position qa,qb;
    term a,b,c;
    InitList(&pc);
    qa = GetHead(*pa);
    qa = qa->next;
    while (qa) {
        a = GetCurElem(qa);
        qb = GetHead(*pb);
        qb = qb->next;
        while (qb) {
            b = GetCurElem(qb);
            c.coef = a.coef*b.coef;
            c.expn = a.expn + b.expn;
            OrderInsertMerge(&pc, c, cmp);
            qb = qb->next;
        }
        qa = qa->next;
    }
    DestroyPolyn(pb);
    ClearList(pa);
    (*pa)->head = pc->head;
    (*pa)->tail = pc->tail;
    (*pa)->len = pc->len;
}

