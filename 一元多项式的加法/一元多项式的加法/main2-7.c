//
//  main2-7.c
//  一元多项式的加法
//
//  Created by chilim on 2018/10/24.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "main2-7.h"

void main27(){
    PLinkList p,q;
    int m;
    printf("请输入第1个一元多项式的非零项的个数:");
    scanf("%d",&m);
    CreatePolyn(&p, m);
    printf("请输入第2个一元多项式的非零项的个数:");
    scanf("%d",&m);
    
    CreatePolyn(&q, m);
    AddPolyn(&p, &q);
    printf("2个一元多项式相加的结果:\n");
    PrintPolyn(&p);
    printf("请输入第3个一元多项式的非零项的个数:");
    scanf("%d",&m);
    CreatePolyn(&q, m);
    AddPolyn1(&p, &q);
    printf("2个一元多项式相加的结果(另一种方法):\n");
    PrintPolyn(&p);
    printf("请输入第4个一元多项式的非零项的个数:"); scanf("%d",&m);
    CreatePolyn(&q,m);
    SubtractPolyn(&p, &q);
    printf("2个一元多项式相减的结果:\n");
    PrintPolyn(&p);
    printf("请输入第5个一元多项式的非零项的个数:");
    scanf("%d",&m);
    CreatePolyn(&q, m);
    MultiplyPolyn(&p, &q);
    printf("2个一元多项式相乘的结果:\n");
    PrintPolyn(&p);
    DestroyPolyn(&p);
}

