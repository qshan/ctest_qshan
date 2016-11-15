/*
 * practice.h
 *
 *  Created on: Nov 4, 2016
 *    Author: qshan
 */

#ifndef SRC_QSHAN_PRACTICE_H_
#define SRC_QSHAN_PRACTICE_H_
#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFARRAYD1(x)  (int)(sizeof(x)/sizeof(x[0]))






//define the dlinst
#if 1
//qs_DListDataType
#define qs_DListDataType int
struct dlist_node{
  qs_DListDataType data;
  struct dlist_node *piror, *next;
};
typedef struct dlist_node qs_DLIST_NODE;
typedef struct dlist_node *qs_DLIST_PTR;
//typedef qs_DLIST_NODE *qs_DLIST_PTR;
#else
typedef struct dlist_node{
  qs_DListDataType data;
  struct dlist_node *piror, *next;
} qs_DLIST_NODE, *qs_DLIST_PTR;
#endif
//declare a struct
//qs_DLIST_NODE struct_customer_name;
//declare a pointer of struct
//qs_DLIST_PTR struct_customer_pointer;
//qs_DLIST_NODE *struct_customer_pointer;

//qs_QueueDataType
#define qs_QueueDataType int
typedef struct queue
{
  //this struct need a cell to diff the full and empty
  int queuesize;
  int head,tail;
  qs_QueueDataType *q;
} qs_QUEUE;

//qs_LStackType
#define qs_LStackType int
typedef struct lStackNode{
  qs_LStackType data;
  struct lStackNode *next;
} qs_LSTACK_NODE, *qs_LSTACK_NODE_PTR;

#define qs_TreeDataType int
typedef struct BiTNode
{
  qs_TreeDataType data;
  struct BiTNode *parent, *lchild, *rchild;
} qs_BITREE_NODE, *qs_BITREE_PTR;

//////// function name list here

//sort#####
int sort_int(int Array[], int size_array);
void print_int_array(int Array[], int size_array);

//list#####
qs_DLIST_PTR qs_dlist_create();
int qs_dlist_insert_R(qs_DLIST_PTR listptr, qs_DListDataType pos, qs_DListDataType data);
int qs_dlist_insert_L();
int qs_dlist_delete(qs_DLIST_PTR listptr, qs_DListDataType data);
int qs_dlist_delete_L();
int qs_dlist_delete_R();
int qs_dlist_print(qs_DLIST_PTR listptr);
int qs_dlist_length();
int qs_dlist_find();
int qs_dlist_find_L();
int qs_dlist_find_R();
//

//queue##### FIFO
int qs_InitQueue(qs_QUEUE *Q, int queuesize);
int qs_EnQueue(qs_QUEUE *Q, qs_QueueDataType key);
qs_QueueDataType qs_DeQueue(qs_QUEUE *Q);
int qs_PrintQueue(qs_QUEUE *Q);
//qs_IsQueueEmpty
//qs_IsQueueFull


//linked stack##### LIFO Last In First Out.
int qs_lStackInit(qs_LSTACK_NODE_PTR head);
int qs_lStackPush(qs_LSTACK_NODE_PTR head, qs_LStackType data);
qs_LStackType qs_lStackPop(qs_LSTACK_NODE_PTR head);
int qs_lStackPrint(qs_LSTACK_NODE_PTR head);

//tree#####
//BFS - Dreadth First Search
//DFS - Depth First Search
//Tree Traversals, Expression Tree


//graph#####

//BST - Binary Search Tree

//AVL Tree

//B Tree

//Hashing

#endif /* SRC_QSHAN_PRACTICE_H_ */
