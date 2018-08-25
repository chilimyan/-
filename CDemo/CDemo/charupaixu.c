//
//  charupaixu.c
//  CDemo
//
//  Created by chilim on 2018/7/29.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "charupaixu.h"

void charupaixu(){
    int a[10] = {4,1,10,33,14,5,20,8,10,9};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j ++) {
            if (a[i+1] < a[j] && i < 9) {
                int temp = a[i+1];
                a[i+1] = a[j];
                a[j] = temp;
            }
        }
    }
   
    for (int k = 0; k < 10; k ++) {
        printf("%i\n",a[k]);
    }
}

void zhebancharupaixu(){
    int a[10] = {4,1,10,33,14,5,20,8,10,9};
    int low,high,mid;
    for (int i = 1; i < 10; i++) {
        int temp = a[i];
        low = 0;
        high = i-1;
        while (low <= high) {//注意是小于等于
            mid = (low+high)/2;
            if (temp < a[mid]) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        for (int j = i; j > low; j --) {
            a[j] = a[j-1];
        }
        a[low] = temp;
    }
    for (int k = 0; k < 10; k ++) {
        printf("%i\n",a[k]);
    }
}
