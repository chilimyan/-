//
//  guibingpaixu.c
//  DemoC
//
//  Created by Apple on 2018/8/1.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "guibingpaixu.h"

void mergeSort(int *a, int indexL, int indeR);
void merge(int *a, int indexL, int indeR, int mid);

void guibingpaixu(){
    int a[10] = {10,2,6,8,12,1,9,22,11,30};
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; i ++) {
        printf("%d\n",a[i]);
    }
}

void mergeSort(int *a, int indexL, int indeR){
    if (indexL >= indeR) {
        return;
    }
    int mid = (indeR + indexL)/2;
    mergeSort(a,indexL,mid);
    mergeSort(a,mid + 1, indeR);
    merge(a, indexL, indeR, mid);
}

void merge(int *a, int indexL, int indeR, int mid){
    // 左边第一个元素
    int i = indexL;
    //右边第一个元素
    int j = mid +1;
    int p = indexL;
    int *b;
    b = (int*)malloc(sizeof(int)*(indeR-indexL + 1));
    int temp = 0;
    while (i <= mid && j <= indeR) {
        if (a[i] < a[j]) {
            b[temp] = a[i++];
        }else{
            b[temp] = a[j++];
        }
        temp ++;
    }
    while (temp <= mid) {
        b[temp] = a[i ++];
        temp++;
    }
    while (j <= indeR) {
        b[temp] = a[j++];
        temp++;
    }
    for (int k = 0; k < temp; k++) {
        a[p] = b[k];
        p++;
    }
//    free(b);
//    if (indeR -indexL == 1) {
//        if (a[indeR] < a[indexL]) {
//            int temp = a[indexL];
//            a[indexL] = a[indeR];
//            a[indeR] = temp;
//        }
//    }else{
//        if (a[mid + 1] < a[mid]) {
//            int j = mid+1;
//            while (j < indeR) {
//                j ++;
//                int low = indexL;
//                int high = j;
//                int temp = a[j];
//                while (low < high) {
//                    int midnew = (low + high)/2;
//                    if (a[j] < a[midnew]) {
//                        high = midnew-1;
//                    }else{
//                        low = midnew + 1;
//                    }
//                }
//                for (int k = j; k > low; k--) {
//                    a[k] = a[k-1];
//                }
//                a[low] = temp;
//            }
//        }
//    }
}
