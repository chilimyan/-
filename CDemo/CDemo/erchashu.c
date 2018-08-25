//
//  erchashu.c
//  CDemo
//
//  Created by chilim on 2018/7/22.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "erchashu.h"

struct BTNode {
    int data;//数据域
    struct BTNode *pLchild;//左指针
    struct BTNode *pRchild;//右指针
};

struct BTNode * createBTree(void);

void preTraverseBTree(struct BTNode *pT);
void inTraverseBTree(struct BTNode *pT);
void postTraverseBTree(struct BTNode *pT);

void initBTree(void){
    struct BTNode *pT = createBTree();
    preTraverseBTree(pT);//先序遍历
    inTraverseBTree(pT);//中序遍历
    postTraverseBTree(pT);// 后序遍历
}

void preTraverseBTree(struct BTNode *pT){
    if (NULL != pT) {
        printf("%c\n",pT->data);
        //pT->pLchild可以代表整个左子树
        if (NULL != pT->pLchild) {
           preTraverseBTree(pT->pLchild);
        }
        if (NULL != pT->pRchild) {
           preTraverseBTree(pT->pRchild);
        }
    }
}

void inTraverseBTree(struct BTNode *pT){
    if (NULL != pT) {
        if (NULL != pT->pLchild) {
            inTraverseBTree(pT->pLchild);
        }
        printf("%c\n",pT->data);
        if (NULL != pT->pRchild) {
            inTraverseBTree(pT->pRchild);
        }
    }
}


void postTraverseBTree(struct BTNode *pT){
    if (NULL != pT) {
        if (NULL != pT->pLchild) {
            postTraverseBTree(pT->pLchild);
        }
        if (NULL != pT->pRchild) {
            postTraverseBTree(pT->pRchild);
        }
        printf("%c\n",pT->data);
    }
}


struct BTNode * createBTree(){
    struct BTNode *pA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode *pE = (struct BTNode *)malloc(sizeof(struct BTNode));
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    
    pA->pLchild = pB;
    pA->pRchild = pC;
    
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;
    
    return pA;
}


