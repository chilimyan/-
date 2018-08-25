
//
//  main1-1.c
//  DemoC
//
//  Created by Apple on 2018/8/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main1-1.h"

void main11(){
    Triplet T;
    ElemType m;
    Status i;
    i = InitTriplet(&T, 5, 7, 9);
    printf("调用初始化函数后T的三个值为T[0]=%d,T[1]=%d,T[2]=%d\n",T[0], T[1], T[2]);
    i = Get(T, 2, &m);
    if (i == OK) {
        printf("T的第二个值为%d\n",m);
    }
    i = Put(T, 2, 6);
    if (i == OK) {
        printf("将T的第二个元素的值改为6后，T的第二个元素的值为%d\n",T[1]);
    }
    i = IsAscending(T);
    printf("T的三个元素是否为升序:i = %d(0否，1是)\n",i);
    i = IsDescending(T);
    printf("T的三个元素是否为降序:i = %d(0否，1是)\n",i);
    if ((i = Max(T, &m)) == OK) {
        printf("T的最大值为%d\n",m);
    }
    if ((i = Min(T, &m)) == OK) {
        printf("T的最小值为%d\n",m);
    }
    i = DestroyTriplet(&T);
    if (i == OK) {
        printf("三元组T销毁成功！");
    }
}
