//
//  LianBiao.c
//  CDemo
//
//  Created by chilim on 2018/6/5.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "LianBiao.h"

///一个节点的表示
typedef struct Node{
    int data;//数据域
    struct Node * pNext;//指针域,指向下一个节点的指针，所以类型是struct Node
}NODE, *PNODE;

