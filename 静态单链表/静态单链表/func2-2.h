//
//  func2-2.h
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef func2_2_h
#define func2_2_h

#include <stdio.h>
#include "c2-3.h"

// 若备用链表非空，则返回分配的结点下标(备用链表的第一个结点);否则返回0
int Malloc(SLinkList space);

// 将下标为k的空闲结点回收到备用链表(成为备用链表的第一个结点)
void Free(SLinkList space,int k);

#endif /* func2_2_h */
