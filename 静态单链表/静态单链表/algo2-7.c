//
//  algo2-7.c
//  静态单链表
//
//  Created by chilim on 2018/10/17.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-7.h"

void main27(){
    SLinkList s = {{"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHANG",8},{"WANG",0}};
    int i;
    i = s[0].cur;// i指示第1个结点的位置
    while (i) {
        printf("%s ",s[i].data); // 输出链表的当前值
        i = s[i].cur;
    }
    printf("\n");
    s[4].cur = 9;
    s[9].cur = 5;
    strcpy(s[9].data, "SHI");
    s[6].cur = 8;// 删除"ZHANG"
    i = s[0].cur;// i指示第1个结点的位置
    while (i) {
        printf("%s ",s[i].data); // 输出链表的当前值
        i = s[i].cur;
    }
    printf("\n");
}



