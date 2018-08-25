//
//  kuaisupaixu.c
//  CDemo
//
//  Created by chilim on 2018/7/22.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "kuaisupaixu.h"

void quickSort(int *a ,int low, int high);

void kuaisupaixu(){
    int a[6] = {2,1,0,5,4,3};
    quickSort(a,0,5);
    for (int i = 0; i < 6; i ++) {
        printf("%d",a[i]);
    }
}

int FindPos(int *a, int low, int high);

void quickSort(int *a ,int low, int high){
    int pos;
    if (low < high) {
        pos = FindPos(a,low,high);
        quickSort(a,low,pos-1);
        quickSort(a,pos+1,high);
    }
}

int FindPos(int *a, int low, int high){
    int val = a[low];
    while (low < high) {
        while (low < high && a[high] >= val) {
            -- high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= val) {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = val;
    return low;
}

