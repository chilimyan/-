//
//  c2-1.c
//  DemoC
//
//  Created by Apple on 2018/8/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "c2-1.h"

#define LIST_INIT_SIZE 10//线性表存储空间的初始分配量
#define LIST_INCREMENT 2 //线性表存储空间的分配增量

struct Sqlist {
    ElemType *elem; //存储空间基址
    int length;   //当前长度
    int listsize; //当前分配的存储容量(以sizeof(ElemType)为单位)
};
