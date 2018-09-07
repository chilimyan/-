//
//  algo2-7.h
//  CDemo
//
//  Created by chilim on 2018/9/2.
//  Copyright © 2018年 chilim. All rights reserved.
//

#ifndef algo2_7_h
#define algo2_7_h

//利用无头结点的单链表结构处理教科书图2.1(学生健康登记表)

#define NAMWLEN 8  //姓名最大长度
#define CLASSLEN 4 //班级名最大长度

struct stud //记录的结构
{
    char name[NAMWLEN + 1]; //包括‘\0’
    long num;
    char sex;
    int age;
    char Class[CLASSLEN + 1]; //包括'\0'
    int health;
};

typedef struct stud ElemType;

#include <stdio.h>
#include "c2-2.h"
#include "func2-4.h"
#include "bo2-3.h"

char sta[3][16] = {"健康","一般","神经衰弱"};//健康状况
FILE *fp;//全局变量

void PrintStud(ElemType e);

#endif /* algo2_7_h */
