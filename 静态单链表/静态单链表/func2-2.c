//
//  func2-2.c
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "func2-2.h"


// 若备用链表非空，则返回分配的结点下标(备用链表的第一个结点);否则返回0
int Malloc(SLinkList space){
    int i = space[0].cur;
    if (i) {
        space[0].cur = space[i].cur;// 备用链表的头结点指向原备用链表的第二个结点
    }
    return i;// 返回新开辟结点的坐标
}

// 将下标为k的空闲结点回收到备用链表(成为备用链表的第一个结点)
void Free(SLinkList space,int k){
    space[k].cur = space[0].cur;// 回收结点的"游标"指向备用链表的第一个结点
    space[0].cur = k;// 备用链表的头结点指向新回收的结点
}
