//
//  algo2-7.c
//  CDemo
//
//  Created by chilim on 2018/9/2.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-7.h"

void PrintStud(StuElemType e){
    //显示记录e的内容
    printf("%-8s %6ld", e.name, e.num);
    if (e.sex == 'm') {
        printf("男");
    }else{
        printf("女");
    }
    printf("%5d %-4s", e.age, e.Class);
    printf("%9s\n", sta[e.health]);
}

void ReadIn(struct stud *e){
    //由键盘输入节点信息
    printf("请输入姓名(<=%d个字符):",NAMWLEN);
    scanf("%s", e->name);
    printf("请输入学号:");
    scanf("%ld",&(e->num));
    printf("请输入性别（m：男 f:女）：");
    scanf("%*c%c",&(e->sex));
    printf("请输入年龄：");
    scanf("%d",&(e->age));
    printf("请输入班级(<=%d个字符):",CLASSLEN);
    scanf("%s",e->Class);
    printf("请输入健康状况(0:%s 1:%s 2:%s):",sta[0],sta[1],sta[2]);
    scanf("%d",&(e->health));
}

void WriteToFile(StuElemType e){
    //将节点信息写入fp指定的文件
    fwrite(&e, sizeof(ElemType), 1, fp);
}

Status ReadFromFile(struct stud *e){
    //由fp指定的文件读取节点信息到e
    int i;
    i = (int)fread(e, sizeof(StuElemType), 1, fp);
    if (i == 1) {
        return OK;
    }else{
        return ERROR;
    }
}

int cmp(StuElemType c1, StuElemType c2){
    return (int)(c1.num - c2.num);
}

void Modify(LinkList *L, StuElemType e){
    //修改节点内容，并按学号将节点非降序插入链表L
    char s[80];
    PrintStud(e);//显示原内容
    printf("请输入待修改项的内容，不修改的项按回车键保持原值:\n");
    printf("请输入姓名(<=%d个字符): ",NAMWLEN);
    gets(s);//gets从标准输入设备读字符串函数，其可以无限读取，不会判断上限，以回车结束读取
    if (strlen(s)) {//从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，直到碰到第一个字符串结束符'\0'为止，然后返回计数器值(长度不包含'\0')。
        strcpy(e.name,s);//strcpy把从src地址开始且含有'\0'结束符的字符串复制到以dest开始的地址空间，返回值的类型为char*
    }
    printf("请输入学号: ");
    gets(s);
    if (strlen(s)) {
        e.num = atol(s);//把字符串转换成长整型数
    }
    printf("请输入性别(m:男 f:女): ");
    gets(s);
    if (strlen(s)) {
        e.sex = s[0];
    }
    printf("请输入年龄: ");
    gets(s);
    if (strlen(s)) {
        strcpy(e.Class, s);
    }
    printf("请输入健康状况(0:%s 1:%s 2:%s):",sta[0],sta[1],sta[2]);
    gets(s);
    if (strlen(s)) {
        e.health = atoi(s);//修改完毕
    }
    InserAscend(L, e.num, cmp);//把q所指结点的内容按学号非降序插入
}

#define N 4//student记录的个数

Status EqualNum(StuElemType c1, StuElemType c2){
    if (c1.num == c2.num) {
        return OK;
    }else{
        return ERROR;
    }
}

Status EqualName(StuElemType c1, StuElemType c2){
    if (strcmp(c1.name, c2.name)) {
        return ERROR;
    }else{
        return OK;
    }
}

void mainStu(){
    //表的初始记录
    StuElemType student[N] = {{"王小林",790631,'m',18,"计91",0},{"陈红",790632,'f',20,"计91",1},{"刘建平",790633,'m',21,"计91",0},{"张丽丽",790634,'m',17,"计91",2}};
    int i,j,flag=1;
    char filename[13];
    ElemType e;
    LinkList T,p,q;
    InitList2(&T);//初始化链表
}



