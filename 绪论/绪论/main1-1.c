//
//  main1-1.c
//  绪论
//
//  Created by chilim on 2018/10/9.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main1-1.h"

void main11(){
    Triplet T = NULL;
    ElemType m;
    Status i = 0;
    T = InitTriplet(5, 7, 9);// 初始化三元组T，其3个元素依次为5，7，9
    printf("调用初始化函数后，i=%d(1:成功) T的3个值为\n",i);
    printf("%d,%d,%d\n",T[0],T[1],T[2]);
    i = Get(T, 2, &m);// 将三元组T的第2个值赋给m
    if (i == OK) {
        printf("T的第2个值为:%d\n",T[1]);
    }
    i = Put(T, 2, 6);
    if (i == OK) {
        printf("T将T的第2个值改为6后，T的3个值为:%d,%d,%d\n",T[0],T[1],T[2]);
    }
    i = IsAscending(T);// 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变
    printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
    i = IsDescending(T);
    printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
    if ((i = Max(T, &m)) == OK) {
        printf("T中的最大值为:%d\n",m);
    }
    if ((i = Min(T, &m)) == OK) {
        printf("T中的最小值为:%d\n",m);
    }
    DestoryTriplet(&T);
    printf("销毁T后，T=%p(NULL)",T);
}
