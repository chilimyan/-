//
//  main.c
//  CDemo
//
//  Created by chilim on 2018/5/30.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrayTest.h"
#include "hannuota.h"
#include "erchashu.h"
#include "kuaisupaixu.h"
#include "maopaopaixu.h"
#include "charupaixu.h"
//
//void f(int *i){
//    int j = 101;
//    i = &j;
//}
////指针就是地址，地址就是指针
////数组与指针
//void f1(){
//    double *p;//p是一个变量，什么样的变量，这种double *的变量，即一个指向double类型的变量指针
//    double x = 66.6;
//
//    p = &x;//x的地址赋值给p，也即p指向x
//
//    double arr[3] = {1.1,2.2,3.3};//这是一个double类型的数组，其中arr表示的是一个指针，指向的是该数组的第一个元素.那么arr+1指向数组第二个元素。因为数组是连续存储的，所以只要我们知道了数组的第一个元素的地址和数组元素个数就能确定一个数组了。
//
//    double *q1,*q2;//q1和q2是指针变量，不管是什么类型的指针变量都是只占4个字节。
//
//    q1 = &arr[0];//q指向了第一个数组元素的地址
//    printf("%p\n",q1);//%p是输出地址，这里是输出第一个数组元素的地址
//
//    q2 = &arr[1];//q指向了第二个数组元素的地址
//    printf("%p\n",q2);//这里是输出第一个数组元素的地址
//    //输出内容：0x7ffeefbff5b0
//    //        0x7ffeefbff5b8
//    //这两个地址相差8个字节。因为1个double类型字符是占8个字节,那么q1指向的是第一个数组元素的地址。第一个元素是占8个字节，第一个字节保存的就是第一个数组元素的地址，相应的q2指向的是第二个数组元素的地址，这个地址是在第二个元素的第一个字节里面保存的。所以q1和q2是相差8个字节
//}
//
//void ff1(int ** q){
//    *q = (int *)0xffffffff;
//}
//
////通过函数修改实参的值，只需要把该实参的地址传给这个函数，通过修改实参的地址去修改实参的值
//void f2(){
//    int i = 9;
//    int * p = &i;
//
//    printf("%p\n",p);//0x7ffeefbff5b0
//    ff1(&p);//这里要通过ff1()函数去修改p的值，那么只需要把p的地址传给ff1就行了。这里p已经是一个指针了，那么p的地址就是指针的指针用**表示
//    printf("%p\n",p);//0x7ffeefbff5b8
//}
//
//struct Student{
//    int sid;
//    int age;
//    char name[200];
//};
//
//void f3(struct Student *pst){
//    (*pst).sid = 99;
//    strcpy(pst->name, "hanmeimei");
//    pst->age = 29;
//}
////这种方式耗内存，耗时间
//void g(struct Student st){
//    printf("%d    %d    %s\n",st.sid,st.age,st.name);
//}
//
//void g2(struct Student *pst){
//    printf("%d    %d    %s\n",pst->sid,pst->age,pst->name);
//}
//
////数组动态分配内存
//void arr(){
//    int a[5] = {4,10,2,8,6};
//
//    //为动态申请5个内存
//    int len = 5;
//    //这里返回的是数组中第一个元素的地址且是int类型的地址
//    int *pArr = (int *)malloc(sizeof(int) * len);
//    *pArr = 4;//类似于a[0] = 4;
//    pArr[1] = 10;//a[1] = 10;
//    pArr[2] = 20;
//    pArr[3] = 30;
//    pArr[4] = 40;
////    free(pArr);//释放pArr申请的动态内存
//    for (int i = 0; i < len; i++) {
//        printf("%d\n",*(pArr+i));
//    }
//}
//
//int f5(){
//    int j = 20;
//    return j;
//}
//
////跨函数使用内存
//struct Person{
//    int age;
//    int sid;
//};
//
//struct Person * creatPerson(){
//    struct Person *pst = (struct Person *)malloc(sizeof(struct Person *));
//    pst->age = 66;
//    pst->sid = 99;
//    return pst;
//}
//
//void showPerson(struct Person *ps){
//    printf("%d   %d\n",ps->age,ps->sid);
//}

//int main(int argc, const char * argv[]) {
//    int i = 9;
////    f(&i);
//    int a[5] = {1,2,3,4,5};
//    //a是一个指针，指向数组的第一个元素
//    printf("i = %p\n",a);
//    printf("i = %p\n",a+1);
//    printf("i = %p\n",a+2);
//    f1();
//    struct Student st = {1000,20,"zhangsan"};
//    printf("%d    %d    %s\n",st.sid,st.age,st.name);
//    st.sid = 99;
//
////    st.name = "lisi";字符串不能这么赋值
//    strcpy(st.name,"lisi");
//    st.age = 22;
//    printf("%d    %d    %s\n",st.sid,st.age,st.name);
//
//    //第二种方式
//    struct Student *pst;
//    pst = &st;
//    pst->sid = 200000;//pst->sid等价于(*pst).sid,等价于st.sid;
//
//    f3(&st);
//   // printf("%d    %d    %s\n",st.sid,st.age,st.name);
//    g(st);
//    g2(&st);
    
//    arr();
    
//    int i = 10;
//    i = f5();
//
//    printf("i = %d\n",i);
    
//    struct Person *psd;
//    psd = creatPerson();
//    showPerson(psd);
//    initShow();
//    char ch1 = 'A';
//    char ch2 = 'B';
//    char ch3 = 'C';
//    int n = 4;
//    hannuota(n, ch1, ch2, ch3);
//    kuaisupaixu();
//    maopaopaixu();
//    charupaixu();
//    zhebancharupaixu();
//    return 0;
//}
#include "main1-1.h"
#include "main2-1.h"

int main(int argc, const char * argv[]) {
    main2();
    return 0;
}


