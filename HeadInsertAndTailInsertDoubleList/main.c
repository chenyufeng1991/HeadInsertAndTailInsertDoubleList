//
//  main.c
//  HeadInsertAndTailInsertDoubleList
//
//  Created by chenyufeng on 16/3/3.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  分别使用头插法和尾插法两种方式来构建不带头结点的双向非循环链表
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化不带头结点的非循环双向链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，链表初始化完成\n",__FUNCTION__);
}

//尾插法创建不带头结点的非循环双向链表
Node *TailInsertCreateList(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;
    pInsert->prior = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pNode;

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            pMove->next = pInsert;
            pInsert->prior = pMove;
            pMove = pMove->next;
        }

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，尾插法建立链表成功\n",__FUNCTION__);

    return pNode;
}

//头插法创建不带头结点的非循环双向链表
Node *HeadInsertCreateList(Node *pNode){

    Node *pInsert;
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));

    pInsert->next = NULL;
    pInsert->prior = NULL;
    scanf("%d",&(pInsert->element));

    if (pInsert->element <= 0) {

        printf("%s函数执行，输入数据非法，建立链表停止\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
        }else{

            pInsert->next = pNode;
            pNode->prior = pInsert;
            pNode = pInsert;
        }

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pInsert->prior = NULL;
        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行，头插法建立链表成功\n",__FUNCTION__);
    return pNode;
}

//打印非循环双向链表
void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//返回不带头节点的双向链表的长度
int sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{

        while (pNode != NULL) {
            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);
    
    pList = TailInsertCreateList(pList);
    printList(pList);
    sizeList(pList);

    pList = HeadInsertCreateList(pList);
    printList(pList);
    sizeList(pList);

    return 0;
}










