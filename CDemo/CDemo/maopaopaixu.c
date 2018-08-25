//
//  maopaopaixu.c
//  CDemo
//
//  Created by chilim on 2018/7/29.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "maopaopaixu.h"

//冒泡排序
void maopaopaixu(){
    int a[10] = {4,1,10,33,14,5,20,8,10,9};
    for (int i = 0; i < 10; i ++) {
        for (int j = i + 1; j < 10; j ++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int k = 0; k < 10; k ++) {
        printf("%i\n",a[k]);
    }
}


