//
//  arrayTest.c
//  CDemo
//
//  Created by chilim on 2018/6/3.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "arrayTest.h"
#include <stdbool.h>
#include <stdlib.h>


////定义一个数据类型
//struct Arr {
//    int *pBase ;//存储的是数组第一个元素的地址
//    int len;//数组所能容纳的最大元素个数
//    int cnt;//当前有效元素的个数
////    int increment;//自动增长因子
//};
//
//void init_arr(struct Arr *pArr, int length);
//bool append_arr(struct Arr *pArr, int value);//追加
//bool insert_arr(struct Arr *pArr, int pos, int value);//在pos前面插入数据
//bool delete_arr(struct Arr *pArr, int pos, int * pVal);
//int get(void);
//bool is_empty(struct Arr *pArr);
//bool is_full(struct Arr *pArr);
//void sort_arr(struct Arr *pArr);//冒泡排序
//void show_arr(struct Arr *pArr);
//void inversion_arr(struct Arr *pArr);//倒置
//
//void initShow(void){
//    struct Arr arr;
//    int val;
//
//    init_arr(&arr,6);
//    append_arr(&arr, 4);
//    append_arr(&arr, 2);
//    append_arr(&arr, 3);
////    delete_arr(&arr, 1, &val);
//    append_arr(&arr, 9);
//    append_arr(&arr, 5);
//    append_arr(&arr, 16);
////    append_arr(&arr, 7);
////    insert_arr(&arr, 4, 11);
//
////    inversion_arr(&arr);
//    sort_arr(&arr);
//    show_arr(&arr);
//}
//
//void init_arr(struct Arr *pArr, int length){
////    (*pArr).len = 99;等价于下面
////    pArr->len = 100;//表示pArr指针指向的那个结构体变量的len成员
//    pArr->pBase = (int *)malloc(sizeof(int) * length);
//    if (NULL == pArr->pBase) {
//        printf("动态程序分配失败！");
//        exit(-1);//终止整个程序
//    }else{
//        pArr->len = length;
//        pArr->cnt = 0;
//    }
//    return;
//}
//
//bool is_empty(struct Arr *pArr){
//    if (pArr->cnt == 0) {
//        return true;
//    }
//    return false;
//}
//
//bool is_full(struct Arr *pArr){
//    if (pArr->cnt == pArr->len) {
//        return true;
//    }
//    return false;
//}
//
//void show_arr(struct Arr *pArr){
//    if (is_empty(pArr)) {
//        printf("数组为空！\n");
//    }else{
//        for (int i = 0; i < pArr->cnt; i ++) {
//            printf("%d",pArr->pBase[i]);
//        }
//        printf("\n");
//    }
//}
//
//bool append_arr(struct Arr *pArr, int value){
//    //数组存满了
//    if (is_full(pArr)) {
//        printf("数组满了！追加失败！");
//        return false;
//    }else{
//        pArr->pBase[pArr->cnt] = value;
//        (pArr->cnt)++;
//        return true;
//    }
//}
//
//bool insert_arr(struct Arr *pArr, int pos, int value){
//    if (pos < 1 || pos > 1+pArr->cnt) {
//        printf("数组满了！");
//        return false;
//    }else{
//        for (int i = pArr->cnt-1; i >= pos-1; i--) {
//            pArr->pBase[i+1] = pArr->pBase[i];
//        }
//        pArr->pBase[pos-1] = value;
//        return true;
//    }
//}
//
//bool delete_arr(struct Arr *pArr, int pos, int * pVal){
//    if (is_empty(pArr)) {
//        return false;
//    }
//    if (pos < 1 || pos > pArr->cnt) {
//        return false;
//    }
//    *pVal = pArr->pBase[pos-1];
//    for (int i = pos; i < pArr->cnt; i ++) {
//        pArr->pBase[i-1] = pArr->pBase[i];
//    }
//    return true;
//}
//
//void inversion_arr(struct Arr *pArr){
//    int i = 0;
//    int j = pArr->cnt-1;
//    int t;
//    while (i<j) {
//        t = pArr->pBase[i];
//        pArr->pBase[i] = pArr->pBase[j];
//        pArr->pBase[j] = t;
//        ++i;
//        --j;
//    }
//}
////冒泡排序
//void sort_arr(struct Arr *pArr){
//    int t;
//    for (int i = 0; i < pArr->cnt; ++i) {
//        for (int j = i+1; j<pArr->cnt; j++) {
//            if (pArr->pBase[i] > pArr->pBase[j]) {
//                t = pArr->pBase[i];
//                pArr->pBase[i] = pArr->pBase[j];
//                pArr->pBase[j] = t;
//            }
//        }
//    }
//}



