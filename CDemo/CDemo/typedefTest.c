
//
//  typedefTest.c
//  CDemo
//
//  Created by chilim on 2018/6/5.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include <stdio.h>

typedef int aaa;//为int再多取一个名字而已

////则ST则相当于struct Student
//typedef struct Student{
//    int sid;
//    char name[200];
//}ST;

//typedef struct Student{
//    int sid;
//    char name[200];
//}* PST, STU;//PST则相当于struct Student *,PST则相当于一个指针
//
//void f(){
//    struct Student st;
//    STU stu;
//    PST pst = &st;
//
//    //下面这两个是等价的
//    stu.sid = 200;
//    pst->sid = 200;
//    (*pst).sid = 200;
//}


