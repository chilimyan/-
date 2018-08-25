//
//  kuaisupaixu2.c
//  CDemo
//
//  Created by chilim on 2018/7/29.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "kuaisupaixu2.h"

int findPos(int *a, int low, int high);
void quickSort1(int *a, int low, int high);

void kuaisupaixu2(){
    int a[10] = {4,1,10,33,14,5,20,8,10,9};
    quickSort1(a, 0, 9);
    for (int k = 0; k < 10; k ++) {
        printf("%i\n",a[k]);
    }
}

void quickSort1(int *a, int low, int high){
    int pos;
    while (low < high) {
        pos = findPos(a,low,high);
        quickSort1(a, low, pos-1);
        quickSort1(a, pos + 1, high);
    }
}

int findPos(int *a, int low, int high){
    int val = a[low];
    while (low < high) {
        while (a[low] <= val && low < high) {
            low ++;
        }
        a[high] = a[low];
        while (a[high] >= val && low < high) {
            high --;
        }
        a[low] = a[high];
    }
    a[low] = val;
    return low;
}
