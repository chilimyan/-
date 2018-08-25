//
//  hannuota.c
//  CDemo
//
//  Created by chilim on 2018/7/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "hannuota.h"

void hannuota(int n, char A, char B, char C){
    if (n == 1) {
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n",n,A,C);
    }else{
        hannuota(n-1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n",n,A,C);
        hannuota(n-1, B, A, C);
    }
}



