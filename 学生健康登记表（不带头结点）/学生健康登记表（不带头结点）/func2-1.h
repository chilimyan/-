//
//  func2-1.h
//  不带头结点的单链表
//
//  Created by chilim on 2018/10/15.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef func2_1_h
#define func2_1_h

#include <stdio.h>
#include "c2-2.h"
#include "bo2-8.h"

// 按关键字非降序将e插入表L。函数compare()返回值为形参1的关键字-形参2的关键字
void InsertAscend(LinkList *L, ElemType e,int(*compare)(ElemType,ElemType));

// 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是 // 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
// 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
LinkList Point(LinkList L,ElemType e,Status(*epual)(ElemType,ElemType),LinkList *p);

// 删除表L中满足条件的结点，并返回TRUE;如无此结点，则返回FALSE。
// 函数equal()的两形参的关键字相等，返回OK;否则返回ERROR
Status DeleteElem(LinkList *L,ElemType *e,Status(*equal)(ElemType,ElemType));

#endif /* func2_1_h */
